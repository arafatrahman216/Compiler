#include"2105118_symbolInfo.h"
#include <algorithm>

string trim (string str) {
    //  fout<<"trimming "<<str<<endl;
    if (str.empty()) return str;
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    if (start == string::npos || end == string::npos) return "";
    str = str.substr(start, end - start + 1);
    //  fout<<"start "<<str <<endl;
    return str;
}


class ScopeTable
{
private:
    static int idCount ;
    int sid ; // static variable to keep track of scope table id
    int bucketSize ;
    int collissionCount ;
    unsigned long (*hashFunction)(string); // function pointer
    symbolInfo** hashtable; // hashtable of symbolInfo
    ScopeTable* parentScope ; // pointer to parent scope, to be used as a stack

public:
    
    ScopeTable(int bucketSize, unsigned long (*hashFunction)( string))  {
        hashtable = new symbolInfo*[bucketSize];
        this->bucketSize = bucketSize;
        for (int i = 0; i < bucketSize; i++) {
            hashtable[i] = NULL;
        }
        sid = ++idCount;
        collissionCount = 0;
        parentScope = nullptr;
        this->hashFunction = hashFunction ;
        fout<< "\tScopeTable# " << sid << " created" << endl;
    }

    static void initializeIDCount() {
        idCount = 0;
    }

    ScopeTable( ScopeTable* parent){
        this->parentScope = parent;
        this->bucketSize = parent->bucketSize;
        this->hashFunction = parent->hashFunction;
        this->sid = ++idCount;
        hashtable = new symbolInfo*[bucketSize];
        collissionCount = 0;
        for (int i = 0; i < bucketSize; i++) {
            hashtable[i] = NULL;
        }
        // scopeCount = 0;
        fout<< "\tScopeTable# " << sid << " created" << endl;
    }

    ~ScopeTable() {

        for (int i = 0; i < bucketSize; i++) {
            if (hashtable[i] != NULL) {
                symbolInfo* temp = hashtable[i];
                while (temp != NULL) {
                    symbolInfo* trash = temp;
                    temp = temp->getNextSymbol();
                    delete trash; 
                }
            }
        }
        delete[] hashtable; 
    }

    void setParentScope(ScopeTable* parent) {
        parentScope = parent;
    }

    ScopeTable* getParentScope() {
        return parentScope;
    }

    int getId() {
        return sid;
    }

    int getBucketSize() {
        return bucketSize;
    }

    
    symbolInfo * getLookUp ( string name, int &position){
        name = trim(name);
        unsigned long index = getHash(name);
        symbolInfo * hashPointer = hashtable[index];
        while ( hashPointer!= nullptr){
            if (hashPointer->getName() == name){
                return hashPointer;
            }
            hashPointer = hashPointer->getNextSymbol();
            position++;
        }
        return nullptr;
    }

    unsigned long getHash(string str){
        str = trim(str);
        return hashFunction(str) % bucketSize;
    }

    bool InsertSymbol(symbolInfo *sInfo) {
        // if name or type is empty or contains only spaces 
        if (sInfo->getName().empty() || sInfo->getType().empty() || sInfo->getName() == " " || sInfo->getType() == " ") {
            fout << "\tError: Missing name or type in input."<<endl;
            return false;
        } 
        sInfo->setName(trim(sInfo->getName()));
        unsigned long index = getHash(sInfo->getName());    
        int position = 1;
        int i = 1;
        symbolInfo* found = getLookUp(sInfo->getName(), i);
        //  fout << found << endl;
        if (found == nullptr){
            symbolInfo* temp = hashtable[index];
            if (hashtable[index] == nullptr) { 
                hashtable[index] = sInfo;
                //  fout << " test 5 " << endl;
                 fout <<"\tInserted in ScopeTable# " << sid << " at position " << index+1<< ", "<<position<<endl;
                // scopeCount++;
                return true;   
            }  
            collissionCount++;
            //  fout<<temp<<endl;
            position++;
            while (temp->getNextSymbol() != nullptr) {
                temp = temp->getNextSymbol();
                position++;
            }
            temp->setNextSymbol(sInfo);
            // scopeCount++;
            //inserted in ScopeTable# 5 at position 7, 3
             fout<< "\tInserted in ScopeTable# " << sid << " at position " << index+1 << ", " << position <<endl;
            return true;
        }       
        else {
            fout<< "\t\'" << sInfo->getName() << "\'"<< " already exists in the current ScopeTable" << endl;
            delete sInfo;
            return false;
        }
    }

    

    symbolInfo * LookUp(string name) {
        int position = 1;
        name = trim(name);
        unsigned long index = getHash(name) +1 ;
        symbolInfo* hashPointer = getLookUp(name, position);
        if (hashPointer != nullptr) {
            fout << "\t\'" << name << "\' found in ScopeTable# " << sid << " at position " << index << ", " << position << endl;
            return hashPointer;
        } else {
            return nullptr;
        }
    }

    bool DeleteSymbol(string name) {
        int i=1;
        if (name.empty()) {
            fout<<"\tNumber of parameters mismatch for the command D"<<endl;
            return false;
        }
        name = trim(name);
        unsigned long index = getHash(name);
        if (getLookUp(name, i) == nullptr) {
             fout << "\tNot found in the current ScopeTable"<<endl;
            return false;
        }
        int position = 1;
        symbolInfo* curr = hashtable[index];
        symbolInfo* prev = nullptr;
        while( curr!= nullptr){
            if (curr->getName() == name){
                if (prev == nullptr) {
                    hashtable[index] = curr->getNextSymbol();
                } else {
                    prev->setNextSymbol(curr->getNextSymbol());
                }
                delete curr;
                 fout << "\tDeleted \'" << name << "\' from ScopeTable# " << sid << " at position " << index+1 << ", " << position << endl;
                return true;
            }
            prev = curr;
            curr = curr->getNextSymbol();
            position++;
        }
        return false;
    }

    unsigned long (*getHashFunction())(string) {
        return hashFunction;
    }

    void PrintScopeTable(string tabs= "\t") {
        fout<<tabs << "ScopeTable# " << sid << endl;
        // cout<<tabs << "ScopeTable# " << sid << endl;
        for (int i = 0; i < bucketSize; i++) {
            // if (hashtable[i] != nullptr) {
                fout<< tabs << i+1 << "--> ";
                // cout<< tabs << i+1 << "--> ";
                symbolInfo* temp = hashtable[i];
                while (temp != nullptr) {
                    temp->PrintSymbolInfo();
                    temp = temp->getNextSymbol();
                }
                fout << endl;
                // cout << endl;
            // }
        }
    }

    int getCollissionCount() {
        return collissionCount;
    }
    
    static void setIdCount(int id) {
        idCount = id;
    }

};


int ScopeTable::idCount= 0; // Initialize static member variable


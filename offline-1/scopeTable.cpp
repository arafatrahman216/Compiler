#include"symbolInfo.h"
#include <algorithm>

#include<fstream>
fstream fout("output.txt", ios::out);

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
    // int scopeCount ;
    unsigned long (*hashFunction)(string); // function pointer
    symbolInfo** hashtable; // hashtable of symbolInfo
    ScopeTable* parentScope ; // pointer to parent scope, to be used as a stack

public:
    
    ScopeTable(int bucketSize, unsigned long (*hashFunction)( string) )  {
        hashtable = new symbolInfo*[bucketSize];
        this->bucketSize = bucketSize;
        //  fout<<" test 1 "<<endl;
        for (int i = 0; i < bucketSize; i++) {
            hashtable[i] = NULL;
        }
        //  fout<<" test 2 "<<endl;
        // scopeCount = 0;
        sid = ++idCount;
        parentScope = nullptr;
        this->hashFunction = hashFunction ;
        cout<< "ScopeTable# " << sid << " created" << endl;
    }

    ScopeTable( ScopeTable* parent){

    }

    ~ScopeTable() {
        for (int i = 0; i < bucketSize; i++) {
            if (hashtable[i] != NULL) {
                symbolInfo* temp = hashtable[i];
                //  fout << " test * " << bucketSize<< endl;
                while (temp != NULL) {
                    symbolInfo* toDelete = temp;
                    temp = temp->getNextSymbol();
                    //  fout << " test 3 " << endl;
                    delete toDelete; // Deleting the current node
                    //  fout << " test 4 " << endl;
                }
            }
        }
        delete[] hashtable; // Deleting the array of pointers (hashtable)
    }

    void setParentScope(ScopeTable* parent) {
        parentScope = parent;
        // if (parent != nullptr) parent->scopeCount++;
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

    // int getScopeCount() {
    //     return scopeCount;
    // }
    
    symbolInfo * getLookUp ( string name, int &position){
        name = trim(name);
        unsigned long index = getHash(name);
        symbolInfo * hashPointer = hashtable[index];
        while ( hashPointer!= nullptr){
            if (hashPointer->getName() == name){
                //  fout << "\'" << name << "\' found in ScopeTable# " << sid << " at position " << index << ", " << position << endl;
                return hashPointer;
            }
            hashPointer = hashPointer->getNextSymbol();
            position++;
        }
        //  fout<<"\'"<<name<<"\' not found in any of the ScopeTables";
        return nullptr;
    }

    unsigned long getHash(string str){
        str = trim(str);
        return hashFunction(str) % bucketSize;
    }

    bool InsertSymbol(symbolInfo *sInfo) {
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
            return false;
        }
    }

    

    symbolInfo * LookUp(string name) {
        int position = 1;
        name = trim(name);
        unsigned long index = getHash(name)+1 ;
        symbolInfo* hashPointer = getLookUp(name, position);
        if (hashPointer != nullptr) {
             fout << "\t\'" << name << "\' found in ScopeTable# " << sid << " at position " << index << ", " << position << endl;
            return hashPointer;
        } else {
             fout << "\t\'" << name << "\' not found in any of the ScopeTables" << endl;
            return nullptr;
        }
    }

    bool DeleteSymbol(string name) {
        int i=1;
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

    void PrintScopeTable(){
        cout << "ScopeTable# " << sid << endl;
        for (int i = 0; i < bucketSize; i++) {
            if (hashtable[i] != nullptr) {
                cout << i+1 << " --> ";
                symbolInfo* temp = hashtable[i];
                while (temp != nullptr) {
                    cout << "<" << temp->getName() << " : " << temp->getType() << "> ";
                    temp = temp->getNextSymbol();
                }
                cout << endl;
            }
        }
    }

    void test(){
        cout<<"ScopeTable# " << sid << endl;
        for (int i = 0; i < bucketSize; i++) {
            // if (hashtable[i] != nullptr) {
                cout << i+1 << " --> ";
                symbolInfo* temp = hashtable[i];
                while (temp != nullptr) {
                    temp->PrintSymbolInfo();
                    cout<<" ";
                    temp = temp->getNextSymbol();
                }
                cout << endl;
            // }
        }
    }
};


int ScopeTable::idCount= 0; // Initialize static member variable


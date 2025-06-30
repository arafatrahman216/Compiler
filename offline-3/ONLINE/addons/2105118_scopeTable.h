#pragma once
#include"2105118_symbolInfo.h"
#include <algorithm>




class ScopeTable
{
private:
    int idCount = 0; // static variable to keep track of scope table id count
    int nestedScopeCount = 1;
    string id = "";
    string errorMsg = "";
    int bucketSize ;
    int collissionCount ;
    unsigned int (*hashFunction)(string, unsigned int); // hash function pointer
    symbolInfo** hashtable; // hashtable of symbolInfo
    ScopeTable* parentScope ; // pointer to parent scope, to be used as a stack


public:
    
    ScopeTable(int bucketSize, unsigned int (*hashFunction)( string, unsigned int), int idCount = 1) { 
        hashtable = new symbolInfo*[bucketSize];
        this->bucketSize = bucketSize;
        for (int i = 0; i < bucketSize; i++) {
            hashtable[i] = NULL;
        }
        collissionCount = 0;
        parentScope = nullptr;
        this->hashFunction = hashFunction ;
        // fout<< "\tScopeTable# " << sid << " created" << endl;
    }
    

    ScopeTable( ScopeTable* parent){
        this->parentScope = parent;
        this->bucketSize = parent->bucketSize;
        this->hashFunction = parent->hashFunction;
        hashtable = new symbolInfo*[bucketSize];
        collissionCount = 0;
        for (int i = 0; i < bucketSize; i++) {
            hashtable[i] = NULL;
        }
        // scopeCount = 0;
        // fout<< "\tScopeTable# " << id << " created" << endl;
        // fout<< "\tScopeTable# " << sid << " created" << endl;
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

    string getId() {
        return id;
    }

    string generateChildId(){
        return id + "." + to_string(nestedScopeCount++);
    }

    int getBucketSize() {
        return bucketSize;
    }

    
    symbolInfo * getLookUp ( string name, int &position){
        name = ScopeTable::trim(name);
        int pos = 0;
        unsigned int index = getHash(name);
        symbolInfo * hashPointer = hashtable[index];
        while ( hashPointer!= nullptr){
            if (hashPointer->getName() == name){
                // cout<<"found "<<name<<" at position "<<index<<", "<<pos<<endl;
                position = pos;
                return hashPointer;
            }
            hashPointer = hashPointer->getNextSymbol();
            position++;
            pos++;
            // cout<<pos<<endl;
        }
        return nullptr;
    }

    unsigned int getHash(string str){
        str = ScopeTable::trim(str);
        return hashFunction(str, bucketSize);
    }

    bool InsertSymbol(symbolInfo *sInfo) {
        // if name or type is empty or contains only spaces 
        if (sInfo->getName().empty() || sInfo->getType().empty() || sInfo->getName() == " " || sInfo->getType() == " ") {
            // fout << "\tError: Missing name or type in input."<<endl;
            errorMsg = "Missing name or type in input.";
            return false;
        } 
        sInfo->setName(ScopeTable::trim(sInfo->getName()));
        unsigned int index = getHash(sInfo->getName());    
        int position = 0;
        int i = 0;
        symbolInfo* found = getLookUp(sInfo->getName(), position);

        //  fout << found << endl;
        if (found == nullptr){
            symbolInfo* temp = hashtable[index];
            if (hashtable[index] == nullptr) { 
                hashtable[index] = sInfo;
                //  fout << " test 5 " << endl;
                //  fout <<"\tInserted in ScopeTable# " << sid << " at position " << index<< ", "<<position<<endl;
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
            //  fout<< "\tInserted in ScopeTable# " << sid << " at position " << index << ", " << position <<endl;
            return true;
        }       
        else {
            // fout<< "< " << sInfo->getName() << " : " << sInfo->getType() << " >"<< " already exists in ScopeTable# " << id << " at position " << index << ", " << position <<endl<< endl    ;
            // fout<< "< " << sInfo->getName() << " : " << sInfo->getType() << " >"<< " already exists in ScopeTable#" << sid << " at position " << i+1 << ", " << position << endl    ;
            errorMsg = "\'" + sInfo->getName() + "\' already exists in the current ScopeTable";
            delete sInfo;
            return false;
        }
    }

    

    symbolInfo * LookUp(string name) {
        int position = 1;
        name = ScopeTable::trim(name);
        unsigned int index = getHash(name) ;
        symbolInfo* hashPointer = getLookUp(name, position);
        if (hashPointer != nullptr) {
            // fout << "\t\'" << name << "\' found in ScopeTable# " << id << " at position " << index << ", " << position << endl;
            // fout << "\t\'" << name << "\' found in ScopeTable# " << sid << " at position " << index << ", " << position << endl;
            return hashPointer;
        } else {
            return nullptr;
        }
    }

    bool DeleteSymbol(string name) {
        int i=1;
        if (name.empty()) {
            // fout<<"\tNumber of parameters mismatch for the command D"<<endl;
            errorMsg = "Number of parameters mismatch for the command D";
            return false;
        }
        name = ScopeTable::trim(name);
        unsigned int index = getHash(name);
        if (getLookUp(name, i) == nullptr) {
            //  fout << "\tNot found in the current ScopeTable"<<endl;
            errorMsg = "\'" + name + "\' not found in the current ScopeTable";
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
                //  fout << "\tDeleted \'" << name << "\' from ScopeTable# " << id << " at position " << index+1 << ", " << position << endl;
                //  fout << "\tDeleted \'" << name << "\' from ScopeTable# " << sid << " at position " << index+1 << ", " << position << endl;
                return true;
            }
            prev = curr;
            curr = curr->getNextSymbol();
            position++;
        }
        return false;
    }

    unsigned int (*getHashFunction())(string, unsigned int) {
        return hashFunction;
    }

    void PrintScopeTable(string tabs, ofstream &fout ) {
        // fout << "ScopeTable # " << sid << endl;
        fout << "ScopeTable # " << id << endl;
        // fout<<tabs << "ScopeTable# " << sid << endl;
        // cout<<tabs << "ScopeTable# " << sid << endl;
        for (int i = 0; i < bucketSize; i++) {
            if (hashtable[i] != nullptr) {
                fout << i << " --> ";
                // fout<<tabs << i << " --> ";
                // cout<< tabs << i+1 << "--> ";
                symbolInfo* temp = hashtable[i];
                while (temp != nullptr) {
                    temp->PrintSymbolInfo(fout);
                    temp = temp->getNextSymbol();
                }
                fout << endl;
                // cout << endl;
            }
        }
    }

    string getErrorMsg(){
        return errorMsg;
    }

    void setId(string id){
        this->id = id;
    }


    int getCollissionCount() {
        return collissionCount;
    }
    
    void setIdCount(int id) {
        idCount = id;
    }

    static string trim (string str) {
    //  fout<<"trimming "<<str<<endl;
    if (str.empty()) return str;
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    if (start == string::npos || end == string::npos) return "";
    str = str.substr(start, end - start + 1);
    //  fout<<"start "<<str <<endl;
    return str;
}

};




#include"symbolInfo.h"

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
    
    ScopeTable(int bucketSize, unsigned long (*hashFunction)( string))  {
        hashtable = new symbolInfo*[bucketSize];
        this->bucketSize = bucketSize;
        // cout<<" test 1 "<<endl;
        for (int i = 0; i < bucketSize; i++) {
            hashtable[i] = NULL;
        }
        // cout<<" test 2 "<<endl;
        // scopeCount = 0;
        sid = ++idCount;
        parentScope = nullptr;
        this->hashFunction = hashFunction ;
    }

    ~ScopeTable() {
        for (int i = 0; i < bucketSize; i++) {
            if (hashtable[i] != NULL) {
                symbolInfo* temp = hashtable[i];
                // cout << " test * " << bucketSize<< endl;
                while (temp != NULL) {
                    symbolInfo* toDelete = temp;
                    temp = temp->getNextSymbol();
                    // cout << " test 3 " << endl;
                    delete toDelete; // Deleting the current node
                    // cout << " test 4 " << endl;
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

    bool InsertSymbol(symbolInfo *sInfo) {
        unsigned long index = getHash(sInfo->getName());    
        int position = 1;
        int i = 1;
        if (hashtable[index] == nullptr) { 
            hashtable[index] = sInfo;
            cout << sInfo->getName() << " Inserted in ScopeTable# " << sid << " at position " << index+1<< ", "<<position;
            // scopeCount++;
            return true;
        } else if (getLookUp(sInfo->getName(),i ) == nullptr) {
            symbolInfo* temp = hashtable[index];
            while (temp->getNextSymbol() != nullptr) {
                temp = temp->getNextSymbol();
                // cout << " test 5 " << endl;
                position++;
            }
            temp->setNextSymbol(sInfo);
            // scopeCount++;
            //inserted in ScopeTable# 5 at position 7, 3
            cout<< sInfo->getName() << " Inserted in ScopeTable# " << sid << " at position " << index+1 << ", " << position ;
            return true;
        } else {
            cout << "Error: Symbol already exists in the current ScopeTable." << endl;
            return false;
        }
    }

    unsigned long getHash(string str){
        return hashFunction(str) % bucketSize;
    }
    
    symbolInfo * getLookUp ( string name, int &position){
        unsigned long index = getHash(name);
        symbolInfo * hashPointer = hashtable[index];
        while ( hashPointer!= nullptr){
            if (hashPointer->getName() == name){
                // cout << "\'" << name << "\' found in ScopeTable# " << sid << " at position " << index << ", " << position << endl;
                return hashPointer;
            }
            hashPointer = hashPointer->getNextSymbol();
            position++;
        }
        // cout<<"\'"<<name<<"\' not found in any of the ScopeTables";
        return nullptr;
    }

    symbolInfo * LookUp(string name) {
        int position = 1;
        unsigned long index = getHash(name)+1 ;
        symbolInfo* hashPointer = getLookUp(name, position);
        if (hashPointer != nullptr) {
            cout << "\'" << name << "\' found in ScopeTable# " << sid << " at position " << index << ", " << position << endl;
            return hashPointer;
        } else {
            cout << "\'" << name << "\' not found in any of the ScopeTables" << endl;
            return nullptr;
            
        }
    }





};

int ScopeTable::idCount= 0; // Initialize static member variable
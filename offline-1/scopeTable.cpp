#include"symbolInfo.h"

class ScopeTable
{
private:
    int sid;
    int bucketSize ;
    int scopeCount ;
    unsigned long (*hashFunction)(const string&); // function pointer
    symbolInfo** hashtable; // hashtable of symbolInfo
    ScopeTable* parentScope ; // pointer to parent scope, to be used as a stack
public:
    ScopeTable(int bucketSize, int sid, unsigned long (*hashFunction)(const string&)) : bucketSize(bucketSize), sid(sid), hashFunction(hashFunction) {
        hashtable = new symbolInfo*[bucketSize];
        for (int i = 0; i < bucketSize; i++) {
            hashtable[i] = nullptr;
        }
        scopeCount = 0;
        parentScope = nullptr;
    }

    ~ScopeTable() {
        for (int i = 0; i < bucketSize; i++) {
            delete hashtable[i];
        }
        delete[] hashtable;
    }

    void setParentScope(ScopeTable* parent) {
        parentScope = parent;
        if (parent != nullptr) parent->scopeCount++;
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

    int getScopeCount() {
        return scopeCount;
    }

    bool InsertSymbol(symbolInfo * sInfo) {
        unsigned long index = hashFunction(sInfo->getName());
        if (hashtable[index] == nullptr) {
            hashtable[index] = sInfo;
            scopeCount++;
            return true;
        } else {
            symbolInfo* current = hashtable[index];
            while (current->getNextSymbol() != nullptr) {
                current = current->getNextSymbol();
            }
            current->setNextSymbol(sInfo);
            scopeCount++;
            return true;
        }
    }

};
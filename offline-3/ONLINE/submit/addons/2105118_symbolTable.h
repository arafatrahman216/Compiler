#pragma once

#include"2105118_scopeTable.h"
#include <cstdio>

class SymbolTable{
    private :
        ScopeTable *scopeTable ;
        int parentIdCount = 0; // to keep track of parent scope id count
        int collisionCount ;
        int scopeCount ;
    public :
        SymbolTable(int bucketSize=7, unsigned int(*hashFunction)( string, unsigned int)=NULL) {
            // ScopeTable::initializeIDCount();
            collisionCount = 0;
            scopeCount = 0;
            if (hashFunction == NULL) {
                hashFunction = SymbolTable::sdbm; // default hash function
            }
            cout<< " SymbolTable initialized with bucket size: " << bucketSize << endl;
            scopeTable = new ScopeTable(bucketSize, hashFunction);
            parentIdCount = 1;
            scopeTable->setId(to_string(parentIdCount));
        }

        string getErrorMsg(){
            return scopeTable->getErrorMsg();
        }

        void EnterScope(){
            scopeCount++;
            ScopeTable *newScope = new ScopeTable(scopeTable->getBucketSize(), scopeTable->getHashFunction());
            newScope->setId(scopeTable->generateChildId());
            newScope->setParentScope(scopeTable);
            
            scopeTable = newScope;
        }

        void ExitScope(bool removeScopeStack = false){
            if ( !removeScopeStack && scopeTable->getParentScope() == nullptr) {
                // fout << "\tNo more scopes to exit" << endl;
                return;
            }
            ScopeTable *temp = scopeTable;
            scopeTable = scopeTable->getParentScope();
            // fout<< "\tScopeTable# " << temp->getId() << " removed" << endl;
            collisionCount += temp->getCollissionCount();
            // cout<< "\tScopeTable# " << temp->getId() << " removed with " << temp->getCollissionCount() << " collisions" << endl;
            delete temp;
        }

        bool Insert(string name, string type, bool isArray, int isFunction, vector<string> params, ofstream &fout) {
            symbolInfo *sInfo = new symbolInfo(name, type, isArray, isFunction, params, nullptr);
            return scopeTable->InsertSymbol(sInfo);
        }

        bool Insert(symbolInfo *sInfo){
            return scopeTable->InsertSymbol(sInfo);
        }

        symbolInfo* LookUp(string name){
            if (name.empty()) {
                // fout << "\tNumber of parameters mismatch for the command L" << endl;
                return nullptr;
            }
            ScopeTable *currentScope = scopeTable;
            while (currentScope != nullptr) {
                symbolInfo *sInfo = currentScope->LookUp(name);
                if (sInfo != nullptr) {
                    return sInfo;
                }
                currentScope = currentScope->getParentScope();
            }
            // fout << "\t\'"<<name<<"\' not found in any of the ScopeTables" << endl;
            return nullptr;
        }

        bool Remove(string name){
            return scopeTable->DeleteSymbol(name);
        }

        void PrintCurrentScopeTable(ofstream &fout) {
            scopeTable->PrintScopeTable("\t",fout);
        }

        void PrintAllScopeTable(ofstream &fout ){
            ScopeTable *temp = scopeTable;
            string tabs = "\t";

            while (temp != nullptr) {
                temp->PrintScopeTable(tabs, fout);
                temp = temp->getParentScope();
                tabs += "\t";
            }
            fout << endl;
        }

        ~SymbolTable(){
            while (scopeTable->getParentScope() != nullptr) {
                ExitScope();
            }
            ExitScope(true);
            
            // cout<< "Total Collisions: " << collisionCount << endl;
        }

        int getCollisionCount() {
            ScopeTable *temp = scopeTable;
            int a= collisionCount;
            while (temp != nullptr) {
                a += temp->getCollissionCount();
                temp = temp->getParentScope();
            }
            // cout<< "Total Collisions: " << a << endl;
            return a;
        }

        int getScopeCount() {
            return scopeCount+1;
        }

        static unsigned int sdbm(string str1, unsigned int num_buckets) {
            char *p = (char *) str1.c_str();
            unsigned int hash = 0;
            auto *str = (unsigned char *) p;
            int c{};
            while ((c = *str++)) {
                hash = c + (hash << 6) + (hash << 16) - hash;
            }
            return hash%num_buckets;
        }
        
};
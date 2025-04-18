#include"scopeTable.cpp"

class SymbolTable{
    private :
        ScopeTable *scopeTable ;
    public :
        SymbolTable(int bucketSize, unsigned long (*hashFunction)( string)){
            scopeTable = new ScopeTable(bucketSize, hashFunction);
            
        }

        void EnterScope(){
            ScopeTable *newScope = new ScopeTable(scopeTable->getBucketSize(), scopeTable->getHashFunction());
            newScope->setParentScope(scopeTable);
            scopeTable = newScope;
        }

        void ExitScope(){
            ScopeTable *temp = scopeTable;
            scopeTable = scopeTable->getParentScope();
            delete temp;
        }

        bool Insert(string name, string type){
            symbolInfo *sInfo = new symbolInfo(name, type, nullptr);
            return scopeTable->InsertSymbol(sInfo);
        }

        symbolInfo* LookUp(string name){
            return scopeTable->LookUp(name);
        }

        bool Remove(string name){
            return scopeTable->DeleteSymbol(name);
        }

        void PrintCurrentScopeTable(){
            
        }
        
};
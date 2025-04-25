#include"2105118_scopeTable.cpp"

class SymbolTable{
    private :
        ScopeTable *scopeTable ;
        int collisionCount ;
        int scopeCount ;
    public :
        SymbolTable(int bucketSize, unsigned int(*hashFunction)( string, unsigned int)){
            ScopeTable::initializeIDCount();
            collisionCount = 0;
            scopeCount = 0;
            scopeTable = new ScopeTable(bucketSize, hashFunction);
        }

        void EnterScope(){
            scopeCount++;
            ScopeTable::setIdCount(scopeCount);
            ScopeTable *newScope = new ScopeTable(scopeTable->getBucketSize(), scopeTable->getHashFunction());
            newScope->setParentScope(scopeTable);
            scopeTable = newScope;
        }

        void ExitScope(bool removeScopeStack = false){
            if ( !removeScopeStack && scopeTable->getParentScope() == nullptr) {
                fout << "\tNo more scopes to exit" << endl;
                return;
            }
            ScopeTable *temp = scopeTable;
            scopeTable = scopeTable->getParentScope();
            fout<< "\tScopeTable# " << temp->getId() << " removed" << endl;
            collisionCount += temp->getCollissionCount();
            // cout<< "\tScopeTable# " << temp->getId() << " removed with " << temp->getCollissionCount() << " collisions" << endl;
            delete temp;
        }

        bool Insert(string name, string type){
            symbolInfo *sInfo = new symbolInfo(name, type, nullptr);
            return scopeTable->InsertSymbol(sInfo);
        }

        bool Insert(symbolInfo *sInfo){
            return scopeTable->InsertSymbol(sInfo);
        }

        symbolInfo* LookUp(string name){
            if (name.empty()) {
                fout << "\tNumber of parameters mismatch for the command L" << endl;
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
            fout << "\t\'"<<name<<"\' not found in any of the ScopeTables" << endl;
            return nullptr;
        }

        bool Remove(string name){
            return scopeTable->DeleteSymbol(name);
        }

        void PrintCurrentScopeTable(){
            scopeTable->PrintScopeTable();
            
        }

        void PrintAllScopeTable(){
            ScopeTable *temp = scopeTable;
            string tabs = "\t";
            while (temp != nullptr) {
                temp->PrintScopeTable(tabs);
                temp = temp->getParentScope();
                tabs += "\t";
            }
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
        
};
#include"scopeTable.cpp"

class SymbolTable{
    private :
        ScopeTable *scopeTable ;
        int collisionCount ;
        int scopeCount ;
    public :
        SymbolTable(int bucketSize, unsigned long (*hashFunction)( string)){
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

        void ExitScope(){
            ScopeTable *temp = scopeTable;
            scopeTable = scopeTable->getParentScope();
            fout<< "\tScopeTable# " << temp->getId() << " removed" << endl;
            collisionCount += temp->getCollissionCount();
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
            while (scopeTable != nullptr) {
                ExitScope();
            }
            // cout<< "Total Collisions: " << collisionCount << endl;
        }

        int getCollisionCount() {
            ScopeTable *temp = scopeTable;
            while (temp != nullptr) {
                collisionCount += temp->getCollissionCount();
                temp = temp->getParentScope();
            }
            return collisionCount;
        }
        
};
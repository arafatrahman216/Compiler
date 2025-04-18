#include"scopeTable.cpp"

class SymbolTable{
    private :
        ScopeTable *scopeTable ;
    public :
        SymbolTable(int bucketSize, unsigned long (*hashFunction)( string)){
            scopeTable = new ScopeTable(bucketSize, hashFunction);
            
        }

        
};
#include"symbolInfo.h"

class ScopeTable
{
private:
    int sid;
    int bucketSize ;
    int scopeCount ;
    unsigned long (*hashFunction)(const std::string&); // function pointer
    symbolInfo** table; // linked list of symbolInfo
    ScopeTable* parentScope ; // pointer to parent scope, to be used as a stack
public:



};
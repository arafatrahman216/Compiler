#include"scopeTable.cpp"
using namespace std;

int main() {
    symbolInfo s1("x", "int");
    symbolInfo s2("y", "float", &s1);
    
    cout << s1 << endl; // Output: Name: x, Type: int
    cout << s2 << endl; // Output: Name: y, Type: float


    cout << "Next Symbol of s2: " << *(s2.getNextSymbol()) << endl; // Output: Name: x, Type: int

    s2.setName("z");
    s2.setType("double");
    cout << "After modification, s2: " << s2 << endl; // Output: Name: z, Type: double
    cout << "Next Symbol of s2 after modification: " << *(s2.getNextSymbol()) << endl; // Output: Name: x, Type: int

    ScopeTable scopeTable(10, 1, [](const string& name) {
        unsigned long hash = 5381;
        for (char c : name) {
            hash = ((hash << 5) + hash) + c; // hash * 33 + c
        }
        return hash % 10; // Assuming bucket size is 10
    });
    scopeTable.setParentScope(nullptr);
    cout << "ScopeTable ID: " << scopeTable.getId() << endl; // Output: ScopeTable ID: 1
    cout << "ScopeTable Bucket Size: " << scopeTable.getBucketSize() << endl; // Output: ScopeTable Bucket Size: 10
    cout << "ScopeTable Scope Count: " << scopeTable.getScopeCount() << endl; // Output: ScopeTable Scope Count: 0
    cout << "Parent Scope: " << scopeTable.getParentScope() << endl; // Output: Parent Scope: 0x0 (or nullptr)
    
    ScopeTable parentScope(5, 0, [](const string& name) {
        unsigned long hash = 5381;
        for (char c : name) {
            hash = ((hash << 5) + hash) + c; // hash * 33 + c
        }
        return hash % 5; // Assuming bucket size is 5
    });
    parentScope.setParentScope(nullptr);
    scopeTable.setParentScope(&parentScope);
    cout << "Parent Scope ID: " << scopeTable.getParentScope()->getId() << endl; // Output: Parent Scope ID: 0  
    cout << "Parent Scope Bucket Size: " << scopeTable.getParentScope()->getBucketSize() << endl; // Output: Parent Scope Bucket Size: 5
    cout << "Parent Scope Scope Count: " << scopeTable.getParentScope()->getScopeCount() << endl; // Output: Parent Scope Scope Count: 0
    cout << "Parent Scope Parent Scope: " << scopeTable.getParentScope()->getParentScope() << endl; // Output: Parent Scope Parent Scope: 0x0 (or nullptr)
    cout << "Parent Scope ID: " << scopeTable.getParentScope()->getId() << endl; // Output: Parent Scope ID: 0

    return 0;
}
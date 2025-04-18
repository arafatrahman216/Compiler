#include"scopeTable.cpp"
using namespace std;

unsigned long sdbm(string str) {
    unsigned long hash = 0;
    for (char c : str) {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}


// int main() {
//     symbolInfo s1("x", "int");
//     symbolInfo s2("y", "float", &s1);
//     string a, b;
//     cin>>a>>b;
    
//     cout << s1 << endl; // Output: Name: x, Type: int
//     cout << s2 << endl; // Output: Name: y, Type: float


//     cout << "Next Symbol of s2: " << *(s2.getNextSymbol()) << endl; // Output: Name: x, Type: int

//     s2.setName("z");
//     s2.setType("double");
//     cout << "After modification, s2: " << s2 << endl; // Output: Name: z, Type: double
//     cout << "Next Symbol of s2 after modification: " << *(s2.getNextSymbol()) << endl; // Output: Name: x, Type: int

//     unsigned long (*hashFunction) (string) ;
//     hashFunction = sdbm;
//     ScopeTable scopeTable(10, hashFunction);
//     scopeTable.setParentScope(nullptr);
//     cout << "ScopeTable ID: " << scopeTable.getId() << endl; // Output: ScopeTable ID: 1
//     cout << "ScopeTable Bucket Size: " << scopeTable.getBucketSize() << endl; // Output: ScopeTable Bucket Size: 10
//     cout << "ScopeTable Scope id: " << scopeTable.getId() << endl; // Output: ScopeTable Scope Count: 0
//     cout << "Parent Scope: " << scopeTable.getParentScope() << endl; // Output: Parent Scope: 0x0 (or nullptr)
    
//     ScopeTable parentScope(7, hashFunction);
//     parentScope.setParentScope(nullptr);
//     scopeTable.setParentScope(&parentScope);
//     cout << "Parent Scope ID: " << scopeTable.getParentScope()->getId() << endl; // Output: Parent Scope ID: 0  
//     cout << "Parent Scope Bucket Size: " << scopeTable.getParentScope()->getBucketSize() << endl; // Output: Parent Scope Bucket Size: 5
//     cout << "Parent Scope id: " << scopeTable.getParentScope()->getId() << endl; // Output: Parent Scope Scope Count: 0
//     cout << "Parent Scope Parent Scope: " << scopeTable.getParentScope()->getParentScope() << endl; // Output: Parent Scope Parent Scope: 0x0 (or nullptr)
    
//     cout << "my hash: " << scopeTable.getHash(a) << endl; // Output: Parent Scope ID: 0
//     cout << "Parent hash: " << scopeTable.getParentScope()->getHash(b) << endl; // Output: Parent Scope ID: 0

//     ScopeTable scopeTable2(5, hashFunction);
//     scopeTable2.setParentScope(&scopeTable);
    

//     return 0;
// }

int main() {
    string a;
    cin>>a;
    cout<<sdbm(a)%7 +1<<endl;
    return 0;
}
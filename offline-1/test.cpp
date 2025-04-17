#include"symbolInfo.h"
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

    return 0;
}
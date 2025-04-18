#include"scopeTable.cpp"
#include<fstream>
#include <sstream>

unsigned long sdbm(string str) {
    unsigned long hash = 0;
    for (char c : str) {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}


int main(){
    string filename = "sample_input.txt";
    ifstream fin(filename);
    int bucket;
    fin>>bucket;
    cout<<bucket<<endl;
    string cmd ;
    fin>>cmd;
    string line;
    ScopeTable sct (bucket, sdbm);
    while (cmd!="Q"){
        if (cmd=="I"){
            getline(fin, line); 
            stringstream ss(line);
            string name, type, extra;
            ss >> name >> type ;
            getline(ss, extra);
            
            if (name.empty() || type.empty()) {
                cout << "Error: Missing name or type in input.";
            } else {
                symbolInfo *sInfo = new symbolInfo(name, type, nullptr, extra);
                sct.InsertSymbol(sInfo);
                // cout << "Inserted " << name << " " << type << " ,extra is " << extra <<"  ";;
            }
            // if ((ss >> extra)) {
            //     cout << "still left !!";
            // }
            cout<<endl;
            
        }
        else if (cmd=="D"){
            string name ;
            getline(fin, name);
            if (name.empty()) {
                cout<<"Error delete"<<endl;
            }
            else cout<<" single Deleted "<<name<<endl;
            
        }
        else if (cmd=="L"){
            getline(fin, line);
            stringstream ss(line);
            string name, ext;
            ss >> name;
            if (name.empty()) {
                cout << "Error: Missing name in input." << endl;
            } 
            else if ((ss >> ext)) {
                cout << "Error: Invalid input format." << endl;
            }
            else {
                cout << "Found " << name << endl;
            }
        }
        else if (cmd=="P"){
            string cmd2,ext ;
            getline(fin, line);
            stringstream ss(line);
            ss >> cmd2;
            // getline(ss, ext);
            if (cmd2.empty()) {
                cout << "Error: Missing name in input." << endl;
            } 
            else if ( ! ext.empty()) {
                cout << "Error: Invalid input format in P" << endl;
            }
            else {
                cout << "Printing ScopeTable with " << cmd2 << endl;
            }
            
        }
        else if (cmd=="S"){
            cout<<"New ScopeTable created"<<endl;
        }
        else if (cmd=="E"){
            cout<<"Exiting from current ScopeTable"<<endl;
        }
        fin>>cmd;

    }

}
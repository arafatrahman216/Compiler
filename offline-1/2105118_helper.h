#include <iostream>
#include <string>
#include <sstream>
#include<fstream>
#include "symbolTable.cpp"


// source : offline spec
unsigned long sdbm(string str) {
    unsigned long hash = 0;
    for (char c : str) {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}


// source : https://stackoverflow.com/questions/7666509/how-to-hash-a-string-in-c
unsigned long djb2(string str) {
    unsigned long hash = 5381;
    for (char c : str) {
        hash = ((hash << 5) + hash) + c; 
    }
    return hash;
}

// source : https://stackoverflow.com/questions/7666509/how-to-hash-a-string-in-c(same as above)
unsigned long jenkins(string str) {
    unsigned long hash = 0;
    for (char c : str) {
        hash += c;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

void CommandHandler( string cmd, SymbolTable &st, string line, int &cmdcount, fstream &fout, ifstream &fin) {
    if (cmd=="I"){
        getline(fin, line); 
        fout<<"Cmd "<<cmdcount<<": "<<cmd << line<<endl;
        stringstream ss(line);
        string name, type, extra;
        ss >> name ;
        getline(ss, type);
        symbolInfo *sInfo = new symbolInfo(name, type, nullptr);
        st.Insert(sInfo);
    }
    else if (cmd=="D"){
        string name ;
        getline(fin, line);
         fout<<"Cmd "<<cmdcount<<": "<<cmd << line<<endl;
        stringstream ss(line);
        ss >> name;
        st.Remove(name);

        
    }
    else if (cmd=="L"){
        getline(fin, line);
        fout<<"Cmd "<<cmdcount<<": "<<cmd << line<<endl;
        // cout<<"Cmd "<<cmdcount<<": "<<cmd << line<<endl;
        stringstream ss(line);
        string name, ext;
        ss >> name;
        if ((ss >> ext))  {
             fout << "\tNumber of parameters mismatch for the command L" << endl;
        } 
        else {
            symbolInfo* found = st.LookUp(name);
        }
    }
    else if (cmd=="P"){
        string cmd2,ext ;
        getline(fin, line);
         fout<<"Cmd "<<cmdcount<<": "<<cmd << line<<endl;
        stringstream ss(line);
        ss >> cmd2;
        // getline(ss, ext);
        if (cmd2.empty()) {
             fout << "\tNumber of parameters mismatch for the command P" << endl;
        } 
        else if ( ! ext.empty()) {
             fout << "\tNumber of parameters mismatch for the command P" << endl;
        }
        else {
             if (cmd2 == "C") {
                 st.PrintCurrentScopeTable();
             } else if (cmd2 == "A") {
                 st.PrintAllScopeTable();
             } else {
                 fout << "\tInvalid command for P" << endl;
             }
        }
        
    }
    else if (cmd=="S"){
         fout<<"Cmd "<<cmdcount<<": "<<cmd <<endl;
         st.EnterScope();
    }
    else if (cmd=="E"){
         fout<<"Cmd "<<cmdcount<<": "<<cmd <<endl;
         st.ExitScope();
    } 
    else {
         fout << "\tInvalid command" << endl;
    }
}


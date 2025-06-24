#include <iostream>
#include <string>
#include <sstream>
#include<fstream>
#include<cmath>
#include "2105118_symbolTable.cpp"


// source : offline spec
unsigned int sdbm(string str1, unsigned int num_buckets) {
    char *p = (char *) str1.c_str();
    unsigned int hash = 0;
    auto *str = (unsigned char *) p;
    int c{};
    while ((c = *str++)) {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash%num_buckets;
}


// source : https://stackoverflow.com/questions/7666509/how-to-hash-a-string-in-c
unsigned int djb2(string str ,  unsigned int num_buckets ) {
    unsigned int hash = 5381;
    for (char c : str) {
        hash = (((hash << 5) + hash) + c) % num_buckets;
    }
    return hash;
}

// source : https://stackoverflow.com/questions/7666509/how-to-hash-a-string-in-c(same as above)
unsigned int jenkins(string str,  unsigned int num_buckets  ) {
    unsigned int hash = 0;
    for (char c : str) {
        hash += c;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    hash %= num_buckets;
    return hash; 
}

void CommandHandler( string cmd, SymbolTable &st, string line, int &cmdcount, fstream &fout, ifstream &fin) {
    if (cmd=="I"){
        getline(fin, line); 
        fout<<"Cmd "<<cmdcount<<": "<<cmd <<" " << trim(line)<<endl;
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
        string line;
        getline(fin, line);
         fout << "Cmd "<<cmdcount<<": "<<cmd << line << endl;
         fout << "\tInvalid command" << endl;
    }
}


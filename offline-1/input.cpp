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
    // fout<<bucket<<endl;
    string cmd ;
    fin>>cmd;
    string line;
    int cmdcount = 0;
    ScopeTable sct (bucket, sdbm);
    while (cmd!="Q"){
        cmdcount++;
        if (cmd=="I"){
            getline(fin, line); 
             fout<<"Cmd "<<cmdcount<<": "<<cmd << line<<endl;
            stringstream ss(line);
            string name, type, extra;
            ss >> name ;
            getline(ss, type);
            
            if (name.empty() || type.empty()) {
                 fout << "\tError: Missing name or type in input.";
            } else {
                symbolInfo *sInfo = new symbolInfo(name, type, nullptr);
                sct.InsertSymbol(sInfo);
                //  fout << "Inserted " << name << " " << type << " ,extra is " << extra <<"  ";;
            }
        }
        else if (cmd=="D"){
            string name ;
            getline(fin, line);
             fout<<"Cmd "<<cmdcount<<": "<<cmd << line<<endl;
            stringstream ss(line);
            ss >> name;
            //  fout<<name<<endl;
            //  fout<<line<<endl;
            if (name.empty()) {
                 fout<<"\tNumber of parameters mismatch for the command D"<<endl;
            }
            else sct.DeleteSymbol(name);

            
        }
        else if (cmd=="L"){
            getline(fin, line);
             fout<<"Cmd "<<cmdcount<<": "<<cmd << line<<endl;
            stringstream ss(line);
            string name, ext;
            ss >> name;
            if (name.empty() || (ss >> ext))  {
                 fout << "\tNumber of parameters mismatch for the command L" << endl;
            } 
            else {
                symbolInfo* found = sct.LookUp(name);
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
                 fout << "\tNumber of parameters mismatch for the command L" << endl;
            }
            else {
                 fout << "\tPrinting ScopeTable with " << cmd2 << endl;
            }
            
        }
        else if (cmd=="S"){
             fout<<"Cmd "<<cmdcount<<": "<<cmd <<endl;
             fout<<"\tScopeTable# created"<<endl;
        }
        else if (cmd=="E"){
             fout<<"Cmd "<<cmdcount<<": "<<cmd <<endl;
             fout<<"\tExiting from current ScopeTable"<<endl;
        }
        fin>>cmd;

    }
     fout<<"Cmd "<<++cmdcount<<": Q"<<endl;
    

}
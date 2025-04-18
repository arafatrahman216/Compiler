#include"2105118_helper.h"
#include<fstream>
#include <sstream>
#include <cmath>

fstream report;

int main(int argc, char *argv[]) {

    unsigned long (*hashFunction) (string) ;
    string infile = "sample_input.txt";
    string outfile = "2105118_report.txt";
    if (argc != 2){
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }
    infile = argv[1];
    cout << "Input file: " << infile << endl;
    cout << "Output file: " << outfile << endl;
    ifstream fin(infile);
    report.open(outfile, ios::out);
    if (!report ||!fin) {
        cout << "Error opening input or output file." << endl;
        return 1;
    }
    int bucket;
    fin>>bucket;
    string cmd ;
    fin>>cmd;
    string line;
    int cmdcount = 0;
    SymbolTable st (bucket, sdbm);
    SymbolTable st2 (bucket, djb2);
    SymbolTable st3 (bucket, jenkins);
    SymbolTable starray[3] = {st, st2, st3};
    // st, cmd,line,cmdcount, fin,fout
    while (cmd != "Q") {
        if (cmd == "I") {
            getline(fin, line);
            report << "Cmd " << cmdcount << ": " << cmd << line << endl;
            stringstream ss(line);
            string name, type, extra;
            ss >> name;
            getline(ss, type);
            symbolInfo *sInfo = new symbolInfo(name, type, nullptr);
            for (int i = 0; i < 3; i++) {
                starray[i].Insert(sInfo);
            }
        } else if (cmd == "D") {
            string name;
            getline(fin, line);
            report << "Cmd " << cmdcount << ": " << cmd << line << endl;
            stringstream ss(line);
            ss >> name;
            for (int i = 0; i < 3; i++) {
                starray[i].Remove(name);
            }
        } else if (cmd == "L") {
            string name;
            getline(fin, line);
            report << "Cmd " << cmdcount << ": " << cmd << line << endl;
            stringstream ss(line);
            ss >> name;
            for (int i = 0; i < 3; i++) {
                starray[i].LookUp(name);
            }
        } else if (cmd == "P") {
            report<<endl<<"Cmd "<<cmdcount<<": "<<cmd<<endl;
            for (int i = 0; i < 3; i++) {
                report<<endl<<"ScopeTable# "<<i+1<<endl;
                starray[i].PrintCurrentScopeTable();
                report<<endl;
            }
        } else if (cmd == "E") {
            report<<endl<<"Cmd "<<cmdcount<<": "<<cmd<<endl;
        } else {
            report<<"Invalid command"<<endl;
        }
    }
        
}
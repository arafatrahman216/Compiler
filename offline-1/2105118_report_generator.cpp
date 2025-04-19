#include"2105118_helper.h"
#include<fstream>
#include <sstream>
#include <cmath>

fstream report;
fstream fout;

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
    fout.open("garbage.txt", ios::out);
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
            symbolInfo *sInfo1 = new symbolInfo(name, type, nullptr);
            symbolInfo *sInfo2 = new symbolInfo(name, type, nullptr);
            symbolInfo *sInfo3 = new symbolInfo(name, type, nullptr);
            starray[0].Insert(sInfo1);
            starray[1].Insert(sInfo2);
            starray[2].Insert(sInfo3);
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
            fout << "Cmd " << cmdcount << ": " << cmd << line << endl;
            stringstream ss(line);
            ss >> name;
            symbolInfo *sInfo1 = starray[0].LookUp(name);
            symbolInfo *sInfo2 = starray[1].LookUp(name);
            symbolInfo *sInfo3 = starray[2].LookUp(name);
        } else if (cmd == "P") {
            string cmd2, ext;
            getline(fin, line);
            fout << "Cmd " << cmdcount << ": " << cmd << line << endl;
            stringstream ss(line);

            if (!cmd2.empty()) {
                ss >> cmd2;
            }

        } else if (cmd == "E") {
            report<<endl<<"Cmd "<<cmdcount<<": "<<cmd<<endl;
            for (int i = 0; i < 3; i++) {
                starray[i].ExitScope();   
            }
        }
        else if (cmd == "S") {
            for (int i = 0; i < 3; i++) {
                starray[i].EnterScope();
            }
        }
        else {
            cout<<"Invalid command"<<endl;
        }
        cmdcount++;
        fin>>cmd;

    }
}       

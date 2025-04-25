#include"2105118_helper.h"
#include<fstream>
#include <sstream>
#include <cmath>
#include <iomanip> 

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
    // SymbolTable starray[3] = {st, st2, st3};
    // st, cmd,line,cmdcount, fin,fout
    while (cmd != "Q") {
        if (cmd == "I") {
            getline(fin, line);
            stringstream ss(line);
            string name, type, extra;
            ss >> name;
            getline(ss, type);
            symbolInfo *sInfo1 = new symbolInfo(name, type, nullptr);
            symbolInfo *sInfo2 = new symbolInfo(name, type, nullptr);
            symbolInfo *sInfo3 = new symbolInfo(name, type, nullptr);
            st.Insert(sInfo1);
            st2.Insert(sInfo2);
            st3.Insert(sInfo3);
        } else if (cmd == "D") {
            string name;
            getline(fin, line);
            stringstream ss(line);
            ss >> name;
            st.Remove(name);
            st2.Remove(name);
            st3.Remove(name);
        } else if (cmd == "L") {
            string name;
            getline(fin, line);
            fout << "Cmd " << cmdcount << ": " << cmd << line << endl;
            stringstream ss(line);
            ss >> name;
            symbolInfo *sInfo1 = st.LookUp(name);
            symbolInfo *sInfo2 = st2.LookUp(name);
            symbolInfo *sInfo3 = st3.LookUp(name);
        } else if (cmd == "P") {
            string cmd2, ext;
            getline(fin, line);
            stringstream ss(line);
            ss >> cmd2 >>ext;
            if (cmd2.empty()) {
                fout << "\tNumber of parameters mismatch for the command P" << endl;
            } else if (!ext.empty()) {
                fout << "\tNumber of parameters mismatch for the command P" << endl;
            } else if (cmd2 == "C") {
                st.PrintCurrentScopeTable();
                st2.PrintCurrentScopeTable();
                st3.PrintCurrentScopeTable();
            } else if (cmd2 == "A") {
                st.PrintAllScopeTable();
                st2.PrintAllScopeTable();
                st3.PrintAllScopeTable();
            } else {
                fout << "\tInvalid command" << endl;
            }



        } else if (cmd == "E") {
            st.ExitScope();
            st2.ExitScope();
            st3.ExitScope();
        }
        else if (cmd == "S") {
            st.EnterScope();
            st2.EnterScope();
            st3.EnterScope();

        }
        else {
            cout<<"Invalid command"<<endl;
        }
        cmdcount++;
        fin>>cmd;


    
    }

    float a ,b, c;
    a = (float)st.getCollisionCount()/(bucket* st.getScopeCount()) ;
    b = (float)st2.getCollisionCount()/(bucket* st2.getScopeCount()) ;
    c = (float)st3.getCollisionCount()/(bucket* st3.getScopeCount()) ;


    report <<left <<setw(20)<<  "Hash Function"<< setw(20)<< "Collision Count" << setw(30) <<
    "Collision/(Bucket Size * Scope Count)" << endl;

    report << string(70, '_') << endl;
    report << left << setw(20) << "sdbm" << setw(20) << st.getCollisionCount()
        << setw(30) << fixed << setprecision(6) << a << endl;

    report << left << setw(20) << "djb2"
        
    << setw(20) << st2.getCollisionCount() << setw(30) << fixed << setprecision(6) 
        << b << endl;

    report << left << setw(20) << "jenkins"
        << setw(20) << st3.getCollisionCount()
        << setw(30) << fixed << setprecision(6) << c<< endl;

    int totalColl = st.getCollisionCount() + st2.getCollisionCount() + st3.getCollisionCount();

    report << endl;
    report << "Total Collisions: " << totalColl << endl;
    report << "Bucket Size: " << bucket << endl;

    report.close();
    fout.close();
    fin.close();
    
}       

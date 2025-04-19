#include"2105118_helper.h"
#include<fstream>
#include <sstream>
#include <cmath>

fstream fout;



int main( int argc, char *argv[]) {
    unsigned long long (*hashFunction) (string) ;
    string infile = "sample_input.txt"; 
    string outfile = "output.txt";
    if (argc == 1 ){
        hashFunction = sdbm;
        cout << "Using default sdbm hash function." << endl;
    }
    else if (argc < 4 || argc > 4) {
        cout << "Usage: " << argv[0] << " <hash_code>" << " <input_file> <output_file>" << endl;
        cout<<"\t[0] sdbm";
        cout<<"\t[1] djb2";
        cout<<"\t[2] jenkins"<<endl;
        return 1;
    }
    else if (argc ==4) {
        string hashCode = argv[1];
        if (hashCode == "0") {
            hashFunction = sdbm;
            cout<<"Using sdbm hash function."<<endl;
        } else if (hashCode == "1") {
            hashFunction = djb2;
            cout<<"Using djb2 hash function."<<endl;
        } else if (hashCode == "2") {
            hashFunction = jenkins;
            cout<<"Using jenkins hash function."<<endl;
        } else {
            cout << "Invalid hash code. Please use 0, 1, or 2." << endl;
            return 1;
        }
        infile = argv[2];
        outfile = argv[3];
        cout << "Input file: " << infile << endl;
        cout << "Output file: " << outfile << endl;
        
    }
    ifstream fin(infile);
    fout.open(outfile, ios::out);
    if (!fout ||!fin) {
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
    // st, cmd,line,cmdcount,  
    while (cmd!="Q"){
        cmdcount++;
        CommandHandler(cmd, st, line, cmdcount, fout, fin);
        fin>>cmd;
    }
     fout<<"Cmd "<<++cmdcount<<": Q"<<endl;
    

}


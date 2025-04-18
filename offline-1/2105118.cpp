#include"symbolTable.cpp"
#include<fstream>
#include <sstream>
#include <cmath>

fstream fout;

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


int main( int argc, char *argv[]) {
    unsigned long (*hashFunction) (string) ;
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
    
    while (cmd!="Q"){
        cmdcount++;
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
        fin>>cmd;

    }
     fout<<"Cmd "<<++cmdcount<<": Q"<<endl;
    

}



// void CommandHandler(string cmd, string line, SymbolTable &st, int cmdcount) 
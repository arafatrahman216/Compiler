#include<iostream>
#include <string>
#include <sstream>
using namespace std;



class symbolInfo
{
private:
    string NAME ;
    string TYPE ;
    // string extras ;
    symbolInfo * nextSymbol ;
public:
    symbolInfo(string NAME , string TYPE , symbolInfo* nextSymbol = nullptr){
        this->NAME = NAME ;
        this->TYPE = TYPE ;
        this->nextSymbol = nextSymbol;
        // this->extras = extras ;
    } 

    symbolInfo (const symbolInfo &sInfo){
        this->NAME = sInfo.NAME ;
        this->TYPE = sInfo.TYPE ;
        this->nextSymbol = sInfo.nextSymbol;
        // this->extras = sInfo.extras ;
    }

    void setName(string _Name){
        this->NAME = _Name ;
    }

    void setType(string _Type){
        this->TYPE = _Type ;
    }

    void setNextSymbol(symbolInfo* _NextSymbol){
        this->nextSymbol = _NextSymbol ;
    }

    string getName(){
        return this->NAME ;
    }

    string getType(){
        return this->TYPE ;
    }

    symbolInfo* getNextSymbol(){
        return this->nextSymbol ;
    }

    // void setExtras(string _Extras){
    //     this->extras = _Extras ;
    // }

    // string getExtras()
    // {
    //     return this->extras;
    // }

    friend ostream& operator<<(ostream& out, const symbolInfo& sInfo) {
        out << "Name: " << sInfo.NAME << ", Type: " << sInfo.TYPE;
        return out;
    }

    void PrintSymbolInfo(){
        cout << "<" << NAME << ",";
        stringstream ss(TYPE);
        string type;
        ss >> type;

        if (type == "INT" || type == "FLOAT" || type == "CHAR" || type == "DOUBLE" 
                    ||type == "VAR"  || type == "NUMBER" || type == "RELOP" || type == "BOOL" ) 
        {
            cout << type<<">";
        } 
        else if (type == "FUNCTION" ){
            cout << "FUNCTION," ;
            string returnType, argType;
            ss >> returnType;
            cout << returnType << "<==(" ;
            while (ss >> argType) {
                cout << argType ;
                if (ss.peek() != EOF ) {
                    cout << ",";
                    ss.ignore();
                }

            }
            cout << ")>" ;
        }
        else if (type == "STRUCT" || type == "UNION"){
            cout << "STRUCT,{" ;
            string retType, varName;
            while ( ss >> retType && ss >> varName) {
                cout <<"("<< retType << "," << varName <<")" ;
                if (ss.peek() != EOF ) {
                    cout << ",";
                    ss.ignore();
                }
            }
            cout << "}>" ;
        }
        else 
        {
            cout << "ERROR: Unknown type" ;
        }
    }

    ~symbolInfo()
    {
        
    }
};


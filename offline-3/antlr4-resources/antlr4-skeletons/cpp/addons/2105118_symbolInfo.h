#pragma once

#include<iostream>
#include <string>
#include <sstream>
#include<fstream>
#include<vector>
#include<cstdio>
#define EOF (-1)

using namespace std;

// fstream fout("output.txt", ios::out);
// fstream fout("output.txt", ios::out | ios::trunc);



class symbolInfo
{
private:
    string NAME ;
    string TYPE ;
    bool isArray = false; // to check if the symbol is an array
    int isFunction = 0; // to check if the symbol is a function
    vector<string> params; // to store extra information about the symbol, if needed
    // string extras ;
    symbolInfo * nextSymbol ;
public:
    symbolInfo(string NAME , string TYPE , bool isArray, int isFunction, vector<string> params, symbolInfo* nextSymbol = nullptr){
        this->NAME = NAME ;
        this->TYPE = TYPE ;
        this->isArray = isArray;
        this->isFunction = isFunction;
        this->params = params;
        this->nextSymbol = nextSymbol;
        // this->extras = extras ;
    } 
    

    symbolInfo (const symbolInfo &sInfo){
        this->NAME = sInfo.NAME ;
        this->TYPE = sInfo.TYPE ;
        this->isArray = sInfo.isArray;
        this->isFunction = sInfo.isFunction;
        this->params = sInfo.params;
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

    void setIsFunction(int _isFunction){
        this->isFunction = _isFunction ;
    }

    int getIsFunction(){
        return this->isFunction ;
    }

    void setIsArray(bool _isArray){
        this->isArray = _isArray ;
    }

    bool getIsArray(){
        return this->isArray ;
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

    vector<string> getParams(){
        return this->params ;
    }

    void setParams(vector<string> _params){
        this->params = _params ;
    }

    int getParamCount() {
        return params.size();
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

    void PrintSymbolInfo(ofstream &fout) {
        fout << "< " << NAME << " : ";
        //cout << "<" << NAME << ",";
        stringstream ss(TYPE);
        string type;
        ss >> type;
        type = "ID";

        if (type == "CONST_INT" || type == "CONST_FLOAT" || type == "CONST_CHAR" || type == "ID"
                    ||type == "VAR"  || type == "NUMBER" || type == "RELOP" || type == "BOOL"  || type=="STRING"||
                type == "INT" || type == "FLOAT" || type == "CHAR" || type == "VOID" || type == "BOOL" || type == "STRING")
        {
            fout << type<<" >";
            //cout << type<<"> ";
        } 
        else if (type == "FUNCTION" ){
            fout << "FUNCTION," ;
            //cout << "FUNCTION," ;
            string returnType, argType;
            ss >> returnType;
            fout << returnType << "<==(" ;
            //cout << returnType << "<==(" ;
            while (ss >> argType) {
                fout << argType ;
                //cout << argType ;
                if (ss.peek() != EOF ) {
                    fout << ",";
                    //cout << ",";
                    ss.ignore();
                }

            }
            fout << ")> " ;
            //cout << ")> " ;
        }
        else if (type == "STRUCT" || type == "UNION"){
            fout << type<<",{" ;
            //cout << "STRUCT,{" ;
            string retType, varName;
            while ( ss >> retType && ss >> varName) {
                fout <<"("<< retType << "," << varName <<")" ;
                //cout <<"("<< retType << "," << varName <<")" ;
                if (ss.peek() != EOF ) {
                    fout << ",";
                    ss.ignore();
                }
            }
            fout << "}> " ;
            //cout << "}> " ;
        }
        else 
        {
            fout << "ERROR: Unknown type" ;
            //cout << "ERROR: Unknown type" ;
        }
    }

    ~symbolInfo()
    {
        
    }
};


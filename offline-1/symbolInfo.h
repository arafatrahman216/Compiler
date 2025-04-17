#include<iostream>
#include <string>
using namespace std;



class symbolInfo
{
private:
    string NAME ;
    string TYPE ;
    symbolInfo * nextSymbol ;
public:
    symbolInfo(string NAME , string TYPE , symbolInfo* nextSymbol = nullptr){
        this->NAME = NAME ;
        this->TYPE = TYPE ;
        this->nextSymbol = nextSymbol;
    } 

    symbolInfo (const symbolInfo &sInfo){
        this->NAME = sInfo.NAME ;
        this->TYPE = sInfo.TYPE ;
        this->nextSymbol = sInfo.nextSymbol;
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

    friend ostream& operator<<(ostream& out, const symbolInfo& sInfo) {
        out << "Name: " << sInfo.NAME << ", Type: " << sInfo.TYPE;
        return out;
    }

    ~symbolInfo()
    {
        
    }
};


//
// Created by marco on 27/03/18.
//

#ifndef CODEPARSER_VARIABLE_H
#define CODEPARSER_VARIABLE_H

#include <iostream>
#include <vector>
#include "Token.h"

using namespace std;


class Variable;

static vector<Variable*>* varTable = new vector<Variable*>();

class Variable {
private:
    string type;
    string value;
    string identifier;
    string memorySlot;

public:
    void setType(string type);

    void setValue(string value);

    void setIdentifier(string identifier);

    void setMemorySlot(string memorySlot);

    void addValue(string value);

    void set();

    string getIdentifier();

    string getValue();

    string getType();

    string getMemorySlot();


};

Variable* findVariable(string identifier,vector<Variable*>* varTable);
#endif //CODEPARSER_VARIABLE_H

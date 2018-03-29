//
// Created by marco on 27/03/18.
//

#include "Variable.h"


Variable* findVariable(string identifier,vector<Variable*>* varTable){
    for (Variable* variable : *varTable) {
        if (identifier == variable->getIdentifier()){
            return variable;
        }

    }
    return nullptr;
}

void Variable::setType(string type){
    this->type = type;
}

void Variable::setValue(string value){
    this->value = value;
}

void Variable::setIdentifier(string identifier){
    this->identifier = identifier;
}

void Variable::setMemorySlot(string memorySlot){
    this->memorySlot = memorySlot;
}

void Variable::addValue(string value){
    if (Token::isPrimitive(value) == IDENTIFIER){
        Variable* var = findVariable(value,varTable);;
        if (var == nullptr){
            cerr << "variable doesn't exist"<<endl;
            return;
        }
        value = var->getValue();
    }
    this->value.append(value);

}

void Variable::set(){
    cout << this->type << " | " << this->identifier
         << " | " << this->value <<endl;

}

string Variable::getIdentifier(){
    return this->identifier;
}

string Variable::getValue(){
    return this->value;
}

string Variable::getType() {
    return this->type;
}

string Variable::getMemorySlot() {
    return this->memorySlot;
}
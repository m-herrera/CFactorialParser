//
// Created by marco on 28/03/18.
//

#ifndef CODEPARSER_PARSER_H
#define CODEPARSER_PARSER_H

#include <iostream>
#include <vector>
#include "Token.h"
#include "Variable.h"
#include <boost/tokenizer.hpp>

using namespace std;

void parse(string);
void parseAux(vector<Token*>*);
vector<Token*>* lex(string);


#endif //CODEPARSER_PARSER_H

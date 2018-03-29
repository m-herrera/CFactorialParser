//
// Created by marco on 28/03/18.
//

#include "Parser.h"

void parse(string code){

    vector<Token*>* tokens = lex(code);
    parseAux(tokens);

}

void parseAux(vector<Token*>* tokens){
    Variable* currentVar = nullptr;
    int count = 1;
    for (auto && token:*tokens) {
        if (token->type == DATA_TYPE){
            if (count != 1){
                cerr << "invalid syntax"<<endl;
                return;
            }
            count *= DATA_TYPE;
            currentVar = new Variable();
            currentVar->setType(token->value);

        }else if (token->type == IDENTIFIER){
            if (count == DATA_TYPE){
                currentVar->setIdentifier(token->value);

            }else if (count % ASSIGNMENT == 0) {
                currentVar->addValue(token->value);
            }else{
                currentVar = findVariable(token->value,varTable);
                if (currentVar == nullptr){
                    cerr << "the variable " << token->value << " doesn't exist"<<endl;
                    return;
                }
            }

            count *= IDENTIFIER;
        }else if (token->type == ASSIGNMENT){
            if (count == DATA_TYPE*IDENTIFIER ||
                count == IDENTIFIER){
                count *= ASSIGNMENT;
            }
            else{
                delete(currentVar);
                cerr << "invalid syntax"<<endl;
                return;
            }
        }else if (token->type == LITERAL){
            if (count % (DATA_TYPE*IDENTIFIER*ASSIGNMENT) == 0 ||
                count % (IDENTIFIER*ASSIGNMENT) == 0){
                currentVar->addValue(token->value);
            }

        }else if (token->type == LINE_SEPARATOR){
            currentVar->set();
            varTable->push_back(currentVar);
            currentVar = nullptr;
            count = 1;

        }else if (token->type == OPERATOR){
            if(currentVar != nullptr){
                currentVar->addValue(token->value);
            }
        }

    }

}

vector<Token*>* lex(string code){

    char* keepTokens("+-/*%;{}");
    char* dropTokens(" ");

    using namespace boost;
    typedef tokenizer<char_separator<char>> tokenizer;

    char_separator<char> sep(dropTokens,keepTokens,drop_empty_tokens);

    vector<Token*>* result = new vector<Token*>();

    tokenizer tokens(code,sep);
    for(tokenizer::iterator beg=tokens.begin(); beg!=tokens.end();++beg){

        result->push_back(new Token(*beg));
    }
    return result;
}
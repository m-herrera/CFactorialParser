//
// Created by marco on 27/03/18.
//
#include "Token.h"


tokenType evaluateToken(string token){
    char types[][7] = {"int","char","long","double","float"};
    for (char* type : types) {
        string stringType(type);
        if ( stringType == token){
            return DATA_TYPE;
        }
    }
    if(token == "="){
        return ASSIGNMENT;
    }
    else if(token == ";"){
        return LINE_SEPARATOR;
    }
    else if(token == "\n") {
        return END_LINE;
    }else if(token == "{"){
        return OPEN_SCOPE;
    }else if(token == "}"){
        return CLOSE_SCOPE;
    }else {
        regex regex("\'[A-Za-z]\'");
        if (regex_match(token,regex)){
            return LITERAL;
        }
        regex regexIdentifier("[_a-zA-Z][_a-zA-Z0-9]");
        if (regex_match(token, regexIdentifier)){
            return IDENTIFIER;
        }

        char arithmeticOperators[][2] = {"+","-","*","/","%"};
        for (char* arithmeticOperator:arithmeticOperators) {
            string stringOperator(arithmeticOperator);
            if (token == arithmeticOperator ){
                return OPERATOR;
            }
        }

    }
}

Token::Token(string value){
    this->value = value;
    this->type = evaluateToken(value);
}

//
// Created by marco on 27/03/18.
//

#ifndef CODEPARSER_TOKENTYPE_H
#define CODEPARSER_TOKENTYPE_H

enum tokenType {
    IDENTIFIER = 2,
    OPERATOR = 3,
    LITERAL = 5,
    LINE_SEPARATOR = 7,
    OPEN_SCOPE = 11,
    CLOSE_SCOPE = 13,
    DATA_TYPE = 17,
    END_LINE = 19,
    ASSIGNMENT = 23

};

#endif //CODEPARSER_TOKENTYPE_H

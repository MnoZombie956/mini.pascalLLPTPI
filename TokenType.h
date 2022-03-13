#ifndef TOKENTYPE_H
#define TOKENTYPE_H

#include <string>

enum TokenType {
    // SPECIALS
    TKN_UNEXPECTED_EOF = -2,
    TKN_INVALID_TOKEN = -1,
    TKN_END_OF_FILE = 0,

    // SYMBOLS
    TKN_DOT,           // .
    TKN_COMMA,         // ,
    TKN_COLON,         // :
    TKN_SEMICOLON,     // ;
    TKN_OPEN_PAR,      // (
    TKN_CLOSE_PAR,     // )

    // OPERATORS
    TKN_ASSIGN,        // :=
    TKN_EQUAL,         // =
    TKN_NOT_EQUAL,     // <>
    TKN_LOWER,         // <
    TKN_GREATER,       // >
    TKN_LOWER_EQ,      // <=
    TKN_GREATER_EQ,    // >=
    TKN_ADD,           // +
    TKN_SUB,           // -
    TKN_MUL,           // *
    TKN_DIV,           // /
    TKN_MOD,           // %

    // KEYWORDS
    TKN_PROGRAM,       // program 19
    TKN_CONST,         // const
    TKN_VAR,           // var
    TKN_BEGIN,         // begin
    TKN_END,           // end
    TKN_IF,            // if
    TKN_THEN,          // then
    TKN_ELSE,          // else
    TKN_CASE,          // case
    TKN_OF,            // of
    TKN_WHILE,         // while
    TKN_DO,            // do
    TKN_REPEAT,        // repeat 31
    TKN_UNTIL,         // until
    TKN_FOR,           // for
    TKN_TO,            // to
    TKN_WRITE,         // write
    TKN_WRITELN,       // writeln
    TKN_READLN,        // readln
    TKN_NOT,           // not
    TKN_AND,           // and
    TKN_OR,            // or 40

    // OTHERS
    TKN_ID,            // identifier
    TKN_INTEGER,       // integer
    TKN_REAL,          // real, is it the same as <value> ?
    TKN_STRING,        // string
};

inline std::string tt2str(enum TokenType type) {
    switch (type) {
        // Specials
        case TKN_UNEXPECTED_EOF:
            return "UNEXPECTED_EOF";
        case TKN_INVALID_TOKEN:
            return "INVALID_TOKEN";
        case TKN_END_OF_FILE:
            return "END_OF_FILE";

        // Symbols
        case TKN_DOT:
            return "DOT";
        case TKN_COMMA:
            return "COMMA";
        case TKN_COLON:
            return "COLON";
        case TKN_SEMICOLON:     // ;
            return "SEMICOLON";
        case TKN_OPEN_PAR:     // (
            return "OPEN_PAR";
        case TKN_CLOSE_PAR:     // )
            return "CLOSE_PAR";

        // OPERATORS
        case TKN_ASSIGN:
            return "ASSIGN";      // :=
        case TKN_EQUAL:
            return "EQUAL";       // =
        case TKN_NOT_EQUAL:
            return "NEQUAL";    // <>
        case TKN_LOWER:
            return "LOWER";         // <
        case TKN_GREATER:
            return "GREATER";       // >
        case TKN_LOWER_EQ:
            return "LOWEREQ";      // <=
        case TKN_GREATER_EQ:
            return "GREATEREQ";    // >=
        case TKN_ADD:
            return "ADD";           // +
        case TKN_SUB:
            return "SUB";           // -
        case TKN_MUL:
            return "MUL";           // *
        case TKN_DIV:
            return "DIV";           // /
        case TKN_MOD:
            return "MOD";           // %

        // KEYWORDS
        case TKN_PROGRAM:
            return "PROGRAM";       // program
        case TKN_CONST:
            return "CONST";         // const
        case TKN_VAR:
            return "VAR";           // var
        case TKN_BEGIN:
            return "BEGIN";         // begin
        case TKN_END:
            return "END";           // end
        case TKN_IF:
            return "IF";            // if
        case TKN_THEN:
            return "THEN";          // then
        case TKN_ELSE:
            return "ELSE";          // else
        case TKN_CASE:
            return "CASE";          // case
        case TKN_OF:
            return "OF";            // of
        case TKN_WHILE:
            return "WHILE";         // while
        case TKN_DO:
            return "DO";            // do
        case TKN_REPEAT:
            return "REPEAT";        // repeat
        case TKN_UNTIL:
            return "UNTIL";         // until
        case TKN_FOR:
            return "FOR";           // for
        case TKN_TO:
            return "TO";            // to
        case TKN_WRITE:
            return "WRITE";         // write
        case TKN_WRITELN:
            return "WRITELN";       // writeln
        case TKN_READLN:
            return "READLN";        // readln
        case TKN_NOT:
            return "NOT";           // not
        case TKN_AND:
            return "AND";          // and
        case TKN_OR:
            return "OR";            // or

        // OTHERS
        case TKN_ID:
            return "ID";            // identifier
        case TKN_INTEGER:
            return "INT";       // integer
        case TKN_REAL:
            return "REAL";          // real
        case TKN_STRING:
            return "STR";        // string

        default:
            throw std::string("invalid token type");
    }
}


#endif

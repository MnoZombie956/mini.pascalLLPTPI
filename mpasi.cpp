#include <iostream>

#include "lexical/LexicalAnalysis.h"
#include "syntatic/SyntaticAnalysis.h"
#include "interpreter/command/Command.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s [miniPascal file]\n", argv[0]);
        return 1;
    }

    try {
        LexicalAnalysis l(argv[1]);

        // O código a seguir é dado para testar o interpretador.
        // TODO: descomentar depois que o analisador léxico estiver OK.
        /*SyntaticAnalysis s(l);
        std::cout << "good1";
        Command* c = s.start();
        std::cout << "good2";
        c->execute();
        std::cout << "good3";
        delete c;

        std::cout << "good4";*/


        //teste do syntatic

        SyntaticAnalysis s(l);
        std::cout << "good1" << std::endl;
        s.start();

        std::cout << "all good" << std::endl;

        /*
        // O código a seguir é usado apenas para testar o analisador léxico.
        // TODO: depois de pronto, comentar o código abaixo.
        struct Lexeme lex;
        while ((lex = l.nextToken()).type > 0) {
            //printf("(\"%s\", %d)\n", lex.token.str(), lex.type);
            std::cout << lex.str() << std::endl;
        }

        switch (lex.type) {
            case TKN_INVALID_TOKEN:
                printf("%02d: Invalid Lexeme [%s]\n", l.line(), lex.token.c_str());
                break;
            case TKN_UNEXPECTED_EOF:
                printf("%02d: Fim de arquivo inesperado\n", l.line());
                break;
            default:
                //printf("(\"%s\", %d)\n", lex.token.c_str(), lex.type);
                std::cout << "end: " << lex.str() <<"\nok";
                break;
        }
        */
    } catch (std::string msg) {
        fprintf(stderr, "Internal error: %s\n", msg.c_str());
        std::cout << "Ops: " << msg.c_str();
        return 2;
    }
    return 0;
}
/*
C:\MinGW\msys\1.0\bin>make --directory=C:\Users\ofzbo\Documents\CeFeT_Mg\CEFET\Semestre4\LP\mPascal_interpreter
make: Entering directory `/c/Users/ofzbo/Documents/CeFeT_Mg/CEFET/Semestre4/LP/mPascal_interpreter'
g++ -g -ggdb -O2 -Wall -c -o mpasi.o mpasi.cpp
g++ -o mpasi mpasi.o lexical/SymbolTable.o lexical/LexicalAnalysis.o
make: Leaving directory `/c/Users/ofzbo/Documents/CeFeT_Mg/CEFET/Semestre4/LP/mPascal_interpreter'

C:\Users\ofzbo\Documents\CeFeT_Mg\CEFET\Semestre4\LP\mPascal_interpreter>mpasi triangle.mpas
("(* a program to check triangles' dimensions *)program", 41)
("triangle", 41)
(";", 4)
("const", 20)
("MSG", 41)
("=", 8)
("'Enter the three sizes of a triangle: '", 44)
(";", 4)
("var", 21)
("a", 41)
(",", 2)
("b", 41)
(",", 2)
("c", 41)
(";", 4)
("valid", 41)
("=", 8)
("1", 42)
(";", 4)
("begin", 22)
("repeat", 31)
("write", 35)
("(", 5)
("MSG", 41)
(")", 6)
(";", 4)
("readln", 37)
("(", 5)
("a", 41)
(",", 2)
("b", 41)
(",", 2)
("c", 41)
(")", 6)
(";", 4)
("write", 35)
("(", 5)
("'('", 44)
(",", 2)
("a", 41)
(",", 2)
("', '", 44)
(",", 2)
("b", 41)
(",", 2)
("', '", 44)
(",", 2)
("c", 41)
(",", 2)
("') '", 44)
(")", 6)
(";", 4)
("if", 24)
("(", 5)
("a", 41)
("+", 14)
("b", 41)
(")", 6)
("<=", 12)
("c", 41)
("or", 40)
("(", 5)
("a", 41)
("+", 14)
("c", 41)
(")", 6)
("<=", 12)
("b", 41)
("or", 40)
("(", 5)
("b", 41)
("+", 14)
("c", 41)
(")", 6)
("<=", 12)
("a", 41)
("then", 25)
("begin", 22)
("writeln", 36)
("(", 5)
("'is an invalid triangle'", 44)
(")", 6)
(";", 4)
("valid", 41)
(":=", 7)
("0", 42)
("end", 23)
("else", 26)
("if", 24)
("a", 41)
("=", 8)
("b", 41)
("and", 39)
("b", 41)
("=", 8)
("c", 41)
("then", 25)
("writeln", 36)
("(", 5)
("'is an equilateral triangle'", 44)
(")", 6)
("else", 26)
("if", 24)
("a", 41)
("=", 8)
("b", 41)
("or", 40)
("a", 41)
("=", 8)
("c", 41)
("or", 40)
("b", 41)
("=", 8)
("c", 41)
("then", 25)
("writeln", 36)
("(", 5)
("'is a isosceles triangle'", 44)
(")", 6)
("else", 26)
("writeln", 36)
("(", 5)
("'is a scalene triangle'", 44)
(")", 6)
(";", 4)
("writeln", 36)
("(", 5)
(")", 6)
("until", 32)
("valid", 41)
("=", 8)
("0", 42)
("end", 23)
(".", 1)
("", 0)
*/
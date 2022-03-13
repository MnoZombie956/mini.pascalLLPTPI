#include <cstdlib>
#include <iostream>
#include "SyntaticAnalysis.h"

#include "../interpreter/command/Command.h"

/*
 FALTA ADICIONAR (* a program to check triangles' dimensions *) E UM PROC PARA Ele

*/

SyntaticAnalysis::SyntaticAnalysis(LexicalAnalysis& lex) :
    m_lex(lex), m_current(m_lex.nextToken()) {
}

SyntaticAnalysis::~SyntaticAnalysis() {
}

/*Command* SyntaticAnalysis::start() { //para o interpretador
    Command* cmd = procProgram();
    eat(TKN_END_OF_FILE);
    return cmd;
    //return 0;
}*/
void SyntaticAnalysis::start() { // para o an. sintatico
    procProgram();
    eat(TKN_END_OF_FILE);
}

void SyntaticAnalysis::advance() {
    printf("Advanced (\"%s\", %d)\n", m_current.token.c_str(), m_current.type);
    m_current = m_lex.nextToken();
}

void SyntaticAnalysis::eat(enum TokenType type) {
    //printf("Expected (..., %s %d), found (\"%s\", %d)\n",tt2str(type),type, m_current.token.c_str(), m_current.type);
    std::cout << "Expected (...,"<<tt2str(type)<<" "<<type<<"), found (\""<<m_current.token.c_str()<<"\", "<<m_current.type<<")\n";
    if (type == m_current.type) {
        printf("ok\n");
    } else {
        printf("nops ------------------------------------------------ \n");
        showError();
    }
        m_current = m_lex.nextToken();
}

void SyntaticAnalysis::showError() {
    printf("%02d: ", m_lex.line());

    switch (m_current.type) {
        case TKN_INVALID_TOKEN:
            printf("Lexema inválido [%s]\n", m_current.token.c_str());
            break;
        case TKN_UNEXPECTED_EOF:
        case TKN_END_OF_FILE:
            printf("Fim de arquivo inesperado\n");
            break;
        default:
            printf("Lexema não esperado [%s]\n", m_current.token.c_str());
            break;
    }
    //exit(1);
}

// <program>  ::= program <id> ';'
//                [ const <const> { <const> } ]
//                [ var <var> { <var> } ]
//                <block> '.'
void SyntaticAnalysis::procProgram() {
    printf("in program\n");
    eat(TKN_PROGRAM);
    procId();// msm de eat TKN_VAR;
    //procVar();
    eat(TKN_SEMICOLON);
    if(m_current.type == TKN_CONST){
        advance();
        procConst();
        while(m_current.type == TKN_ID){
            //advance();
            procConst();
        }
    }
    if(m_current.type == TKN_VAR){
        advance();
        //eat(TKN_VAR);
        //eat(TKN_ID);
        procVar();
        while(m_current.type == TKN_ID){
            //advance();
            procVar();
        }
    }
    procBlock();
    eat(TKN_DOT);
}

// <const>    ::= <id> = <value> ';'
void SyntaticAnalysis::procConst() {
    printf("in const\n");
    procId();// eh a msm coisa de eat(TKN_VAR); meio irrelevante mas ele ta la
    eat(TKN_EQUAL);
    procValue();
    eat(TKN_SEMICOLON);
}

// <var>      ::= <id> { ',' <id> } [ = <value> ] ';'
void SyntaticAnalysis::procVar() {
    printf("in var\n");
    procId();
    while (m_current.type == TKN_COMMA){
       advance();
       procId();
    }
    if(m_current.type == TKN_EQUAL){
        advance();
        procValue();
    }
    eat(TKN_SEMICOLON);
}

// <body>     ::= <block> | <cmd>
void SyntaticAnalysis::procBody() {
    printf("in body\n");
    if (m_current.type == TKN_BEGIN){
        procBlock();
    }else if (m_current.type == TKN_ID ||
        m_current.type == TKN_IF     ||
        m_current.type == TKN_CASE   ||
        m_current.type == TKN_WHILE  ||
        m_current.type == TKN_FOR    ||
        m_current.type == TKN_REPEAT ||
        m_current.type == TKN_WRITE  ||
        m_current.type == TKN_WRITELN||
        m_current.type == TKN_READLN){
        //advance();
        procCmd();
    }/*else{
        showError();
    }*/
}

// <block>    ::= begin [ <cmd> { ';' <cmd> } ] end
void SyntaticAnalysis::procBlock() {
    printf("in block\n");
    eat(TKN_BEGIN);

    if(m_current.type == TKN_ID ||
        m_current.type == TKN_IF     ||
        m_current.type == TKN_CASE   ||
        m_current.type == TKN_WHILE  ||
        m_current.type == TKN_FOR    ||
        m_current.type == TKN_REPEAT ||
        m_current.type == TKN_WRITE  ||
        m_current.type == TKN_WRITELN||
        m_current.type == TKN_READLN){
        //advance();
        procCmd();
        while(m_current.type == TKN_SEMICOLON){
            advance();
            procCmd();
        }
    }
    eat(TKN_END);
}

// <cmd>      ::= <assign> | <if> | <case> | <while> | <for> | <repeat> | <write> | <read>
void SyntaticAnalysis::procCmd() {
    printf("in cmd\n");
    switch (m_current.type){
        case TKN_ID:// <assign> começa com <id> que eh o tkn var ?
            procAssign();break;
        case TKN_IF:
            procIf();break;
        case TKN_CASE:
            procCase();break;
        case TKN_WHILE:
            procWhile();break;
        case TKN_FOR:
            procFor();break;
        case TKN_REPEAT:
            procRepeat();break;
        case TKN_WRITE:
        case TKN_WRITELN:
            procWrite();break;
        case TKN_READLN:
            procRead();break;
        default:
            break;//eles nao estao entre parenteses certo ? else: show error
    }
}

// <assign>   ::= <id> ''''':=''''' <expr>
void SyntaticAnalysis::procAssign() {
    printf("in ass\n");
    procId();
    eat(TKN_ASSIGN);
    procExpr();
}

// <if>       ::= if <boolexpr> then <body> [else <body>]
void SyntaticAnalysis::procIf() {
    printf("in if\n");
    eat(TKN_IF);
    procBoolExpr();
    eat(TKN_THEN);
    procBody();
    if (m_current.type== TKN_ELSE){
        advance();
        procBody();
    }

}

// <case>     ::= case <expr> of { <value> ''''':''''' <body> ';' } [ else <body> ';' ] end
void SyntaticAnalysis::procCase() {
    printf("in case\n");
    eat(TKN_CASE);
    procExpr();
    eat(TKN_OF);
    while (m_current.type == TKN_INTEGER||
        m_current.type == TKN_REAL||
        m_current.type== TKN_STRING){
        advance();
        procValue();
        eat(TKN_COLON);
        procBody();
        eat(TKN_SEMICOLON);
    }
    if (m_current.type== TKN_ELSE){
        advance();
        procBody();
        eat(TKN_SEMICOLON);
    }
    eat(TKN_END);
}

// <while>    ::= while <boolexpr> do <body>
void SyntaticAnalysis::procWhile() {
    printf("in while\n");
    eat(TKN_WHILE);
    procBoolExpr();
    eat(TKN_DO);
    procBody();
}

// <repeat>   ::= repeat [ <cmd> { ';' <cmd> } ] until <boolexpr>
void SyntaticAnalysis::procRepeat() {
    printf("in repeat\n");
    eat(TKN_REPEAT);
    if (m_current.type == TKN_VAR    ||
        m_current.type == TKN_IF     ||
        m_current.type == TKN_CASE   ||
        m_current.type == TKN_WHILE  ||
        m_current.type == TKN_FOR    ||
        m_current.type == TKN_REPEAT ||
        m_current.type == TKN_WRITE  ||
        m_current.type == TKN_WRITELN||
        m_current.type == TKN_READLN){
        //advance();
        procCmd();
        while(m_current.type== TKN_SEMICOLON){
            //eat(TKN_SEMICOLON);
            advance();
            procCmd();
        }
    }
    eat(TKN_UNTIL);
    procBoolExpr();
}

// <for>      ::= for ''''''<id>'''''' := <expr> to <expr> do <body>
void SyntaticAnalysis::procFor() {
    printf("in for\n");
    eat(TKN_FOR);
    procId();
    eat(TKN_ASSIGN);
    procExpr();
    eat(TKN_TO);
    procExpr();
    eat(TKN_DO);
    procBody();
}

// <write>    ::= (write | writeln) '(' [ <expr> { ',' <expr> } ] ')'
void SyntaticAnalysis::procWrite() {
    printf("in write\n");
    if (m_current.type== TKN_WRITE){
        eat(TKN_WRITE);
    }else if(m_current.type== TKN_WRITELN){
        eat(TKN_WRITELN);
    }else{
        showError();
    }
    eat(TKN_OPEN_PAR);
    if (m_current.type == TKN_INTEGER ||
        m_current.type == TKN_REAL    ||
        m_current.type == TKN_STRING  ||
        m_current.type == TKN_ID      ||
        m_current.type == TKN_OPEN_PAR){
        advance();
        while(m_current.type == TKN_COMMA){
            advance();
            procExpr();
        }
    }
    eat(TKN_CLOSE_PAR);
}

// <read>     ::= readln '(' <id> { ',' <id> } ')'
void SyntaticAnalysis::procRead() {
    printf("in read\n");
    eat(TKN_READLN);
    eat(TKN_OPEN_PAR);
    procId();
    while(m_current.type== TKN_COMMA){
        //eat(TKN_COMMA)
        advance();
        procId();
    }
    eat(TKN_CLOSE_PAR);
}

// <boolexpr> ::= [ not ] <cmpexpr> [ (and | or) <boolexpr> ]
void SyntaticAnalysis::procBoolExpr() {
    printf("in boolexpr\n");
    if (m_current.type== TKN_NOT){
        advance();
    }
    procCmpExpr();
    if(m_current.type==TKN_AND || m_current.type==TKN_OR){
        advance();
        procBoolExpr();
    }/*else{
        showError();
    }*/
}

// <cmpexpr>  ::= <expr> ('=' | '<>' | '<' | '>' | '<=' | '>=') <expr>
void SyntaticAnalysis::procCmpExpr() {
    printf("in cmpexpr\n");
    procExpr();
    if(m_current.type== TKN_EQUAL     ||
        m_current.type== TKN_NOT_EQUAL||
        m_current.type== TKN_LOWER    ||
        m_current.type== TKN_GREATER  ||
        m_current.type== TKN_LOWER_EQ ||
        m_current.type== TKN_GREATER_EQ){
        advance();       
    }else{
        showError();
    }
    procExpr();
}

// <expr>     ::= <term> { ('+' | '-') <term> }
void SyntaticAnalysis::procExpr() {
    printf("in expr\n");
    procTerm();
    while ( m_current.type== TKN_ADD || m_current.type== TKN_SUB){
        advance();
        procTerm();
    }
}

// <term>     ::= <factor> { ('*' | '/' | '%') <factor> }
void SyntaticAnalysis::procTerm() {
    printf("in term\n");
    procFactor();
    while ( m_current.type== TKN_INTEGER ||
        m_current.type== TKN_REAL    ||
        m_current.type== TKN_STRING  ||
        m_current.type == TKN_ID     ||
        m_current.type == TKN_OPEN_PAR){
        advance();
        procFactor();
    }
}

// <factor>   ::= <value> | <id> | '(' <expr> ')'
void SyntaticAnalysis::procFactor() {
    printf("in factor\n");
    /*if(m_current.type== TKN_REAL || m_current.type== TKN_VAR){
        advance();
    }*/
    switch (m_current.type){
        case TKN_REAL:
        case TKN_INTEGER:
        case TKN_STRING:
            procValue();
            break;
        case TKN_ID:
            procId();
            break;
        case TKN_OPEN_PAR:
            advance();
            procExpr();
            eat(TKN_CLOSE_PAR);
            break;
        default:
            break;
    }
}

// <value>    ::= <integer> | <real> | <string>
void SyntaticAnalysis::procValue() {
    printf("in value\n");
    if (m_current.type==TKN_INTEGER || m_current.type==TKN_REAL || m_current.type==TKN_STRING){
        switch (m_current.type){
            case TKN_INTEGER:
                procInteger();break;
            case TKN_REAL:
                procReal();break;
            case TKN_STRING:
                procString();break;
            default:
                break;
        }
    }
}

void SyntaticAnalysis::procId() {
    eat(TKN_ID);
}

void SyntaticAnalysis::procInteger() {
    eat(TKN_INTEGER);
}

void SyntaticAnalysis::procReal() {
    eat(TKN_REAL);
}

void SyntaticAnalysis::procString() {
    eat(TKN_STRING);
}

/*
<program> ::= program <id> ';'
             [ const <const> { <const> } ]
             [ var <var> { <var> } ]
             <block> '.'
<const> ::= <id> '=' <value> ';'
<var> ::= <id> { ',' <id> } [ '=' <value> ] ';'
<body> ::= <block> | <cmd>
<block> ::= begin [ <cmd> { ';' <cmd> } ] end
<cmd> ::= <assign> | <if> | <case> | <while> | <for> | <repeat> | <write> | <read>
<assign> ::= <id> ':=' <expr>
<if> ::= if <boolexpr> then <body> [ else <body> ]
<case> ::= case <expr> of { <value> ':' <body> ';' } [ else <body> ';' ] end
<while> ::= while <boolexpr> do <body>
<repeat> ::= repeat [ <cmd> { ';' <cmd> } ] until <boolexpr>
<for> ::= for <id> ':=' <expr> to <expr> do <body>
<write> ::= (write | writeln) '(' [ <expr> { ',' <expr> } ] ')'
<read> ::= readln '(' <id> { ',' <id> } ')'
<boolexpr> ::= [ not ] <cmpexpr> [ (and | or) <boolexpr> ]
<cmpexpr> ::= <expr> ('=' | '<>' | '<' | '>' | '<=' | '>=') <expr>
<expr> ::= <term> { ('+' | '-') <term> }
<term> ::= <factor> { ('*' | '/' | '%') <factor> }
<factor> ::= <value> | <id> | '(' <expr> ')'
<value> ::= <integer> | <real> | <string>

<id> ::= variable's_name
<integer> ::= int
<real> ::= double
<string> ::= str

*/
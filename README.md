# mini.pascalLLPTPI
Interpreter for a subset of the Pascal programming language.

### Caracteristics
```
1) Comandos:
a. atribuição: atribuir uma expressão a uma variável.
b. if:  executar comandos baseado em expressões condicionais. 
c. case: executar comandos baseados no valor de uma expressão.
d. while: repetir comandos enquanto a expressão for verdadeira.
e. repeat: repetir comandos enquanto a expressão for falsa.
f. for: repetir comandos para uma sequência de valores.
g. write/writeln: imprimir na tela.
h. readln: ler do teclado.
2) Constantes:
a. Inteiro: número formado por dígitos.
b. Real: número com precisão em ponto-flutuante.
c. String: uma sequência de caracteres entre aspas simples.
d. Lógico: operações de comparações que obtém um valor lógico (não 
podem ser armazenados em variáveis).
3) Valores:
a. Variáveis (começam com _ ou letras, seguidos de _, letras ou dígitos).
b. Constantes (variáveis cujo valor não pode ser modificado)
c. Literais (inteiros, reais e strings).
4) Operadores:
a. Inteiro: + (adição),  - (subtração),  * (multiplicação),
/ (divisão), % (resto, somente para inteiros).
b. Lógico: = (igual),  <> (diferença),  < (menor),  > (maior),  <= (menor 
igual), >= (maior igual), not (negação).
c. Conector: and (E lógico), or (OU lógico).
d. Atribuição: := (atribuir)
```
### Grammar, extend Backus-Naur format(EBNF)

```
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
```

### How to run
```
$ ./mpasi triangle.mpas
Usage: ./mpasi [miniPascal file]
$ ./mpasi triangle.mpas
Enter the three sizes of the triangle: 3 4 5
(3, 4, 5) is a scalene triangle
Enter the three sizes of the triangle: 0 0 0
(0, 0, 0) is an invalid triangle
```

### Project Planning
![fsm](https://github.com/MnoZombie956/mini.pascalLLPTPI/blob/main/imgs/fsm_lexical.png?raw=false)
![classes](https://github.com/MnoZombie956/mini.pascalLLPTPI/blob/main/imgs/class_diagram.png?raw=false)

#ifndef EXPR_H
#define EXPR_H

#include "../value/Type.h"

class Expr {

public:
  virtual ~Expr(){}  
  int getLine(){return line;}
  virtual Type* expr() =0;


protected:
  Expr(int line){}

private:
  int line;

};

#endif  

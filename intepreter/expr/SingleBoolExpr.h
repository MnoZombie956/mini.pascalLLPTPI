#ifndef SINGLE_BOOL_EXPR_H
#define SINGLE_BOOL_EXPR_H

#include "BoolExpr.h"
#include "Expr.h"
#include "../value/IntegerValue.h"
#include "../value/RealValue.h"
#include <iostream>

class SingleBoolExpr : public BoolExpr
{

public:
  enum Op
  {
    EQUAL,
    NOT_EQUAL,
    LOWER_THAN,
    LOWER_EQUAL,
    GREATER_THAN,
    GREATER_EQUAL
  };
  
  SingleBoolExpr(int line, Expr *left, enum Op RelOp, Expr* right);
  virtual ~SingleBoolExpr();

  int getLine(){return BoolExpr::getLine();};

  virtual bool expr();

private:
  Expr* left;
  enum Op RelOp;
  Expr* right;
};

#endif
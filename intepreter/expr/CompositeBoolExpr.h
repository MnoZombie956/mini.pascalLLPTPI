#ifndef COMPOSITE_BOOL_EXPR_H
#define COMPOSITE_BOOL_EXPR_H

#include "Expr.h"
#include "BoolExpr.h"

class CompositeBoolExpr:public BoolExpr{

public:

  enum BoolOp{
    And,
    Or
  };

  CompositeBoolExpr(int line, BoolExpr* left, enum BoolOp op, BoolExpr* right);

  virtual ~CompositeBoolExpr();

  int getLine(){return BoolExpr::getLine();};

  bool virtual expr();

private:

  BoolExpr* left;
  enum BoolOp op;
  BoolExpr* right;

};

#endif
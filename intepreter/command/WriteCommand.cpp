#include "WriteCommand.h"
#include <iostream>

WriteCommand::WriteCommand(int line, bool writeln) : Command(line), writeln(writeln) {}

WriteCommand::~WriteCommand()
{
}

void WriteCommand::addExpr(Expr *expr)
{
  exprs.push_back(expr);
}

void WriteCommand::Execute()
{
  if (writeln)
  {
    for (std::list<Expr *>::iterator it = exprs.begin(), ed = exprs.end(); it != ed; it++)
    {
      Expr *exp = *it;
      Type *t = exp->expr();
      if (t->type() == Type::IntegerType)
      {
        IntegerValue *iv = (IntegerValue *)t;
        std::cout << iv->value() << std::endl; 
      }
      else if (t->type() == Type::RealType)
      {
        RealValue *rv = (RealValue *)t;
        std::cout << rv->value() << std::endl;
      }
      else
      {
        StringValue *sv = (StringValue *)t;
        std::cout << sv->value() << std::endl;
      }
    }
  }
  else
  {
    for (std::list<Expr *>::iterator it = exprs.begin(), ed = exprs.end(); it != ed; it++)
    {
      Expr *exp = *it;
      Type *t = exp->expr();
      if (t->type() == Type::IntegerType)
      {
        IntegerValue *iv = (IntegerValue *)t;
        std::cout << (iv->value());
      }
      else if (t->type() == Type::RealType)
      {
        RealValue *rv = (RealValue *)t;
        std::cout << (rv->value());
      }
      else
      {
        StringValue *sv = (StringValue *)t;
        std::cout << (sv->value());
      }    }
  }
}
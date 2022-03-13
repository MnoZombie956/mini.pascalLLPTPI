#ifndef WRITE_COMMAND_H
#define WRITE_COMMAND_H

#include <list>
#include "Command.h"
#include "../expr/Expr.h"
#include "../value/Type.h"
#include "../value/Value.h"
#include "../value/IntegerValue.h"
#include "../value/RealValue.h"
#include "../value/StringValue.h"



class WriteCommand : public Command{

  public:
    WriteCommand(int line, bool writeln);
    virtual ~WriteCommand();

    void addExpr(Expr* expr);

    virtual void Execute();

  private:
    bool writeln;
    std::list<Expr*> exprs;

};


#endif
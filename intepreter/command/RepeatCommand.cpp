#include "RepeatCommand.h"

RepeatCommand::RepeatCommand(int line, std::list<Command *> cmds, BoolExpr *cond)
    : Command(line), cond(cond), cmds(cmds){};

RepeatCommand::~RepeatCommand()
{
}

void RepeatCommand::Execute()
{
  do
  {
    for (std::list<Command *>::iterator it = cmds.begin(), end = cmds.end(); it != end; it++)
    {
      Command *m = *it;
      m->Execute();
    }
  }while (cond->expr());
}
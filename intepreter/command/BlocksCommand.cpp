#include "BlocksCommand.h"

BlocksCommand::BlocksCommand(int line): Command(line){

}
    
    
BlocksCommand::~BlocksCommand() {
  
}

void BlocksCommand::addCommand(Command* cmd){
  m_cmds.push_back(cmd);
}

void BlocksCommand::Execute(){
  for (std::list<Command*>::iterator it = m_cmds.begin(), end = m_cmds.end(); it != end; it++){
    Command* m = *it;
    m->Execute();
  }
}



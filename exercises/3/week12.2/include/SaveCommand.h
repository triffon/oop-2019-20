#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H
#include "Command.h"
#include<string>
#include<vector>
  
   using namespace std;
   class SaveCommand : public Command{
   public:
        virtual string execute(vector<string> args, int count);
   };
#endif /* SAVECOMMAND_H */

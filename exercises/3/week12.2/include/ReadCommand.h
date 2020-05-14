#ifndef READCOMMAND_H
#define READCOMMAND_H
#include"Command.h"
#include<string>
#include<vector>
  
using namespace std;
class ReadCommand: public Command{
public:
           virtual string execute(vector<string> args, int count);
};
#endif /* READCOMMAND_H */

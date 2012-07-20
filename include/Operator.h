/* 
 * File:   Operator.h
 * Author: tomko
 *
 * Created on 29 maj 2012, 21:42
 */

#ifndef OPERATOR_H
#define	OPERATOR_H

#include <map>
#include <string>

class Operator
{
public:
  Operator();
  Operator(const Operator& orig);
  virtual ~Operator();
  typedef void (Operator::*MemPointer)();
  typedef void (Operator::*MemPointerString)(std::string);

  void addAction(std::string s, MemPointer action);
  void addAction(std::string s, std::string action_code);
  void procedeAction(std::string s);
  void readActions(std::string filename);
private:
  std::map<std::string, MemPointer> map_void;
  std::map<std::string, MemPointerString> map_string;
  std::map<std::string, std::string> map_patters_action;

  void someAction();
  void runProgram(std::string pro);

};

#endif	/* OPERATOR_H */


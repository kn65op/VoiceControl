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

  void addAction(std::string s);
  void procedeAction(std::string s);
private:
  typedef void (*MemPointer)();
  map<std::string, MemPointer> map_void;

  void someAction();
};

#endif	/* OPERATOR_H */


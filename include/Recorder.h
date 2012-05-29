/* 
 * File:   Recorder.h
 * Author: tomko
 *
 * Created on 29 maj 2012, 21:30
 */

#ifndef RECORDER_H
#define	RECORDER_H

#include "Operator.h"

class Recorder
{
public:
  Recorder();
  Recorder(const Recorder& orig);
  virtual ~Recorder();

  void start();
  void stop();

  void setOperator(Operator* op);
private:
  Operator* oper;
};

#endif	/* RECORDER_H */


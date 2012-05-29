/* 
 * File:   Recorder.h
 * Author: tomko
 *
 * Created on 29 maj 2012, 21:30
 */

#ifndef RECORDER_H
#define	RECORDER_H

#include <thread>
#include <atomic>

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

  std::atomic<bool> recording;
  void record();
  std::thread *rec_thread;
};

#endif	/* RECORDER_H */


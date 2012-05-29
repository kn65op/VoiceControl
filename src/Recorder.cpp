/* 
 * File:   Recorder.cpp
 * Author: tomko
 * 
 * Created on 29 maj 2012, 21:30
 */

#include "../include/Recorder.h"

Recorder::Recorder()
{
}

Recorder::Recorder(const Recorder& orig)
{
}

Recorder::~Recorder()
{
}

void Recorder::setOperator(Operator* op)
{
  oper = op;
}

void Recorder::start()
{
  rec_thread = new std::thread(&Recorder::record, this);
  recording = true;
}

void Recorder::stop()
{
  recording = false;
  rec_thread->join();
  delete rec_thread;
  rec_thread = 0;
}
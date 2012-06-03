/* 
 * File:   VoiceControlWindow.cpp
 * Author: tomko
 * 
 * Created on 11 kwiecień 2012, 14:34
 */

#include "../include/VoiceControlWindow.h"

#include "../include/Pattern.h"

//TODO usunąć
#include <iostream>

VoiceControlWindow::VoiceControlWindow()
{
  op = new Operator();
  op->readActions("patterns");
  rec.setOperator(op);
  start_stop.set_label("Start");
  recording = false;
  start_stop.signal_clicked().connect(sigc::mem_fun(*this, &VoiceControlWindow::on_start_stop_clicked));
  add(start_stop);
  start_stop.show();

  Pattern::loadPatterns("paterny");
}

VoiceControlWindow::~VoiceControlWindow()
{
  if (recording) 
  {
    rec.stop();
  }
}


void VoiceControlWindow::on_start_stop_clicked()
{
  if (recording) //stopowanie
  {
    start_stop.set_label("Start");
    rec.stop();
  }
  else //startowanie
  {
    start_stop.set_label("Stop");
    rec.start();
  }
  recording = !recording;
}
/* 
 * File:   VoiceControlWindow.cpp
 * Author: tomko
 * 
 * Created on 11 kwiecień 2012, 14:34
 */

#include "../include/VoiceControlWindow.h"

VoiceControlWindow::VoiceControlWindow()
{
  op = new Operator();
  rec.setOperator(op);
  rec.start();
}

VoiceControlWindow::~VoiceControlWindow()
{
  rec.stop();
}


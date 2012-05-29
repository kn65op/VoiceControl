/* 
 * File:   VoiceControlWindow.h
 * Author: tomko
 *
 * Created on 11 kwiecień 2012, 14:34
 */

#ifndef VOICECONTROLWINDOW_H
#define	VOICECONTROLWINDOW_H

#include <gtkmm-3.0/gtkmm.h>

#include "Recorder.h"
#include "Operator.h"

class VoiceControlWindow : public Gtk::Window
{
public:
  VoiceControlWindow();
  VoiceControlWindow(const VoiceControlWindow& orig) = delete;
  virtual ~VoiceControlWindow();
private:
  Gtk::Button a;

  Recorder rec;
  Operator *op;
};

#endif	/* VOICECONTROLWINDOW_H */


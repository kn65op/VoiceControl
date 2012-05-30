/* 
 * File:   Recorder.cpp
 * Author: tomko
 * 
 * Created on 29 maj 2012, 21:30
 */

#include "../include/Recorder.h"
#include <vector>

#include <Data.h>
#include <Device.h>


///TODO usunąć
#include <iostream>

Recorder::Recorder()
{
  recognizer.loadParameters();
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
  recording = true;
  rec_thread = new std::thread(&Recorder::record, this);
}

void Recorder::stop()
{
  if (!recording)
  {
    return;
  }
  recording = false;
  rec_thread->join();
  delete rec_thread;
  rec_thread = 0;
}

void Recorder::record()
{
  int time = 3; //3 sekundy
  int freq = 16000; //częstotliwość próbkowania
  TALSA::Data data;
  TALSA::Device device;
  TALSA::DataFormat df = TALSA::DataFormat::U8;
  device.setDevice("default");
  device.setDataFormat(df);
  device.setFrequency(freq);
  device.open(TALSA::AccessMode::READ);
  data.setDataFormat(df);
  data.setSize(time*freq);
  data.setFrameLength(256, 160);
  data.setSampleFrequency(freq);
  std::vector<std::vector<double>> parameters;
  std::vector<double> probabilities_from_speech;
  std::vector<double> 

  while (recording)
  {
    std::cout << "READ\n";
    device.read(data);
    
    //MTMP
    data.saveRawDataToFile("raw_data.dat");
    //TMP

    if (!data.findSpeechBorders()) //nie ma mowy w nagranym fragmencie
    {
      continue;
    }
    data.findPhonemeBorders();
    data.analyzeSegments();
    parameters = data.getParameters();
    for (auto p : parameters)
    {
      probabilities_from_speech = recognizer.getProbabilities(p.begin(), p.end());

      std::cout << recognizer.getLastLetter();
      std::cout << "\n";
      for (auto pp : probabilities_from_speech)
      {
	std::cout << pp << " ";
      }
      std::cout << "\n";
    }
  }
  device.close();
}
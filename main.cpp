/* 
 * File:   main.cpp
 * Author: tomko
 *
 * Created on 11 kwiecień 2012, 12:46
 */

#include <cstdlib>

using namespace std;

#include <Device.h>
#include <Data.h>
#include <extras.h>

/*
 * 
 */
int main(int argc, char** argv)
{
  TALSA::Device d;
  TALSA::Device d1;
  d.setDevice("default");
  d1.setDevice("file:'tmp.wav',wav");
  d.setDataFormat(TALSA::DataFormat::U8);
  d1.setDataFormat(TALSA::DataFormat::U8);
  TALSA::Data data;
  data.setSize(44100);
  data.setDataFormat(TALSA::DataFormat::U8);
  d.open(TALSA::AccessMode::READ);
  d1.open(TALSA::AccessMode::WRITE);
  d.read(data);
  d1.write(data);
  return 0;
}


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

#include <iostream>
#include <WaveFile.h>
#include <feature/MfccExtractor.h>
#include <feature/TextFeatureWriter.h>

/*
 * 
 */
int main(int argc, char** argv)
{
  TALSA::DataFormat f = TALSA::DataFormat::U8;
  TALSA::Device d;
  TALSA::Device d1;
  d.setDevice("default");
  d1.setDevice("file:'tmp.wav',wav");
  d.setDataFormat(f);
  d1.setDataFormat(f);
  TALSA::Data data;
  data.setSize(1 * 48000);
  data.setDataFormat(f);
  d.open(TALSA::AccessMode::READ);
  d1.open(TALSA::AccessMode::WRITE);
  d.read(data);
  d1.write(data);
  d.close();
  d1.close();


  {
    Aquila::WaveFile wav;
    wav.load("tmp.wav");
    std::cout << "Filename: " << wav.getFilename();
    std::cout << "\nLength: " << wav.getAudioLength() << " ms";
    std::cout << "\nSample frequency: " << wav.getSampleFrequency() << " Hz";
    std::cout << "\nChannels: " << wav.getChannelsNum();
    std::cout << "\nByte rate: " << wav.getBytesPerSec() / 1024 << " kB/s";
    std::cout << "\nBits per sample: " << wav.getBitsPerSamp() << "b\n";
  }

  Aquila::WaveFile wav(20, 0.66);
  wav.load("tmp.wav");
  Aquila::MfccExtractor extractor(20, 10);
  Aquila::TransformOptions options;
  options.preemphasisFactor = 0.9375;
  options.windowType = Aquila::WIN_HAMMING;
  options.zeroPaddedLength = wav.getSamplesPerFrameZP();
  extractor.process(&wav, options);
  Aquila::TextFeatureWriter writer("feature.txt");
  extractor.save(writer);

  return 0;
}


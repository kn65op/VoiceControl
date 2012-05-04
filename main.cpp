/* 
 * File:   main.cpp
 * Author: tomko
 *
 * Created on 11 kwiecień 2012, 12:46
 */

#include <cstdlib>

#include <Device.h>
#include <Data.h>
#include <extras.h>
#include <NeuralNetwork.h>
#include <LinearActivationFunction.h>

#include <iostream>
#include <fstream>
#include <WaveFile.h>
#include <feature/MfccExtractor.h>
#include <feature/TextFeatureWriter.h>

//#define network_LOAD
#define AKW
/*
 * 
 */
int main(int argc, char** argv)
{
#ifdef network_LOAD
  NeuralNetwork<double, LinearActivationFunction<double >> network;
  network.setEntries(12);
  network.setExits(4);
  network.setLayersCount(2);
  network.setNeurons(1, 8);
  network.init();

  std::vector<double> ins(12);
  std::vector<double> outs(4);

  //czytanie plików
  std::ifstream file;
  file.open("literaA.txt", std::ios::in);
  outs[0] = 1;
  while (!file.eof())
  {
    for (auto & d : ins)
    {
      file >> d;
    }
    network.insertPattern(ins.begin(), ins.end(), outs.begin(), outs.end());
  }
  file.close();

  file.open("literaE.txt", std::ios::in);
  outs[0] = 0;
  outs[1] = 1;
  while (!file.eof())
  {
    for (auto & d : ins)
    {
      file >> d;
    }
    network.insertPattern(ins.begin(), ins.end(), outs.begin(), outs.end());
  }
  file.close();

  file.open("literaI.txt", std::ios::in);
  outs[1] = 0;
  outs[2] = 1;
  while (!file.eof())
  {
    for (auto & d : ins)
    {
      file >> d;
    }
    network.insertPattern(ins.begin(), ins.end(), outs.begin(), outs.end());
  }
  file.close();

  file.open("literaO.txt", std::ios::in);
  outs[2] = 0;
  outs[3] = 1;
  while (!file.eof())
  {
    for (auto & d : ins)
    {
      file >> d;
    }
    network.insertPattern(ins.begin(), ins.end(), outs.begin(), outs.end());
  }
  file.close();

  std::cout << network.learnFromPattern() << "\n";
  std::cout << network.learnFromPattern() << "\n";
  std::cout << network.learnFromPattern() << "\n";
  std::cout << network.learnFromPattern() << "\n";


  std::vector<double> out;

  file.open("literaA.txt", std::ios::in);
  std::cout << "A\n";
  while (!file.eof())
  {
    for (auto & d : ins)
    {
      file >> d;
    }
    network.setInput(ins.begin(), ins.end());
    out = network.calcOutput();
    for (auto o : out)
    {
std::cout << o << " ";
    }
    std::cout << "\n";
  }
  file.close();

  file.open("literaE.txt", std::ios::in);
  std::cout << "E\n";
  outs[0] = 0;
  outs[1] = 1;
  while (!file.eof())
  {
    for (auto & d : ins)
    {
      file >> d;
    }
    network.setInput(ins.begin(), ins.end());
    out = network.calcOutput();
    for (auto o : out)
    {
std::cout << o << " ";
    }
    std::cout << "\n";
  }
  file.close();

  file.open("literaI.txt", std::ios::in);
  std::cout << "I\n";
  outs[1] = 0;
  outs[2] = 1;
  while (!file.eof())
  {
    for (auto & d : ins)
    {
      file >> d;
    }
    network.setInput(ins.begin(), ins.end());
    out = network.calcOutput();
    for (auto o : out)
    {
std::cout << o << " ";
    }
    std::cout << "\n";
  }
  file.close();

  file.open("literaO.txt", std::ios::in);
  std::cout << "O\n";
  outs[2] = 0;
  outs[3] = 1;
  while (!file.eof())
  {
    for (auto & d : ins)
    {
      file >> d;
    }
    network.setInput(ins.begin(), ins.end());
    out = network.calcOutput();
    for (auto o : out)
    {
std::cout << o << " ";
    }
    std::cout << "\n";
  }
  file.close();

#endif
#ifdef AKW
  TALSA::DataFormat f = TALSA::DataFormat::U8;
  TALSA::Device d;
  TALSA::Device d1;
  TALSA::Device d2;
  TALSA::Data data;
  try
  {
    d.setDevice("default");
    d1.setDevice("file:'tmp.wav',wav");
    d2.setDevice("file:'tmp_after.wav',wav");
    d.setDataFormat(f);
    d1.setDataFormat(f);
    d2.setDataFormat(f);
    data.setSize(5 * 8000); //testote 2 sekundy
    data.setSampleFrequency(8000);
    data.setDataFormat(f);
    d.open(TALSA::AccessMode::READ);
    d1.open(TALSA::AccessMode::WRITE);
    d2.open(TALSA::AccessMode::WRITE);
    d.read(data);
    d1.write(data);
    d.close();
    d1.close();
    //data.removeConstantComponent();
    d2.write(data);
    d2.close();
    data.test();
    data.saveRawDataToFile("raw_data.dat");
    data.setFrameLength(1, 0.5);
    std::cout << data.getWindowsNumber() << "\n";
  }
  catch (TALSA::InvalidOperation inv)
  {
    std::cout << "Invalid operation: " << inv.getMessage() << "\n";
  }
  catch (TALSA::WrongArgument wa)
  {
    std::cout << "Wrong argument: " << wa.getMessage() << "\n";
  }

/*/ ekstracja cech z użyciem Aquily
  {
    Aquila::WaveFile wav;
    wav.load("tmp.wav");
    std::cout << "Filename: " << wav.getFilename();
    std::cout << "\nLength: " << wav.getAudioLength() << " ms";
    std::cout << "\nSample frequency: " << wav.getSampleFrequency() << " Hz";
    std::cout << "\nChanetworkels: " << wav.getChannelsNum();
    std::cout << "\nByte rate: " << wav.getBytesPerSec() / 1024 << " kB/s";
    std::cout << "\nBits per sample: " << wav.getBitsPerSamp() << "b\n";
  }

  Aquila::WaveFile wav(20, 0.50);
  wav.load("tmp.wav");
  Aquila::MfccExtractor extractor(20, 12);
  Aquila::TransformOptions options;
  options.preemphasisFactor = 0.9375;
  options.windowType = Aquila::WIN_HAMMING;
  options.zeroPaddedLength = wav.getSamplesPerFrameZP();
  extractor.process(&wav, options);
  Aquila::TextFeatureWriter writer("feature.txt");
  extractor.save(writer);

  data.setFrameLength(0.02, 0.5);
  int max = data.getWindowsNumber();
  int max1 = wav.getFramesCount();
  std::vector<double> a;
  std::ofstream file("litera1.txt");
  for (int i = 0; i < max; ++i)
  {
    if (data.isFrameWithSpeech(i)) // jest coś
    {
      file << i << ":\n";
      a = extractor.getVector(i);
      for (auto i : a)
      {
        file << i << "\t";
      }
      file << "\n";
    }
  }
  file.close();
 * **/
#endif

  return 0;
}


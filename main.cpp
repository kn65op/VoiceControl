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

#include "include/Letter.h"
#include "include/Recognizer.h"
#include "include/VoiceControlWindow.h"

//#define NET_FOURIER
//#define NET_ALL
//#define TEST_PAR
//#define NET_PAR
//#define NET_BT
//#define network_LOAD
//#define AKW
//#define NET_FILE
//#define TEST_FILE
//#define TEST_SPEECH
//#define TEST_ALGO
//#define CALC_AVG
//#define LAST_CHANCE

/*
 * 
 */
int main(int argc, char** argv)
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
  VoiceControlWindow vcw;
  return app->run(vcw);
#ifdef LAST_CHANCE
  Recognizer recognizer;
  recognizer.loadParameters();

  std::vector<double> ins(7);
  std::vector<double> out;

  std::ifstream in_file("parameters_cut.dat", std::ios::in);

  int i = 0;
  while (!in_file.eof())
  {
    for (auto & a : ins)
    {
      in_file >> a;
    }
    out = recognizer.getProbabilities(ins.begin(), ins.end());
    std::cout << recognizer.getLastLetter() << "\n";
    for (auto o : out)
    {
      std::cout << o <<  " " ;
    }
    std::cout << "\n";
  }
  in_file.close();

#endif
#ifdef NET_PAR

  int npar = 2;
  NeuralNetwork<double, LinearActivationFunction<double >> network;
  network.setEntries(12);
  network.setExits(npar);
  network.setLayersCount(3);
  network.setNeurons(1, 6);
  network.setNeurons(2, 3);
  network.init();

  std::vector<double> ins(12);
  std::vector<double> outs(npar);

  std::ifstream in_file("lista_parameters.txt", std::ios::in);
  std::string filename;

  int i = 0;
  while (!in_file.eof())
  {
    in_file >> filename;
    outs[i] = 1;
    std::ifstream in(filename, std::ios::in);
    while (!in.eof())
    {
      for (auto & a : ins)
      {
        in >> a;
      }
      network.insertPattern(ins.begin(), ins.end(), outs.begin(), outs.end());
    }
    in.close();
    outs[i++] = 0;
  }
  // in_file.close();
  std::cout << "Learning: \n";

  network.learnFromPattern(0.1, 5000);

  network.saveNetworkToFile("allparameters.net");
#endif
#ifdef CALC_AVG 
  std::vector<double> ins(12);
  std::vector<double> outs(31);

  std::ifstream in_file("lista_parameters.txt", std::ios::in);
  std::ofstream of_file("parameters.csv", std::ios::out);
  std::string filename;
  double tmp;
  int iterat;

  int i = 0;
  while (!in_file.eof())
  {
    in_file >> filename;
    outs[i] = 1;
    std::ifstream in(filename, std::ios::in);
    for (auto & a : ins)
    {
      a = 0;
    }
    iterat = 0;
    while (!in.eof())
    {
      ++iterat;
      for (auto & a : ins)
      {
        in >> tmp;
        a += tmp;
      }
    }
    of_file << filename << " ";
    for (auto & a : ins)
    {
      of_file << a / iterat << " ";
    }
    of_file << "\n";
    in.close();
  }
  // in_file.close();

#endif
#ifdef NET_FOURIER

  NeuralNetwork<double, LinearActivationFunction<double >> network;
  network.setEntries(257);
  network.setExits(31);
  network.setLayersCount(2);
  network.setNeurons(1, 150);
  //  network.setNeurons(2, 75);
  network.init();

  std::vector<double> ins(257);
  std::vector<double> outs(31);

  std::ifstream in_file("lista_fouriera.txt", std::ios::in);
  std::string filename;

  int i = 0;
  while (!in_file.eof())
  {
    in_file >> filename;
    outs[i] = 1;
    std::ifstream in(filename, std::ios::in);
    while (!in.eof())
    {
      for (auto & a : ins)
      {
        in >> a;
      }
      network.insertPattern(ins.begin(), ins.end(), outs.begin(), outs.end());
    }
    in.close();
    outs[i++] = 0;
  }
  // in_file.close();
  std::cout << "Learning: \n";

  network.learnFromPattern(0.1, 1000);

  network.saveNetworkToFile("allfourier.net");
#endif
#ifdef NET_BT

  NeuralNetwork<double, LinearActivationFunction<double >> network;
  network.setEntries(513);
  network.setExits(31);
  network.setLayersCount(2);
  network.setNeurons(1, 150);
  //  network.setNeurons(2, 75);
  network.init();

  std::vector<double> ins(513);
  std::vector<double> outs(31);

  std::ifstream in_file("lista_bt.txt", std::ios::in);
  std::string filename;

  int i = 0;
  while (!in_file.eof())
  {
    in_file >> filename;
    outs[i] = 1;
    std::ifstream in(filename, std::ios::in);
    while (!in.eof())
    {
      for (auto & a : ins)
      {
        in >> a;
      }
      network.insertPattern(ins.begin(), ins.end(), outs.begin(), outs.end());
    }
    in.close();
    outs[i++] = 0;
  }
  //in_file.close();
  std::cout << "Learning: \n";

  network.learnFromPattern(0.1, 500);

  network.saveNetworkToFile("allbt2.net");
#endif
#ifdef NET_ALL

  NeuralNetwork<double, LinearActivationFunction<double >> network;
  network.setEntries(771);
  network.setExits(31);
  network.setLayersCount(2);
  network.setNeurons(1, 300);
  //  network.setNeurons(2, 100);
  network.init();

  std::vector<double> ins(771);
  std::vector<double> outs(31);

  std::ifstream in_file("lista_fonemow.txt", std::ios::in);
  std::string filename;

  int i = 0;
  while (!in_file.eof())
  {
    in_file >> filename;
    outs[i] = 1;
    std::ifstream in(filename, std::ios::in);
    while (!in.eof())
    {
      for (auto & a : ins)
      {
        in >> a;
      }
      network.insertPattern(ins.begin(), ins.end(), outs.begin(), outs.end());
    }
    in.close();
    outs[i++] = 0;
  }
  in_file.close();
  std::cout << "Learning: \n";

  network.learnFromPattern(0.1, 500);

  network.saveNetworkToFile("normalized.net");

#endif
#ifdef TEST_PAR 

  NeuralNetwork<double, LinearActivationFunction<double >> network;
  network.loadNetworkFromFile("best_parameters.net");
  //test na innym pliku
  std::vector<double> out;
  std::vector<double> ins(12);
  std::vector<std::string> out2;
  std::string filename = "parameters_all.dat";
  std::ifstream in(filename, std::ios::in);
  Letter let;
  while (!in.eof())
  {
    for (auto & a : ins)
    {
      in >> a;
    }
    network.setInput(ins.begin(), ins.end());
    out = network.calcOutput();
    std::cout << "POCZ: ";
    let.setLetter(out.begin(), out.end());
    out2 = let.getPosobilities();
    for (auto o : out)
      //for (auto o : out2)
    {
      std::cout << (o > 0.5 ? 1 : o) << " ";
      // std::cout << o << " ";
    }
    if (out2.empty())
    {
      std::cout << "BRAK";
    }
    std::cout << "\n";
  }
  in.close();
#endif
#ifdef TEST_FILE

  NeuralNetwork<double, LinearActivationFunction<double >> network;
  network.loadNetworkFromFile("bestnew.net");
  //test na innym pliku
  std::vector<double> out;
  std::vector<double> ins(771);
  std::vector<std::string> out2;
  std::string filename = "wektor.dat";
  std::ifstream in(filename, std::ios::in);
  Letter let;
  while (!in.eof())
  {
    for (auto & a : ins)
    {
      in >> a;
    }
    network.setInput(ins.begin(), ins.end());
    out = network.calcOutput();
    std::cout << "POCZ: ";
    let.setLetter(out.begin(), out.end());
    out2 = let.getPosobilities();
    //    for (auto o : out)
    for (auto o : out2)
    {
      //      std::cout << (o > 0.5 ? 1 : o) << " ";
      std::cout << o << " ";
    }
    if (out2.empty())
    {
      std::cout << "BRAK";
    }
    std::cout << "\n";
  }
  in.close();
#endif
#ifdef TEST_SPEECH
  TALSA::DataFormat f = TALSA::DataFormat::U8;
  TALSA::Device d;
  TALSA::Device d1;
  TALSA::Device d2;
  TALSA::Data data;
  int freq = 16000;
  try
  {
    d.setDevice("default");
    d1.setDevice("file:'tmp.wav',wav");
    d2.setDevice("file:'tmp_after.wav',wav");
    d.setDataFormat(f);
    d1.setDataFormat(f);
    d2.setDataFormat(f);
    data.setSize(3 * freq); //testote 2 sekundy
    data.setSampleFrequency(freq);
    d.setFrequency(freq);
    d1.setFrequency(freq);
    d2.setFrequency(freq);
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
    data.saveRawDataToFile("raw_data.dat");
  }
  catch (TALSA::InvalidOperation inv)
  {
    std::cout << "Invalid operation: " << inv.getMessage() << "\n";
  }
  catch (TALSA::WrongArgument wa)
  {
    std::cout << "Wrong argument: " << wa.getMessage() << "\n";
  }

  //własna ekstrakcja cech
  data.setFrameLength(256, 160);
  data.test();
  int max = data.getWindowsNumber();
  //  std::vector < std::vector<double >> feature(max);
  std::vector<double> a;
  std::vector<double> formants;
  std::ofstream file("literaTEST.txt");

  //próba z użyciem binarnego wektora

  data.findPhonemeBorders();

  NeuralNetwork<double, LinearActivationFunction<double >> network;
  network.loadNetworkFromFile("bestnormalized.net");
  NeuralNetwork<double, LinearActivationFunction<double >> networkf;
  networkf.loadNetworkFromFile("bestfourier.net");
  NeuralNetwork<double, LinearActivationFunction<double >> networkbt;
  networkbt.loadNetworkFromFile("bestbt.net");
  //test na innym pliku
  std::vector<double> out;
  std::vector<double> ins(771);
  std::vector<double> insf(257);
  std::vector<double> insbt(513);
  std::vector<std::string> out2;
  std::string filename = "wektor.dat";
  std::string filenamef = "fourier.dat";
  std::string filenamebt = "before_thres.dat";
  std::string dstart, dstop, di;
  std::ifstream in(filename, std::ios::in);
  std::ifstream inf(filenamef, std::ios::in);
  std::ifstream inbt(filenamebt, std::ios::in);
  std::ifstream in_desc("wektor_desc.dat", std::ios::in);
  Letter let;
  while (!in.eof())
  {
    for (auto & a : ins)
    {
      in >> a;
    }
    for (auto & a : insf)
    {
      inf >> a;
    }
    for (auto & a : insbt)
    {
      inbt >> a;
    }
    network.setInput(ins.begin(), ins.end());
    out = network.calcOutput();
    in_desc >> di >> dstart >> dstop;
    std::cout << dstart << ":" << dstop << "\n";
    let.setLetter(out.begin(), out.end());
    out2 = let.getPosobilities();
    //    for (auto o : out)
    for (auto o : out2)
    {
      //      std::cout << (o > 0.5 ? 1 : o) << " ";
      std::cout << o << " ";
    }
    if (out2.empty())
    {
      std::cout << "BRAK";
    }
    std::cout << " | ";
    networkf.setInput(insf.begin(), insf.end());
    out = networkf.calcOutput();
    let.setLetter(out.begin(), out.end());
    out2 = let.getPosobilities();
    for (auto o : out2)
    {
      //      std::cout << (o > 0.5 ? 1 : o) << " ";
      std::cout << o << " ";
    }
    if (out2.empty())
    {
      std::cout << "BRAK";
    }
    std::cout << " | ";
    networkbt.setInput(ins.begin(), ins.end());
    out = networkbt.calcOutput();
    let.setLetter(out.begin(), out.end());
    out2 = let.getPosobilities();
    for (auto o : out2)
    {
      //      std::cout << (o > 0.5 ? 1 : o) << " ";
      std::cout << o << " ";
    }
    if (out2.empty())
    {
      std::cout << "BRAK";
    }
    std::cout << "\n";
  }
  in.close();
#endif
#ifdef NET_FILE
  NeuralNetwork<double, LinearActivationFunction<double >> network;
  network.loadNetworkFromFile("bestnormalized.net");
  //test na innym pliku
  std::vector<double> out;
  std::vector<double> ins(771);
  std::ifstream in_file("lista_fonemow.txt", std::ios::in);
  std::string filename;

  int i = 0;
  while (!in_file.eof())
  {
    in_file >> filename;
    std::ifstream in(filename, std::ios::in);
    std::cout << filename << ":\n";
    while (!in.eof())
    {
      for (auto & a : ins)
      {
        in >> a;
      }
      network.setInput(ins.begin(), ins.end());
      out = network.calcOutput();
      std::cout << "POCZ: ";
      for (auto o : out)
      {
        std::cout << (o > 0.5 ? 1 : o) << " ";
      }
      std::cout << "\n";
    }
    in.close();
  }
  in_file.close();

  /*  file.open("litera1.txt", std::ios::in);
    std::cout << "TEST\n";
    while (!file.eof())
    {
      for (auto & d : ins)
      {
        file >> d;
      }
      network.setInput(ins.begin(), ins.end());
      out = network.calcOutput();
      A = out[0] > 0.9 ? 1 : 0;
      E = out[1] > 0.9 ? 1 : 0;
      I = out[2] > 0.9 ? 1 : 0;
      O = out[3] > 0.9 ? 1 : 0;
      if (A + E + I + O == 1)
      {
        if (A)
        {
          std::cout << "A";
        }
        else if (E)
        {
          std::cout << "E";
        }
        else if (I)
        {
          std::cout << "I";
        }
        else
        {
          std::cout << "O";
        }
      }
      else
      {
        std::cout << "?";
      }
      std::cout << "\n";
    }
    file.close();
   */
#endif

#ifdef network_LOAD
  NeuralNetwork<double, LinearActivationFunction<double >> network;
  network.setEntries(513);
  network.setExits(4);
  network.setLayersCount(2);
  network.setNeurons(1, 250);
  //  network.setNeurons(2, 10);
  network.init();

  std::vector<double> ins(513);
  std::vector<double> outs(4);

  //czytanie plików
  std::ifstream file;
  file.open("wektorA.dat", std::ios::in);
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

  file.open("wektorS.dat", std::ios::in);
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

  file.open("wektorT.dat", std::ios::in);
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

  file.open("wektorR.dat", std::ios::in);
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
  std::cout << "LICZENIE\n";

  std::cout << network.learnFromPattern(1, 500) << "\n";
  //  std::cout << network.learnFromPattern() << "\n";
  //std::cout << network.learnFromPattern(0.01) << "\n";
  //std::cout << network.learnFromPattern(0.01) << "\n";
  network.saveNetworkToFile("STAR.net");


  //test
  std::vector<double> out;

  file.open("wektorA.dat", std::ios::in);
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

  file.open("wektorS.dat", std::ios::in);
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

  file.open("wektorT.dat", std::ios::in);
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

  file.open("wektorR.dat", std::ios::in);
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

  //test na innym pliku
  file.open("wektorSTART.dat", std::ios::in);
  std::cout << "TEST\n";
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
    int A, E, I, O;
    A = out[0] > 0.8 ? 1 : 0;
    E = out[1] > 0.8 ? 1 : 0;
    I = out[2] > 0.8 ? 1 : 0;
    O = out[3] > 0.8 ? 1 : 0;
    if (A + E + I + O == 1)
    {
      if (A)
      {
        std::cout << "A";
      }
      else if (E)
      {
        std::cout << "S";
      }
      else if (I)
      {
        std::cout << "T";
      }
      else
      {
        std::cout << "R";
      }
    }
    else
    {
      std::cout << "?";
    }

    /*
    for (auto o : out)
    {
      std::cout << o << " ";
    }*/
    std::cout << "\n";
  }
  file.close();

#endif
#ifdef TEST_ALGO
  TALSA::DataFormat f = TALSA::DataFormat::U8;
  TALSA::Device d;
  TALSA::Data data;
  d.setDevice("file:'tmp.wav', wav");
  d.setDataFormat(f);
  data.setDataFormat(f);
  data.setSize(3 * 16000);
  data.setSampleFrequency(16000);
  d.setFrequency(16000);
  d.open(TALSA::AccessMode::READ);
  d.read(data);
  d.close();

  data.saveRawDataToFile("test2.dat");
  data.setFrameLength(256, 160);
  data.findPhonemeBorders();
#endif
#ifdef AKW
  TALSA::DataFormat f = TALSA::DataFormat::U8;
  TALSA::Device d;
  TALSA::Device d1;
  TALSA::Device d2;
  TALSA::Data data;
  int freq = 16000;
  try
  {
    d.setDevice("default");
    d1.setDevice("file:'tmp.wav',wav");
    d2.setDevice("file:'tmp_after.wav',wav");
    d.setDataFormat(f);
    d1.setDataFormat(f);
    d2.setDataFormat(f);
    data.setSize(3 * freq); //testote 2 sekundy
    data.setSampleFrequency(freq);
    d.setFrequency(freq);
    d1.setFrequency(freq);
    d2.setFrequency(freq);
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
    data.saveRawDataToFile("raw_data.dat");
  }
  catch (TALSA::InvalidOperation inv)
  {
    std::cout << "Invalid operation: " << inv.getMessage() << "\n";
  }
  catch (TALSA::WrongArgument wa)
  {
    std::cout << "Wrong argument: " << wa.getMessage() << "\n";
  }

  //własna ekstrakcja cech
  data.setFrameLength(256, 160);
  data.test();
  int max = data.getWindowsNumber();
  //  std::vector < std::vector<double >> feature(max);
  std::vector<double> a;
  std::vector<double> formants;
  std::ofstream file("literaTEST.txt");

  //próba z użyciem binarnego wektora

  data.findPhonemeBorders();




  /*/  for (int i = 0; i < max; ++i)
    {
      if (data.isFrameWithSpeech(i)) // jest coś
      {
        file << i << ":\n";
        formants = data.get3Formants(i);
        for (auto f : formants)
        {
          file << f << "\t";
        }
   //     a = data.getMFCCFromFrame(i);
  //      a.push_back(data.getFrameEnergy(i));
  //      a.push_back(data.spectralMoment0() / 4000);
        a.clear();
        a.push_back(data.normalizedMoment1() / 4000);
        a.push_back(data.normalizedCentralMoment2()/ 8 / 1000000.0);
   //     a.push_back(data.normalizedCentralMoment3()/ 2 / 10000000000.0);
   //     feature[i] = a;
        for (auto i : a)
        {
          file << i << "\t";
        }
        file << "\n";
      }**/
  /*  else
    {
      feature[i] = std::vector<double>(13);
    }**/
  //}
  //liczenie pochodnych
  /** std::vector < std::vector<double >> delta(max);
   for (int i = 2; i < max - 2; ++i)
   {
     for (int j = 0; j < 13; ++j)
     {
       delta[i].push_back((2 * feature[i + 2][j] + feature[i + 1][j] - feature[i - 1][j] - 2 * feature[i - 2][j]) / 10);
     }
   }
   for (int i = 2; i < max - 2; ++i)
   {
     if (data.isFrameWithSpeech(i))
     {
       for (int j = 0; j < 13; ++j)
       {
         file << feature[i][j] << " " << delta[i][j] << " ";
         file << (2 * delta[i + 2][j] + delta[i + 1][j] - delta[i - 1][j] - 2 * delta[i - 2][j]) / 10 << " ";
       }
       file << "\n";
     }
   }*/

  file.close();

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
    std::ofstream file("litera2.txt");
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


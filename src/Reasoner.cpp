/* 
 * File:   Reasoner.cpp
 * Author: tomko
 * 
 * Created on 30 maj 2012, 18:47
 */

#include "../include/Reasoner.h"

#include <algorithm>

#include <iostream>

Reasoner::Reasoner()
{
//  network.loadNetworkFromFile("reasoner.net");
}

Reasoner::~Reasoner()
{
 
}

std::vector<Phoneme*> Reasoner::getPossibleLetters(std::vector<double>& from_speech, std::vector<double>& from_patterns, std::vector<Phoneme*> previous)
{
  std::vector<Phoneme*> ret;
  std::vector<Phoneme*> phonemes = Phoneme::getPhonemes();
  //szukanie max w speech
  std::vector<double>::iterator max_speech = std::max(from_speech.begin(), from_speech.end());
  std::vector<double>::iterator max_patterns = std::max(from_patterns.begin(), from_patterns.end());
  std::vector<double>::iterator it_speech = std::max(from_speech.begin(), from_speech.end());
  std::vector<double>::iterator it_patterns = std::max(from_patterns.begin(), from_patterns.end());
  std::vector<double> input(7);
  input[1] = *max_speech;
  input[2] = from_patterns[max_speech - from_speech.begin()];
  input[3] = from_speech[max_patterns - from_patterns.begin()];
  input[4] = *max_patterns;
  std::vector<double> out;
   
  for (auto p : phonemes)
  {
    input[0] = std::find(previous.begin(), previous.end(), p) == previous.end() ? 0 : 1;
    input[5] = *(it_speech++);
    input[6] = *(it_patterns++);

    //TMP
    for (auto i: input)
    {
      std::cout << i << " ";
    }
    std::cout << "\n";

   // network.setInput(input.begin(), input.end());
    /*/
    out = network.calcOutput();
    if (out[1] > 0.9)
    {
      ret.push_back(p);
    }**/
  }
}


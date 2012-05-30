/* 
 * File:   Phoneme.cpp
 * Author: tomko
 * 
 * Created on 29 maj 2012, 12:53
 */

#include "../include/Phoneme.h"
#include <cstring>
#include <stdexcept>

bool Phoneme::initialized = false;
std::vector<Phoneme*> Phoneme::phonemes = std::vector<Phoneme*>();

Phoneme::Phoneme(std::string s) : symbol(s)
{
}

Phoneme::~Phoneme()
{
}

std::string Phoneme::getStringFromPhonemes(std::vector<Phoneme*>* v)
{
  std::string tmp;
  for (auto p : *v)
  {
    tmp += p->symbol;
  }
  return tmp;
}

std::vector<Phoneme*> Phoneme::getPhonemesFromString(std::string s)
{
  int n = s.length();
  std::vector<Phoneme*> tmp;
  for (int i = 0; i < n; ++i)
  {
    try
    {
      if (islower(s.at(i + 1)))
      {
        tmp.push_back(Phoneme::getPhonemeFromString(s.substr(i, 2)));
        ++i;
        continue;
      }
    }
    catch (std::out_of_range e)
    {
      //nie ma potrzeby nic robić
    }
    tmp.push_back(Phoneme::getPhonemeFromString(s[i]));
  }
  return tmp;
}

Phoneme* Phoneme::getPhonemeFromString(std::string s)
{
  if (!initialized)
  {
    initialized = true;
    Phoneme::initPhonemes();
  }
  for (auto a : Phoneme::phonemes)
  {
    if (a->getSymbol() == s)
    {
      return a;
    }
  }
}

Phoneme* Phoneme::getPhonemeFromString(char c)
{
  char tmp[2];
  tmp[0] = c;
  tmp[1] = '\0';
  return getPhonemeFromString(tmp);
}

void Phoneme::initPhonemes()
{
  phonemes.push_back(new Phoneme("A"));
  phonemes.push_back(new Phoneme("B"));
  phonemes.push_back(new Phoneme("C"));
  phonemes.push_back(new Phoneme("Ci"));
  phonemes.push_back(new Phoneme("Cz"));
  phonemes.push_back(new Phoneme("D"));
  phonemes.push_back(new Phoneme("Dz"));
  phonemes.push_back(new Phoneme("E"));
  phonemes.push_back(new Phoneme("F"));
  phonemes.push_back(new Phoneme("G"));
  phonemes.push_back(new Phoneme("H"));
  phonemes.push_back(new Phoneme("I"));
  phonemes.push_back(new Phoneme("J"));
  phonemes.push_back(new Phoneme("K"));
  phonemes.push_back(new Phoneme("L"));
  phonemes.push_back(new Phoneme("Li"));
  phonemes.push_back(new Phoneme("M"));
  phonemes.push_back(new Phoneme("N"));
  phonemes.push_back(new Phoneme("O"));
  phonemes.push_back(new Phoneme("P"));
  phonemes.push_back(new Phoneme("R"));
  phonemes.push_back(new Phoneme("S"));
  phonemes.push_back(new Phoneme("Si"));
  phonemes.push_back(new Phoneme("Sz"));
  phonemes.push_back(new Phoneme("T"));
  phonemes.push_back(new Phoneme("U"));
  phonemes.push_back(new Phoneme("W"));
  phonemes.push_back(new Phoneme("Y"));
  phonemes.push_back(new Phoneme("Z"));
  phonemes.push_back(new Phoneme("Zy"));
  phonemes.push_back(new Phoneme("Zi"));
}

std::vector<Phoneme*> Phoneme::getPhonemes()
{
  return phonemes;
}
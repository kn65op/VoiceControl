/* 
 * File:   Recognizer.cpp
 * Author: tomko
 * 
 * Created on 29 maj 2012, 09:00
 */

#include "../include/Recognizer.h"

#include <fstream>

int Recognizer::letters_count = 31;
int Recognizer::params_count = 7;

Recognizer::Recognizer()
{
}

Recognizer::Recognizer(const Recognizer& orig)
{
}

Recognizer::~Recognizer()
{
}

void Recognizer::loadParameters()
{
  std::ifstream inf("zakres.txt", std::ios::in);
  std::string stmp;
  double dtmp;
  double d2tmp;
  std::vector<double> astmp;
  std::vector<double> bstmp;
  std::vector<double> avgstmp;
  for (int i = 0; i < letters_count; ++i)
  {
    astmp.clear();
    bstmp.clear();
    avgstmp.clear();
    inf >> stmp; //odczytanie litery
    letters.push_back(Phoneme::getPhonemeFromString(stmp));
    for (int i = 0; i < params_count; ++i)
    {
      inf >> dtmp; //odczytanie początku zakresu
      astmp.push_back(dtmp);
      inf >> d2tmp; //odczytanie końca zakresu
      bstmp.push_back(d2tmp);
      avgstmp.push_back((dtmp + d2tmp) / 2); //zapisanie średniej (środka przedziału)
    }
    as.push_back(astmp);
    bs.push_back(bstmp);
    avgs.push_back(avgstmp);
  }
  inf.close();
}

std::string Recognizer::getLastLetter()
{
  return last_letter;
}
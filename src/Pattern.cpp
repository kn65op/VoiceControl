/* 
 * File:   Pattern.cpp
 * Author: tomko
 * 
 * Created on 29 maj 2012, 08:43
 */

#include "../include/Pattern.h"

#include <fstream>
#include <stdexcept>
std::list<std::vector<Phoneme*>*> Pattern::patterns = std::list<std::vector<Phoneme*>*>();

Pattern::Pattern() : patterns_possible(patterns)
{
}

Pattern::Pattern(const Pattern& orig)
{
}

Pattern::~Pattern()
{
}

void Pattern::addPattern(std::vector<Phoneme*> s)
{
  patterns.push_back(new std::vector<Phoneme*>(s));
}

void Pattern::loadPatterns(std::string file)
{
  std::ifstream in(file, std::ios::in);
  std::string tmp;
  while (!in.eof())
  {
    in >> tmp;
    addPattern(Phoneme::getPhonemesFromString(tmp));
  }
}

void Pattern::savePatterns(std::string file)
{
  std::ofstream out(file, std::ios::out);
  for (auto a : patterns)
  {
    out << Phoneme::getStringFromPhonemes(a);
    out << "\n";
  }
}

double Pattern::getProbablityLetterPosition(Phoneme* l, int n)
{
  int count = 0;
  int all = 0;
  for (auto s : patterns_possible)
  {
    try
    {
      if (s->at(n) == l)
      {
        ++count;
      }
      ++all;
    }
    catch (std::out_of_range e)
    {
      //TODO: chyba nic
    }
  }
  return double(count / all);
}

double Pattern::getProbablityLetterPositionAndPrecedence(Phoneme* l, int n, Phoneme* s)
{
  int count = 0;
  int all = 0;
  for (auto p : patterns_possible)
  {
    try
    {
      if (p->at(n) == l && p->at(n - 1) == s)
      {
        ++count;
      }
      ++all;
    }
    catch (std::out_of_range e)
    {
      //TODO: chyba nic
    }
  }
  return double(count / all);
}

double Pattern::getProbablityLetterPrecedence(Phoneme* l, Phoneme* s)
{
  int count = 0;
  int all = 0;
  std::vector<Phoneme*>::iterator it, end;
  for (auto p : patterns_possible)
  {
    for(it = p->begin(), end = p->end() - 1; it != end; ++it)
    {
      try
      {
        if (*it == s && *(it + 1) == l)
        {
          ++count;
        }
        ++all;
      }
      catch (std::out_of_range e)
      {
        //TODO: chyba nic
      }
    }
  }
  return double(count / all);
}

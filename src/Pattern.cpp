/* 
 * File:   Pattern.cpp
 * Author: tomko
 * 
 * Created on 29 maj 2012, 08:43
 */

#include "../include/Pattern.h"

#include <fstream>
#include <stdexcept>
#include <algorithm>

//TODO usunąć
#include <iostream>

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
  for (auto p : s)
  {
    std::cout << p->getSymbol() << ":";
  }
  std::cout << "\n";
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
  patterns.pop_back();
}

void Pattern::loadPatterns(std::string file, Operator* op)
{
  std::ifstream in(file, std::ios::in);
  std::string tmp;
  std::string sop;
  while (!in.eof())
  {
    in >> tmp;
    in >> sop;
    addPattern(Phoneme::getPhonemesFromString(tmp));
    op->addAction(tmp, sop);
  }
  patterns.pop_back();
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
  if (all)
  {
    return double(count) / double(all);
  }
  return 0;
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
  if (all)
  {
    return double(count) / double(all);
  }
  return 0;
}

double Pattern::getProbablityLetterPrecedence(Phoneme* l, Phoneme* s)
{
  int count = 0;
  int all = 0;
  std::vector<Phoneme*>::iterator it, end;
  for (auto p : patterns_possible)
  {
    for (it = p->begin(), end = p->end() - 1; it != end; ++it)
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
  if (all)
  {
    return double(count) / double(all);
  }
  return 0;
}

std::vector<double> Pattern::getProbabilitiesLetterPosition(int n)
{
  std::vector<double> tmp;
  std::vector<Phoneme*> pho = Phoneme::getPhonemes();
  for (auto p : pho)
  {
    tmp.push_back(getProbablityLetterPosition(p, n));
  }
  return tmp;
}

std::vector<double> Pattern::getProbablitiesLetterPrecedence(Phoneme* s)
{
  std::vector<double> ret;
  std::vector<Phoneme*> pho = Phoneme::getPhonemes();
  for (auto p : pho)
  {
    ret.push_back(getProbablityLetterPrecedence(p, s));
  }
  return ret;
}

std::vector<double> Pattern::getProbablitiesLetterPrecedence(std::vector<Phoneme*> s)
{
  std::vector<double> ret;
  double tmp;
  std::vector<Phoneme*> pho = Phoneme::getPhonemes();
  for (auto p : pho)
  {
    tmp = 0;
    for (auto ss : s)
    {
      tmp += getProbablityLetterPrecedence(p, ss);
    }
    ret.push_back(tmp / s.size());
  }
  return ret;
}

void Pattern::limitPatterns(std::vector<Phoneme*> limiter, int pos)
{

  patterns_possible.remove_if([limiter, pos](std::vector<Phoneme*>* pat)
  {
                              return std::find(limiter.begin(), limiter.end(), pat->at(pos)) == limiter.end();
  });
}

bool Pattern::isPattern() const
{
  return patterns_possible.size() == 1;
}

std::string Pattern::getPattern() const
{
  return Pattern::convertToString(patterns_possible.front());
}

std::string Pattern::convertToString(std::vector<Phoneme*>* word)
{
  std::string ret;
  for (auto p : *word)
  {
    ret += p->getSymbol();
  }
  return ret;
}

void Pattern::guessWord(std::vector<std::vector<Phoneme* >> phonemes)
{

}

bool checkThis(std::vector<Phoneme*>* word, std::vector<std::vector<Phoneme* >> &phonemes, int pos_word, int pos_phonemes)
{
  for (auto p : phonemes[pos_phonemes])
  {
    try
    {
      if (word->at(pos_word) == p)
      {
        if (checkThis(word, phonemes, pos_word + 1, pos_phonemes + 1))
        {
          return true;
        }
      }
      else if (pos_word > 1)
      {
        if (word->at(pos_word - 1) == p)
        {
          if (checkThis(word, phonemes, pos_word, pos_phonemes + 1))
          {
            return true;
          }
        }
      }
    }
    catch (std::out_of_range e) //koniec wyrazu
    {
      for (auto it = phonemes.begin() + pos_phonemes + 1, end = phonemes.end(); it != end; ++it)
      {
        if (std::find(it->begin(), it->end(), word->back()) == it->end())
        {
          return false;
        }
      }
      return true;
    }
  }
  return false;
}

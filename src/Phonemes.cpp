/* 
 * File:   Phonemes.cpp
 * Author: tomko
 * 
 * Created on 16 maj 2012, 20:52
 */

#include <vector>

#include "../include/Phonemes.h"

std::vector<std::string> Phonemes::alphabet = std::vector<std::string>();

Phonemes::Phonemes()
{
}

Phonemes::Phonemes(const Phonemes& orig)
{
}

Phonemes::~Phonemes()
{
}

void Phonemes::initAlphabet()
{
  alphabet.push_back("A");
//  alphabet.push_back("Ai");
  alphabet.push_back("B");
  alphabet.push_back("C");
  alphabet.push_back("Ci");
  alphabet.push_back("Cz");
  alphabet.push_back("D");
  alphabet.push_back("Dz");
//  alphabet.push_back("Dzy");
 // alphabet.push_back("Dzi");
  alphabet.push_back("E");
 // alphabet.push_back("Ei");
  alphabet.push_back("F");
  alphabet.push_back("G");
  alphabet.push_back("H");
  alphabet.push_back("I");
  alphabet.push_back("J");
  alphabet.push_back("K");
  alphabet.push_back("L");
  alphabet.push_back("Li");
  alphabet.push_back("M");
  alphabet.push_back("N");
//  alphabet.push_back("Ni");
  alphabet.push_back("O");
  alphabet.push_back("P");
  alphabet.push_back("R");
  alphabet.push_back("S");
  alphabet.push_back("Si");
  alphabet.push_back("Sz");
  alphabet.push_back("T");
  alphabet.push_back("U");
  alphabet.push_back("W");
  alphabet.push_back("Y");
  alphabet.push_back("Z");
  alphabet.push_back("Zy");
  alphabet.push_back("Zi");
}

std::string Phonemes::getPhonem(int i)
{
  if (alphabet.empty())
  {
    initAlphabet();
  }
  return alphabet[i];
}
/* 
 * File:   Letter.cpp
 * Author: tomko
 * 
 * Created on 16 maj 2012, 20:48
 */

#include "../include/Letter.h"

Letter::Letter()
{
}

Letter::Letter(const Letter& orig)
{
}

Letter::~Letter()
{
}

std::vector<std::string> Letter::getPosobilities() const
{
  return posibilities;
}
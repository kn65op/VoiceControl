/* 
 * File:   Operator.cpp
 * Author: tomko
 * 
 * Created on 29 maj 2012, 21:42
 */

#include "../include/Operator.h"

//TODO usun
#include <iostream>

#include <fstream>
#include <stdexcept>

Operator::Operator()
{
}

Operator::Operator(const Operator& orig)
{
}

Operator::~Operator()
{
}

void Operator::addAction(std::string s, std::string action_code)
{
  map_patters_action.insert(std::pair<std::string, std::string>(s, action_code));
  if (action_code.substr(0, action_code.find('_')) == "open")
  {
    map_string.insert(std::pair<std::string, MemPointerString > (s, &Operator::runProgram));
  }
  else
  {
    map_void.insert(std::pair<std::string, MemPointer > (s, &Operator::someAction));
  }
}

void Operator::procedeAction(std::string s)
{
  try
  {
    MemPointer p = map_void.at(s);
    (this->*p)();
  }
  catch (std::out_of_range ex)
  {
    try
    {
      MemPointerString p = map_string.at(s);
      std::string tmp = map_patters_action.at(s);
      (this->*p)(tmp.substr(tmp.find('_') + 1));
    }
    catch (std::out_of_range ex)
    {
      //nothing to do
    }
  }
}

void Operator::someAction()
{
  std::cout << "JEAH\n";
}

void Operator::readActions(std::string filename)
{
  std::ifstream file(filename, std::ios::in);
  std::string pat, action;
  while (!file.eof())
  {
    file >> pat;
    file >> action;
    addAction(pat, action);
  }
}

void Operator::runProgram(std::string pro)
{
  if (!fork())
  {
    std::cout << execlp(pro.c_str(), pro.c_str(), NULL) << "\n";
    exit(-1);
  }
}
/* 
 * File:   Pattern.cpp
 * Author: tomko
 * 
 * Created on 29 maj 2012, 08:43
 */

#include "../include/Pattern.h"

std::vector<std::string*> Pattern::patterns = std::vector<std::string*>();

Pattern::Pattern() : patterns_possible(patterns)
{
}

Pattern::Pattern(const Pattern& orig)
{
}

Pattern::~Pattern()
{
}


/* 
 * File:   Letter.h
 * Author: tomko
 *
 * Created on 16 maj 2012, 20:48
 */

#ifndef LETTER_H
#define	LETTER_H

#include <vector>
#include <string>

#include "../include/Phonemes.h"

/**
 * Klasa obrazująca jedną literę rozpoznawania (nie jest to koniecznie jedna litera).
 */
class Letter
{
public:
  Letter();
  Letter(const Letter& orig);
  virtual ~Letter();
  template<class InputIterator> void setLetter(InputIterator begin, InputIterator end)
  {
    posibilities.clear();
    int i =0;
    for(; begin != end; ++begin)
    {
      if (*begin > 0.9)
      {
	posibilities.push_back(Phonemes::getPhonem(i));
      }
      ++i;
    }
  }

  std::vector<std::string> getPosobilities() const;
private:
/* Możliwości
 */
 std::vector<std::string> posibilities;
};

#endif	/* LETTER_H */


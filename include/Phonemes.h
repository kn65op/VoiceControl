/* 
 * File:   Phonemes.h
 * Author: tomko
 *
 * Created on 16 maj 2012, 20:52
 */

#ifndef PHONEMES_H
#define	PHONEMES_H

#include <string>
#include <vector>

class Phonemes
{
public:
  Phonemes();
  Phonemes(const Phonemes& orig);
  virtual ~Phonemes();
  /**
   * Funkcja zwracająca fonem będący na i-tej pozycji w alfabecie.
   * @param i Pozycja w alfabecie.
   * @return std::string będący na i-tej pozycji.
   */
  static std::string getPhonem(int i);
private:
  static std::vector<std::string> alphabet;
  static void initAlphabet();
};

#endif	/* PHONEMES_H */


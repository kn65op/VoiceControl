/* 
 * File:   Phoneme.h
 * Author: tomko
 *
 * Created on 29 maj 2012, 12:53
 */

#ifndef PHONEME_H
#define	PHONEME_H

#include <vector>
#include <string>
/**
 * Klasa reprezentująca fonem.
 */
class Phoneme
{
public:
  Phoneme();
  Phoneme(const Phoneme& orig);
  virtual ~Phoneme();
  /**
   * Funkcja czytająca fonem z std::string.
   * @param in std::string z zapisem fonemów,
   * @return Wektor przeczytanych fonemów.
   */
  static std::vector<Phoneme*> getPhonemesFromString(std::string s);
  /**
   * Funkcja zapisująca wektor fonemów do stringa.
   * @param v Wektor fonemów.
   * @return std::string z zapisaem fonemów.
   */
  static std::string getStringFromPhonemes(std::vector<Phoneme*>* v);
private:
  std::string symbol;
};

#endif	/* PHONEME_H */


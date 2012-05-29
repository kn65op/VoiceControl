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
  Phoneme(std::string s);
  Phoneme(const Phoneme& orig) = delete;
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
  /**
   * Funkcja zwracająca wskaźnik do fonemu oznaczonego danym stringiem.
   * @param std::string oznaczający jeden fonem.
   * @return Wskaźnik do fonemu.
   */
  static Phoneme* getPhonemeFromString(std::string s);
  /**
   * Funkcja zwracająca wskaźnik do fonemu oznaczonego danym znakiem.
   * @param char oznaczający jeden fonem.
   * @return Wskaźnik do fonemu.
   */
  static Phoneme* getPhonemeFromString(char c);
  /**
   * Funkcja zwracająca symbol opisujący dany fonem.
   * @return std::string odpowiadający symbolowi.
   */
  std::string getSymbol() const
  {
    return symbol;
  }
private:
  std::string symbol;
  static std::vector<Phoneme*> phonemes;

  /**
   * Funkcja inicjująca zestaw fonemów.
   */
  static void initPhonemes();
  /** czy zainicjowano?
   */
  static bool initialized;
};

#endif	/* PHONEME_H */


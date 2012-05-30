/* 
 * File:   Pattern.h
 * Author: tomko
 *
 * Created on 29 maj 2012, 08:43
 */

#ifndef PATTERN_H
#define	PATTERN_H

#include "Phoneme.h"

#include <vector>
#include <list>
#include <string>

/**
 * Klasa reprezentująca słowo (lub słowa) do rozpoznania.
 */
class Pattern
{
public:
  Pattern();
  Pattern(const Pattern& orig);
  virtual ~Pattern();
  /**
   * Funkcja licząca prawdopodobieństwo wystąpienia fonemu na danej pozycji we wzorcach.
   * @param l Phoneme* oznaczający fonem.
   * @param n Pozycja fonemu.
   * @return Prawdopodobieństwo.
   */
  double getProbablityLetterPosition(Phoneme* l, int n);
  /**
   * Funkcja licąca prawdopodobieństwa wystąpienia fonemów na danej pozycji we wzorcach.
   * @param n Pozycja fonemu.
   * @return Wektor prawdopodobieństw.
   */
  std::vector<double> getProbabilitiesLetterPosition(int n);
  /**
   * Funkcja licząca prawdopodobieństwo wystąpnienia fonemu na danej pozycji i przy danym fonemie poprzedzającym.
   * @param l Phoneme* oznaczający fonem.
   * @param n Pozycja fonemu.
   * @param s Phoneme* oznaczający fonem poprzedzający.
   * @return Prawdopodobieństwo.
   */
  double getProbablityLetterPositionAndPrecedence(Phoneme* l, int n, Phoneme* s);
  /**
   * Funkcja licząca prawdopodobieństwa wystąpnienia fonemów na danej pozycji i przy danym fonemie poprzedzającym.
   * @param n Pozycja fonemu.
   * @param s Phoneme* oznaczający fonem poprzedzający.
   * @return Wektor prawdopodobieństw.
   */
  double getProbablitiesLetterPositionAndPrecedence(int n, Phoneme* s);
  /**
   * Funkcja licząca prawdopodobieństwo wystąpienia fonemu przy danym fonemie poprzedzającym.
   * @param l Phoneme* oznaczający fonem.
   * @param s Phoneme* oznaczający fonem poprzedzający.
   * @return  Prawdopodobieństwo.
   */
  double getProbablityLetterPrecedence(Phoneme* l, Phoneme* s);
  /**
   * Funkcja licząca prawdopodobieństwa wystąpienia fonemów przy danym fonemie poprzedzającym.
   * @param s Phoneme* oznaczający fonem poprzedzający.
   * @return  Wektor prawdopodobieństw.
   */
  double getProbablitiesLetterPrecedence(Phoneme* s);
  /**
   * Funkcja dodająca do zbioru wzorców nowy.
   * @param s std::vector<Phoneme*> oznaczający nowy wzorzec.
   */
  static void addPattern(std::vector<Phoneme*> s);
  /**
   * Funkcja czytająca wzorce z pliku.
   * @param file Nazwa pliku.
   */
  static void loadPatterns(std::string file);
  /**
   * Funkcja zapisujące wzorce do pliku.
   * @param file Nazwa pliku.
   */
  static void savePatterns(std::string file);
  /**
   * Funkcja ograniczająca możliwe wzorce.
   * @param limiter Fragment, który musi być dopasowany.
   * @param pos Pozycja fragmentu.
   */
  void limitPatters(std::string limiter, int pos);
  /**
   * Funkcja zwracająca informację, czy są jeszcze jakieś wzorce po ograniczeniach.
   * @return true jeśli są, false w przeciwnym wypadku.
   */
  bool isPattern() const;
  /**
   * Funkcja zwracająca wzorzec jeśli jest tylko jeden.
   * @return Jedyny wzorzec jaki pozostał lub pusty string jeśli nie ma żadnego wzorca lub jest ich wiele.
   */
  std::string getPattern() const;

private:
  static std::list<std::vector<Phoneme*>*> patterns;
  std::list<std::vector<Phoneme*>*> patterns_possible;
};

#endif	/* PATTERN_H */


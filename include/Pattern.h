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
   * Funkcja licząca prawdopodobieństwo wystąpnienia fonemu na danej pozycji i przy danym fonemie poprzedzającym.
   * @param l Phoneme* oznaczający fonem.
   * @param n Pozycja fonemu.
   * @param s Phoneme* oznaczający fonem poprzedzający.
   * @return Prawdopodobieństwo.
   */
  double getProbablityLetterPositionAndPrecedence(Phoneme* l, int n, Phoneme* s);
  /**
   * Funkcja licząca prawdopodobieństwo wystąpienia fonemu przy danym fonemie poprzedzającym.
   * @param l Phoneme* oznaczający fonem.
   * @param s Phoneme* oznaczający fonem poprzedzający.
   * @return  Prawdopodobieństwo.
   */
  double getProbablityLetterPrecedence(Phoneme* l, Phoneme* s);
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
private:
  static std::list<std::vector<Phoneme*>*> patterns;
  std::list<std::vector<Phoneme*>*> patterns_possible;
};

#endif	/* PATTERN_H */


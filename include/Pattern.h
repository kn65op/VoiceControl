/* 
 * File:   Pattern.h
 * Author: tomko
 *
 * Created on 29 maj 2012, 08:43
 */

#ifndef PATTERN_H
#define	PATTERN_H

#include <vector>
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
   * @param l std::string oznaczający fonem.
   * @param n Pozycja fonemu.
   * @return Prawdopodobieństwo.
   */
  double getProbablityLetterPosition(std::string l, int n);
  /**
   * Funkcja licząca prawdopodobieństwo wystąpnienia fonemu na danej pozycji i przy danym fonemie poprzedzającym.
   * @param l std::string oznaczający fonem.
   * @param n Pozycja fonemu.
   * @param s std::string oznaczający fonem poprzedzający.
   * @return Prawdopodobieństwo.
   */
  double getProbablityLetterPositionAndPrecedence(std::string l, int n, std::string s);
  /**
   * Funkcja licząca prawdopodobieństwo wystąpienia fonemu przy danym fonemie poprzedzającym.
   * @param l std::string oznaczający fonem.
   * @param s std::string oznaczający fonem poprzedzający.
   * @return  Prawdopodobieństwo.
   */
  double getProbablityLetterPrecedence(std::string s, td::string s);
  /**
   * Funkcja dodająca do zbioru wzorców nowy.
   * @param s std::string oznaczający nowy wzorzec.
   */
  static void addPattern(std::string s);
  /**
   * Funkcja czytająca wzorce z pliku.
   * @param file Nazwa pliku.
   */
  static void loadPatterns(std::string file);
private:
  static std::vector<std::string*> patterns;
  std::vector<std::string*> patterns_possible;
};

#endif	/* PATTERN_H */


/* 
 * File:   Recognizer.h
 * Author: tomko
 *
 * Created on 29 maj 2012, 09:00
 */

#ifndef RECOGNIZER_H
#define	RECOGNIZER_H

#include <string>
#include <list>
#include <vector>

/**
 * Klasa rozpoznawacza, która określa prawdopodobieństwo wystąpienia danego fonemu.
 */
class Recognizer
{
public:
  Recognizer();
  Recognizer(const Recognizer& orig);
  virtual ~Recognizer();

  /**
   * Funkcja wczytująca dane o fonemach i zakresach ich wartości z pliku.
   */
  void loadParameters();

  /**
   * Funkcja zwracająca ostatnio rozpoznany fonem.
   * @return std::string z ostatno rozpoznanym fonemem.
   */
  std::string getLastLetter();
  /**
   * Funkcja licząca prawdopodobieństwa wystąpienia wszystkich fonemów.
   * @param begin iterator do początku parametrów.
   * @param end iterator do końca parametrów.
   * @return std::vector<double> z prawdopodobieństwami dla kolejnych liter.
   */
  template <class InputIterator> std::vector<double> getProbabilities(InputIterator begin, InputIterator end)
  {
    last_letter = "";
    std::vector<double> tmp(letters_count);
    InputIterator it;
    double dtmp;
    double max = 0;
    double d2tmp;
    for (int i = 0; i < letters_count; ++i) //dla każdej litery
    {
      dtmp = 0;
      it = begin;
      for (int j = 0; j < params_count; ++j) //dla każdego parametru
      {
        if (it == end)
        {
          return std::vector<double>();
        }
        if (*it < avgs[i][j]) //mniejsze od średniej
        {
          if (*it < as[i][j]) //poza zakresem
          {
            d2tmp = (as[i][j] - *it) / (avgs[i][j] - as[i][j]) * 2;
            dtmp += d2tmp > 1 ? 0 : 0.5 - 0.5 * d2tmp;
          }
          else //w zakresie
          {
            dtmp += 1 - (avgs[i][j] - *it) / (avgs[i][j] - as[i][j]) * 0.5;
          }
        }
        else //większe od średniej
        {
          if (*it > bs[i][j]) //poza zakresem
          {
            d2tmp = (*it - bs[i][j]) / (bs[i][j] - avgs[i][j]) * 2;
            dtmp += d2tmp > 1 ? 0 : 0.5 - 0.5 * d2tmp;
          }
          else //w zakresie
          {
            dtmp += 1 - (*it - avgs[i][j]) / (bs[i][j] - avgs[i][j]) * 0.5;
          }
        }
        ++it;
      }
      tmp[i] = dtmp / params_count;
      if (tmp[i] > max)
      {
	max = tmp[i];
	last_letter = letters[i];
      }
    }
    return tmp;
  }
private:
  std::vector<std::string> letters;
  std::vector<std::vector<double >> as;
  std::vector<std::vector<double >> bs;
  std::vector<std::vector<double >> avgs;

  std::string last_letter;
  static int letters_count;
  static int params_count;
};

#endif	/* RECOGNIZER_H */


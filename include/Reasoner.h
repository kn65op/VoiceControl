/* 
 * File:   Reasoner.h
 * Author: tomko
 *
 * Created on 30 maj 2012, 18:47
 */

#ifndef REASONER_H
#define	REASONER_H

#include <vector>

#include <NeuralNetwork.h>
#include <LinearActivationFunction.h>

#include "Phoneme.h"

class Reasoner
{
public:
  Reasoner();
  Reasoner(const Reasoner& orig) = delete;
  virtual ~Reasoner();

  std::vector<Phoneme*> getPossibleLetters(std::vector<double> & from_speech, std::vector<double> & from_patterns, std::vector<Phoneme*> previous);
private:
  NeuralNetwork<double, LinearActivationFunction <double> > network;

};

#endif	/* REASONER_H */


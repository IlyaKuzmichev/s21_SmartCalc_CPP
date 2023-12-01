/* ==========================================================================*/
/* Copyright 2023 © Moscow, Russian Federaion
 *
 * This file contains Original Code created by
 * Ilya Kuzmichev aka wilmerno.
 *
 * The Original Code and all software developed in the process of
 * participation on learning by experimental programming educational method.
 * The whole methodology was developed and distributed by
 * Autonomous non-profit organization «School 21» (ANO «School 21»).
 *
 * Redistribution and use of this file, its parts, or entire project
 * are permitted by confirmation of its original creator.
 */
/* ==========================================================================*/

/**
 * \author Ilya Kuzmichev aka Wilmer Norma
 * \mainpage
 * Basicly OOP Smart Calculator, using MVC pattern and some SOLID principles
 * with GUI realised on QT Creator with qcustomplot.h usage for graphics
 *
 * Calculating arbitrary bracketed arithmetic expressions in infix notation.
 *
 * Calculate arbitrary bracketed arithmetic expressions in infix notation with
 * substitution of the value of the variable x as a number.
 *
 * Plotting a graph of a function given by an expression in infix notation with
 * the variable x (with coordinate axes, mark of the used scale and an adaptive
 * grid)
 *
 * Credit and Deposit Calculator
 */

/*!
\file
\brief Header file of main calculation model
*/
#ifndef SMARTCALC_MODEL_MODELCALC_H_
#define SMARTCALC_MODEL_MODELCALC_H_

#include <string>
#include <utility>
#include <vector>

#include "model/exception.h"
#include "model/stringTokenizer.h"
#include "model/token.h"

namespace s21 {
/*!
\brief Class with Reverse Polish Notation Calculator realisation
\author wilmerno
\version 1.0
\date 11/2023
*/
class SmartCalc {
 public:
  SmartCalc() = default;
  explicit SmartCalc(const std::string& l, double arg);

  void SetLexeme(const std::string& l) noexcept;
  void SetArg(const double arg) noexcept;
  double CountLexeme();

 protected:
  void PostfixNotation();
  double CountNotation();
  void ClearStructures() noexcept;

  std::string lexeme_;
  double arg_ = 0;
  std::vector<Token> tokens_;
  std::vector<Token> notation_;
  uint32_t pointsQuantity = 100000.;
};

}  // namespace s21

#endif  // SMARTCALC_MODEL_MODELCALC_H_

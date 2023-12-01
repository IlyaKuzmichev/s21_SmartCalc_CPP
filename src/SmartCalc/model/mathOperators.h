/*!
\file
\brief Header file with mathematical operators handler
*/
#ifndef SMARTCALC_MODEL_MATHOPERATORS_H_
#define SMARTCALC_MODEL_MATHOPERATORS_H_

#include <cmath>
#include <functional>
#include <unordered_map>

#include "model/exception.h"
#include "model/token.h"

namespace s21 {

double Plus(double a, double b) { return a + b; }

double Minus(double a, double b) { return a - b; }

double Mul(double a, double b) { return a * b; }

double Div(double a, double b) { return a / b; }

using MathOperator = std::function<double(double, double)>;

/*!
\brief Class that helps to apply math operators by a given symbol with proxy
enum ofc \author wilmerno \version 1.0 \date 11/2023
*/
class MathOperators {
 public:
  MathOperators() {
    operators[Lexeme::kPlus] = static_cast<double (*)(double, double)>(Plus);
    operators[Lexeme::kMinus] = static_cast<double (*)(double, double)>(Minus);
    operators[Lexeme::kMul] = static_cast<double (*)(double, double)>(Mul);
    operators[Lexeme::kDiv] = static_cast<double (*)(double, double)>(Div);
    operators[Lexeme::kMod] =
        static_cast<double (*)(double, double)>(std::fmod);
    operators[Lexeme::kPow] = static_cast<double (*)(double, double)>(std::pow);
  }
  /*!
  \brief Function to call math operators
  \param[in] lex Operator from enum
  \param[in] argL First argument
  \param[in] argR Second argument
  \returns Result of applied math operator for given arguments
  */
  double CallOperator(const Lexeme lex, double argL, double argR) const {
    auto it = operators.find(lex);
    if (it != operators.end()) {
      return it->second(argL, argR);
    } else {
      throw(s21::Exception("Invalid operator for our calculator"));
    }
  }

 private:
  std::unordered_map<Lexeme, MathOperator> operators;
};

}  // namespace s21

#endif  // SMARTCALC_MODEL_MATHOPERATORS_H_

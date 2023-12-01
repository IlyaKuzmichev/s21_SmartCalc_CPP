/*!
\file
\brief Header file with mathematical functions handler
*/
#ifndef SMARTCALC_MODEL_MATHFUNCTIONS_H_
#define SMARTCALC_MODEL_MATHFUNCTIONS_H_

#include <cmath>
#include <functional>
#include <unordered_map>

#include "model/exception.h"
#include "model/token.h"

namespace s21 {

double powUnary(double arg) { return arg * (-1); }

using MathFunction = std::function<double(double)>;

/*!
\brief Class that helps to apply math functions by a given name
\author wilmerno
\version 1.0
\date 11/2023
*/
class MathFunctions {
 public:
  MathFunctions() {
    functions[Lexeme::kSin] = static_cast<double (*)(double)>(std::sin);
    functions[Lexeme::kCos] = static_cast<double (*)(double)>(std::cos);
    functions[Lexeme::kTan] = static_cast<double (*)(double)>(std::tan);
    functions[Lexeme::kAsin] = static_cast<double (*)(double)>(std::asin);
    functions[Lexeme::kAcos] = static_cast<double (*)(double)>(std::acos);
    functions[Lexeme::kAtan] = static_cast<double (*)(double)>(std::atan);
    functions[Lexeme::kSqrt] = static_cast<double (*)(double)>(std::sqrt);
    functions[Lexeme::kLn] = static_cast<double (*)(double)>(std::log);
    functions[Lexeme::kLog] = static_cast<double (*)(double)>(std::log10);
    functions[Lexeme::kUnMinus] = static_cast<double (*)(double)>(powUnary);
  }
  /*!
  \brief Function to call math functions
  \param[in] lex Short name of the function (from enum class)
  \param[in] arg Argument for the function to be apply on
  \returns Result of applied math function for given argument
  */
  double CallFunction(const Lexeme lex, double arg) const {
    auto it = functions.find(lex);
    if (it != functions.end()) {
      return it->second(arg);
    } else {
      throw(s21::Exception("Invalid function for our calculator"));
    }
  }

 private:
  std::unordered_map<Lexeme, MathFunction> functions;
};

}  // namespace s21

#endif  // SMARTCALC_MODEL_MATHFUNCTIONS_H_

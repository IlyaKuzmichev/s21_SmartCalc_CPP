/*!
\file
\brief Header file with realisation of RPN Calculator Controller
*/
#ifndef SRC_CONTROLLER_CONTROLLERCALC_H_
#define SRC_CONTROLLER_CONTROLLERCALC_H_

#include <string>

#include "model/modelCalc.h"

namespace s21 {
/*!
\brief Class of controller for calculator
\author wilmerno
\version 1.0
\date 11/2023
*/
class ControllerCalc {
 public:
  /*!
  \brief Puts lexeme from view to model class
  \param[in] l Transfering string(lexeme)
  */
  void SetLexeme(std::string& l) { calc_.SetLexeme(l); }

  /*!
  \brief Puts argument from view to model class
  \param[in] a Transfering argument
  */
  void SetArg(double a) { calc_.SetArg(a); }

  /*!
  \brief Counts the expression
  \return Result of expression, calculeted in model
  */
  double Count() { return calc_.CountLexeme(); }

 private:
  SmartCalc calc_;
};
}  // namespace s21

#endif  // SRC_CONTROLLER_CONTROLLERCALC_H_

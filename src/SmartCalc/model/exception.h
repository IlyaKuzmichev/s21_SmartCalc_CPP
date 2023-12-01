/*!
\file
\brief Header file with user Exceptions realisation
*/
#ifndef SMARTCALC_MODEL_EXCEPTION_H_
#define SMARTCALC_MODEL_EXCEPTION_H_

#include <string>

namespace s21 {
/*!
\brief Class of user's Exceptions realisation
\author wilmerno
\version 1.0
\date 11/2023
*/
class Exception {
 public:
  explicit Exception(const std::string& msg) : msg_(msg) {}

  std::string GetMessage() const { return (msg_); }

 private:
  std::string msg_;
};
}  // namespace s21

#endif  //  SMARTCALC_MODEL_EXCEPTION_H_

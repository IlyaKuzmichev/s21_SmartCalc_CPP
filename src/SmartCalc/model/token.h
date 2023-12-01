#ifndef SMARTCALC_MODEL_TOKEN_H_
#define SMARTCALC_MODEL_TOKEN_H_

namespace s21 {
/**
 * Lexeme
 * @brief enum for lexeme tokens
 */
enum class Lexeme {
  kPlus = 1,
  kMinus,
  kUnMinus,
  kMul,
  kDiv,
  kMod,
  kPow,
  kSin,
  kCos,
  kTan,
  kAsin,
  kAcos,
  kAtan,
  kSqrt,
  kLn,
  kLog,
  kOpenBracket,
  kCloseBracket
};

/**
 * LexemeType
 * @brief enum for lexeme token types
 */
enum class LexemeType {
  kBracket = 1,
  kOperator,
  kFunction,
  kUnMinus,
  kNumber,
  kVariable
};

/**
 * Priority
 * @brief enum for lexeme token's priority
 */
enum class Priority {
  kFirst = 1,  ///> basic + and -
  kSecond,     ///> * and / and mod
  kThird,      ///> unary -
  kFourth,     ///> ^
  kFifth,      ///> functions
  kSixth       ///> brackets
};

/**
 * Token
 * @brief Lexeme token structure
 */
struct Token {
  LexemeType type;    ///> type of token
  Lexeme lexeme;      ///> symbols of lexeme
  Priority priority;  ///> operand/operator priority
  double value;       ///> value if number
};
}  // namespace s21

#endif  // SMARTCALC_MODEL_TOKEN_H_

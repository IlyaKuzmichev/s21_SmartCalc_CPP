/*!
\file
\brief Header file of Main Window of our application
*/
#ifndef SMARTCALC_VIEW_VIEW_H
#define SMARTCALC_VIEW_VIEW_H

#include <QMainWindow>
#include <memory>

#include "controller/controllerCalc.h"
#include "controller/controllerCredit.h"
#include "controller/controllerDebit.h"
#include "view/graphview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace s21 {
/*!
\brief Enum for different periodicity
*/
typedef enum {
  kNone = 0,     ///> never or in the end
  kMonth = 1,    ///> every month
  kQuarter = 3,  ///> every quarter
  kHalf = 6,     ///> every half of the year
  kYear = 12     ///> every year
} Periodicity;

/*!
\brief Class for UI (MainWindow of the application)
\author wilmerno
\version 1.0
\date 11/2023
*/
class View : public QMainWindow {
  Q_OBJECT

 public:
  explicit View(QWidget *parent = nullptr);
  ~View();

 private slots:
  /*!
  \brief Puts simple symbol from button to the lineEdit(screen of our
  calculator)
  */
  void PressCalc();

  /*!
  \brief Puts name of the function with open bracket from pushed button to the
  lineEdit(screen of our calculator)
  */
  void PressFunc();

  /*!
  \brief Button erases expression from the screen
  */
  void on_button_ac_clicked();

  /*!
  \brief Button erases last symbol from the screen
  */
  void on_button_backspace_clicked();

  /*!
  \brief Button equal, that initializes action of calculation
  */
  void on_button_eq_clicked();

  /*!
  \brief Button that initialises drawing of the graph with given expression
  */
  void on_button_graph_clicked();

  /*!
  \brief Calculate credit
  */
  void on_button_calculate_clicked();

  /*!
  \brief Calculate deposit
  */
  void on_button_calculate_depo_clicked();

  /*!
  \brief Slot on changing deposit ComboBox
  */
  void on_combo_deposit_currentIndexChanged(int index);

  /*!
  \brief Slot on changing withdrawal ComboBox
  */
  void on_combo_withdrawal_currentIndexChanged(int index);

 private:
  /*!
  \brief Function sets validators for all lineEdits in the UI
  */
  void SetValidators();

  /*!
  \brief Function establishes connections from signals to slots
  */
  void SetSlots();

  /*!
  \brief Add shortcut for button "equal" to several buttons (enter, equal and
  return) on keyboard
  */
  void AddShortcutForEq();

  /*!
  \brief Check all lineEdits in Deposit calculator is correct
  */
  bool CheckInputDeposit();

  /*!
  \brief Common functions to associate enum Periodicity with index of ComboBox
  */
  uint32_t SetPeriodicity(int index);

  Ui::View *ui;
  GraphView *graph_;
  s21::ControllerCalc contCalc_;
  s21::ControllerCredit contCredit_;
  s21::ControllerDebit contDebit_;

  std::unique_ptr<QRegularExpressionValidator> validateDouble_;
  std::unique_ptr<QRegularExpressionValidator> validatePositiveDouble_;
  std::unique_ptr<QRegularExpressionValidator> validateInteger_;
};

}  // namespace s21
#endif  // SMARTCALC_VIEW_VIEW_H

#ifndef AMERICANOPTIONFORM_H
#define AMERICANOPTIONFORM_H

#include "algorithm/treesimulator.h"
#include <QDialog>

namespace Ui {
class AmericanOptionForm;
}

class AmericanOptionForm : public QDialog
{
    Q_OBJECT

public:
    explicit AmericanOptionForm(QWidget *parent = nullptr);
    ~AmericanOptionForm();
    const TreeSimulator &simulator() const;
    void setSimulator(const TreeSimulator &newSimulator);

private slots:
    void on_AbuttonBox_accepted();

private:
    Ui::AmericanOptionForm *ui;
    TreeSimulator m_simulator;
};

#endif // AMERICANOPTIONFORM_H

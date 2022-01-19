#ifndef PATHDEPENDENTMC_H
#define PATHDEPENDENTMC_H

#include <QDialog>
#include "algorithm/pathdependentmcsimulator.h"

namespace Ui {
class PathDependentMC;
}

class PathDependentMC : public QDialog
{
    Q_OBJECT

public:
    explicit PathDependentMC(QWidget *parent = nullptr);
    ~PathDependentMC();

    const PathDependentMCSimulator &simulator() const;
    void setSimulator(const PathDependentMCSimulator &newSimulator);

private slots:
    void on_pdButtonBox_accepted();
    void on_pdButtonBox_rejected();

private:
    Ui::PathDependentMC *ui;
    PathDependentMCSimulator m_simulator;
};

#endif // PATHDEPENDENTMC_H

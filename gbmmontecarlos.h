#ifndef GBMMONTECARLOS_H
#define GBMMONTECARLOS_H

#include <QDialog>
#include "algorithm/montecarlossimulator.h"

namespace Ui {
class GbmMonteCarlos;
}

class GbmMonteCarlos : public QDialog
{
    Q_OBJECT

public:
    explicit GbmMonteCarlos(QWidget *parent = nullptr);
    ~GbmMonteCarlos();

    const MonteCarlosSimulator &simulator() const;
    void setSimulator(const MonteCarlosSimulator &newSimulator);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::GbmMonteCarlos *ui;
    // object that can run the monte carlos simulation
    MonteCarlosSimulator m_simulator;
};

#endif // GBMMONTECARLOS_H

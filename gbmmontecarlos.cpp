#include "gbmmontecarlos.h"
#include "ui_gbmmontecarlos.h"

GbmMonteCarlos::GbmMonteCarlos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GbmMonteCarlos)
{
    ui->setupUi(this);
}

GbmMonteCarlos::~GbmMonteCarlos()
{
    delete ui;
}

const MonteCarlosSimulator &GbmMonteCarlos::simulator() const
{
    return m_simulator;
}

void GbmMonteCarlos::setSimulator(const MonteCarlosSimulator &newSimulator)
{
    m_simulator = newSimulator;
}

void GbmMonteCarlos::on_buttonBox_accepted()
{
    m_simulator.setType((ui->comboOptionType->currentText()).toStdString());
    m_simulator.setS(ui->SpinS->value());
    m_simulator.setK(ui->SpinK->value());
    m_simulator.setR(ui->SpinR->value());
    m_simulator.setT(ui->SpinT->value());
    m_simulator.setSigma(ui->SpinSigma->value());
    m_simulator.setSimulations(ui->SpinSimulations->value());
    accept();
}

void GbmMonteCarlos::on_buttonBox_rejected()
{
    reject();
}


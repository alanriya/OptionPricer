#include "pathdependentmc.h"
#include "ui_pathdependentmc.h"

PathDependentMC::PathDependentMC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PathDependentMC)
{
    ui->setupUi(this);
}

PathDependentMC::~PathDependentMC()
{
    delete ui;
}

const PathDependentMCSimulator &PathDependentMC::simulator() const
{
    return m_simulator;
}

void PathDependentMC::setSimulator(const PathDependentMCSimulator &newSimulator)
{
    m_simulator = newSimulator;
}


void PathDependentMC::on_pdButtonBox_accepted()
{

    m_simulator.setS(ui->PdSpinS->value());
    m_simulator.setK(ui->PdSpinK->value());
    m_simulator.setSigma(ui->PdSpinSigma->value());
    m_simulator.setR(ui->PdSpinR->value());
    m_simulator.setT(ui->PdSpinT->value());
    m_simulator.setD(ui->PdSpinD->value());
    m_simulator.setSteps(ui->PdSpinNSteps->value());
    m_simulator.setSimulations(ui->PdSpinSimulations->value());
    m_simulator.setType((ui->PdComboOptionType->currentText()).toStdString());
    accept();
}


void PathDependentMC::on_pdButtonBox_rejected()
{
    reject();
}


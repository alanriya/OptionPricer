#include "americanoptionform.h"
#include "ui_americanoptionform.h"

AmericanOptionForm::AmericanOptionForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AmericanOptionForm)
{
    ui->setupUi(this);
}

AmericanOptionForm::~AmericanOptionForm()
{
    delete ui;
}

const TreeSimulator &AmericanOptionForm::simulator() const
{
    return m_simulator;
}

void AmericanOptionForm::setSimulator(const TreeSimulator &newSimulator)
{
    m_simulator = newSimulator;
}




void AmericanOptionForm::on_AbuttonBox_accepted()
{
  m_simulator.setType((ui->AComboOptionType->currentText()).toStdString());
  m_simulator.setS(ui->ASpinS->value());
  m_simulator.setK(ui->ASpinK->value());
  m_simulator.setR(ui->ASpinR->value());
  m_simulator.setT(ui->ASpinT->value());
  m_simulator.setD(ui->ASpinD->value());
  m_simulator.setSigma(ui->ASpinSigma->value());
  m_simulator.setSteps(ui->ASpinNSteps->value());
}


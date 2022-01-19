#include "maininterface.h"
#include "./ui_maininterface.h"
#include "utilities/qcustomplot.h"
#include <QVector>

MainInterface::MainInterface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainInterface)
{
    ui->setupUi(this);
//    QVector<double> x(101), y(101); // initialize with entries 0..100
//    for (int i=0; i<101; ++i)
//    {
//      x[i] = i/50.0 - 1; // x goes from -1 to 1
//      y[i] = x[i]*x[i]; // let's plot a quadratic function
//    }


//    ui->ScenarioPlot->addGraph();
//    ui->ScenarioPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
//    ui->ScenarioPlot->graph()->setLineStyle(QCPGraph::lsLine);

//    // give the axes some labels:
//    ui->ScenarioPlot->xAxis->setLabel("x");
//    ui->ScenarioPlot->yAxis->setLabel("y");
//    // set axes ranges, so we see all data:
//    ui->ScenarioPlot->xAxis->setRange(-1, 1);
//    ui->ScenarioPlot->yAxis->setRange(0, 1);

//    // set interactivity:
//    ui->ScenarioPlot->setInteraction(QCP::iRangeDrag, true);
//    ui->ScenarioPlot->setInteraction(QCP::iRangeZoom, true);
//    ui->ScenarioPlot->setInteraction(QCP::iSelectPlottables, true);

//    ui->ScenarioPlot->graph(0)->setData(x, y);
//    ui->ScenarioPlot->rescaleAxes();
//    ui->ScenarioPlot->replot();
}

MainInterface::~MainInterface()
{
    delete ui;
}

void MainInterface::GbmSimulate(){
    ui->MCResults->clear();
    ui->MCResults->setReadOnly(true);
    QString result;
    result+="------------------------Results for "+  QString::fromStdString((m_simulator.type())) + "-------------------------\r\n";
    m_simulator.runSimulation();
    for (unsigned i=0; i < m_simulator.results().size(); i++){
        std::vector<double> current_result = m_simulator.results()[i];
        result+=("Simulation Count: " + QString::number(current_result[1])+ ", estimated price: " + QString::number(current_result[0])) + "\r\n";
    }
    ui->MCResults->setPlainText(result);
}

void MainInterface::pathDependentSimulate()
{
    ui->MCExoticResults->clear();
    ui->MCExoticResults->setReadOnly(true);
    m_pd_simulator.runSimulation();
    QString result;
    result+="------------------------Results for "+  QString::fromStdString(m_pd_simulator.type()) + "-------------------------\r\n";
    for (unsigned i=0; i < m_pd_simulator.results().size(); i++){
        std::vector<double> current_result = m_pd_simulator.results()[i];
        result+=("Simulation Count: " + QString::number(current_result[1])+ ", estimated price: " + QString::number(current_result[0])) + "\r\n";
    }
    ui->MCExoticResults->setPlainText(result);
}

void MainInterface::AmericanTreeSimulate()
{
    ui->AmericanResults->clear();
    ui->AmericanResults->setReadOnly(true);
    m_tree_simulator.runSimulation();
    QString result;
    result+="------------------------Results for "+  QString::fromStdString(m_tree_simulator.type()) + "-------------------------\r\n";
    result += "Underlying Price, S = " + QString::number(m_tree_simulator.S()) +  "\r\n";
    result += "Strike Price, K = " + QString::number(m_tree_simulator.K()) +  "\r\n";
    result += "Interest Rate, r = " + QString::number(m_tree_simulator.r()) +  "\r\n";
    result += "Dividend Rate, d = " + QString::number(m_tree_simulator.d()) +  "\r\n";
    result += "Maturity in Years, T = " + QString::number(m_tree_simulator.T()) +  "\r\n";
    result += "Binomal Tree Steps size, steps = " + QString::number(m_tree_simulator.steps()) +  "\r\n";
    result += "Computed Price : $" + QString::number(m_tree_simulator.results()) + "\r\n";
    ui->AmericanResults->setPlainText(result);

}

void MainInterface::on_pushButton_clicked()
{
    GbmMonteCarlos *editForm = new GbmMonteCarlos(this);
    editForm->setSimulator(m_simulator);
    editForm->exec();
    m_simulator = editForm->simulator();
    GbmSimulate();
    delete editForm;
}


void MainInterface::on_ExoticGbmBtn_clicked()
{
    PathDependentMC *editForm = new PathDependentMC(this);
    editForm->setSimulator(m_pd_simulator);
    editForm->exec();
    m_pd_simulator = editForm->simulator();
    pathDependentSimulate();
    delete editForm;
}


void MainInterface::on_btnTree_clicked()
{
    AmericanOptionForm *editForm = new AmericanOptionForm(this);
    editForm->setSimulator(m_tree_simulator);
    editForm->exec();
    m_tree_simulator = editForm->simulator();
    AmericanTreeSimulate();
    delete editForm;
}


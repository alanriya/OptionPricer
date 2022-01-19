#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QMainWindow>
#include "algorithm/montecarlossimulator.h"
#include "algorithm/pathdependentmcsimulator.h"
#include "algorithm/treesimulator.h"
#include "gbmmontecarlos.h"
#include "pathdependentmc.h"
#include "americanoptionform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainInterface; }
QT_END_NAMESPACE

class MainInterface : public QMainWindow
{
    Q_OBJECT

public:
    MainInterface(QWidget *parent = nullptr);
    ~MainInterface();

    void GbmSimulate();
    void pathDependentSimulate();
    void AmericanTreeSimulate();

private slots:
    void on_pushButton_clicked();

    void on_ExoticGbmBtn_clicked();

    void on_btnTree_clicked();

private:
    Ui::MainInterface *ui;
    // monte carlos page
    GbmMonteCarlos m_gbmmc_page;
    MonteCarlosSimulator m_simulator;
    PathDependentMC m_pdmc_page;
    PathDependentMCSimulator m_pd_simulator;
    AmericanOptionForm m_american_page;
    TreeSimulator m_tree_simulator;



};
#endif // MAININTERFACE_H

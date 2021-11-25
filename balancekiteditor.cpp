#include "balancekiteditor.h"
#include "ui_balancekiteditor.h"
#include <QMessageBox>
#include <QTimer>

BalanceKitEditor::BalanceKitEditor(QWidget *parent,
                                   Qt::WindowFlags flags) :
    QMainWindow(parent,flags),
    ui(new Ui::BalanceKitEditor)
{
    ui->setupUi(this);

    // add a minimal distribution for the statswidget
    ui->stats_widget_->SetTitle("un beau graphique");
    ui->stats_widget_->SetXAxisTitle("axe #1");
    ui->stats_widget_->SetYAxisTitle("axe #2");

    QList<QPointF> distribution={QPointF(0,0),QPointF(1,3),QPointF(2,7),QPointF(3,4),QPointF(4,5),QPointF(5,2)};
    ui->stats_widget_->SetDistribution(distribution);
}

BalanceKitEditor::~BalanceKitEditor()
{
    delete ui;
}

void BalanceKitEditor::OnShowClicked()
{

}

void BalanceKitEditor::OnQuitClicked()
{
    qApp->exit();
}

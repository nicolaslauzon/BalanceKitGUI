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

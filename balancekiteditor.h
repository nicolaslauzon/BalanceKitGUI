#ifndef BALANCEKITEDITOR_H
#define BALANCEKITEDITOR_H

#include <QMainWindow>


namespace Ui
{
class BalanceKitEditor;
}

class BalanceKitEditor : public QMainWindow
{
    Q_OBJECT
public:
    explicit BalanceKitEditor(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    virtual ~BalanceKitEditor();

protected slots:
    void OnShowClicked();
    void OnQuitClicked();

private:
    Ui::BalanceKitEditor *ui;
};

#endif // BALANCEKITEDITOR_H

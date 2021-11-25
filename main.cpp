
#include "balancekiteditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BalanceKitEditor *main_window=new BalanceKitEditor();
    main_window->show();
    return a.exec();
}

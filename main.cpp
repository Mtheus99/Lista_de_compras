#include "fm_dados.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fm_dados w;
    w.show();
    return a.exec();

}

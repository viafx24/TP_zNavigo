// code de base d'une fonction main pour une Gui sous Qt.
// FenPrincipale est une classe de type QMainWindows.


#include <QApplication>
#include <QtWidgets>
#include <QtWebEngineWidgets>
#include "FenPrincipale.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenPrincipale fenetre;

    fenetre.show();

    return app.exec();

}


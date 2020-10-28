#include <QApplication>
#include <QtWidgets>
#include <QtWebEngineWidgets>
#include "FenPrincipale.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenPrincipale fenetre;
    fenetre.show();


 //   QtWebEngine::initialize();

       QWebEngineView *view = new QWebEngineView();
        view->load(QUrl("http://qt-project.org/"));
        view->show();

    return app.exec();
}


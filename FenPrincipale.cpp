#include "FenPrincipale.h"
#include <QtWebEngineWidgets>

FenPrincipale::FenPrincipale()
{

// //    Création des menus
//    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
//    QAction *actionQuitter = menuFichier->addAction("&Quitter");
//    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
//    actionQuitter->setIcon(QIcon("icone.png"));

//    QMenu *menuEdition = menuBar()->addMenu("&Edition");
//    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");

//    // Création de la barre d'outils
//    QToolBar *toolBarFichier = addToolBar("Fichier");
//    toolBarFichier->addAction(actionQuitter);


    view = new QWebEngineView(this);

    view->load(QUrl("https://via-fx-24.herokuapp.com/"));
 //   view->show();

    setFixedSize({800, 600});
    setCentralWidget(view);
    setAttribute(Qt::WA_DeleteOnClose);

//    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
}

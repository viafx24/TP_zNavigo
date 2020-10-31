#include "FenPrincipale.h"

FenPrincipale::FenPrincipale()
{
    view = new QWebEngineView(this);
    setCentralWidget(view);

    url = new QUrl("http://www.stackoverflow.com");
    view->load(*url);

    resize(1000,800);

    creationMenu();
    creationToolbar();
    adjustLocation();
    createStatusBar();

    connect(locationEdit, SIGNAL(returnPressed()), SLOT(changeLocation()));

// les deux variantes ci-dessous marchent aussi, je m'y perds un peu
//    connect(locationEdit, SIGNAL(returnPressed()),this, SLOT(changeLocation()));
//    connect(locationEdit, SIGNAL(returnPressed()),view, SLOT(changeLocation()));

}


void FenPrincipale::creationMenu()
{
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *actionQuitter = menuFichier->addAction("&Quitter");
    QAction *actionNewOnglet = menuFichier->addAction("&Nouvel onglet");
    QAction *actionCloseOnglet = menuFichier->addAction("&fermer l'onglet");
    actionQuitter->setShortcut(QKeySequence("Alt+F4"));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));


    QMenu *menuNavigation = menuBar()->addMenu("&Navigation");
    menuNavigation->addAction(view->pageAction(QWebEnginePage::Back));
    menuNavigation->addAction(view->pageAction(QWebEnginePage::Back));
    menuNavigation->addAction(view->pageAction(QWebEnginePage::Forward));
    menuNavigation->addAction(view->pageAction(QWebEnginePage::Reload));
    menuNavigation->addAction(view->pageAction(QWebEnginePage::Stop));
    //QAction *actionPrecedent = menuFichier->addAction(view->pageAction(QWebEnginePage::Back));
//    QAction *actionSuivant = menuFichier->addAction("&Suivant");
//    QAction *actionActualise = menuFichier->addAction("&Actualiser");
//    QAction *actionHome = menuFichier->addAction("&Pagde d'accueil");
//    QAction *actionStop = menuFichier->addAction("&Arrêter");

    QMenu *menuAide = menuBar()->addMenu("&Aide");
    QAction *actionApropos = menuAide->addAction("&A propos de zNavigator");


}

void FenPrincipale::creationToolbar()
{
    // Création de la barre d'outils
    QToolBar *toolBar = addToolBar("Navigation");
    toolBar->addAction(view->pageAction(QWebEnginePage::Back));
    toolBar->addAction(view->pageAction(QWebEnginePage::Forward));
    toolBar->addAction(view->pageAction(QWebEnginePage::Reload));
    toolBar->addAction(view->pageAction(QWebEnginePage::Stop));

    locationEdit = new QLineEdit(this);
    locationEdit->setSizePolicy(QSizePolicy::Expanding, locationEdit->sizePolicy().verticalPolicy());
    toolBar->addWidget(locationEdit);

}

void FenPrincipale::adjustLocation()
{
    locationEdit->setText(url->toString());
}


void  FenPrincipale::createStatusBar()
{
    progressBar= new QProgressBar(this);
    statusLabel = new QLabel(this);
    statusLabel->setText("Status Label");

    statusBar()->addPermanentWidget(statusLabel);
    statusBar()->addPermanentWidget(progressBar);
    connect(view, SIGNAL(loadProgress(int)),progressBar, SLOT(setValue(int)));

}


//Slots

void FenPrincipale::changeLocation()
{
    *url= url->fromUserInput(locationEdit->text());
    view->load(*url);
    view->setFocus();

}


void FenPrincipale::setHome()
{
    url->setUrl("http://www.google.fr");
    view->load(*url);
//    view->setFocus();
    locationEdit->setText(url->toString());
}

void FenPrincipale::aPropos()
{

QMessageBox::aboutQt(this, "test");

}

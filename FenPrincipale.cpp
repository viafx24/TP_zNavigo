#include "FenPrincipale.h"

FenPrincipale::FenPrincipale()
{




    //setAttribute(Qt::WA_DeleteOnClose);
    //   view->show();

 //    Création des menus
//    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
//    QAction *actionQuitter = menuFichier->addAction("&Quitter");
//    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
//    actionQuitter->setIcon(QIcon(":/Ressources/home.png"));

//    QMenu *menuEdition = menuBar()->addMenu("&Edition");
//    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");




//    statusBar = new QStatusBar(this);
//    progressBar= new QProgressBar(statusBar);
//    connect(this, SIGNAL(loadProgress(int)),progressBar, SLOT(setValue(int)));

//    loadProgress()
//[signal]void QWebEngineView::loadProgress(int progress)


//    toolBarFichier->addAction(actionQuitter);

    view = new QWebEngineView(this);
    url = new QUrl("http://www.stackoverflow.com");
    view->load(*url);

    resize(1000,800);
    //setFixedSize({800, 600});

    creationMenu();
    creationToolbar();
    adjustLocation();
    createStatusBar();

   //connect(locationEdit, SIGNAL(returnPressed()),this, SLOT(changeLocation()));
   // connect(this, SIGNAL(loadProgress(int)),progressBar, SLOT(setValue(int)));


    setCentralWidget(view);

}


void FenPrincipale::creationMenu()
{
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *actionQuitter = menuFichier->addAction("&Quitter");
    QAction *actionNewOnglet = menuFichier->addAction("&Nouvel onglet");
    QAction *actionCloseOnglet = menuFichier->addAction("&fermer l'onglet");
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));


    QMenu *menuNavigation = menuBar()->addMenu("&Navigation");
    menuFichier->addAction(view->pageAction(QWebEnginePage::Back));
    //QAction *actionPrecedent = menuFichier->addAction(view->pageAction(QWebEnginePage::Back));
    QAction *actionSuivant = menuFichier->addAction("&Suivant");
    QAction *actionActualise = menuFichier->addAction("&Actualiser");
    QAction *actionHome = menuFichier->addAction("&Pagde d'accueil");
    QAction *actionStop = menuFichier->addAction("&Arrêter");

    QMenu *menuAide = menuBar()->addMenu("&Aide");
    QAction *actionApropos = menuFichier->addAction("&Apropos");


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

void FenPrincipale::changeLocation()
{
    *url= url->fromUserInput(locationEdit->text());
    view->load(*url);
    view->setFocus();

    connect(locationEdit, SIGNAL(returnPressed()),this, SLOT(changeLocation()));
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

#include "FenPrincipale.h"
#include <QtWebEngineWidgets>
#include <QLineEdit>
#include <QUrl>
#include <QStatusBar>

FenPrincipale::FenPrincipale()
{

    view = new QWebEngineView(this);
    url = new QUrl("http://www.stackoverflow.com");
    view->load(*url);

    //setFixedSize({800, 600});


    //setAttribute(Qt::WA_DeleteOnClose);
    //   view->show();

 //    Création des menus
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *actionQuitter = menuFichier->addAction("&Quitter");
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    actionQuitter->setIcon(QIcon(":/Ressources/home.png"));

//    QMenu *menuEdition = menuBar()->addMenu("&Edition");
//    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");

    // Création de la barre d'outils
    QToolBar *toolBar = addToolBar("Navigation");
    toolBar->addAction(view->pageAction(QWebEnginePage::Back));
    toolBar->addAction(view->pageAction(QWebEnginePage::Forward));
    toolBar->addAction(view->pageAction(QWebEnginePage::Reload));
    toolBar->addAction(view->pageAction(QWebEnginePage::Stop));


//    statusBar = new QStatusBar(this);
//    progressBar= new QProgressBar(statusBar);
//    connect(this, SIGNAL(loadProgress(int)),progressBar, SLOT(setValue(int)));

//    loadProgress()
//[signal]void QWebEngineView::loadProgress(int progress)


//    toolBarFichier->addAction(actionQuitter);

    locationEdit = new QLineEdit(this);
    locationEdit->setSizePolicy(QSizePolicy::Expanding, locationEdit->sizePolicy().verticalPolicy());
    toolBar->addWidget(locationEdit);

    adjustLocation();
    createStatusBar();

//    QString A =url->toString();
//    locationEdit->setText(url->toString());
//    locationEdit->setText("guillaume");
//    QString A =url.toString();
//    url.toString()
//    locationEdit->setText(view->url.toString());

//    adjustLocation();
    connect(locationEdit, SIGNAL(returnPressed()),this, SLOT(changeLocation()));
    setCentralWidget(view);
 //   connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
}


void FenPrincipale::adjustLocation()
{
    //locationEdit->setText(view->url().toString());
    locationEdit->setText(url->toString());
}

void FenPrincipale::changeLocation()
{
   // url = QUrl::fromUserInput(locationEdit->text());
    *url= url->fromUserInput(locationEdit->text());
    view->load(*url);
    view->setFocus();
}


void  FenPrincipale::createStatusBar()
{
    statusBar = new QStatusBar(this);
    statusBar->showMessage(tr("Ready"));
//    progressBar= new QProgressBar;
//    statusBar->addWidget(progressBar);
}

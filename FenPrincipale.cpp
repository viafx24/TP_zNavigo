#include "FenPrincipale.h"

FenPrincipale::FenPrincipale()
{
    view = new QWebEngineView(this); // this probablement pas necessaire
    setCentralWidget(view); // place la page web vue en place centrale de la QMainWindows

    url = new QUrl("http://www.stackoverflow.com");
    view->load(*url);

    resize(1000,800);// la fonction resize choisit la taille de fenètre et cette dernière est ajustable: idéal pour les fenètres.

    // appel des 4 méthodes.

    creationMenu();
    creationToolbar();
    adjustLocation();
    createStatusBar();

   // si je change l'url dans la barre d'addresse, quand j'appuie sur entré (returnpressed), ca appelle slot changeLocation
    // qui charge la page demandé
    connect(locationEdit, SIGNAL(returnPressed()), SLOT(changeLocation()));

// les deux variantes ci-dessous marchent aussi, je m'y perds un peu:
//    connect(locationEdit, SIGNAL(returnPressed()),this, SLOT(changeLocation()));
//    connect(locationEdit, SIGNAL(returnPressed()),view, SLOT(changeLocation()));

}


void FenPrincipale::creationMenu()
{

    // le & devant Fichier crée un raccourci avec la lettre F (alt+F selectionne automatiquemnt l'onglet).
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *actionQuitter = menuFichier->addAction("&Quitter");

    // j'ai mis alt+F4 car ctrl+Q est reservé par powertoys

    // le qApp n'étant defini null part, il est bizarre que l'application se ferme: en fait, j'ai trouvé sur le net:
    // "qApp is a global pointer referring to the unique application object.
    //It is equivalent to QCoreApplication::instance(), but cast as a QApplication pointer,
    // so only valid when the unique application object is a QApplication.

    actionQuitter->setShortcut(QKeySequence("Alt+F4"));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));


    QMenu *menuNavigation = menuBar()->addMenu("&Navigation");
    menuNavigation->addAction(view->pageAction(QWebEnginePage::Back));
    menuNavigation->addAction(view->pageAction(QWebEnginePage::Back));
    menuNavigation->addAction(view->pageAction(QWebEnginePage::Forward));
    menuNavigation->addAction(view->pageAction(QWebEnginePage::Reload));
    menuNavigation->addAction(view->pageAction(QWebEnginePage::Stop));
    actionHome = menuNavigation->addAction("&Page d'accueil");
    connect(actionHome, SIGNAL(triggered()),this, SLOT(setHome()));
    QMenu *menuAide = menuBar()->addMenu("&Aide");
    QAction *actionApropos = menuAide->addAction("&A propos de zNavigator");
    connect(actionApropos, SIGNAL(triggered()),this, SLOT(aPropos()));

}

void FenPrincipale::creationToolbar()
{
    // Création de la barre d'outils
    QToolBar *toolBar = addToolBar("Navigation");
    toolBar->addAction(view->pageAction(QWebEnginePage::Back));
    toolBar->addAction(view->pageAction(QWebEnginePage::Forward));
    toolBar->addAction(view->pageAction(QWebEnginePage::Reload));
    toolBar->addAction(view->pageAction(QWebEnginePage::Stop));
    toolBar->addAction(actionHome);

    // pour utiliser des images externes sans utiliser le path, Qt dispose du fonctionnement avec les ressources
    // voir onenote: on cree un nouveau .qrc et on met les images dans le repertoire crée. Pour appeler ces images,
    // on rajoute ":/" devant et l'image arrive.
    actionHome->setIcon(QIcon(":/Ressources/home.png"));

    locationEdit = new QLineEdit(this);
    // trouvé sur internet, je ne sais pas trop comment ca marche mais permet d'avoir la barre d'adresse
    //au bon endroit à la bonne taille.
    locationEdit->setSizePolicy(QSizePolicy::Expanding, locationEdit->sizePolicy().verticalPolicy());
    toolBar->addWidget(locationEdit);

}
// change l'url quand change de page( par exemple quand on clique sur home)
// il y a une erreur: quand je navique sur le web avec les liens hypertext, la barre d'addresse n'est pas mise à jour.
// je n'ai pas le temps de régler ce problème, je passe à autre chose.

void FenPrincipale::adjustLocation()
{
    locationEdit->setText(url->toString());
}

// barre du bas
void  FenPrincipale::createStatusBar()
{
    progressBar= new QProgressBar(this);
    statusLabel = new QLabel(this);
    statusLabel->setText("Etat du téléchargement de la page");

    statusBar()->addPermanentWidget(statusLabel);
    statusBar()->addPermanentWidget(progressBar);

    // quand on veut passer un argument du signal au slot, on ne passe que son type, ici un int qui indique l'état du
    // téléchargement de 1 à 100
    connect(view, SIGNAL(loadProgress(int)),progressBar, SLOT(setValue(int)));

}


//Slots

void FenPrincipale::changeLocation()
{
    *url= url->fromUserInput(locationEdit->text());
    view->load(*url);

    // je ne sais pas trop ce que fais ce setFocus ni si il est necessaire
    view->setFocus();

}


void FenPrincipale::setHome()
{
    url->setUrl("http://www.google.fr");
    view->load(*url);

    // j'aurai pu sans doute aussi appeler ma méthode adjustlocation
    locationEdit->setText(url->toString());
}

// crée un fenètre apropos toute faite par Qt.
void FenPrincipale::aPropos()
{

QMessageBox::aboutQt(this, "Qt");

}

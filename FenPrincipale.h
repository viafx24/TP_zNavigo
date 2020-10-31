#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtWidgets>
#include <QtWebEngineWidgets>

class FenPrincipale : public QMainWindow
{

    // Q_OBJECT est necessaire si on definit des slots: attention, on a tendance à l'oublier.
    Q_OBJECT


    public:
    // constructeur
    FenPrincipale();

    // méthodes
    void  adjustLocation(); // met le bon nom dans la barre d'adresse.
    void creationMenu();
    void  creationToolbar();
    void createStatusBar(); // la barre en bas qui indique l'état du telechargement de la page

    // slots (appeler quand on clique dans le menu ou sur les boutons de la barre d'outils.
public slots:


   void changeLocation();// quand on change l'adresse dans la barre d'adresse et appuie sur entré: change de page web
   void setHome();
   void aPropos();

    private:

  // Quelque chose de pas evident à comprendre pour moi:
  //si je définis ici les attributs, je ne dois pas le faire dans le .cpp
  // dans le cpp, je fais simplement url= new QUrl(etc...)
   // par contre si je ne definis pas l'attribut, alors dans le cpp, je fais:
   //  QUrl *url = new QUrl("http://www.stackoverflow.com");
   // mais alors mes methodes n'ont pas accés à l'URL.
   // ca dépend des cas donc.


    QUrl *url; // Url demandé
    QWebEngineView *view;  // la page web
    QLineEdit *locationEdit; // la barre d'adresse
    QProgressBar *progressBar; // barre de progression en bas
    QLabel *statusLabel; // texte à coté de la barre de progression
    QAction *actionHome; // revenir à la page d'accueil.

};

#endif

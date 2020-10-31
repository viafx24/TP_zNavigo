#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtWidgets>
#include <QtWebEngineWidgets>

class FenPrincipale : public QMainWindow
{

    Q_OBJECT


    public:
    FenPrincipale();

    void  adjustLocation();
    void creationMenu();
    void  creationToolbar();
    void createStatusBar();

public slots:


   void  changeLocation();
   void setHome();
   void aPropos();

    private:
    QUrl *url;
    QWebEngineView *view;  
   // QStatusBar *statusBar;
    QLineEdit *locationEdit;
    QProgressBar *progressBar;
    QLabel *statusLabel;

};

#endif

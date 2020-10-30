#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtWidgets>
#include <QtWebEngineWidgets>

class FenPrincipale : public QMainWindow
{

    Q_OBJECT


    public:
    FenPrincipale();

    void createStatusBar();

public slots:

   void  adjustLocation();
   void  changeLocation();


    private:
    QUrl *url;
    QWebEngineView *view;  
   // QStatusBar *statusBar;
    QLineEdit *locationEdit;
    QProgressBar *progressBar;


};

#endif

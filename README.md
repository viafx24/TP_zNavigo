# TP_zNavigo

TP issu de Openclassroom (cours sur le CPP) mais qui utilise le nouveau QWebEngineView au lieu du QWebView (plus ancien et deprecié). 
Il s'agit de ma propre version qui n'utilise pas la correction proposée.
elle n'est pas exempt de bug et souffre des defaults suivants:
+ il n'y a pas d'actualisation de la barre d'adresse quand on navigue sur le web
+ il n'y a pas d'onglets (je n'ai pas réussi, l'implémentation necessitait plus de temps)
+ il y a parfois des fuites de mémoire detecté par Qt creator à la fermeture de la fenètre principale, dont je connais pas la provenance.

Sinon, le reste des fonctionnalités marchent a peu prés et le code est relativement commenté et donc reutilisable pour apprendre et comprendre Qt.

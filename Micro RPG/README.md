# Micro RPG

## Project

This project is a micro game built for a recruiting process.

## Rules (in french)

### Caract�ristiques du chevalier :

- Il dispose de 20 points de vie et d'un bouclier de 50 points.
- Il dispose d'une �p�e lui permettant de faire 5 points de d�g�ts par tour.
- Il dispose d'une capacit� "charge" lui permettant de faire le double de d�g�ts ce tour-ci. Cette capacit� ne peut �tre utilis�e que tous les 3 tours de jeu.
Elle a 60% de chance de r�ussir. Si elle ne r�ussit pas, il faudra attendre les 3 tours mentionn�s ci-dessus pour la tenter de nouveau.
- Les d�g�ts pris par le chevalier sont d'abord inflig�s au bouclier et lorsque le bouclier n'a plus de points, l'unit� perd des points de vie.
 
### Caract�ristiques de l'orc :

- L'orc dispose de 60 points de vie mais n'a pas de bouclier.
- Il dispose d'une hache lui permettant de faire 8 points de d�g�ts par tour.
- Il dispose d'une capacit� "stun" lui permettant d'�tourdir l'ennemi pendant un tour. Un ennemi �tourdi ne pourra pas faire de d�g�t ce tour-ci.
- Cette capacit� ne peut �tre utilis�e que tous les 5 tours de jeu. Elle a 20% de chance de r�ussir.
Si elle ne r�ussit pas, il faudra attendre les 5 tours mentionn�s ci-dessus pour la tenter de nouveau.

### D�roulement de la partie :

- Un tour de jeu est constitu� de 2 �l�ments successifs : lancement de capacit�s sp�ciales, puis combat entre les unit�s.
- Il y a autant de tour de jeu que n�cessaire pour que l'un des c�t�s gagne la partie.
- Un c�t� gagne la partie quand l'unit� adverse a �t� tu�e.
- Pour le combat entre 2 unit�s, chaque unit� inflige directement les d�g�ts � l'unit� ennemie (en prenant en compte les �ventuels effets des capacit�s).

### Contraintes suppl�mentaires :

- Afin de v�rifier que votre programme fonctionne normalement, il serait appr�ciable de pouvoir suivre l'�volution de la partie en affichant notamment les informations de chaque unit� � chaque tour de jeu.
- Il faut que le programme soit correctement architectur� pour qu'il soit facile d'ajouter de nouvelles classes et/ou de nouvelles caract�ristiques.

### Bonus :
- Pour rendre le jeu plus "dynamique", il pourrait �tre sympa de pouvoir faire des choix avant le lancement de la partie/pendant la partie.
- Vous �tes libre de faire une/des propositions et de les impl�menter.

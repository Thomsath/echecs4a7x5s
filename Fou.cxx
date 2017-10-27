#include "Pion.h"
#include <iostream>
#include "Echiquier.h"
#include "Fou.h"
#include "Piece.h"
#include "Reine.h"
#include <cmath>

using namespace std;

Fou::Fou() { }

Fou::Fou(bool white, bool left) : Piece((left?3:6),(white?1:8),white) { }

bool
Fou::mouvementValide(Echiquier &e, int x, int y)
{
    // Déplacement en diago
    int y_axis = min(y,m_y)+1;
    int x_axis = min(x,m_x)+1;
    bool estValide = false;

if (Piece::mouvementValide(e,x,y)) {
    // Ici on vérifie que c'est bien une diagonale (les valeurs x et y en diagonale étant toujours égales)
    if(abs(x-m_x) == abs(y-m_y)){
    // Pour chaque case pour un déplacement du fou

    for (x_axis; x_axis<max(x,m_x); x_axis++) {
        if(e.getPiece(x_axis,y_axis)) {
            cout << "Déplacement impossible, pièce sur le déplacement du fou" << endl;
        }
        y_axis = y_axis +1;
    }

      cout << "mouvementValide de Fou" << endl;
      estValide = true;
     }
}
     else {
        cout << "Mouvement non autorisé pour un fou" << endl;
    }

    return estValide;
}

char
Fou::type()
{
  return m_white ? 'F' : 'f';
}

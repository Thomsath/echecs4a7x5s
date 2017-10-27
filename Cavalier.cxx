#include "Pion.h"
#include <iostream>
#include "Echiquier.h"
#include "Piece.h"
#include "Cavalier.h"
#include <cmath>


using namespace std;

Cavalier::Cavalier(bool white, bool left) : Piece((left?2:7),(white?1:8),white) { }
bool
Cavalier::mouvementValide(Echiquier &e, int x, int y)
{
    bool estValide = false;

    //Vérifier que la case d'arrivée est valide
    // Sachant que le cavalier peut faire 1 déplacement vertical/horizontal de 2 cases
    // et vertical/horizontal d'une case en faisant un L
    if ((abs(y-m_y) == 1 && abs(x-m_x) == 2 ) || (abs(x-m_x) == 1 && abs(y-m_y) == 2))
    {
       cout << "Mouvement OK" << endl;
       estValide = true;
    } else {
        estValide=false;
    }

    return estValide;
}

char
Cavalier::type()
{
  return m_white ? 'C' : 'c';
}

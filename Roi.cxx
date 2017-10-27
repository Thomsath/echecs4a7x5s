#include "Pion.h"
#include <iostream>
#include "Echiquier.h"
#include "Piece.h"
#include "Roi.h"
#include <cmath>

using namespace std;
Roi::Roi(bool white) : Piece(5,(white?1:8),white) { }

bool
Roi::mouvementValide(Echiquier &e, int x, int y)
{
    bool estValide = false;

    //Le roi peut se déplacer d'une case dans toutes les directions
    if ((abs(x - m_x) == 1) || (abs(y - m_y) == 1))
    {

        cout << "Le mouvement du Roi est valide" << endl;
        estValide = true;

    }

    cout << "Le mouvement du Roi est NON valide" << endl;
    return estValide;
}


char
Roi::type()
{
    return m_white ? 'R' : 'r';
}

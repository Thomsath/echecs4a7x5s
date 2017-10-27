#include <iostream>
#include "Echiquier.h"
#include "Piece.h"
#include "Reine.h"

using namespace std;

Reine::Reine(bool white) : Piece(4,(white?1:8),white) { }


bool
Reine::mouvementValide(Echiquier &e, int x, int y)
{
  bool mouvementOk = false;

  //La reine peut se déplacer verticalement, horizontalement et en diagonale. Elle cumule le déplacement de la Tour et du Fou
  if (Tour::mouvementValide(e,x,y) || Fou::mouvementValide(e,x,y))
  {
      cout << "Le mouvement de la Reine est valide." << endl;
      mouvementOk = true;
  }
  else cout << "Le mouvement de la Reine est NON valide." << endl;

  return mouvementOk;
}

char
Reine::type()
{
  return m_white ? 'Q' : 'q';
}

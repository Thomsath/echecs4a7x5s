/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include "Piece.h"
#include <iostream>
#include "Echiquier.h"
#include "Pion.h"
#include "Fou.h"
#include "Reine.h"


using namespace std;

Piece::Piece()
{
  // ne fait rien => objet instancie mais non valide.
  //cout << "Une piece creee" << endl;
}

Piece::Piece(int x, int y, bool white) {
  init(x,y,white);
  //cout << "Une piece creee" << endl;
}

Piece::Piece(const Piece & p)
{
  init(p.x(), p.y(), p.isWhite());
}

Piece::~Piece() {

 //cout << "Une piece détruite " << endl;
}

Piece & Piece::operator=(const Piece & p) {
  this->m_x = p.x();
  this->m_y = p.y();
  this->m_white = p.isWhite();

  return *this; // On retourne une référence sur l'objet courant
}

void
Piece::init( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
}

bool
Piece::samePlace(const Piece p)
{
return((m_x == p.x())&&(m_y == p.y()));
}

bool
Piece::samePlace(const Piece & p)
{
return((m_x == p.x())&&(m_y == p.y()));
}

Piece
Piece::plusForte(const Piece & p)
{
if(true)
    return(p);
else
    return(*this);
}

void
Piece::move( int x, int y )
{
  m_x = x;
  m_y = y;
}
void
Piece::affiche()
{
  cout << "Piece: x=" << m_x << " y=" << m_y << " ; "
       << type() << endl;
}

int
Piece::x() const
{
  return m_x;
}

int
Piece::y() const
{
  return m_y;
}

bool
Piece::isWhite() const
{
  return m_white;
}

bool
Piece::isBlack() const
{
  return !isWhite();
}

bool
Piece::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "Mouvement Valide Generique" << endl;
  return true;
}

char
Piece::type()
{
  return m_white ? 'B' : 'N';
}

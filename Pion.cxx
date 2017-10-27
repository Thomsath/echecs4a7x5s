#include "Pion.h"
#include <iostream>
#include "Echiquier.h"
#include "Piece.h"
#include <cmath>


using namespace std;

Pion::Pion(int x, bool white) : Piece(x, (white?2:7), white) { }

bool Pion::mouvementValide(Echiquier &e, int x, int y){
    bool mouvementValide = false;

    if((m_y == 2 && m_white) || (m_y == 7 && !m_white)){
        /**** AVANCER 2 CASES ****/
        if ((x == m_x && y == m_y+2 && m_white) || (x == m_x && y == m_y-2 && !m_white)){ // blanc || noir
            if (m_white && e.getPiece(m_x, m_y+1) == NULL && e.getPiece(m_x, m_y+2) == NULL){
                cout << "Mouvement Pion 2 cases valide." << endl;
                mouvementValide = true;
            }
            else{
                if (!m_white && e.getPiece(m_x, m_y-1) == NULL && e.getPiece(m_x, m_y-2) == NULL){
                    cout << "Mouvement Pion 2 cases valide." << endl;
                    mouvementValide = true;
                }
            }
        }
        else{ /**** AVANCER 1 CASE ****/
            if ((x == m_x && y == m_y+1 && m_white) || (x == m_x && y == m_y-1 && !m_white)){
                if(e.getPiece(x,y) == NULL){
                    cout << "Mouvement Pion 1 case valide." << endl;
                    mouvementValide = true;
                }
            }
            else{
                if((1 == abs(x-m_x) && y == m_y+1 && m_white) || (1 == abs(x-m_x) && y == m_y-1 && !m_white)){
                    if (e.getPiece(x,y) != NULL && e.getPiece(x, y)->isWhite() != m_white){
                        e.enleverPiece(x,y);
                        cout << "Mouvement Pion 1 case valide." << endl;
                        mouvementValide = true;
                    }
                }
            }
        }
    }
    else { /**** DIAGONALE ****/
        if ((x == m_x && y == m_y+1 && m_white) || (x == m_x && y == m_y-1 && !m_white)){
                if(e.getPiece(x,y) == NULL){
                    cout << "Mouvement Pion diagonale valide." << endl;
                    mouvementValide = true;
                }
            }
            else{
                if((1 == abs(x-m_x) && y == m_y+1 && m_white) || (1 == abs(x-m_x) && y == m_y-1 && !m_white)){
                    if (e.getPiece(x,y) != NULL && e.getPiece(x, y)->isWhite() != m_white){
                        e.enleverPiece(x,y);
                        cout << "Mouvement Pion diagonale valide." << endl;
                        mouvementValide = true;
                    }
                }
            }
    }

  return mouvementValide;
}

char Pion::type()
{
  return m_white ? 'P' : 'p';
}

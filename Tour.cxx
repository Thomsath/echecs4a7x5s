#include "Pion.h"
#include <iostream>
#include "Echiquier.h"
#include "Piece.h"
#include "Tour.h"


using namespace std;


Tour::Tour() { }

Tour::Tour(bool white, bool left) : Piece((left?1:8),(white?1:8),white) { }

bool Tour::mouvementValide(Echiquier &e, int x, int y){
    bool mouvementValide = false;
    int i = 0;

    if ((x == m_x && y>=1 && y <=8) || (y == m_y && x>=1 && x<=8)){
        /**** DROITE ****/
        if (m_x < x){
            for (i = m_x; i <= x; i++){
                if (e.getPiece(i,y) != NULL){
                    //Piece présente sur case arrivée
                    if (i == x && e.getPiece(i,y)->isWhite() != m_white){   //Si piece couleur adverse
                        e.enleverPiece(x,y);
                        cout << "Mouvement Tour à droite valide" << endl;
                        mouvementValide = true;
                    }
                }
                else{
                    //Case libre
                    if(i == x && mouvementValide == false){
                        cout << "Mouvement Tour à droite valide" << endl;
                        mouvementValide = true;
                    }
                }
            }
        }
        else{
            /**** GAUCHE ****/
            if (m_x > x){
                for (i = m_x; i <= x; i--){
                    if (e.getPiece(i,y) != NULL){
                        if (i == x && e.getPiece(i,y)->isWhite() != m_white){
                            e.enleverPiece(x,y);
                            cout << "Mouvement Tour à gauche valide" << endl;
                            mouvementValide = true;
                        }
                    }
                    else{
                        if(i == x && mouvementValide == false){
                            cout << "Mouvement Tour à gauche valide" << endl;
                            mouvementValide = true;
                        }
                    }
                }
            }
            else{
                /**** BAS ****/
                if(m_y < y){
                    for (i = m_y; i <= y; i++){
                        if (e.getPiece(x,i) != NULL){
                            if (i == y && e.getPiece(x,i)->isWhite() != m_white){
                                e.enleverPiece(x,y);
                                cout << "Mouvement Tour en bas valide" << endl;
                                mouvementValide = true;
                            }
                        }
                        else{
                            if(i == y && mouvementValide == false){
                                cout << "Mouvement Tour en bas valide" << endl;
                                mouvementValide = true;
                            }
                        }
                    }
                }
                else{
                    /**** HAUT ****/
                    for (i = m_y; i <= y; i--){
                        if (e.getPiece(x,i) != NULL){
                            if (i == y && e.getPiece(x,i)->isWhite() != m_white)
                            {
                                e.enleverPiece(x,y);
                                cout << "Mouvement Tour en haut valide" << endl;
                                mouvementValide = true;
                            }
                        }
                        else
                        {
                            if(i == y && mouvementValide == false)
                            {
                                cout << "Mouvement Tour en haut valide" << endl;
                                mouvementValide = true;
                            }
                        }
                    }
                }
            }
        }
    }

  return mouvementValide;
}
char Tour::type()
{
  return m_white ? 'T' : 't';
}

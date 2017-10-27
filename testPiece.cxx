/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include <assert.h>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"
#include "Pion.h"
#include "Fou.h"
#include "Reine.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"
#include "Cavalier.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;


// Vérification de la validité des coordonnées saisie
bool coordonneeValide(string coord)
{
    if(coord.length() == 2)
    {
        if(coord[0] >= '1' && coord[0] <= '8' && coord[1] >= '1' && coord[1] <= '8')
        {
            return true;
        }
    }
    return false;
}


/**
 * Programme principal
 */
int main( int argc, char** argv )
{
    int xDepart;
    int yDepart;
    int xArrivee;
    int yArrivee;
    string depart;
    string arrivee;

    JoueurNoir jn;
    JoueurBlanc jb;
    Echiquier e;

    bool piecesOK;
    piecesOK = jn.placerPieces(e);
    assert(piecesOK);
    piecesOK = jb.placerPieces(e);
    assert(piecesOK);

    jn.affiche();
    jb.affiche();
    e.affiche();

    //Initialisation du joueur qui commence la partie
    bool tourBlanc=true;


    //Tant qu'il n'y a pas echec ou mat on continue la partie
    while(!jb.Mat() && !jn.Mat())
    {
        if(tourBlanc)
        {
            cout <<"######### AU TOUR DU JOUEUR BLANC DE JOUER ! (joueur en haut)  #########" << endl;
        }
        else
        {
            cout <<"######### AU TOUR DU JOUEUR NOIR DE JOUER ! (joueur en bas) ######### " << endl;
        }


        //Le joueur saisis les coordonnées de la pièce qu'il souhaite déplacer
        while(!coordonneeValide(depart))
        {
            cout << "Saisir les coordonnees de la piece que vous souhaitez deplacer : " << endl;
            cin >> depart;
            if(!coordonneeValide(depart))
            {
                cout << "Coordonnées NON valide !! Recommencer !! " << endl;
            }
            else{
            xDepart = toupper(depart[0])-64;
            yDepart = depart[1]-48;
}
        }

        //Le joueur saisis les coordonnées de destination de la pièce
        while(!coordonneeValide(arrivee))
        {
            cout << "Saisir les coordonnees de la case de destination de la piece :" << endl;
            cin >> arrivee;
            if(!coordonneeValide(arrivee))
            {
                cout << "Coordonnees NON valide !! Recommencer !! " << endl;
            }
             else{
            xArrivee = toupper(arrivee[0])-64;
            yArrivee = arrivee[1]-48;
}
        }
        Piece * p = e.getPiece(xDepart, yDepart);


        //Vérification de la validité du déplacement de la pièce
        if(p != NULL && p -> mouvementValide(e,xArrivee, yArrivee))
        {
            e.deplacer(p, xArrivee, yArrivee);
        }
        else
        {
            cout << " Deplacement impossible !!!" << endl;
        }

        //Affichage de l'échiquier
        e.affiche();


        //Vérification si il y a echec ou mat pour le joueur blanc
        if(jb.Mat()||jb.Echec()){
          cout<<"################### VICTOIRE DU JOUEUR BLANC !!!! ###################"<<endl;
        }


        //Vérification si il y a echec ou mat pour le joueur noir
        if(jb.Mat()||jb.Echec()){
           cout<<"################### VICTOIRE DU JOUEUR NOIR !!!! ###################"<<endl;
        }

        //Changement de joueur
        if(tourBlanc)
        {
            tourBlanc=false;
        }
        else
        {
            tourBlanc=true;
        }
        depart = "";
        arrivee = "";
    }
    return 0;
}

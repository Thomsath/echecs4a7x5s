#if !defined Joueur_h
#define Joueur_h

#include "Piece.h"
#include "Echiquier.h"

class Joueur
{
private:
    Piece *m_pieces[16];

public:
    Joueur( bool white );
    Joueur();
    ~Joueur();

    void init( bool white );
    void affiche();
    bool placerPieces(Echiquier & e);
    bool Mat();
    bool Echec();
};

#endif // !defined Joueur_h

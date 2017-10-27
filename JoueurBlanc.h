#if !defined JoueurBlanc_h
#define JoueurBlanc_h

#include "Joueur.h"


class JoueurBlanc : public Joueur {
public:
        JoueurBlanc();
        ~JoueurBlanc();

        bool isWhite();
        bool isBlack();
};
#endif // !defined Joueur_h

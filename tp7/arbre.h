#ifndef ARBRE_H
#define ARBRE_H

typedef struct _noeud noeud;

struct _noeud
{
	int valeur;
	noeud* gauche;
	noeud* droit;
};

void parcours_grd(noeud* racine);
void parcours_rgd(noeud* racine);
void insertion_recursive(noeud** racine, int valeur);
void insertion_iterative(noeud** racine, int valeur);
void suppression(noeud** racine, int valeur);
void remplissage(noeud** racine, const char* nom);
noeud** rechercher(noeud** racine, int valeur);

#endif

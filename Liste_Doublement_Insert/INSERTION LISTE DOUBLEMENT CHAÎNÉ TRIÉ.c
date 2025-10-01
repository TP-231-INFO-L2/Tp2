#include <stdio.h>
#include <stdlib.h>

// STRUCTURE POUR UNE CELLULE DOUBLEMENT CHAÎNÉE
typedef struct Cellule {
    int valeur;
    struct Cellule* suivant;
    struct Cellule* precedent;
} Cellule;

// CRÉER UNE CELLULE
Cellule* creerCellule(int val) {
    Cellule* nouveau = (Cellule*)malloc(sizeof(Cellule));
    nouveau->valeur = val;
    nouveau->suivant = NULL;
    nouveau->precedent = NULL;
    return nouveau;
}

// AJOUT EN FIN (POUR CONSTRUIRE LA LISTE INITIALE)
Cellule* insererFin(Cellule* tete, int val) {
    Cellule* nouveau = creerCellule(val);
    if (tete == NULL) return nouveau;

    Cellule* p = tete;
    while (p->suivant != NULL) {
        p = p->suivant;
    }
    p->suivant = nouveau;
    nouveau->precedent = p;
    return tete;
}

// AFFICHAGE
void afficherListe(Cellule* tete) {
    Cellule* p = tete;
    printf("LISTE : ");
    while (p != NULL) {
        printf("%d <-> ", p->valeur);
        p = p->suivant;
    }
    printf("NULL\n");
}

// VÉRIFIER ORDRE
// retourne 0 = croissant, 1 = décroissant, -1 = pas ordonné
int verifierOrdre(Cellule* tete) {
    if (tete == NULL || tete->suivant == NULL) return 0; // une seule valeur = croissant
    int ordre = -1; // -1 = inconnu, 0 = croissant, 1 = décroissant

    Cellule* p = tete;
    while (p->suivant != NULL) {
        if (p->valeur < p->suivant->valeur) {
            if (ordre == -1) ordre = 0;
            else if (ordre == 1) return -1; // contradiction
        } else if (p->valeur > p->suivant->valeur) {
            if (ordre == -1) ordre = 1;
            else if (ordre == 0) return -1;
        }
        p = p->suivant;
    }
    return (ordre == -1) ? 0 : ordre;
}

// INSÉRER UNE VALEUR DANS UNE LISTE TRIÉE
Cellule* insererTrie(Cellule* tete, int val, int ordre) {
    Cellule* nouveau = creerCellule(val);

    // CAS TÊTE
    if ((ordre == 0 && val < tete->valeur) ||
        (ordre == 1 && val > tete->valeur)) {
        nouveau->suivant = tete;
        tete->precedent = nouveau;
        return nouveau;
    }

    // CAS MILIEU / FIN
    Cellule* p = tete;
    while (p->suivant != NULL &&
          ((ordre == 0 && p->suivant->valeur < val) ||
           (ordre == 1 && p->suivant->valeur > val))) {
        p = p->suivant;
    }

    // INSÉRER APRÈS p
    nouveau->suivant = p->suivant;
    nouveau->precedent = p;
    if (p->suivant != NULL) {
        p->suivant->precedent = nouveau;
    }
    p->suivant = nouveau;

    return tete;
}

// PROGRAMME PRINCIPAL
int main() {
    Cellule* tete = NULL;
    int n, val, ordre, valeurInserer;

    printf("COMBIEN D'ELEMENTS VOULEZ-VOUS INSERER ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("ENTRER LA VALEUR %d : ", i + 1);
        scanf("%d", &val);
        tete = insererFin(tete, val);
    }

    printf("\nLISTE INITIALE :\n");
    afficherListe(tete);

    ordre = verifierOrdre(tete);
    if (ordre == -1) {
        printf("ERREUR : LA LISTE N'EST PAS ORDONNEE. RESSAISIR UNE LISTE CORRECTE.\n");
        return 0;
    }

    if (ordre == 0) printf("LA LISTE EST DANS L'ORDRE CROISSANT.\n");
    else printf("LA LISTE EST DANS L'ORDRE DECROISSANT.\n");

    printf("\nENTRER LA VALEUR A INSERER : ");
    scanf("%d", &valeurInserer);

    tete = insererTrie(tete, valeurInserer, ordre);

    printf("\nLA NOUVELLE LISTE EST :\n");
    afficherListe(tete);

    return 0;
}
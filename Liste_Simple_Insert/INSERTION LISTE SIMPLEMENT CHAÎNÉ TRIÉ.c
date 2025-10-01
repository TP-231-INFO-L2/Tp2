#include <stdio.h>
#include <stdlib.h>

typedef struct Cellule {
    int valeur;
    struct Cellule* suivant;
} Cellule;

// Créé une cellule 
Cellule* creerCellule(int val) {
    Cellule* nouveau = (Cellule*)malloc(sizeof(Cellule));
    nouveau->valeur = val;
    nouveau->suivant = NULL;
    return nouveau;
}

// Ajout en fin
Cellule* insererFin(Cellule* tete, int val) {
    Cellule* nouveau = creerCellule(val);
    if (tete == NULL) return nouveau;

    Cellule* p = tete;
    while (p->suivant != NULL) {
        p = p->suivant;
    }
    p->suivant = nouveau;
    return tete;
}

// Affichage
void afficherListe(Cellule* tete) {
    Cellule* p = tete;
    printf("LISTE : ");
    while (p != NULL) {
        printf("%d -> ", p->valeur);
        p = p->suivant;
    }
    printf("NULL\n");
}

// Vérification de l'ordre 
int verifierOrdre(Cellule* tete) {
    if (tete == NULL || tete->suivant == NULL) return 0; // une seule valeur = croissant par défaut
    int ordre = -1; // -1 = inconnu, 0 = croissant, 1 = décroissant

    Cellule* p = tete;
    while (p->suivant != NULL) {
        if (p->valeur < p->suivant->valeur) {
            if (ordre == -1) ordre = 0;
            else if (ordre == 1) return -1; // contradiction
        } else if (p->valeur > p->suivant->valeur) {
            if (ordre == -1) ordre = 1;
            else if (ordre == 0) return -1; // contradiction
        }
        p = p->suivant;
    }
    return (ordre == -1) ? 0 : ordre; // si égalité partout → croissant par défaut
}

// nsérer une valeur dans une liste trié 
Cellule* insererTrie(Cellule* tete, int val, int ordre) {
    Cellule* nouveau = creerCellule(val);

    // si on se trouve en tête 
    if ((ordre == 0 && val < tete->valeur) ||
        (ordre == 1 && val > tete->valeur)) {
        nouveau->suivant = tete;
        return nouveau;
    }

    // si c'est au milieu où en fin
    Cellule* p = tete;
    while (p->suivant != NULL &&
          ((ordre == 0 && p->suivant->valeur < val) ||
           (ordre == 1 && p->suivant->valeur > val))) {
        p = p->suivant;
    }

    nouveau->suivant = p->suivant;
    p->suivant = nouveau;

    return tete;
}

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
        return 0; // fin du programme
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
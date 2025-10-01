#include <stdio.h>
#include <stdlib.h>

// Définition d'une cellule de la liste doublement chaînée
typedef struct Cellule {
    int valeur;
    struct Cellule* suivant;
    struct Cellule* precedent;
} Cellule;

// Fonction pour créer une nouvelle cellule
Cellule* creerCellule(int val) {
    Cellule* nouveau = (Cellule*)malloc(sizeof(Cellule));
    nouveau->valeur = val;
    nouveau->suivant = NULL;
    nouveau->precedent = NULL;
    return nouveau;
}

// Fonction pour insérer un élément à la fin
Cellule* insererFin(Cellule* tete, int val) {
    Cellule* nouveau = creerCellule(val);

    if (tete == NULL) {
        return nouveau; 
    }

    Cellule* courant = tete;
    while (courant->suivant != NULL) {
        courant = courant->suivant;
    }
    courant->suivant = nouveau;
    nouveau->precedent = courant;
    return tete;
}

// Fonction pour afficher la liste (dans les 2 sens)
void afficherListe(Cellule* tete) {
    Cellule* courant = tete;
    Cellule* dernier = NULL;

    printf("\nLISTE (SENS NORMAL) : ");
    while (courant != NULL) {
        printf("%d <-> ", courant->valeur);
        if (courant->suivant == NULL) dernier = courant; // on garde la fin
        courant = courant->suivant;
    }
    printf("NULL\n");

    printf("LISTE (SENS INVERSE) : ");
    while (dernier != NULL) {
        printf("%d <-> ", dernier->valeur);
        dernier = dernier->precedent;
    }
    printf("NULL\n");
}

// Fonction pour supprimer toutes les occurrences d'une valeur
Cellule* supprimerValeur(Cellule* tete, int val, int* compteur) {
    Cellule* courant = tete;

    while (courant != NULL) {
        if (courant->valeur == val) {
            (*compteur)++;

            // Si c'est la tête
            if (courant->precedent == NULL) {
                tete = courant->suivant;
                if (tete != NULL) tete->precedent = NULL;
                free(courant);
                courant = tete;
            }
            // Si c'est au milieu ou fin
            else {
                courant->precedent->suivant = courant->suivant;
                if (courant->suivant != NULL) {
                    courant->suivant->precedent = courant->precedent;
                }
                Cellule* temp = courant->suivant;
                free(courant);
                courant = temp;
            }
        } else {
            courant = courant->suivant;
        }
    }

    return tete;
}

// Programme principal
int main() {
    Cellule* tete = NULL;
    int n, val, nbr, compteur = 0;

    printf("COMBIEN D'ELEMENTS VOULEZ-VOUS INSERER ? : \t");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("ENTRER LA VALEUR %d : ", i + 1);
        scanf("%d", &val);
        tete = insererFin(tete, val);
    }

    printf("\nLISTE INITIALE :\n");
    afficherListe(tete);

    printf("\nENTRER LA VALEUR A SUPPRIMER : ");
    scanf("%d", &nbr);

    tete = supprimerValeur(tete, nbr, &compteur);

    if (compteur > 0) {
        printf("\nLA VALEUR %d APPARAISSAIT %d FOIS DANS LA LISTE.\n", nbr, compteur);
    } else {
        printf("\nLA VALEUR %d N'APPARAIT PAS DANS LA LISTE.\n", nbr);
    }

    printf("\nLA NOUVELLE LISTE EST :\n");
    afficherListe(tete);

    return 0;
}
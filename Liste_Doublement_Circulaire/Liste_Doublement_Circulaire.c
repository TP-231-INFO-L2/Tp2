#include <stdio.h>
#include <stdlib.h>

// Definition de notre liste doublement circulaire
typedef struct Liste_Doublement_Circulaire
{
    int value;
    struct Liste_Doublement_Circulaire *prev;
    struct Liste_Doublement_Circulaire *suiv;
    
}doub;
//  Ma liste est vide
doub *liste = NULL;
// Creation du noeud comme pour la liste chainee circulaire simple
doub *noeud(int n){
    doub *nouveau =(doub*)malloc(sizeof(doub));
        // Je verifie si on a belle et bien allouer la memoire (effet de bord)
        if(nouveau == NULL)
        {
            printf("Erreur d'allocation memoire ");
            exit(1);
        }
        nouveau->value = n;
        nouveau->suiv = nouveau;
        nouveau->prev = nouveau;
        return nouveau;
}

// Ajout_tete
doub *ajout_tete(doub *liste,int n)
{
    doub *nouveau;
    nouveau = noeud(n);
    if(liste == NULL)
    {
        liste = nouveau;
    }
    else
    {
        // Je l'ai declarer pour ne pas perdre l'acces au dernier elt
        doub *last = liste->prev;
        nouveau->suiv = liste;
        nouveau->prev = last;
        last->suiv = nouveau;
        liste->prev = nouveau;
        liste = nouveau;
    }
    return liste;
}

doub *ajout_queue(doub *liste,int n)
{
    doub *nouveau = noeud(n);
    if(liste == NULL)
    {
        liste = nouveau;
    }
    else
    {
        doub *last = liste->prev; // je recupere le dernier elt
        nouveau->suiv = liste;
        nouveau->prev = last;
        last->suiv = nouveau;
        liste->prev = nouveau;
    }
return liste;
}

// Affichage de notre liste
void affiche(doub *liste)
{
    doub *afficher = liste;
    // Verification de la liste
    if(liste == NULL)
        printf("La liste semble vide");
    else
    {
        do
        {
            printf("%d \t",afficher->value);
            afficher = afficher->suiv;
        }while(afficher != liste);
        printf("\n");
    }
}

int main()
{
    int c = 0;
    int val;
    doub *liste = NULL;

    printf("Entrer le nombre de valeurs a entrer dans la liste : ");
    scanf("%d",&c);
    // Remplissage de notre liste circulaire
    printf("Ajout au debut \n");
    for(int i = 0; i < c ; i++)
    {
        printf("Valeur %d : ",i+1);
        scanf("%d",&val);
        liste = ajout_tete(liste,val);
    }
    affiche(liste);
    free(liste);
    printf("Ajout en fin \n");
    for(int i = 0; i < c ; i++)
    {
        printf("Valeur %d : ",i+1);
        scanf("%d",&val);
        liste = ajout_queue(liste,val);
    }
    affiche(liste);
    return 0;
}
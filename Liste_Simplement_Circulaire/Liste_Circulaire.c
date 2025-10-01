#include <stdio.h>
#include <stdlib.h>

// Definition de notre liste chainees circulaire
typedef struct Liste_Circulaire
{
    int data;
    struct Liste_Circulaire *next;

}circulaire;

// J'initialise ma liste a vide 
circulaire *l = NULL;

circulaire *new_noeud(int n)
{   
    // Ici je cree un noeud qui va pointer sur lui-meme
    circulaire *nouveau = (circulaire *)malloc(sizeof(circulaire));
    // Je verifie si on a belle et bien allouer la memoire (effet de bord)
    if(nouveau == NULL){
        printf("Erreur d'allocation memoire ");
        exit(1);
    }
    nouveau->data = n;
    nouveau->next = nouveau;
    return nouveau;
}

circulaire *ajout_debut(circulaire *l,int n)
{
    // Creation du noeud qui va pointer sur lui meme
    circulaire *nouveau;
    nouveau = new_noeud(n);
    if(l==NULL)
    {   
        // la je me dis que si la liste pointe vers null alors il prend notre noeud qui pointe sur lui mm
        // Comme ca on aura initialise notre liste circulaire
        l = nouveau;
    }
    else
    {
        /*Ceci s'execute lorsque nous aurions une deuxieme valeur a executer
        Je modelise afin de pouvoir bien deplacer les pointeurs*/
        nouveau->next = l->next;
        l->next = nouveau;
    }
    return l;
}   

circulaire *ajout_fin(circulaire *l,int n)
{
    // Creation d'un nouveau noeud
    circulaire *tempo;
    tempo = new_noeud(n);

    if(l!=NULL)
    {
        // J'indique juste l'addresse pour plus d'explication veuillez me contactez
        tempo->next = l->next;
        l->next = tempo;
    }
    l = tempo;
    return l;
}


void affiche_circulaire(circulaire *l)
{
    circulaire *affichage;
    // Verifie si la liste peu etre vide au depart
    if(l == NULL)
        printf("La liste est vide ");
    else
    {
        affichage = l->next;
        // car il contient l'addresse du premier element puisque c'est une liste circulaire
        do
        {
            printf("%d \t",affichage->data);
            affichage = affichage->next;
        }while(affichage != l->next);
        printf("\n");
    }
}

int main()
{
    int c = 0;
    int val;
    circulaire *l = NULL;

    printf("Entrer le nombre de valeurs a entrer dans la liste : ");
    scanf("%d",&c);
    // Remplissage de notre liste circulaire
    printf("Ajout au debut \n");
    for(int i = 0; i < c ; i++)
    {
        printf("Valeur %d : ",i+1);
        scanf("%d",&val);
        l = ajout_debut(l,val);
    }
    affiche_circulaire(l);
    free(l);
    printf("Ajout en fin \n");
    for(int i = 0; i < c ; i++)
    {
        printf("Valeur %d : ",i+1);
        scanf("%d",&val);
        l = ajout_fin(l,val);
    }
    affiche_circulaire(l);
    return 0;
}

- Cahier de suivi individuel — INF231 (TP)
- Étudiant : Leudjeu Njiatcha Yanis Ael
- Matricule : 24G2349
- Groupe : INF231_EC2

# Projet : Listes Simples Chainees et Circulaire en C
Exercices attribués :
- Ecrire une liste simplement chainees faisant l'insertion d'un element dans une liste triee
- Ecrire une liste simplement chainees circulaire faisant l'ajout entete et fin dans une liste
##  Introduction
Ce projet illustre l’utilisation des **listes simplement chaînées** en langage C, à travers deux cas concrets :  

1. **Liste simplement chaînée circulaire** :  
   - Gestion d’une liste où le dernier élément pointe vers le premier, formant un cycle.  
   - Insertion, affichage et suppression d’éléments.  

2. **Insertion dans une liste simplement chaînée triée** :  
   - Ajout d’un nouvel élément tout en maintenant l’ordre croissant.  
   - Utile pour gérer des données dynamiques toujours ordonnées.  

Ces exercices permettent de renforcer la compréhension des **pointeurs** et de la **gestion dynamique de la mémoire** en C.  

---

##  Fonctionnalités

###  Liste simplement chaînée circulaire
- Création d’un nœud.  
- Insertion d’un élément à la tete.
- Insertion d’un élément à la fin.  
- Affichage de la liste.  


###  Insertion dans une liste triée
- Création d’un nœud.  
- Insertion d’un élément au bon emplacement en conservant l’ordre croissant.  
- Affichage de la liste.  

---

##  Structures de données

### Liste simplement chaînée circulaire
```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;

## Compilation et Execution

gcc Liste_Circulaire.c -o circ
./circ

gcc "INSERTION LISTE SIMPLEMENT CHAÎNÉ TRIÉ.c" -o trie
./trie


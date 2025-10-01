# Projet : Listes Doublement Chaînées Circulaires en C

**Nom :** MAFOGANG MBE  
**Prénom :** JENNIE PRISCA  
**Matricule :** 24G2630  

---

## Introduction
Ce projet illustre l’utilisation des **listes doublement chaînées circulaires** en langage C.  
Deux cas principaux sont traités :  
1. **Insertion en tête et en queue** : ajout d’éléments au début ou à la fin de la liste.  
2. **Insertion dans une liste triée** : maintien automatique de l’ordre croissant lors de l’ajout d’un nouvel élément.  

Ces programmes permettent de comprendre :  
- Les notions de **maillons (nœuds)**.  
- Les pointeurs **avant/arrière**.  
- La gestion circulaire (**le dernier élément pointe vers le premier et inversement**).  

---

## Fonctionnalités
- Création d’une liste doublement chaînée circulaire.  
- Insertion en tête.  
- Insertion en queue.  
- Insertion dans une liste triée.  
- Affichage des éléments de la liste.  

---

## Structure d’un nœud
```c
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

gcc programme.c -o programme
puis 
./programme
#  Projet : Listes Chaînées en C

##  Auteur
- **Nom :** MBALLA YVES ELYSEE  
- **Matricule :** 24G2879

- **Nom :** NGINDJEL ONANA BENOIT AURION  
- **Matricule :** 24F2839
  
- **Nom :** TANDJI NKWINGA RIDEL RONIS
- **Matricule :** 24G2856
  
- **Nom :** LEUDJEU NJIATCHA YANIS AEL
- **Matricule :** 24G2349
  
- **Nom :** MAFOGANG MBE JENNIE PRISCA
- **Matricule :** 24G2630 

- **Nom :** FOUDA ZANGANA CHARLES GHISLAIN DONIVANE
- **Matricule :** 24G2912

---

##  Introduction
Ce dépôt regroupe différents programmes en **langage C** illustrant l’utilisation des **listes chaînées** (simples, doublement chaînées, circulaires, avec insertion et suppression).  
Chaque projet met en avant une variante particulière des listes, permettant de comprendre les notions de :  
- Maillons (**nœuds**)  
- Pointeurs (`next`, `prev`)  
- Gestion circulaire (dernier nœud relié au premier)  
- Suppression et insertion dynamiques  

---

##  Contenu du dépôt

### 🔹 1. Liste_Doublement_Circulaire
- Implémentation d’une **liste doublement chaînée circulaire**.  
- Fonctionnalités : insertion, affichage d’éléments.  
- Application : manipulation de données avec parcours dans les deux sens.  

### 🔹 2. Liste_Doublement_Insert
- Implémentation d’une **liste doublement chaînée simple avec tri par insertion**.  
- Fonctionnalités : insertion d'un element dans une liste et affichage parcours dans les deux sens possibles.  
- Application : garder la liste toujours ordonnée (tri par ordre croissant) après chaque insertion.  

### 🔹 3. Liste_Simple_Insert
- Implémentation d’une **liste simplement chaînée avec insertion dans l’ordre croissant**.  
- Fonctionnalités : ajout d’un élément tout en maintenant le tri.  
- Application : gestion d’une liste triée sans avoir besoin de retrier après insertion.  

### 🔹 4. Liste_Simplement_Circulaire
- Implémentation d’une **liste simplement chaînée circulaire**.  
- Fonctionnalités : insertion, affichage et suppression d’un élément donné.  
- Application : représentation de structures cycliques (ex. : jeux, tours de rôle).  

### 🔹 5. Supprimer_Occurence_Doublement
- Implémentation d’une **liste doublement chaînée simple** avec suppression de **toutes les occurrences** d’une valeur.  
- Fonctionnalités : ajout, affichage, suppression multiple, libération mémoire.  
- Application : nettoyage d’une liste contenant plusieurs doublons.  

### 🔹 6. Supprimer_Occurence_Simplement
- Implémentation d’une **liste simplement chaînée** avec suppression de **toutes les occurrences** d’une valeur.  
- Fonctionnalités : ajout, affichage, suppression multiple, libération mémoire.  
- Application : gestion simplifiée de données avec suppression en masse.  

---

##  Structures de données

###  Liste simplement chaînée
```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```

### 🔸 Liste doublement chaînée
```c
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
```

---

## 💻 Compilation & Exécution
Compiler avec :
```bash
gcc fichier.c -o programme
```
Exécuter avec :
```bash
./programme
```

---

## Complexité (Résumé)
                                | Simple Chaînée | Doublement Chaînée |
                                |----------------|---------------------|
 Insertion en tête              | O(1)           | O(1)                |
 Insertion en queue             | O(n)           | O(1)                |
 Insertion triée                | O(n)           | O(n)                |
 Suppression d’un élément       | O(n)           | O(n)                |
 Suppression de toutes occurrences | O(n)        | O(n)                |  Affichage                      | O(n)           | O(n)                |

---

##  Exemple d’utilisation

### Liste Doublement Chaînée Circulaire
```
Entrer le nombre d'éléments: 4
Élément 1: 10
Élément 2: 20
Élément 3: 30
Élément 4: 40
10 20 30 40
Vous voulez supprimer quel élément? 20
Élément 20 supprimé.
10 30 40
```

### Liste Simplement Chaînée Triée
```
Liste initiale : 10 20 40 50
Nouvel élément à insérer : 30
Liste après insertion : 10 20 30 40 50
```

---

##  Conclusion
Ce projet met en pratique différentes variantes de **listes chaînées** en C :  
- **simples** et **doublement chaînées**  
- **circulaires** et **non circulaires**  
- avec **insertion triée** et **suppression multiple**  

Il constitue une excellente base pour comprendre la **gestion des pointeurs**, la **mémoire dynamique** et les **structures de données fondamentales**.  

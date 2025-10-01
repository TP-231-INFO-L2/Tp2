# Structures de Données : Listes Chaînées

**Nom :** NGINDJEL ONANA  
**Prénom :** BENOIT AURION  
**Matricule :** 24F2839  

---

## 1. Liste Doublement Chaînée Circulaire

### Description
Cette structure est une liste doublement chaînée circulaire où chaque nœud contient :
- Une valeur entière (`val`)
- Un pointeur vers le nœud suivant (`suiv`)
- Un pointeur vers le nœud précédent (`prev`)

### Fonctions principales
- `inserer(int valeur)` : insère un élément à la fin de la liste.  
- `affiche(*tete)` : affiche les éléments depuis la tête jusqu’au retour au début.  
- `supprimer(Noeud **tete, int V)` : supprime le premier nœud contenant la valeur V.  

### Fonctionnalités
- **Insertion :**  
  Si la liste est vide, le nouvel élément devient la tête et pointe sur lui-même. Sinon, insère à la fin en mettant à jour les pointeurs.  
- **Affichage :**  
  Parcourt la liste circulaire à partir de la tête pour afficher toutes les valeurs.  
- **Suppression :**  
  Supprime le premier nœud contenant la valeur donnée. Gère les cas : liste vide, un seul élément ou plusieurs.  

### Complexités
| Fonction   | Complexité temporelle | Complexité spatiale |
|------------|------------------------|----------------------|
| inserer    | O(1)                   | O(1)                 |
| affiche    | O(n)                   | O(1)                 |
| supprimer  | O(n)                   | O(1)                 |

### Compilation & Exécution
```bash
gcc -o liste_circ liste_doublement_chainee_circulaire.c
./liste_circ

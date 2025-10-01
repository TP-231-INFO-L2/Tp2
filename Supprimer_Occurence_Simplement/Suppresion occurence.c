#include <stdio.h>
#include <stdlib.h>

// Définition d’un nœud
struct Node {
    int data;
    struct Node* next;
};

// Fonction pour créer un nouveau nœud
struct Node* newNode(int val) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = val;
    p->next = NULL;
    return p;
}

// Construire la liste en lisant n éléments
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *last = NULL;
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        temp = newNode(val);
        if (head == NULL) {
            head = temp;
        } else {
            last->next = temp;
        }
        last = temp;
    }
    return head;
}

// Afficher la liste
void printList(struct Node* head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Supprimer toutes les occurrences de x
struct Node* deleteOccurrences(struct Node* head, int x) {
    // Cas où la tête contient x
    while (head != NULL && head->data == x) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == x) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}

// Programme principal
int main() {
    int n, x;
    printf("Nombre d’elements : ");
    scanf("%d", &n);

    printf("Entrez les %d elements :\n", n);
    struct Node* head = createList(n);

    printf("Liste initiale : ");
    printList(head);

    printf("Valeur a supprimer : ");
    scanf("%d", &x);

    head = deleteOccurrences(head, x);

    printf("Liste apres suppression : ");
    printList(head);
}
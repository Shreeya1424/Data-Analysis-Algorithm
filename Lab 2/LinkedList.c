#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at last
void insert(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;

    if (head == NULL)
        head = n;
    else {
        struct Node *t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
}

// Delete at last
void del() {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *t = head;
    while (t->next->next) t = t->next;
    free(t->next);
    t->next = NULL;
}

// Display
void show() {
    struct Node *t = head;
    if (!t) {
        printf("Empty\n");
        return;
    }
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    del();
    show();    
    return 0;
}

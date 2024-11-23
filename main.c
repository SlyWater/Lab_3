#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct node {
    char inf[256];
    struct node* next;
} node;


node* get_stack() {
    struct node* p = NULL;
    char s[256];

    if ((p = (node*)malloc(sizeof(node))) == NULL)
    {
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }

    printf("Введите название объекта: \n");
    scanf("%s", s);
    if (*s == 0)
    {
        printf("Запись не была произведена\n");
        return NULL;
    }
    strcpy(p->inf, s);
    p->next = NULL;

    return p;
}

void push(node** s) {
    node* p = get_stack();
    if (p != NULL) {
        p->next = *s;
        *s = p;
    }
}

void pop(node** s) {
    node* p = *s;
    if (*s == NULL) {
        printf("\nСтек пуст\n");
        return;
    }
    *s = (*s)->next;
    printf("\nУдален элемент: %s\n", p->inf);
    free(p);
}

void review(node* s) {
    node* p = s;
    printf("\nСтек\n");
    if (s == NULL) printf("Стек пуст\n");
    while (p) {
        printf("Имя - %s\n", p->inf);
        p = p->next;
    }
    return;
}

int main() {
    setlocale(LC_ALL, "Rus");
    node* stack = NULL;
    push(&stack);
    push(&stack);
    push(&stack);
    review(stack);
    pop(&stack);
    review(stack);
    pop(&stack);
    review(stack);
    pop(&stack);
    review(stack);
    pop(&stack);
    return 0;
}
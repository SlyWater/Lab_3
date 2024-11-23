#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct node {
    char inf[256];
    struct node* next;
} node;

struct node* head = NULL, * last = NULL;
void push(void), review(void), pop(void);
char find_el[256];
struct node* find(char* name);
struct node* get_struct(void);

struct node* get_struct(void) {
    struct node* p = NULL;
    char s[256];

    if ((p = (node*)malloc(sizeof(struct node))) == NULL)
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

void push(void) {
    struct node* p = NULL;
    p = get_struct();
    if (p == NULL) return;

    if (head == NULL)
    {
        head = p;
        last = p;
    }
    else
    {
        last->next = p;
        last = p;
    }
}

void pop(void) {
    if (head == NULL)
    {
        printf("\nОчередь пуста\n");
        return;
    }

    struct node* temp = head;
    head = head->next;
    free(temp);

    if (head == NULL)
    {
        last = NULL;
    }
}

void review(void) {
    struct node* struc = head;
    printf("\n");
    if (head == NULL)
    {
        printf("\nОчередь пуста\n");
    }
    while (struc)
    {
        printf("Имя - %s\n", struc->inf);
        struc = struc->next;
    }
    return;
}

struct node* find(char* name) {
    struct node* struc = head;
    if (head == NULL)
    {
        printf("\nОчередь пуста\n");
    }
    while (struc)
    {
        if (strcmp(name, struc->inf) == 0)
        {
            return struc;
        }
        struc = struc->next;
    }
    printf("\nЭлемент не найден\n");
    return NULL;
}

int main() {
    setlocale(LC_ALL, "Rus");
    push();
    push();
    push();
    review();
    pop();
    review(); 
    pop();
    pop();
    pop();

    return 0;
}
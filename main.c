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
void spstore(void), review(void), del(char* name);
char find_el[256];
struct node* find(char* name);
struct node* get_struct(void);

struct node* get_struct(void)
{
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

void spstore(void)
{
    struct node* p = NULL;
    p = get_struct();
    if (p == NULL) return;

    if (head == NULL)
    {
        head = p;
        last = p;
    }
    else if (strlen(p->inf) < strlen(head->inf))
    {
        p->next = head;
        head = p;
    }
    else
    {
        struct node* current = head;
        while (current->next != NULL && strlen(current->next->inf) <= strlen(p->inf))
        {
            current = current->next;
        }
        p->next = current->next;
        current->next = p;
        if (p->next == NULL) last = p;
    }
}

void review(void)
{
    struct node* struc = head;
    if (head == NULL)
    {
        printf("Список пуст\n");
    }
    while (struc)
    {
        printf("Имя - %s, \n", struc->inf);
        struc = struc->next;
    }
    return;
}

struct node* find(char* name)
{
    struct node* struc = head;
    if (head == NULL)
    {
        printf("Список пуст\n");
    }
    while (struc)
    {
        if (strcmp(name, struc->inf) == 0)
        {
            return struc;
        }
        struc = struc->next;
    }
    printf("Элемент не найден\n");
    return NULL;
}

void del(char* name)
{
    struct node* struc = head;
    struct node* prev = NULL;
    int flag = 0;

    if (head == NULL)
    {
        printf("Список пуст\n");
        return;
    }

    if (strcmp(name, struc->inf) == 0)
    {
        flag = 1;
        head = struc->next;
        free(struc);
        struc = head;
    }
    else
    {
        prev = struc;
        struc = struc->next;
    }

    while (struc)
    {
        if (strcmp(name, struc->inf) == 0)
        {
            flag = 1;
            if (struc->next)
            {
                prev->next = struc->next;
                free(struc);
                struc = prev->next;
            }
            else
            {
                prev->next = NULL;
                free(struc);
                return;
            }
        }
        else
        {
            prev = struc;
            struc = struc->next;
        }
    }

    if (flag == 0)
    {
        printf("Элемент не найден\n");
        return;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    spstore();
    spstore();
    spstore();
    review();
    return 0;
}
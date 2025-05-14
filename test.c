#include <stdio.h>
#include <stdlib.h>

typedef struct s_list{
    int data;
    struct s_list *next;
} t_list;

t_list *createNode(int data)
{
    t_list *new;
    new = malloc(sizeof(t_list));
    if (!new)
        return NULL;
    new->data = data;
    new->next = NULL;
    return new;
}

void addback(t_list **lst,int data)
{
    t_list *temp;
    t_list *toapp;

    toapp = createNode(data);
    if (!*lst)
    {
        *lst = toapp;
        return;
    }
    temp = *lst;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = toapp;
}

void printdata(t_list *liste)
{
    while (liste)
    {
        printf("data : %d\n", liste->data);
        liste = liste->next;
    }
}
void rrliste(t_list **liste)
{
    t_list *temp;
    t_list *end;
    temp = *liste;
    while (temp->next)
    {
        end = temp; //khdit akhir node 
        temp = temp->next;
    }
    end->next = NULL;
    // temp->next = NULL; //the new end of the liste
    temp->next = *liste; //anwli npointi 3la lhead
    *liste = temp; // lpointer mpointi 3la lhead jdid
}

void addfront(t_list **head, int data)
{
    t_list *temp;
    t_list *toadd;
    toadd = createNode(data);
    if (!*head)
    {
        *head = toadd;
        return;
    }
    temp = *head;
    toadd->next = temp;
    *head = toadd;
}
int main()
{
    t_list *liste = NULL;

    addfront(&liste, 1000);
    addback(&liste, 2);
    addback(&liste, 1);
    addback(&liste, 9);
    addback(&liste, 15);
    addback(&liste, 3);
    rrliste(&liste);
    addfront(&liste, 100);
    printdata(liste);
}
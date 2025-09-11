#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdlib.h>

typedef struct item{
    struct item *prev;
    struct item *next;
}item;

typedef struct list{
    item *head;
    item *tail;
}list;

int createItem(item **item);

void add(list *listadd,item *itemadd);

int count(list *listAddress);

void listout(list *listAddress);

item* getItem(list *listAddress,int n);

item* removeItem(list *listAddress,int n);

void Delete(list *listadd,int n);

void clear(list *listadd);

void clear(list *listadd);

void insert(list *listadd,item *itemadd,int n);

#endif
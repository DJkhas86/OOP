#include "list.hpp"
#include <iostream>

Item::Item(){
    next = (nullptr);
    prev = (nullptr);
    owner = (nullptr);
}

Item::~Item() {
    if(owner){
        owner->removeItem(owner->getIndex(this));
    }
}

List::List(){
    head = (nullptr);
    tail = (nullptr);
}

List::~List() {
    clear();
}

void List::add(Item *itemadd){
    if(itemadd){
        itemadd->owner = this;
        if(!head){
            head = tail = itemadd;
        }else{
            tail->next = itemadd;
            itemadd->prev = tail;
            tail = itemadd;
        }
    }
}

int List::count(){
    Item *temp = head;
    int count  =  0;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}

Item* List::getItem(int n){
    if(n < 0){
        return nullptr;
    }
    Item *temp = head;
    int i = 0;
    while(temp && i < n){
        temp = temp->next;
        i++;
    }
    return temp;
}

Item* List::removeItem(int n){
    Item *item = getItem(n);
    if(!item) return nullptr;

    if(item == head){
        head = item->Next();
        if(head){
            head->prev = nullptr;
        }
        else{
            tail = nullptr;
        }
    }
    else if ( item == tail){
        tail = item->Prev();
        if(tail){
            tail->next = nullptr;
        }
        else{
            item->Prev()->next = item->Next();
            item->Next()->prev = item->Prev();
        }
    }else
    {
        item->Prev()->next = item->Next();
        item->Next()->prev = item->Prev();
    }
    item->next = nullptr;
    item->prev = nullptr;
    item->owner = nullptr;
}

void List::Delete(int n){
    if(n < 0) throw std::out_of_range("Index is out of range.");
    Item* item = getItem(n);
    if (!item) return;
    delete item;
}

void List::clear(){
     while (head) {
        Delete(0);
    }
}

int List::getIndex(Item *itemadd){
    int i = 0;
    Item *temp = NULL;

    if (itemadd) {
        temp = head;

        while (temp != itemadd && temp) {
            i++;
            temp = temp->next;
        }
    }

    return (temp) ? i : -1;
}

void List::insert(Item *itemadd,int n){
    if(!itemadd) return;

    itemadd->owner = this;
    
    if(n == 0){
        if(head){
            itemadd->next = head;
            head->prev = itemadd;
        }
        head = itemadd;
        if(!tail) tail = itemadd;
        return;
    }
    Item *temp = getItem(n);
    if(!temp){
        add(itemadd);
        return;
    }
    itemadd->next = temp;
    itemadd->prev = temp->prev;
    if(temp->prev){
        temp->prev->next = itemadd;
    }
    temp->prev = itemadd;
}

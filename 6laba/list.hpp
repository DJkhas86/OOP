#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>


class List;

class Item{
    public:
        Item* next;
        Item* prev;
        List* owner;
        Item();
        ~Item();
        Item* Next() const{return next;}
        Item* Prev() const{return prev;}

        friend class List;
};

class List{
    public:
        Item* head;
        Item* tail;
        List();
        ~List();
        void add(Item *itemadd);
        int count();
        Item* getItem(int n);
        Item* removeItem(int n);
        int getIndex(Item *itemadd);
        void Delete(int n);
        void clear();
        void insert(Item *itemadd,int n);
        Item* Head() const { return head; }
        Item* Tail() const { return tail; }
};


#endif
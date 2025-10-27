#include<stdlib.h>
#include<stdio.h>

typedef struct item{
    struct item *prev;
    struct item *next;
}item;

typedef struct list{
    item *head;
    item *tail;
}list;

void cls() {
    system("cls");
}

int createItem(item **item){
    int code = 0;
    *item =calloc(1,sizeof(item));
    if(!item){
        code = 1;
    }
    return code;
}

void add(list *listadd,item *itemadd){
    if (listadd && itemadd) {
        if(listadd->head == NULL){
            itemadd->next = NULL;
            itemadd->prev = NULL;
            listadd->head = itemadd;
            listadd->tail = itemadd;
        }
        else{
            itemadd->next = NULL;
            itemadd->prev = listadd->tail;
            listadd->tail->next = itemadd;
            listadd->tail = itemadd;
        }
    }    
}

int count(list *listAddress){
    item *items = listAddress->head;
    int i = 0;
    if(listAddress->head != NULL){
        while(items){
            i++;
            items = items->next;
        }
    }
    return i;
}

void listout(list *listAddress){
    item *items = listAddress->head;
    int i = 0;
    printf("List: %p\tHead: %p\tTail: %p\n", listAddress, listAddress->head, listAddress->tail);
    printf("N\titem\t\tprev\t\tnext\n");
    while(items){
        printf("%d%016p\t%016p\t%016p\n", i, items, items->prev, items->next);
        i++;
        items = items->next;
    }
}

item* getItem(list *listAddress,int n){
    item *items = NULL;
    if(listAddress->head != NULL){
        items = listAddress->head;
        int i = 0;
        while(items  && i != n){
            items = items->next;
            i++;
        }
    }
    return items;
}

item* getIndex(item *itemadd,list *listadd){
    int i = 0;
    int f = 0;
    item *current = listadd->head;
    while(current != itemadd){
        i++;
        current = current->next;
        f = 1;
    }
    if (f == 1){
        return current;
    }
    else{
        return 0;
    }
}

item* removeItem(list *listAddress,int n){
    item *itemFound = NULL;
    if(listAddress){
        itemFound = getItem(listAddress,n);
        if(itemFound){
            item *temp = NULL;
            if(listAddress->head == listAddress->tail){
                listAddress->head = NULL;
                listAddress->tail = NULL;
            }
            else if(itemFound ==listAddress->head){
                temp = itemFound->next;
                temp->prev = NULL;
                listAddress->head = temp;
            }
            else if(itemFound ==listAddress->tail){
                temp = itemFound->prev;
                temp->next = NULL;
                listAddress->tail = temp;
            }
            else{
                temp = itemFound->prev;
                temp->next = itemFound->next;
                temp = itemFound->next;
                temp->prev = itemFound->prev;
            }
        }
    }
    return itemFound;
}

void Delete(list *listadd,int n){
    if(listadd){
        item *itemFound = removeItem(listadd,n);
        if(itemFound){
            free(itemFound);
        }
    }
}    

void clear(list *listadd){
    if(listadd){
        while(listadd->head){
            Delete(listadd,0);
        }
    }
    listadd->head = NULL;
    listadd->tail = NULL;
}

void insert(list *listadd,item *itemadd,int n){
    if(listadd && itemadd){
        item *next = getItem(listadd,n);
        if (listadd->head == NULL || !next) {
            add(listadd, itemadd);
        }
        else if(next == listadd->head){
            itemadd->next = listadd->head;
            listadd->head->prev = itemadd;
            listadd->head = itemadd;
        }
        else{
            itemadd->next = next;
            itemadd->prev = next->prev;
            next->prev->next = itemadd;
            next->prev = itemadd;
        }
    }
}

int main(){
    int p = 1, choise = 0,poisk = 0,amount = 0;
    list *listAddress= malloc(sizeof(item));
    item *items = NULL;
    item *functionTest = malloc(sizeof(item));
    listAddress->head = NULL;
    listAddress->tail = NULL;
    while(p != 0){
        printf("menu:\n");
        printf("1.Add Item\n");
        printf("2.List Output\n");
        printf("3.Count Items\n");
        printf("4.Get Item by index\n");
        printf("5.Remove Item \n");
        printf("6.Delete Item \n");
        printf("7.Clear List \n");
        printf("8.insert Item \n");
        printf("9.get index \n");
        printf("0.Close program\n");
        scanf("%d",&choise);
        switch (choise) {
            cls();
            case 0:
                p = 0;
                
                break;
            case 1:
                if(!createItem(&items)){
                    add(listAddress,items);
                    printf("Item %p added\n",items);
                }
                else{
                    printf("Memory allocation error! Please try again\n");
                }
                break;
            case 2:
                listout(listAddress);
                break;
            case 3:
                amount = count(listAddress);
                printf("Amount Items:%d \n",amount);
                break;
            case 4:
                printf("Choose Index of Item:");
                scanf("%d",&poisk);
                functionTest = getItem(listAddress,poisk);
                printf("Item: %p\tNext: %p\tPrev: %p\n", functionTest, functionTest->next, functionTest->prev);
                break;
            case 5:
                printf("Choose Index to Remove:");
                scanf("%d",&poisk);
                functionTest = removeItem(listAddress,poisk);
                listout(listAddress);
                break;
            case 6:
                if(listAddress->head != NULL){
                    printf("Choose Index to Delete:");
                    scanf("%d",&poisk);
                    Delete(listAddress,poisk);
                    listout(listAddress);
                    }
                    else{
                        printf("ERROR:List is empty\n");
                    }
                break;
            case 7:
                if(listAddress->head != NULL){
                    clear(listAddress);
                }
                else{
                    printf("ERROR:List is empty\n");
                }
                break;
            case 8:
                if(!createItem(&items)){
                    printf("Choose Index to Insert:");
                    scanf("%d",&poisk);
                    insert(listAddress,items,poisk);
                }
                break;
            case 9:
                functionTest = getIndex(getItem(listAddress,2),listAddress);
                printf("Item: %p\tNext: %p\tPrev: %p\n", functionTest, functionTest->next, functionTest->prev);
                break;        
            }
    }
    free(listAddress);
    free(items);
    free(functionTest);
    system("pause");
    return 0;
}
#include "interface.h"
#include <stdio.h>

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
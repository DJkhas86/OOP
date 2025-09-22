#include "3interface.h"
#include "3subj.h"
#include <stdio.h>
int main(){
    int p = 1, choise = 0,poisk = 0,amount = 0;
    list *listAddress= malloc(sizeof(item));
    item *items = NULL;
    Base *bas = NULL;
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
        printf("0.Close program\n");
        scanf("%d",&choise);
        switch (choise) {
            case 0:
                p = 0;
                
                break;
            case 1:{
                int t = rand() % 5;
                switch(t){
                    case(0):
                        break;
                    case(1):{
                        bas = createObject(itSingleIndicator);
                        inputrand(bas);
                        break;
                    }
                    case(2):{
                        bas = createObject(itTwoColorIndicator);
                        inputrand(bas);
                        break;
                    }
                    case(3):{
                        bas = createObject(itSignIndicator);
                        inputrand(bas);
                        break;
                    }
                    case(4):{
                        bas = createObject(itMatrixIndicator);
                        inputrand(bas);
                        break;
                    }
                }
                if(t != 0){
                    add(listAddress,(item *)bas);
                    print(bas);
                }
                break;
            }
            case 2:
                printList(listAddress);
                break;
            case 3:
                amount = count(listAddress);
                printf("Amount Items:%d \n",amount);
                break;
            case 4:
                printf("Choose Index of Item:");
                scanf("%d",&poisk);
                functionTest = getItem(listAddress,poisk);
                print((Base *)functionTest);
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
            case 8:{
                int t = rand() % 5;
                switch(t){
                    case(0):
                        break;
                    case(1):{
                        bas = createObject(itSingleIndicator);
                        inputrand(bas);
                        break;
                    }
                    case(2):{
                        bas = createObject(itTwoColorIndicator);
                        inputrand(bas);
                        break;
                    }
                    case(3):{
                        bas = createObject(itSignIndicator);
                        inputrand(bas);
                        break;
                    }
                    case(4):{
                        bas = createObject(itMatrixIndicator);
                        inputrand(bas);
                        break;
                    }
                }    
                if(bas){
                        printf("Choose Index to Insert:");
                        scanf("%d",&poisk);
                        insert(listAddress,(item*)bas,poisk);
                    }
                break;
            }
        }    
    }
    free(listAddress);
    free(items);
    free(functionTest);
    free(bas);
    system("pause");
    return 0;
}
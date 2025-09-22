#include "3subj.h"

char *typeName[] = {
    "Empty","SingleIndicator","TwoColorIndicator","SignIndicator","MatrixIndicator"
};

Base* createObject(ItemType type){
    Base *obj = NULL;
    switch(type){
        case(itSingleIndicator):
            obj = (Base *)calloc(1, sizeof(signIndicator));
            break;
        case(itTwoColorIndicator):
            obj = (Base *)calloc(1, sizeof(twoCOlorIndicator));
            break;
        case(itSignIndicator):
            obj = (Base *)calloc(1, sizeof(signIndicator));
            break;
        case(itMatrixIndicator):
            obj = (Base *)calloc(1, sizeof(matrixIndicator));
            break;
        default:
            printf("undefined type!\n");
            break;
    }
    if (obj) {
        obj->Item = type;
    }
    return obj;
}

void input(Base *obj){
    if (!obj) return;
    SafeInputString("Enter name: ", obj->name, 50);
    SafeInputFloat("Enter Voltage Drop: ");
    obj->currentLimit = SafeInputFloat("Enter Current Limit: ");
    obj->waveLength = SafeInputFloat("Enter Wave Length: ");
    obj->radiationPower = SafeInputFloat("Enter Radiation Power: ");
    obj->summarPower = obj->currentLimit * obj->radiationPower;
    switch (obj->Item){
        case itSingleIndicator: {
            singleIndicator *si = (singleIndicator *)obj;
            SafeInputString("Enter figure: ", si->figure, 50);
            si->radiatingArea = SafeInputFloat("Enter Radiation Limit: ");
            break;
        }
        case itTwoColorIndicator: {
            twoCOlorIndicator *tci = (twoCOlorIndicator *)obj;
            SafeInputFloat("Enter Wave Length: ");
            SafeInputFloat("Enter Radiation Power Of Second Crystal: ");
            tci->base.summarPower =  tci->base.summarPower + (tci->base.currentLimit * tci->radPowOFsecondCrystal);
            break;
        }
        case itSignIndicator: {
            signIndicator *signI = (signIndicator *)obj;
            signI->amountSegments = SafeInputInt("Enter Amount Segments: ", 0, 100);
            signI->signs = SafeInputInt("Enter Signs (1 - yes, 0 - no): ", 0, 1);
            SafeInputString("Enter Type Of Connection (anode, cathode, separate): ", signI->connectionDiagram, 8);
            signI->base.summarPower = signI->base.summarPower * signI->amountSegments;
            break;
        }
        case itMatrixIndicator: {
            matrixIndicator *mi = (matrixIndicator *)obj;
            mi->strings = SafeInputInt("Enter Amount Strings: ", 0, 100);
            mi->column = SafeInputInt("Enter Amount Column:", 0, 100);
            mi->base.summarPower = mi->base.summarPower *(mi->column * mi->strings);
            break;
        }
        default:
            printf("undefined type!\n");
    }

}
void inputrand(Base *obj){
    if (!obj) return;
    snprintf(obj->name,sizeof(obj->name),"%d",rand() % 11);
    obj->voltageDrop = rand()%101;
    obj->currentLimit = rand()%101;
    obj->waveLength = rand()%101;
    obj->radiationPower = rand()%101;
    obj->summarPower = obj->currentLimit * obj->radiationPower;
    switch (obj->Item){
        case itSingleIndicator: {
            singleIndicator *si = (singleIndicator *)obj;
            snprintf(si->figure,sizeof(si->figure),"%d",rand() % 3);
            si->radiatingArea = rand()%101;
            break;
        }
        case itTwoColorIndicator: {
            twoCOlorIndicator *tci = (twoCOlorIndicator *)obj;
            tci->waveLength = rand()%101;
            tci->radPowOFsecondCrystal = rand()%101;
            break;
        }
        case itSignIndicator: {
            signIndicator *signI = (signIndicator *)obj;
            signI->amountSegments = rand()%101;
            signI->signs = rand()%3;
            snprintf(signI->connectionDiagram,sizeof(signI->connectionDiagram),"%d",rand() % 5);
            break;
        }
        case itMatrixIndicator: {
            matrixIndicator *mi = (matrixIndicator *)obj;
            mi->strings = rand()%101;
            mi->column = rand()%101;
            break;
        }
        default:
            printf("undefined type!\n");
    }

}

void print(Base *obj){
    if (!obj) return;
    printf("Name: %s\n", obj->name);
    printf("Voltage Drop: %f\n", obj->voltageDrop);
    printf("Current Limit: %f\n", obj->currentLimit);
    printf("Wave Length: %f\n", obj->waveLength);
    printf("Radiation Power: %f\n", obj->radiationPower);
    printf("summar Power: %f\n", obj->summarPower);
    
    switch (obj->Item) {
        case itSingleIndicator: 
        {
            singleIndicator *si = (singleIndicator *)obj;
            printf("Figure: %s\n", si->figure);
            printf("Radiating Area: %d\n", si->radiatingArea);
            break;
        }
        case itTwoColorIndicator: {
            twoCOlorIndicator *tci = (twoCOlorIndicator *)obj;
            printf("radPowOFsecondCrystal %d\n", tci->radPowOFsecondCrystal);
            printf("second wave length %d\n", tci->waveLength);
            break;
        }
        case itSignIndicator: {
            signIndicator *singI = (signIndicator *)obj;
            printf("Amount Segments: %d\n", singI->amountSegments);
            printf("Signs?: %d\n", singI->signs ? "Yes" : "No");
            printf("Connection of Diagramm: %s\n", singI->connectionDiagram);
            break;
        }
        case itMatrixIndicator: {
            matrixIndicator *mi = (matrixIndicator *)obj;
            printf("amount Strings: %d\n", mi->strings);
            printf("amount column: %d\n", mi->column);
            break;
        }
        default:
            printf("Undefined type\n");
    }
}

void printList(list *list){
     if (!list || !list->head) {
        printf("Список пуст.\n");
        return;
    }
    item *p = list->head;
    while (p) {
        print((Base *)p);
        p = p->next;
        printf("\n");
    }
}

int compareWave(Base *obj1,Base *obj2){
    int result = 0;
    if(obj1 && obj2){
        if(obj1->waveLength > obj2->waveLength){
            result = 1;
        }
    }
    return result;
}

void sortList(list *listadd){
    if (!listadd || !listadd->head) return;
    int i = 0,j = 1,n = count(listadd);
    list *buffl = listadd;
    Base *temp1 = NULL;
    Base *temp2 = NULL;
    Base *bufft = NULL;
    for(i = 0;i<n;i++){
        temp1 = (Base *)getItem(listadd,i);
        for(j=i+1;j<n;j++){
            temp2 = (Base *)getItem(listadd,j);
            if(compareWave(temp1,temp2)){
                *getItem(listadd,j) = temp1->base;
                *getItem(listadd,i) = temp2->base;
            }   
        }
    }
}

void found(list *list){
    int min,max,i;
    printf("Enter Min edge");
    scanf("%d",&min);
    printf("Enter Max edge");
    scanf("%d",&max);
    for(i = 0;i < count(list);i++){
        if(((Base*)getItem(list,i))->summarPower >= min && ((Base *)getItem(list,i))->summarPower <= max){
            printf("Item: %p\tNext: %p\tPrev: %p\n", getItem(list,i), getItem(list,i)->next, getItem(list,i)->prev);
        }
    }
}


int SafeInputInt(const char *prompt, int minValue, int maxValue) {
    int value;
    char buffer[100];
    int isValid = 0;

    do {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin)) {
            if (sscanf(buffer, "%d", &value) == 1 && value >= minValue && value <= maxValue) {
                isValid = 1;
            } else {
                printf("ERRORR: print number in [%d - %d]!\n", minValue, maxValue);
            }
        }
    } while (!isValid);

    return value;
}

float SafeInputFloat(const char *prompt) {
    float value;
    char buffer[100];
    int isValid = 0;

    do {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin)) {
            if (sscanf(buffer, "%f", &value) == 1) {
                isValid = 1;
            } else {
                printf("ERRRORRR: printf correct number\n");
            }
        }
    } while (!isValid);

    return value;
}


void SafeInputString(const char *prompt, char *destination, int maxLength) {
    char buffer[256];
    int isValid = 0;

    do {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin)) {
            // Удаляем символ новой строки
            buffer[strcspn(buffer, "\n")] = 0;

            if (strlen(buffer) <= (size_t)maxLength) {
                strncpy(destination, buffer, maxLength);
                isValid = 1;
            } else {
                printf("ERRRORRR - max string length - %d.\n", maxLength);
            }
        }
    } while (!isValid);
}
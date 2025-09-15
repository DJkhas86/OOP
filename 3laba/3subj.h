#ifndef SUBJ_H
#define SUBJ_H

#include "3Interface.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    itNone,
    itSingleIndicator,
    itTwoColorIndicator,
    itSignIndicator,
    itMatrixIndicator
} ItemType;

extern const char *const TypeName[];

typedef struct Base{
    item base;
    ItemType Item;
    char name[3];
    float voltageDrop;
    float currentLimit;
    float waveLength;
    float radiationPower;
    float summarPower;

}Base;
//единичных индикаторов
typedef struct{
    Base base;
    char figure[50];
    int radiatingArea;

}singleIndicator;

typedef struct{
    Base base;
    float waveLength;
    float radPowOFsecondCrystal;
}twoCOlorIndicator;

typedef struct{
    Base base;
    int amountSegments;
    int signs;
    char connectionDiagram[50];
}signIndicator;

typedef struct{
    Base base;
    int strings;
    int column;
}matrixIndicator;

Base* createObject(ItemType);
void input(Base *obj);
void print(Base *obj);

void printList(list *list);
void sortList(list *list);
int compareWave(Base *obj1,Base *obj2);
void found(list *list);


// Безопасный ввод целого числа с проверкой
int SafeInputInt(const char *prompt, int minValue, int maxValue);
// Безопасный ввод числа с плавающей точкой
float SafeInputFloat(const char *prompt);
// Безопасный ввод строки
void SafeInputString(const char *prompt, char *destination, int maxLength);

#endif
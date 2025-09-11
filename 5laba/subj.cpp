#include "list.hpp"
#include "subj.hpp"
#include <iostream>

using namespace std;

base::base(itemType t) : type(t){
    name[0] = '\0'; 
    voltageDrop = NULL;
    currentLimit = NULL;
    waveLength = NULL;
    radiationPower = NULL;
}

singleIndicator::singleIndicator() : base(itemType::itSingleIndicator){
    figure[0] = '\0';
    radiatingArea = NULL;
}

twoCOlorIndicator::twoCOlorIndicator() : base(itemType::itTwoColorIndicator){
    secondWaveLength = NULL;
    radPowOFsecondCrystal = NULL;
}

signIndicator::signIndicator() : base(itemType::itSignIndicator){
    amountSegments = NULL;
    signs = false;
    connectionDiagram[0] = '\0';
}

matrixIndicator::matrixIndicator() : base(itemType::itMatrixIndicator){
    strings = NULL;
    column = NULL;
}

void base::print(){
    switch (type) {
        case itemType::itSingleIndicator:
            static_cast<singleIndicator*>(this)->print();
            break;
        case itemType::itTwoColorIndicator:
            static_cast<twoCOlorIndicator*>(this)->print();
            break;
        case itemType::itSignIndicator:
            static_cast<signIndicator*>(this)->print();
            break;
        case itemType::itMatrixIndicator:
            static_cast<matrixIndicator*>(this)->print();
            break;
        default:
            cout << "Неизвестный тип объекта!" << endl;
    }
}


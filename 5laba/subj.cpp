#include "subj.hpp"
#include <iostream>
#include <limits>
#include <cstring>

using namespace std;

base::base(itemType t) : type(t){
    name[0] = '\0'; 
    voltageDrop = 0;
    currentLimit = 0;
    waveLength = 0;
    radiationPower = 0;
}
base::~base(){}
singleIndicator::singleIndicator() : base(itemType::itSingleIndicator){
    figure[0] = '\0';
    radiatingArea = 0;
}

twoCOlorIndicator::twoCOlorIndicator() : base(itemType::itTwoColorIndicator){
    secondWaveLength = 0;
    radPowOFsecondCrystal = 0;
}

signIndicator::signIndicator() : base(itemType::itSignIndicator){
    amountSegments = 0;
    signs = false;
    connectionDiagram[0] = '\0';
}

matrixIndicator::matrixIndicator() : base(itemType::itMatrixIndicator){
    strings = 0;
    column = 0;
}

void base::input(){
    switch (type) {
        case itemType::itSingleIndicator:
            static_cast<singleIndicator*>(this)->input();
            break;
        case itemType::itTwoColorIndicator:
            static_cast<twoCOlorIndicator*>(this)->input();
            break;
        case itemType::itSignIndicator:
            static_cast<signIndicator*>(this)->input();
            break;
        case itemType::itMatrixIndicator:
            static_cast<matrixIndicator*>(this)->input();
            break;
        default:
            cout << "Неизвестный тип объекта!" << endl;
    }
}

void singleIndicator::input(){
    SafeInputString("Enter name: ", name);
    voltageDrop = SafeInputFloat("Enter Voltage Drop: ");
    currentLimit = SafeInputFloat("Enter Current Limit: ");
    waveLength = SafeInputFloat("Enter Wave Length: ");
    radiationPower = SafeInputFloat("Enter Radiation Power: ");
    SafeInputString("Enter Figure: ", figure);
    radiatingArea = SafeInputInt("Enter Radiation area: ",0,1000);
}

void twoCOlorIndicator::input(){
    SafeInputString("Enter name: ", name);
    voltageDrop = SafeInputFloat("Enter Voltage Drop: ");
    currentLimit = SafeInputFloat("Enter Current Limit: ");
    waveLength = SafeInputFloat("Enter Wave Length: ");
    radiationPower = SafeInputFloat("Enter Radiation Power: ");
    secondWaveLength = SafeInputFloat("Enter secondWaveLength: ");
    radPowOFsecondCrystal = SafeInputFloat("Enter radPowOFsecondCrystal: ");
}

void signIndicator::input(){
    int buff;
    SafeInputString("Enter name: ", name);
    voltageDrop = SafeInputFloat("Enter Voltage Drop: ");
    currentLimit = SafeInputFloat("Enter Current Limit: ");
    waveLength = SafeInputFloat("Enter Wave Length: ");
    radiationPower = SafeInputFloat("Enter Radiation Power: ");
    amountSegments = SafeInputInt("Enter amount Segments : ",0,10);
    buff = SafeInputInt("Enter signs(0 or 1): ",0,1);
    if(buff){  
        signs = true;
    }else{
        signs = false;
    }
    SafeInputString("Enter connection Diagram: ", connectionDiagram);
}

void matrixIndicator::input(){
    SafeInputString("Enter name: ", name);
    voltageDrop = SafeInputFloat("Enter Voltage Drop: ");
    currentLimit = SafeInputFloat("Enter Current Limit: ");
    waveLength = SafeInputFloat("Enter Wave Length: ");
    radiationPower = SafeInputFloat("Enter Radiation Power: ");
    strings = SafeInputInt("Enter strings : ",0,10);
    column = SafeInputInt("Enter column : ",0,10);
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

void singleIndicator::print(){
    cout << "Name: " << name << endl;
    cout << "Voltage Drop: " << voltageDrop << endl;
    cout << "Current Limit: " << currentLimit << endl;
    cout << "Wave Length: " << waveLength << endl;
    cout << "Radiation Power: " << radiationPower << endl;
    
    cout << "Figure: " << figure << endl;
    cout << "Radiation area: " << radiatingArea << endl;
}

void twoCOlorIndicator::print(){
    cout << "Name: " << name << endl;
    cout << "Voltage Drop: " << voltageDrop << endl;
    cout << "Current Limit: " << currentLimit << endl;
    cout << "Wave Length: " << waveLength << endl;
    cout << "Radiation Power: " << radiationPower << endl;

    cout << "secondWaveLength: " << secondWaveLength << endl;
    cout << "radPowOFsecondCrystal: " << radPowOFsecondCrystal << endl;
}

void signIndicator::print(){
    cout << "Name: " << name << endl;
    cout << "Voltage Drop: " << voltageDrop << endl;
    cout << "Current Limit: " << currentLimit << endl;
    cout << "Wave Length: " << waveLength << endl;
    cout << "Radiation Power: " << radiationPower << endl;

    cout << "amount Segments: " << amountSegments << endl;
    cout << "signs: " << signs << endl;
    cout << "connection Diagram: " << connectionDiagram << endl;
}

void matrixIndicator::print(){
    cout << "Name: " << name << endl;
    cout << "Voltage Drop: " << voltageDrop << endl;
    cout << "Current Limit: " << currentLimit << endl;
    cout << "Wave Length: " << waveLength << endl;
    cout << "Radiation Power: " << radiationPower << endl;

    cout << "strings: " << strings << endl;
    cout << "column: " << column << endl;
}


int SafeInputInt(const char *prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minValue && value <= maxValue) {
            cin.ignore();
            return value;
        }
        cout << "Ошибка: Введите число от " << minValue << " до " << maxValue << "!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

float SafeInputFloat(const char *prompt) {
    float value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore();
            return value;
        }
        cout << "Ошибка: Введите корректное число!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void SafeInputString(const char *prompt, char *destination) {
    char buffer[20];
    int maxLength = 20;
    while (true) {
        cout << prompt;
        if (cin.getline(buffer, sizeof(buffer))) {
            if (strlen(buffer) <= (size_t)maxLength) {
                strncpy(destination, buffer, maxLength);
                return;
            }
            cout << "Ошибка: Максимальная длина - " << maxLength << " символов!" << endl;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
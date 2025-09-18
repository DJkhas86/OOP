#include "subj.hpp"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

Base::Base(){
    name = '\0'; 
    voltageDrop = 0;
    currentLimit = 0;
    waveLength = 0;
    radiationPower = 0;
    summarPower = currentLimit * radiationPower;
}

singleIndicator::singleIndicator(){
    figure = '\0';
    radiatingArea = 0;
}

twoCOlorIndicator::twoCOlorIndicator(){
    secondWaveLength = 0;
    radPowOFsecondCrystal = 0;
}

signIndicator::signIndicator(){
    amountSegments = 0;
    signs = false;
    connectionDiagram = '\0';
}

matrixIndicator::matrixIndicator(){
    strings = 0;
    column = 0;
}

void singleIndicator::input(){
    SafeInputString("Enter name: ", &name,4);
    voltageDrop = SafeInputFloat("Enter Voltage Drop: ");
    currentLimit = SafeInputFloat("Enter Current Limit: ");
    waveLength = SafeInputFloat("Enter Wave Length: ");
    radiationPower = SafeInputFloat("Enter Radiation Power: ");

    summarPower = currentLimit * radiationPower;
    SafeInputString("Enter Figure: ", &figure,20);
    radiatingArea = SafeInputInt("Enter Radiation area: ",0,1000);
}

void twoCOlorIndicator::input(){
    SafeInputString("Enter name: ", &name,4);
    voltageDrop = SafeInputFloat("Enter Voltage Drop: ");
    currentLimit = SafeInputFloat("Enter Current Limit: ");
    waveLength = SafeInputFloat("Enter Wave Length: ");
    radiationPower = SafeInputFloat("Enter Radiation Power: ");

    secondWaveLength = SafeInputFloat("Enter secondWaveLength: ");
    radPowOFsecondCrystal = SafeInputFloat("Enter radPowOFsecondCrystal: ");

    summarPower = currentLimit * radiationPower;
    summarPower = summarPower + (currentLimit * radPowOFsecondCrystal);
}

void signIndicator::input(){
    int buff;
    SafeInputString("Enter name: ", &name,4);
    voltageDrop = SafeInputFloat("Enter Voltage Drop: ");
    currentLimit = SafeInputFloat("Enter Current Limit: ");
    waveLength = SafeInputFloat("Enter Wave Length: ");
    radiationPower = SafeInputFloat("Enter Radiation Power: ");

    amountSegments = SafeInputInt("Enter amount Segments : ",0,10);
    buff = SafeInputInt("Enter signs(0 or 1): ",0,1);
    if(buff == 1){  
        signs = true;
    }else{
        signs = false;
    }
    SafeInputString("Enter connection Diagram: ", &connectionDiagram,20);

    summarPower = currentLimit * radiationPower;
    summarPower = summarPower * amountSegments;
}

void matrixIndicator::input(){
    SafeInputString("Enter name: ", &name,4);
    voltageDrop = SafeInputFloat("Enter Voltage Drop: ");
    currentLimit = SafeInputFloat("Enter Current Limit: ");
    waveLength = SafeInputFloat("Enter Wave Length: ");
    radiationPower = SafeInputFloat("Enter Radiation Power: ");

    strings = SafeInputInt("Enter strings : ",0,10);
    column = SafeInputInt("Enter column : ",0,10);

    summarPower = currentLimit * radiationPower;
    summarPower = summarPower * (column * strings);
}



void singleIndicator::print() const{
    cout << "Name: " << name << endl;
    cout << "Voltage Drop: " << voltageDrop << endl;
    cout << "Current Limit: " << currentLimit << endl;
    cout << "Wave Length: " << waveLength << endl;
    cout << "Radiation Power: " << radiationPower << endl;
    cout << "Summar Power: " << summarPower << endl;
    
    cout << "Figure: " << figure << endl;
    cout << "Radiation area: " << radiatingArea << endl;
}

void twoCOlorIndicator::print() const{
    cout << "Name: " << name << endl;
    cout << "Voltage Drop: " << voltageDrop << endl;
    cout << "Current Limit: " << currentLimit << endl;
    cout << "Wave Length: " << waveLength << endl;
    cout << "Radiation Power: " << radiationPower << endl;
    cout << "Summar Power: " << summarPower << endl;

    cout << "secondWaveLength: " << secondWaveLength << endl;
    cout << "radPowOFsecondCrystal: " << radPowOFsecondCrystal << endl;
}

void signIndicator::print() const{
    cout << "Name: " << name << endl;
    cout << "Voltage Drop: " << voltageDrop << endl;
    cout << "Current Limit: " << currentLimit << endl;
    cout << "Wave Length: " << waveLength << endl;
    cout << "Radiation Power: " << radiationPower << endl;
    cout << "Summar Power: " << summarPower << endl;

    cout << "amount Segments: " << amountSegments << endl;
    cout << "signs: " << signs << endl;
    cout << "connection Diagram: " << connectionDiagram << endl;
}

void matrixIndicator::print() const{
    cout << "Name: " << name << endl;
    cout << "Voltage Drop: " << voltageDrop << endl;
    cout << "Current Limit: " << currentLimit << endl;
    cout << "Wave Length: " << waveLength << endl;
    cout << "Radiation Power: " << radiationPower << endl;
    cout << "Summar Power: " << summarPower << endl;

    cout << "strings: " << strings << endl;
    cout << "column: " << column << endl;
}

void subjList::printList(){
    if(!head){
        cout << "ist is empty" << endl;
    }
    else{
        Item *temp = head;
        while(temp){
            static_cast<Base*>(temp)->print();
            cout << endl;
            temp = temp->next;
        } 
    }
} 

int subjList::compareWave(float obj1,float obj2){
    if(obj1 >  obj2){
        return 1;
    }
    else{
        return 0;
    }
}

void subjList::sortList(){
    if (!head) return;

    bool swapped;
    do {
        swapped = false;
        Item *temp = head;

        while (temp && temp->next) {
            Base *a = static_cast<Base*>(temp);
            Base *b = static_cast<Base*>(temp->next);

            if (compareWave(a->waveLength,b->waveLength) > 0) {
                if (temp->prev) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }

                if (temp->next->next) {
                    temp->next->next->prev = temp;
                } else {
                    tail = temp;
                }
                temp->next->prev = temp->prev;
                temp->prev = temp->next;
                temp->next = temp->next->next;
                temp->prev->next = temp;

                swapped = true;
            } else {
                temp = temp->next;
            }
        }
    } while (swapped);
}

void subjList::found(){
    int min = 0;
    int max = 0;
    int n = this->count();
    min = SafeInputFloat("Enter Min:");
    max = SafeInputFloat("Enter Max:");
    Item *temp = head;
    Base *a = static_cast<Base*>(temp);
    for(int i = 0;i<n;i++){
        if(a->summarPower >= min && a->summarPower <= max){
            a->print();
        }
        a = static_cast<Base*>(a->next);
    }
    
}

int SafeInputInt(string prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minValue && value <= maxValue) {
            cin.ignore();
            return value;
        }
        cout << "ERROR: ENTER  NUMBER from  " << minValue << " to " << maxValue << "!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

float SafeInputFloat(string prompt) {
    float value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore();
            return value;
        }
        cout << "ERROR: ENTER COORECT NUMBER!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void SafeInputString(string prompt, string *destination, int maxLength) {
    std::string buffer;
    while (true) {
        cout << prompt;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (getline(cin, buffer)) {
            if (buffer.length() <= maxLength) {
                *destination = buffer;
                return;
            }
            cout << "Ошибка: Максимальная длина - " << maxLength << " символов!" << endl;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
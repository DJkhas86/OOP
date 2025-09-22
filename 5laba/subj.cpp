#include "subj.hpp"
#include <iostream>
#include <limits>


using namespace std;

base::base(itemType t) : type(t){
    name[0] = '\0'; 
    voltageDrop = 0;
    currentLimit = 0;
    waveLength = 0;
    radiationPower = 0;
    summarPower = currentLimit * radiationPower;
}
// base::~base(){}
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
    SafeInputString("Enter name: ", &name,3);
    voltageDrop = SafeInputFloat("Enter Voltage Drop: ");
    currentLimit = SafeInputFloat("Enter Current Limit: ");
    waveLength = SafeInputFloat("Enter Wave Length: ");
    radiationPower = SafeInputFloat("Enter Radiation Power: ");
    SafeInputString("Enter Figure: ", &figure,10);
    radiatingArea = SafeInputInt("Enter Radiation area: ",0,1000);
}

void twoCOlorIndicator::input(){
    SafeInputString("Enter name: ", &name,3);
    voltageDrop = SafeInputFloat("Enter Voltage Drop: ");
    currentLimit = SafeInputFloat("Enter Current Limit: ");
    waveLength = SafeInputFloat("Enter Wave Length: ");
    radiationPower = SafeInputFloat("Enter Radiation Power: ");
    secondWaveLength = SafeInputFloat("Enter secondWaveLength: ");
    radPowOFsecondCrystal = SafeInputFloat("Enter radPowOFsecondCrystal: ");
    summarPower = summarPower + (currentLimit * radPowOFsecondCrystal);
}

void signIndicator::input(){
    int buff;
    SafeInputString("Enter name: ", &name,3);
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
    SafeInputString("Enter connection Diagram: ", &connectionDiagram,10);
    summarPower = summarPower * amountSegments;
}

void matrixIndicator::input(){
    SafeInputString("Enter name: ", &name,3);
    voltageDrop = SafeInputFloat("Enter Voltage Drop: ");
    currentLimit = SafeInputFloat("Enter Current Limit: ");
    waveLength = SafeInputFloat("Enter Wave Length: ");
    radiationPower = SafeInputFloat("Enter Radiation Power: ");
    strings = SafeInputInt("Enter strings : ",0,10);
    column = SafeInputInt("Enter column : ",0,10);
    summarPower = summarPower *(column * strings);
}

void base::inputrand(){
    switch (type) {
        case itemType::itSingleIndicator:
            static_cast<singleIndicator*>(this)->inputrand();
            break;
        case itemType::itTwoColorIndicator:
            static_cast<twoCOlorIndicator*>(this)->inputrand();
            break;
        case itemType::itSignIndicator:
            static_cast<signIndicator*>(this)->inputrand();
            break;
        case itemType::itMatrixIndicator:
            static_cast<matrixIndicator*>(this)->inputrand();
            break;
        default:
            cout << "Undefined type of object!" << endl;
    }

}
void singleIndicator::inputrand(){
    name = to_string(rand() % 11);
    voltageDrop = rand()%101;
    currentLimit = rand()%101;
    waveLength = rand()%101;
    radiationPower = rand()%101;
    summarPower = currentLimit * radiationPower;
    figure = to_string(rand() % 3);
    radiatingArea = rand()%101;
}

void twoCOlorIndicator::inputrand(){
    name = to_string(rand() % 11);
    voltageDrop = rand()%101;
    currentLimit = rand()%101;
    waveLength = rand()%101;
    radiationPower = rand()%101;
    summarPower = currentLimit * radiationPower;
    waveLength = rand()%101;
    radPowOFsecondCrystal = rand()%101;
}

void signIndicator::inputrand(){
    int buff;
    name = to_string(rand() % 11);
    voltageDrop = rand()%101;
    currentLimit = rand()%101;
    waveLength = rand()%101;
    radiationPower = rand()%101;
    summarPower = currentLimit * radiationPower;
    buff = rand()%2;
    amountSegments = rand()%101;
    connectionDiagram =to_string(rand() % 5);
    if(buff){  
        signs = true;
    }else{
        signs = false;
    }
}

void matrixIndicator::inputrand(){
    name = to_string(rand() % 11);
    voltageDrop = rand()%101;
    currentLimit = rand()%101;
    waveLength = rand()%101;
    radiationPower = rand()%101;
    summarPower = currentLimit * radiationPower;
    strings = rand()%101;
    column = rand()%101;
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

void subjList::printList(){
    if(!head){
        cout << "ist is empty" << endl;
    }
    else{
        Item *temp = head;
        while(temp){
            static_cast<base*>(temp)->print();
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
            base *a = static_cast<base*>(temp);
            base *b = static_cast<base*>(temp->next);

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
    base *a = static_cast<base*>(temp);
    for(int i = 0;i<n;i++){
        if(a->summarPower >= min && a->summarPower <= max){
            a->print();
        }
        a = static_cast<base*>(a->next);
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
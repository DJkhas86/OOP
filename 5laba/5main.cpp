#include <iostream> 
#include "subj.hpp"
#include <Windows.h>

class DebugList : public List {
public:
    void Menu();
    void Print();
};

int main(){
    subjList list;
    int choice,amount = 0;
    base *bas = NULL;
    bool p = true;
    while (p){
        list.menu();
        std::cin >> choice;
        switch(choice){
            case 0:
                list.clear();
                p = false;
                break;
            case 1:{
                int t = 1 + rand() % 4;
                switch(t){
                    case(1):{
                        singleIndicator *newsing = new singleIndicator();
                        newsing->inputrand();
                        newsing->print();
                        list.add(newsing);
                        break;
                    }
                    case(2):{
                        twoCOlorIndicator *newtci = new twoCOlorIndicator();
                        newtci->inputrand();
                        newtci->print();
                        list.add(newtci);
                        break;
                    }
                    case(3):{
                        signIndicator *newsignI = new signIndicator();
                        newsignI->inputrand();
                        newsignI->print();
                        list.add(newsignI);
                        break;
                    }
                    case(4):{
                        matrixIndicator *newmatrix = new matrixIndicator();
                        newmatrix->inputrand();
                        newmatrix->print();
                        list.add(newmatrix);
                        break;
                    }
                }
                break;
            }
            case 2:{
                int v = 0;
                switch(v){
                    case 1:{
                    singleIndicator *newSingle = new singleIndicator();
                    newSingle->input();
                    list.add(newSingle);
                    std::cout << "Completle added new Singl Indicator!" << std::endl;
                    break;
                    }
                    case 2:{
                        twoCOlorIndicator *newtwoColor = new twoCOlorIndicator();
                        newtwoColor->input();
                        list.add(newtwoColor);
                        std::cout << "Completle added new Two Color Indicator!" << std::endl;
                        break;
                    }
                    case 3:{
                        signIndicator *newSign = new signIndicator();
                        newSign->input();
                        list.add(newSign);
                        std::cout << "Completle added new Sign Ingicator!" << std::endl;
                        break;
                    }
                    case 4:{
                        matrixIndicator *newMatrix = new matrixIndicator();
                        newMatrix->input();
                        list.add(newMatrix);
                        std::cout << "Completle added new Matrix Indicator!" << std::endl;
                        break;
                    }
                }
            }
                break;
            case 3:
                list.printList();
                break;
            case 4:
                list.sortList();
                list.printList();
                break;
            case 5:
                list.found();
                break;
            case 6:
                list.clear();
                break;   
            }
        }
    return 0;
}
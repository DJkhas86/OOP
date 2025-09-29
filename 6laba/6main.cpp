#include <iostream> 
#include "subj.hpp"
#include <Windows.h>
#include <string>
int main(){
    subjList list;
    int choice,amount = 0;
    bool p = true;
    Base *pointer = NULL; 
    while (p){
        std::cout << "Menu:\n";
        std::cout << "1.Add random Item\n";
        std::cout << "2.Add control Item\n";
        std::cout << "3.Print all\n";
        std::cout << "4.Sort by wave length\n";
        std::cout << "5.Found by summar power\n";
        std::cout << "6.delete all\n";
        std::cout << "0.Close program\n";
        std::cin >> choice;
        switch(choice){
            case(1):{
            int t = 1 + rand() % 4;
            switch(t){
                case(1):{
                    pointer = Base::create(itemType::itSingleIndicator);
                    pointer->print();
                    list.add(pointer);
                    break;
                }
                case(2):{
                        pointer = Base::create(itemType::itTwoColorIndicator);
                        pointer->print();
                        list.add(pointer);
                        break;
                    }
                    case(3):{
                        pointer = Base::create(itemType::itSignIndicator);
                        pointer->print();
                        list.add(pointer);
                        break;
                    }
                    case(4):{
                        pointer = Base::create(itemType::itMatrixIndicator);
                        pointer->print();
                        list.add(pointer);
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
            case 0:
                list.clear();
                p = false;
                break; 

        }
    }
    return 0;
}
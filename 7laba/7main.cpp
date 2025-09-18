#include <iostream> 
#include "subj.hpp"
#include <Windows.h>
#include <string>
int main(){
    subjList list;
    int choice,amount = 0;
    bool p = true;
    while (p){
        std::cout << "Menu:\n";
        std::cout << "1.Add Single Indicator\n";
        std::cout << "2.add Two Color Indicator\n";
        std::cout << "3.add Sign Indicator\n";
        std::cout << "4.add Matrix Indicator\n";
        std::cout << "5.Print all\n";
        std::cout << "6.Sort by wave length\n";
        std::cout << "7.Found by summar power\n";
        std::cout << "8.delete all\n";
        std::cout << "0.EXIT\n";
        std::cin >> choice;
        switch(choice){
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
            case 5:
                list.printList();
                break;
            case 6:
                list.sortList();
                list.printList();
                break;
            case 7:
                list.found();
                break;
            case 8:
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
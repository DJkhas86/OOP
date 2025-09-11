#include <iostream> 
#include "list.h"
#include <Windows.h>

class DebugList : public List {
public:
    void Menu();
    void Print();
};

void DebugList::Menu() {
    std::cout << "Menu:\n";
    std::cout << "1.Add Item\n";
    std::cout << "2.List Output\n";
    std::cout << "3.Count Items\n";
    std::cout << "4.Get Item by index\n";
    std::cout << "5.Remove Item\n";
    std::cout << "6.Clear List\n";
    std::cout << "7.insert Item\n";
    std::cout << "0.Close program\n";
}

void DebugList::Print() {
    Item* item = Head();
    int index = 0;
        std::cout << "id\tAddress\tPrev\tNext\n";
        while (item) {
            std::cout << index << '\t' 
                      << item << '\t' 
                      << item->Prev() << '\t' 
                      << item->Next() << '\n';
            item = item->Next();
            index++;
        }
}

int main(){
    DebugList list;
    int choice,amount = 0;
    bool p = true;
    while (p){
        list.Menu();
        std::cin >> choice;
        switch(choice){
            case 0:
                std::cout << "EXIT....\n";
                p = false;
                break;
            case 1:
                list.add(new Item());
                std::cout << "Item Added \n" << std::endl;
                break;
            case 2:
                list.Print();
                break;
            case 3:
                amount = list.count();
                printf("Amount Items:%d \n",amount);
                break;
            case 4:{
                std::cout <<"Choose Index of Item:"<< std::endl;
                std::cin >> choice;
                Item* item = list.getItem(choice);
                std::cout << "Item" << item << "| prev " << item->Prev() << "| next" << item->Next() << "\n" << std::endl;
                break;
            }
            case 5:{
                std::cout << "Choose Index to Remove:";
                std::cin >> choice;
                list.removeItem(choice);
                std::cout << "Completle removed\n";
                break;
            }
            case 7:
                list.clear();
                std::cout << "List Deleted";
                break;
        }
    }
    return 0;
}
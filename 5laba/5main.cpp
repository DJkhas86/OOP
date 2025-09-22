#include <iostream> 
#include "subj.hpp"
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
    std::cout << "6.delete Item\n";
    std::cout << "7.Clear List\n";
    std::cout << "8.insert Item\n";
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
    base *bas = NULL;
    bool p = true;
    while (p){
        list.Menu();
        std::cin >> choice;
        switch(choice){
            case 0:
                std::cout << "EXIT....\n";
                p = false;
                break;
            case 1:{
                int t = rand() % 5;
                switch(t){
                    case(0):
                        break;
                    case(1):{
                        std::cout << t << std::endl;
                        bas = new base(itemType::itSingleIndicator);
                        std::cout << t << std::endl;
                        bas->inputrand();
                        std::cout << t << std::endl;
                        break;
                    }
                    case(2):{
                        bas = new base(itemType::itTwoColorIndicator);
                        bas->inputrand();
                        break;
                    }
                    case(3):{
                        bas = new base(itemType::itSignIndicator);
                        bas->inputrand();
                        break;
                    }
                    case(4):{
                        bas = new base(itemType::itMatrixIndicator);
                        bas->inputrand();
                        break;
                    }
                }
                if(t != 0){
                    bas->print();
                    Item *itemadd = static_cast<Item *>(bas);
                    list.add(itemadd);
                    bas->print();
                }
                break;
            }
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
            case 6:
                list.clear();
                std::cout << "List Deleted";
                break;
            case 7:
                std::cout << "Choose Index to Insert:";
                std::cin >> choice;
                list.insert(new Item(),choice);
                break;
        }
    }
    return 0;
}
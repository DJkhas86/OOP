#ifndef SUBJ_HPP
#define SUBJ_HPP

#include "list.hpp"
#include <string>
enum class itemType {
    itNone,
    itSingleIndicator,
    itTwoColorIndicator,
    itSignIndicator,
    itMatrixIndicator
};

class base : public Item{
    protected:
        itemType type;
    public :
        std::string name;
        float voltageDrop;
        float currentLimit;
        float waveLength;
        float radiationPower;
        float summarPower;
        base(itemType t);
        virtual ~base(){}
        virtual void input();
        virtual void inputrand();
        virtual void print();
        virtual float getWaveLength(){return waveLength;}
};

class singleIndicator : public base{
    public:
        std::string figure;
        int radiatingArea;
        singleIndicator();
        void input() override;
        void inputrand() override;
        void print() override;

};

class twoCOlorIndicator : public base{
    public:
        float secondWaveLength;
        float radPowOFsecondCrystal;
        twoCOlorIndicator();
        void input() override;
        void inputrand() override;
        void print() override;
};

class signIndicator : public base {
    public:
        int amountSegments;
        bool signs;
        std::string connectionDiagram;
        signIndicator();
        void input() override;
        void inputrand() override;
        void print() override;
};

class matrixIndicator : public base{
    public:
        int strings;
        int column;
        matrixIndicator();
        void input() override;
        void inputrand() override;
        void print() override;
};

class subjList : public List{
    public:
        void menu();
        void printList();
        void sortList();
        int compareWave(float obj1,float obj2);
        void found();

};


int SafeInputInt(std::string prompt, int minValue, int maxValue);
float SafeInputFloat(std::string prompt);
void SafeInputString(std::string prompt, std::string *destination, int maxLength);

#endif
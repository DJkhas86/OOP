#ifndef SUBJ_HPP
#define SUBJ_HPP

#include "list.hpp"
enum class itemType {
    itNone,
    itSingleIndicator,
    itTwoColorIndicator,
    itSignIndicator,
    itMatrixIndicator
};

class Base : public Item{
    public :
        char name[3];
        float voltageDrop;
        float currentLimit;
        float waveLength;
        float radiationPower;
        float summarPower;

        Base();
        virtual ~Base() = default;

        virtual void input() = 0;
        virtual void print() const = 0;
        virtual itemType getItemType() const = 0;
};
class singleIndicator : public Base{
    public:
        char figure[20];
        int radiatingArea;
        singleIndicator();

        void input() override;
        void print() const override;
        itemType getItemType() const override { return itemType::itSingleIndicator; }

};

class twoCOlorIndicator : public Base{
    public:
        float secondWaveLength;
        float radPowOFsecondCrystal;
        twoCOlorIndicator();

        void input() override;
        void print() const override;
        itemType getItemType() const override { return itemType::itTwoColorIndicator; }
};

class signIndicator : public Base {
    public:
        int amountSegments;
        bool signs;
        char connectionDiagram[20];
        signIndicator();

        void input() override;
        void print() const override;
        itemType getItemType() const override { return itemType::itSignIndicator; }
};

class matrixIndicator : public Base{
    public:
        int strings;
        int column;
        matrixIndicator();

        void input() override;
        void print() const override;
        itemType getItemType() const override { return itemType::itMatrixIndicator; }
};

class subjList : public List{
    public:
        void printList();
        void sortList();
        int compareWave(float obj1,float obj2);
        void found();

};


int SafeInputInt(const char *prompt, int minValue, int maxValue);
float SafeInputFloat(const char *prompt);
void SafeInputString(const char *prompt, char *destination, int maxLength);

#endif
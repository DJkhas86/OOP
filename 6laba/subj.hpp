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

class base : public Item{
    public :
        char name[3];
        float voltageDrop;
        float currentLimit;
        float waveLength;
        float radiationPower;
        float summarPower;
        base();
        virtual ~base(){};

        virtual void input();
        virtual void print() const = 0;
        virtual itemType getItemType() const = 0;
};
class singleIndicator : public base{
    public:
        char figure[20];
        int radiatingArea;
        singleIndicator();

        void input() override;
        void print() const override;
        itemType getItemType() const override { return itemType::itSingleIndicator; }

};

class twoCOlorIndicator : public base{
    public:
        float secondWaveLength;
        float radPowOFsecondCrystal;
        twoCOlorIndicator();

        void input() override;
        void print() const override;
        itemType getItemType() const override { return itemType::itTwoColorIndicator; }
};

class signIndicator : public base {
    public:
        int amountSegments;
        bool signs;
        char connectionDiagram[20];
        signIndicator();

        void input() override;
        void print() const override;
        itemType getItemType() const override { return itemType::itSignIndicator; }
};

class matrixIndicator : public base{
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
void SafeInputString(const char *prompt, char *destination);

#endif
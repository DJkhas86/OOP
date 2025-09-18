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

class Base : public Item{
    public :
        std::string name;
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
        std::string figure;
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
        std::string connectionDiagram;
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


int SafeInputInt(std::string prompt, int minValue, int maxValue);
float SafeInputFloat(std::string prompt);
void SafeInputString(std::string prompt, std::string *destination, int maxLength);

#endif
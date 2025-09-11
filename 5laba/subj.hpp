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
    protected:
        itemType type;
    public :
        char name[3];
        float voltageDrop;
        float currentLimit;
        float waveLength;
        float radiationPower;

        base(itemType t);
        virtual ~base();

        virtual void input();
        virtual void print();
        virtual float getWaveLength(){return waveLength;}
};

class singleIndicator : public base{
    public:
        char figure[20];
        int radiatingArea;

        singleIndicator();

        void input() override;
        void print() override;

};

class twoCOlorIndicator : public base{
    private:
        float secondWaveLength;
        float radPowOFsecondCrystal;

        twoCOlorIndicator();

        void input() override;
        void print() override;
};

class signIndicator : public base {
    int amountSegments;
    bool signs;
    char connectionDiagram[20];

    signIndicator();

    void input() override;
    void print() override;
};

class matrixIndicator : public base{
    private :
        int strings;
        int column;

        matrixIndicator();

        void input() override;
        void print() override;
};

class subjList : public List{
    private:

    public:
        subjList();
        ~subjList();

        void printList();
        void sortList();
        int compareWave();

};


int SafeInputInt(const char *prompt, int minValue, int maxValue);
float SafeInputFloat(const char *prompt);
void SafeInputString(const char *prompt, char *destination, int maxLength);

#endif
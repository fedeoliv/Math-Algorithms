#include <bits/stdc++.h>
#define uint unsigned int
#define ull unsigned long long
using namespace std;

class MathRoutines {
    public:
      template <class Element>
      static void RaiseToPower(Element& theElement, int thePower, const Element& theRingUnit);
      inline static int Maximum(int a, int b){  if (a>b) return a; else return b; }
};

class LargeUI {
    vector<unsigned int> theDigits;
    void AddNoFitSize(const LargeUI& x);
    public:
        //The zero element is assumed to have length one array with a zero entry.
        //CarryOverBound is the "base" over which we work.
        //Requirements on the CarryOverBound:
        //1.  CarryOverBound*2-1 must fit inside an unsigned (int)
        //    on the system
        //2. (CarryOverBound*2)^2-1 must fit inside (long long)
        //    on the system.
        static const unsigned int CarryOverBound = 1000000000UL;
        void SubtractSmallerPositive(const LargeUI& x);
        inline int size()const{return this->theDigits.size();}
        string GetFactorial()const;
        void MakeOne(){ this->theDigits.resize(1);  this->theDigits[0] = 1;}
        void MakeZero(){ this->theDigits.resize(1); this->theDigits[0] = 0;}
        bool IsGEQ(const LargeUI& x)const;

        /* Prime numbers using Sieve of Erathostenes */
        static void GetPrimes(unsigned int n, std::vector<unsigned int>& output) {
            vector<int> primes;
            primes.resize(n+1);

            for(uint i = 0; i < n+1; i++) primes[i] = 1;
            output.resize(0);
            output.reserve(n/2);

            for(uint i = 2; i <= n; i++)
                if(primes[i] != 0) {
                    output.push_back(i);
                    for (uint j = i; j <= n; j += i) primes[j] = 0;
                }
        }

        inline void operator *= (const LargeUI& right);
        void AssignFactorial(unsigned int x);
        void MultiplyBy(const LargeUI& x, LargeUI& output)const;
        void AddInt(unsigned int x, int shift); /* Add shifted int smaller than carry over bound */
        void AssignShiftedUInt(unsigned int x, int shift);
        inline void operator += (const LargeUI& other);

        inline void operator = (const LargeUI& other) {
            this->theDigits = other.theDigits;
        }

        LargeUI() {
            this->theDigits.push_back(0);
        }

        void FitSize();
};

void LargeUI::AssignFactorial(unsigned int x) {
    this->MakeOne();
    vector<unsigned int> primesBelowX;
    LargeUI::GetPrimes(x, primesBelowX);
    LargeUI tempInt, tempOne;

    tempOne.MakeOne();

    for(uint i = 0; i < primesBelowX.size(); i++) {
        uint thePrime = primesBelowX[i];
        uint thePowerOfThePrime = 0;
        uint currentPower = thePrime;

        do {
            thePowerOfThePrime += x/currentPower;
            currentPower *= thePrime;
        } while (currentPower <= x);

        tempInt.AssignShiftedUInt(thePrime, 0);
        MathRoutines::RaiseToPower(tempInt, thePowerOfThePrime, tempOne);
        *this *= tempInt;
    }
}

template <class Element>
void MathRoutines::RaiseToPower(Element& theElement, int thePower, const Element& theOne) {
    if(thePower <= 1) return;

    if(thePower == 0) {
        theElement = theOne;
        return;
    }

    Element Result = theOne;

    if(thePower < 4) {
        for(int i = 0; i < thePower; i++) Result.operator *= (theElement);
        theElement = Result;
        return;
    }

    vector<Element> containerList;
    int log2RoundedDown = 0;
    int highest = 1; /* Highest power, lower than or equal to the power*/

    for(; highest <= thePower; highest *= 2) log2RoundedDown++;

    highest /= 2;
    log2RoundedDown--;
    containerList.reserve(log2RoundedDown);
    Result = theElement;
    containerList.push_back(Result);

    for(int i = 1; i <= log2RoundedDown; i++) {
        Result.operator *= (Result);
        containerList.push_back(Result);
    }

    thePower -= highest;
    highest /= 2;
    int currentIndex = containerList.size()-2;

    for(; thePower > 0;) {
        if(thePower >= highest){
            Result.operator *= (containerList[currentIndex]);
            thePower -= highest;
        }

        currentIndex--;
        highest /= 2;
    }

    theElement = Result;
}

inline void LargeUI::AddInt(uint x, int shift) {
    while(x > 0){
        if(shift >= this->size()) {
            int oldsize = this->size();
            this->theDigits.resize(shift+1);

            for(int i = oldsize; i < this->size(); i++) this->theDigits[i] = 0;
        }

        this->theDigits[shift] += x;

        if(this->theDigits[shift] >= LargeUI::CarryOverBound) {
            this->theDigits[shift] -= LargeUI::CarryOverBound;
            x=1;
            shift++;
        } else x = 0;
    }
}

inline void LargeUI::AssignShiftedUInt(uint x, int shift) {
    if (x == 0) {
        this->MakeZero();
        return;
    }

    this->theDigits.resize(shift+1);

    for(int i = 0; i < shift; i++) this->theDigits[i] = 0;

    uint tempX = x % LargeUI::CarryOverBound;
    this->theDigits[shift]=tempX;
    x = x/LargeUI::CarryOverBound;

    while(x != 0) {
        tempX = x % LargeUI::CarryOverBound;
        this->theDigits.push_back(tempX);
        x = x/LargeUI::CarryOverBound;
    }
}

inline void LargeUI::AddNoFitSize(const LargeUI& x) {
    int oldsize= this->size();
    this->theDigits.resize(MathRoutines::Maximum(this->size(), x.size())+1);

    for(int i = oldsize; i < this->size(); i++) this->theDigits[i] = 0;

    uint CarryOver = 0;
    for(int i = 0; i < x.size(); i++) {
        this->theDigits[i] += x.theDigits[i] + CarryOver;

        if(this->theDigits[i] >= LargeUI::CarryOverBound) {
            this->theDigits[i] -= LargeUI::CarryOverBound;
            CarryOver = 1;
        } else CarryOver = 0;
    }

    if (CarryOver != 0)
        for(int i = x.size(); i < this->size(); i++) {
            this->theDigits[i] += 1;
            if (this->theDigits[i] >= LargeUI::CarryOverBound)
                this->theDigits[i] -= LargeUI::CarryOverBound;
            else break;
        }
}

void LargeUI::operator += (const LargeUI& x) {
    this->AddNoFitSize(x);
    this->FitSize();
}

void LargeUI::SubtractSmallerPositive(const LargeUI& x) {
    uint CarryOver = 0;
    for(int i = 0; i < x.size(); i++)
        if(this->theDigits[i] < x.theDigits[i] + CarryOver) {
            this->theDigits[i] += LargeUI::CarryOverBound;
            this->theDigits[i] -= (x.theDigits[i] + CarryOver);
            CarryOver = 1;
        } else {
            this->theDigits[i] -= (x.theDigits[i] + CarryOver);
            CarryOver = 0;
        }

    if(CarryOver != 0) {
        for(int i = x.size(); i < this->size(); i++)
            if(this->theDigits[i] > 0) {
                this->theDigits[i]--;
                break;
            } else this->theDigits[i] = LargeUI::CarryOverBound-1;
    }

    this->FitSize();
}

void LargeUI::MultiplyBy(const LargeUI& x, LargeUI& output) const {
    output.theDigits.resize(x.size() + output.size());

    for(int i = 0; i < output.size(); i++) output.theDigits[i] = 0;

    for(int i = 0; i < this->size(); i++)
        for(int j = 0; j < x.size(); j++) {
            ull tempLong = this->theDigits[i];
            ull tempLong2 = x.theDigits[j];
            tempLong = tempLong*tempLong2;
            ull lowPart = tempLong % LargeUI::CarryOverBound;
            ull highPart = tempLong/LargeUI::CarryOverBound;
            output.AddInt((uint) lowPart, i+j);
            output.AddInt((uint) highPart, i+j+1);
        }

    output.FitSize();
}

void LargeUI::FitSize() {
    int newSize = this->size();

    for(int i = this->size()-1; i >= 1; i--)
        if(this->theDigits[i] == 0) newSize--;
        else break;
    this->theDigits.resize(newSize);
}

void LargeUI::operator *= (const LargeUI& x) {
    LargeUI tempInt;
    this->MultiplyBy(x, tempInt);
    this->operator = (tempInt);
}



string LargeUI::GetFactorial() const {
    stringstream out;

    if(this->CarryOverBound != 1000000000UL) return "This method is not implemented";

    string tempS;
    out << (this->theDigits[this->size()-1]);

    for(int i = this->size()-2; i >= 0; i--) {
        stringstream tempStream;
        tempStream << this->theDigits[i];
        tempS = tempStream.str();
        int numZeroesToPad = 9 - tempS.length();
        for(int j = 0; j < numZeroesToPad; j++) out << "0";
        out << tempS;
    }

    return out.str();
}

int main() {
    LargeUI tempInt;
    uint x;

    scanf("%u", &x);

    tempInt.AssignFactorial(x);
    printf("%s\n", tempInt.GetFactorial().c_str());
    return 0;
}

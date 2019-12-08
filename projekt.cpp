#include <iostream>

using namespace std;

enum class Day{
    pn=1, wt=2, sr=3, czw=4, pt=5, sb=6, nd=7
};

struct Zajecia{
    string Godzina;
    Day Dzien;
    string Grupa;
    string Przedmiot;  
};

struct Prowadzacy{
    string Nazwisko;
    Zajecia* pNext;
};


int main()
{
    return 0;
}

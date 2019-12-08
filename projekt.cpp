#include <iostream>

using namespace std;

enum class Day{
    pn=1, wt=2, sr=3, czw=4, pt=5, sb=6, nd=7
};
struct Prowadzacy{
    string Nazwisko;
    Prowadzacy* pNext;
};

struct Zajecia{
    string GodzinaPocz;
    string GodzinaKon;
    Day Dzien;
    string Grupa;
    string Przedmiot;
    Prowadzacy* pZajecia;
    Zajecia* pNext;
    
};

int main()
{
    return 0;
}

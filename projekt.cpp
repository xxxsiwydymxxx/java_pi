#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

enum class Dzien{
    pn=1, wt=2, sr=3, czw=4, pt=5, sb=6, nd=7
};
struct Godzina {
    int Godzinka;
    int Minuta;
};
struct Prowadzacy{
    string Nazwisko;
    Prowadzacy* pNext;
};
struct Zajecia{
    Godzina PoczatekZajec;
    Godzina KoniecZajec;
    Dzien DzienZajec;
    string Grupa;
    string Przedmiot;
    Prowadzacy* pZajecia;
    Zajecia* pNext;
};

void DodajProwadzcego (Prowadzacy *& pHead, const string & nazwisko){
    if (pHead == nullptr)
    {
        pHead = new Prowadzacy{nazwisko, nullptr};
    }
    else
    {

    }
}


void DodajZajecia (Zajecia *& pHead, Godzina PoczatekZajec, Godzina KoniecZajec, Dzien DzienZajec, string Grupa, string Przedmiot){
    if (pHead == nullptr)
    {
        pHead = new Zajecia{PoczatekZajec, KoniecZajec, DzienZajec, Grupa, Przedmiot, nullptr, nullptr};
    }
    else
    {

    }

}
int main()
{
    return 0;
}

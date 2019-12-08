#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

enum class Day{
    pn=1, wt=2, sr=3, czw=4, pt=5, sb=6, nd=7
};

struct Prowadzacy{
    string Godzina;
    Day Dzien;
    string Grupa;
    string Nazwisko;
    string Przedmiot;
    Prowadzacy* pNext;
};

void dodajProwadzacego(Prowadzacy*& pHead, string Godzina, Day Dzien, string Grupa, string Nazwisko, string Przedmiot)
{
    //gdy lista jest pusta
    if (pHead == nullptr)
    {
        pHead = new Prowadzacy{Godzina, Dzien, Grupa, Nazwisko, Przedmiot, nullptr};
    }
    else
    {
        //sortowanie wg. godziny i daty
        Prowadzacy* temp = pHead;
        if ()
        {

        }
        else
        {

        }
    }
}




void usunListeIteracyjnie(Prowadzacy*& pHead)
{
    while (pHead)
    {
        auto p = pHead;
        pHead = pHead->pNext;
        delete p;
    }
}

int main()
{
    return 0;
}

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

enum class Dzien{
    pn=1, wt=2, sr=3, czw=4, pt=5, sb=6, nd=7
};

struct Prowadzacy{
    string Godzina;
    Dzien Dzien;
    string Grupa;
    string Nazwisko;
    string Przedmiot;
    Prowadzacy* pNext;
};

void dodajProwadzacego(Prowadzacy*& pHead, string Godzina, Dzien Dzien, string Grupa, string Nazwisko, string Przedmiot)
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
        //jesli godzina i dzien sa wieksze 
        if (Godzina < temp->Godzina and Dzien < temp->Dzien)
        {
        	Prowadzacy* t= new Prowadzacy{Godzina, Dzien, Grupa, Nazwisko, Przedmiot, pHead};
        	pHead=t;
            
        }
        //jesli godzina i dzien sa mniejsze
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

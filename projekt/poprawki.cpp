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
/** element listy z zajeciami */
struct Zajecia{
    Godzina PoczatekZajec;
    Godzina KoniecZajec;
    Dzien DzienZajec;
    string Grupa;
    string Przedmiot;
    Zajecia* pLewy;
    Zajecia* pPrawy;
};
/** element listy prowadzacych */
struct Prowadzacy{
    string Nazwisko;
    Prowadzacy* pNastepnyProwadzacy;
    Zajecia * pGlowaListyZajec;
};

void DodajProwadzcego (Prowadzacy *& pHead, string nazwisko){
    if (not pHead)
    {
        pHead = new Prowadzacy{nazwisko, nullptr};
    }
    else
    {
        auto p = pHead;
        while(p->pNastepnyProwadzacy)
          p=p->pNastepnyProwadzacy;

        p->pNastepnyProwadzacy = new Prowadzacy {Nazwisko, nullptr}
    }
}
Prowadzacy * ZnajdzProwadzacego (Prowadzacy * pHead, string nazwisko){
  if (pHead)
    {
      if (pHead->Prowadzacy == nazwisko)
        return pHead;
      else
        return ZnajdzProwadzacego(pHead->pNastepnyProwadzacy, nazwisko)
    }
  else return nullptr;
}

void DodajZajecia ()

int main()
{
    return 0;
}

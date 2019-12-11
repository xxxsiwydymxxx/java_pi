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
    string NazwiskoProwadzacego;
    Prowadzacy* pNastepnyProwadzacy;
    Zajecia* pGlowaListyZajec;
};

Prowadzacy * ZnajdzProwadzacegoRekurencyjnie (Prowadzacy * pGlowaProwadzacego, string nazwisko){
    //jeśli istnieje
  if (pGlowaProwadzacego)
    {
      //jeśli znaleźliśmy prowadzącego zwrócić wskaźnik
      if (pGlowaProwadzacego->NazwiskoProwadzacego == nazwisko)
        return pGlowaProwadzacego;
      //jeśli nie znaleźlismy szukaj dalej
      else
        return ZnajdzProwadzacegoRekurencyjnie(pGlowaProwadzacego->pNastepnyProwadzacy, nazwisko);
    }
    //nie ma takiego prowadzacego
  else
      return nullptr;
}

void DodajProwadzacegoNaPoczatek (Prowadzacy *& pGlowaProwadzacego, Zajecia *& pGlowaListyZajec, string nazwisko){
    //tylko jeden prowadzacy
    while(true)
    {
        auto p = pGlowaProwadzacego;
        if(pGlowaProwadzacego->NazwiskoProwadzacego == nazwisko)
        {
            p = pGlowaProwadzacego->pNastepnyProwadzacy;
        }
        else
        {
            pGlowaProwadzacego = new Prowadzacy {nazwisko, pGlowaProwadzacego, pGlowaListyZajec};
              break;
        }
    }
}
/** zwraca glowe drzewa? */
Zajecia * DodajZajeciaProwadzacemu (Godzina Poczatek, Godzina Koniec, Dzien Dzien, string Grupa, string Przedmiot){

    return nullptr;

}

void Wczytaj (){

}

int main()
{
    return 0;
}


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

#include "struktury.h"
#include "funkcje.h"

/** funkcja porwnujaca dzien nastepnie godzine zajec a potem minute */
bool Mniejsza(const Zajecia & pLewy, const Zajecia & pPrawy)
{
    if(pLewy.DzienZajec < pPrawy.DzienZajec)
        return true;
    else if(pLewy.DzienZajec > pPrawy.DzienZajec)
        return false;
    else // dni takie same, porownujemy godziny
    {
        if(pLewy.PoczatekZajec.Godzinka < pPrawy.PoczatekZajec.Godzinka)
            return true;
        else if(pLewy.PoczatekZajec.Godzinka > pPrawy.PoczatekZajec.Godzinka)
            return false;
        else // godziny takie same, porownujemy minuty
        {
            if(pLewy.PoczatekZajec.Minuta < pPrawy.PoczatekZajec.Minuta)
                return true;
            else //if(pLewy.PoczatekZajec.Minuta >= pPrawy.PoczatekZajec.Minuta)
                return false;
        }
    }
  //  return false;
}

/** funkcja wypisujaca enum jako string */
string WypiszDzien(Dzien DzienZajec){
    switch(DzienZajec)
    {
        case pn: return "pn";
        case wt: return "wt";
        case sr: return "sr";
        case cz: return "cz";
        case pt: return "pt";
        case sb: return "sb";
        case nd: return "nd";
    }
}
/** funkcja zwracajaca wskaznik na szukanego prowadzacego */
Prowadzacy* ZnajdzProwadzacegoRekurencyjnie (Prowadzacy* pGlowaListyProwadzacych, string nazwisko){
    //jeśli istnieje
    if (pGlowaListyProwadzacych)
    {
        //jeśli znaleźliśmy prowadzącego zwrócić wskaźnik
        if (pGlowaListyProwadzacych->NazwiskoProwadzacego == nazwisko)
            return pGlowaListyProwadzacych;
        //jeśli nie znaleźlismy szukaj dalej
        else
            return ZnajdzProwadzacegoRekurencyjnie(pGlowaListyProwadzacych->pNastepnyProwadzacy, nazwisko);
    }
    //nie ma takiego prowadzacego i zwraca nullptr
    else
        return nullptr;
}
/** funkcja dodajaca prowadzacego na poczatek listy jednokierunkowej */
Prowadzacy* DodajProwadzacegoNaPoczatek (Prowadzacy*& pGlowaListyProwadzacych, /*Zajecia*& pKorzen,*/ string nazwisko)
{
    return pGlowaListyProwadzacych = new Prowadzacy {nazwisko, pGlowaListyProwadzacych, nullptr };
    
   /* 
    
    //jeśli nie istnieje to dodaj do listy bez wskaźnika na następnego prowadzacego
    if (not pGlowaListyProwadzacych)
        pGlowaListyProwadzacych = new Prowadzacy {nazwisko, nullptr, pKorzen};
    //dodaj na poczatek listy ze wskaznikiem na nastepnego prowadzacego i wskaznikiem na liste zajec
    //tak aby byl tylko jeden o takim samym nazwisku prowadzacy
    //ZnajdzProwadzacegoRekurencyjnie jesli nie znajdzie nazwiska zwraca nullptr
    else if (ZnajdzProwadzacegoRekurencyjnie(pGlowaListyProwadzacych, nazwisko) == nullptr)
        pGlowaListyProwadzacych = new Prowadzacy {nazwisko, pGlowaListyProwadzacych, pKorzen};
    
    */
}
/** funkcja ktora dodaje posortowane zajecia */
void DodajZajeciaProwadzacemu (Zajecia*& pKorzen, Godzina& PoczatekZajec, Godzina& KoniecZajec, Dzien& DzienZajec, string& grupa, string& przedmiot)
{
    auto pNowy = new Zajecia {PoczatekZajec, KoniecZajec, DzienZajec, grupa, przedmiot, nullptr, nullptr};
    
    if(not pKorzen)
        pKorzen = pNowy;
    else
    {
      auto p = pKorzen;
      while(true)
      {
          if (Mniejsza (*pNowy, *p))  // nowy jest mniejszy od p
        //if(Mniejsza(*p->pLewy,*p->pPrawy) ==true)
        {
          if(p->pLewy)
            p = p->pLewy;
          else
          {
            p->pLewy = pNowy;
            return;
          }
        }
        else
        {
          if(p->pPrawy)
            p = p->pPrawy;
          else
          {
            p->pPrawy = pNowy;
            return;
          }
        }
      }
   }
}

void DodajZajeciaProwadzacemu2 (Zajecia*& pKorzen, Godzina PoczatekZajec, Godzina KoniecZajec, Dzien DzienZajec, string grupa, string przedmiot)
{
    if(not pKorzen)
        pKorzen = new Zajecia {PoczatekZajec, KoniecZajec, DzienZajec, grupa, przedmiot, nullptr, nullptr};
    else
    {
        auto p = pKorzen;
        while(
            (DzienZajec<p->DzienZajec/* mamy isc w lewo */ and p->pLewy/* sciezka w lewo istnieje */)
            or
            (DzienZajec<=p->DzienZajec/* mamy isc w prawo */ and p->pPrawy/* sciezka w prawo istnieje*/)
             )
        {
            //przesuniecie na nastepny wezel
            if(DzienZajec < p->DzienZajec)
                p = p->pLewy;
            else
                p = p->pPrawy;
        }
        //p wskazuje na poprzednik elementu do wstawienia
        if(DzienZajec< p->DzienZajec)
            p->pLewy = new Zajecia {PoczatekZajec, KoniecZajec, DzienZajec, grupa, przedmiot, nullptr, nullptr};
        else
            p->pPrawy = new Zajecia {PoczatekZajec, KoniecZajec, DzienZajec, grupa, przedmiot, nullptr, nullptr};
    }
}

/** funkcja wypisujaca posortowane zajecia prowadzacego*/
//inorder traversal
void WypiszZajeciaProwadzacego(Zajecia* pKorzen){
    //jesli istnieje
    if (pKorzen)
    {
        WypiszZajeciaProwadzacego(pKorzen->pLewy);
            cout<<setw(2)<<setfill('0')<<pKorzen->PoczatekZajec.Godzinka<<
            ":"<<setw(2)<<setfill('0')<<pKorzen->PoczatekZajec.Minuta<<
            "-"<<setw(2)<<setfill('0')<<pKorzen->KoniecZajec.Godzinka<<
            ":"<<setw(2)<<setfill('0')<<pKorzen->KoniecZajec.Minuta<<
            " "<<WypiszDzien(pKorzen->DzienZajec)<<
            " "<<pKorzen->Grupa<<
            " "<<pKorzen->Przedmiot<<endl;
        WypiszZajeciaProwadzacego(pKorzen->pPrawy);
    }
}
/** funkcja usuwajaca drzewo zajec */
void UsunDrzewo(Zajecia*& pKorzen){
    //jesli korzen istnieje
    if (pKorzen)
        {
            //usun drzewo rekurencyjnie
            UsunDrzewo(pKorzen->pLewy);
            UsunDrzewo(pKorzen->pPrawy);
            //usun korzen i wskaznik na korzen
            delete pKorzen;
            pKorzen = nullptr;
        }
}

//usun drzewo-> wskaznik na nastepnego prowadzacego-> usun poprzedniego i wskaznik
//potem rekurencja
//czy grzebiemy w pamieci?
/** funkcja usuwajaca liste i wszystkie drzewa */
void UsunWszystko(Zajecia*& pKorzen, Prowadzacy*& pGlowaListyProwadzacych){
    //jesli prowadzacy istnieje
    if (pGlowaListyProwadzacych)
    {
        UsunDrzewo(pKorzen);
        //przechodzimy do nastepnego prowadzacego;
        auto p = pGlowaListyProwadzacych->pNastepnyProwadzacy;
        delete pGlowaListyProwadzacych;
        pGlowaListyProwadzacych = nullptr;
        //krok rekurencyjny przechodzacy do nastepnego prowadzacego
        UsunWszystko(pKorzen, p);
    }
}

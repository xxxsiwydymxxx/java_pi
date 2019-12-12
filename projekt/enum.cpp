#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

enum Dzien{
    pn=1, wt=2, sr=3, cz=4, pt=5, sb=6, nd=7
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

//enum zwraca stringa zeby wypisac posortowane drzewo
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

void DodajProwadzacegoNaPoczatek (Prowadzacy*& pGlowaListyProwadzacych, Zajecia*& pGlowaListyZajec, string nazwisko){
    //jeśli nie istnieje to dodaj do listy bez wskaźnika na następnego prowadzacego
    if (not pGlowaListyProwadzacych)
        pGlowaListyProwadzacych = new Prowadzacy {nazwisko, nullptr, pGlowaListyZajec};
    //dodaj na poczatek listy ze wskaznikiem na nastepnego prowadzacego i wskaznikiem na liste zajec
    //tak aby byl tylko jeden o takim samym nazwisku prowadzacy
    //ZnajdzProwadzacegoRekurencyjnie jesli nie znajdzie nazwiska zwraca nullptr
    else if (ZnajdzProwadzacegoRekurencyjnie(pGlowaListyProwadzacych, nazwisko) == nullptr)
        pGlowaListyProwadzacych = new Prowadzacy {nazwisko, pGlowaListyProwadzacych, pGlowaListyZajec};
}
/** posortowane drzewo wg. dnia*/
//posortowac wg godziny i minuty
//poddrzewo?
//skad wiadomo ktore zajecia do jakiego prowadzacego
void DodajZajeciaProwadzacemu (Zajecia*& pKorzen, Godzina PoczatekZajec, Godzina KoniecZajec, Dzien DzienZajec, string grupa, string przedmiot){
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

/** wypisz posortowane drzewo zajec wg. dnia i godziny dla każdego prowadzącego*/
//inorder traversal
void WypiszZajeciaProwadzacego(Zajecia* pKorzen){
    //jesli istnieje
    if (pKorzen)
    {
        WypiszZajeciaProwadzacego(pKorzen->pLewy);
        cout<<pKorzen->PoczatekZajec.Godzinka<<":"<<pKorzen->PoczatekZajec.Minuta<<
            "-"<<pKorzen->KoniecZajec.Godzinka<<":"<<pKorzen->KoniecZajec.Minuta<<
            " "<<WypiszDzien(pKorzen->DzienZajec)<<
            " "<<pKorzen->Grupa<<
            " "<<pKorzen->Przedmiot<<endl;
        WypiszZajeciaProwadzacego(pKorzen->pPrawy);
    }
}
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
void UsunWszystko(Zajecia*& pKorzen, Prowadzacy*& pGlowaListyProwadzacych){
    //jesli prowadzacy istnieje
    if (pGlowaListyProwadzacych)
    {
        UsunDrzewo(pKorzen);
        //przechodzimy do nastepnego prowadzacego;
        auto p = pGlowaListyProwadzacych->pNastepnyProwadzacy;
        delete pGlowaListyProwadzacych;
        pGlowaListyProwadzacych = nullptr;
        //tu powinna byc rekurencja
        UsunWszystko(pKorzen, p);
    }
}

void Wczytaj(){

}

int main()
{
    return 0;
}

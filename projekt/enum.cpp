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

void DodajProwadzacegoNaPoczatek (Prowadzacy *& pGlowaListyProwadzacych, Zajecia *& pGlowaListyZajec, string nazwisko){
    //jeśli nie istnieje to dodaj do listy bez wskaźnika na następnego prowadzacego
    if (not pGlowaListyProwadzacych)
        pGlowaListyProwadzacych = new Prowadzacy {nazwisko, nullptr, pGlowaListyZajec};
    //dodaj na poczatek listy ze wskaznikiem na nastepnego prowadzacego i wskaznikiem na liste zajec
    //tak aby byl tylko jeden o takim samym nazwisku prowadzacy
    //ZnajdzProwadzacegoRekurencyjnie jesli nie znajdzie nazwiska zwraca nullptr
    else if (ZnajdzProwadzacegoRekurencyjnie(pGlowaListyProwadzacych, nazwisko) == nullptr)
        pGlowaListyProwadzacych = new Prowadzacy {nazwisko, pGlowaListyProwadzacych, pGlowaListyZajec};
}

/** wskaźnik na korzeń drzewa binarnego */
//zrobić warunki dla godzin i minut
// lewo = pKorzen->pLewy
// if (PoczatekZajec > lewo->PoczatekZajec)
// lewo->pLewy
// else lewo->pPrawy i to samo dla drugiej strony?
Zajecia* DodajZajeciaProwadzacemu (Zajecia* pKorzen, Godzina PoczatekZajec, Godzina KoniecZajec, Dzien DzienZajec, string grupa, string przedmiot){
    if (not pKorzen)
    {
        Zajecia * temp = new Zajecia;
        temp->PoczatekZajec.Godzinka = PoczatekZajec.Godzinka;
        temp->PoczatekZajec.Minuta = PoczatekZajec.Minuta;
        temp->DzienZajec = DzienZajec;
        temp->KoniecZajec.Godzinka = KoniecZajec.Godzinka;
        temp->KoniecZajec.Minuta = KoniecZajec.Minuta;
        temp->Grupa = grupa;
        temp->Przedmiot = przedmiot;
        //temp->dla wszystkich?
        temp->pLewy = temp->pPrawy = nullptr;
        return temp;
    }
    auto Prawo = pKorzen->pPrawy;
    auto Lewo = pKorzen->pLewy;
    //posortowac wg. minut
    if(DzienZajec > (pKorzen->DzienZajec))
    {
        if(PoczatekZajec.Godzinka and PoczatekZajec.Minuta > (pKorzen->PoczatekZajec.Godzinka and pKorzen->PoczatekZajec.Minuta))
        {
            Prawo->pPrawy = DodajZajeciaProwadzacemu(Prawo->pPrawy, PoczatekZajec, KoniecZajec, DzienZajec, grupa, przedmiot);
        }
        else
            Prawo->pLewy = DodajZajeciaProwadzacemu(Prawo->pLewy, PoczatekZajec, KoniecZajec, DzienZajec, grupa, przedmiot);
    }
    else if (DzienZajec <= (pKorzen->DzienZajec))
    {
        if(PoczatekZajec.Godzinka and PoczatekZajec.Minuta <= (pKorzen->PoczatekZajec.Godzinka and pKorzen->PoczatekZajec.Minuta))
        {
            Lewo->pLewy = DodajZajeciaProwadzacemu(Lewo->pLewy, PoczatekZajec, KoniecZajec, DzienZajec, grupa, przedmiot);
        }
        else
            Lewo->pPrawy = DodajZajeciaProwadzacemu(Lewo->pPrawy, PoczatekZajec, KoniecZajec, DzienZajec, grupa, przedmiot);
    }
    return pKorzen;
}

/** wypisz posortowane drzewo zajec wg. dnia i godziny dla każdego prowadzącego*/
//inorder traversal
void WypiszZajeciaProwadzacego(Zajecia*& pKorzen){
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

void UsunWszystko(){
    
}

void Wczytaj (){
    
}

int main()
{
    return 0;
}

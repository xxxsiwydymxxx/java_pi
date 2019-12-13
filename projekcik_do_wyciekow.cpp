
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

enum Dzien {
    pn = 1, wt = 2, sr = 3, cz = 4, pt = 5, sb = 6, nd = 7
};

struct Godzina {
    int Godzinka;
    int Minuta;
};

/** element listy z zajeciami */
struct Zajecia {
    Godzina PoczatekZajec;
    Godzina KoniecZajec;
    Dzien DzienZajec;
    string Grupa;
    string Przedmiot;
    Zajecia* pLewy;
    Zajecia* pPrawy;
};

/** element listy prowadzacych */
struct Prowadzacy {
    string NazwiskoProwadzacego;
    Prowadzacy* pNastepnyProwadzacy;
    Zajecia* pKorzenListyZajec;
};

/** */
bool Mniejsza(const Zajecia& pLewy, const Zajecia& pPrawy)
{
    if (pLewy.DzienZajec < pPrawy.DzienZajec)
        return true;
    else if (pLewy.DzienZajec > pPrawy.DzienZajec)
        return false;
    else // dni takie same, porownujemy godziny
    {
        if (pLewy.PoczatekZajec.Godzinka < pPrawy.PoczatekZajec.Godzinka)
            return true;
        else if (pLewy.PoczatekZajec.Godzinka > pPrawy.PoczatekZajec.Godzinka)
            return false;
        else // godziny takie same, porownujemy minuty
        {
            if (pLewy.PoczatekZajec.Minuta < pPrawy.PoczatekZajec.Minuta)
                return true;
            else
                return false;
        }
    }
}

/** funkcja wypisujaca enum jako string */
string WypiszDzien(Dzien DzienZajec) {
    switch (DzienZajec)
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
Prowadzacy* ZnajdzProwadzacegoRekurencyjnie(Prowadzacy* pGlowaListyProwadzacych, string nazwisko) {
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
Prowadzacy* DodajProwadzacegoNaPoczatek(Prowadzacy*& pGlowaListyProwadzacych, string nazwisko) {
    if (not pGlowaListyProwadzacych)
        return pGlowaListyProwadzacych = new Prowadzacy{ nazwisko, pGlowaListyProwadzacych, nullptr };
    else 
        DodajProwadzacegoNaPoczatek(pGlowaListyProwadzacych->pNastepnyProwadzacy, nazwisko);
}
/** funkcja ktora dodaje posortowane zajecia */
void DodajZajeciaProwadzacemu(Zajecia*& pKorzen, Godzina& PoczatekZajec, Godzina& KoniecZajec, Dzien& DzienZajec, string& grupa, string& przedmiot)
{
    auto pNowy = new Zajecia{ PoczatekZajec, KoniecZajec, DzienZajec, grupa, przedmiot, nullptr, nullptr };

    if (not pKorzen)
        pKorzen = pNowy;
    else
    {
        auto p = pKorzen;
        while (true)
        {
            if (Mniejsza(*pNowy, *p))  // nowy jest mniejszy od p
            {
                if (p->pLewy)
                    p = p->pLewy;
                else
                {
                    p->pLewy = pNowy;
                    return;
                }
            }
            else
            {
                if (p->pPrawy)
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

/** funkcja wypisujaca posortowane zajecia prowadzacego*/
//inorder traversal
void WypiszZajeciaProwadzacego(Zajecia* pKorzen) {
    //jesli istnieje
    if (pKorzen)
    {
        WypiszZajeciaProwadzacego(pKorzen->pLewy);
        cout << setw(2) << setfill('0') << pKorzen->PoczatekZajec.Godzinka <<
            ":" << setw(2) << setfill('0') << pKorzen->PoczatekZajec.Minuta <<
            "-" << setw(2) << setfill('0') << pKorzen->KoniecZajec.Godzinka <<
            ":" << setw(2) << setfill('0') << pKorzen->KoniecZajec.Minuta <<
            " " << WypiszDzien(pKorzen->DzienZajec) <<
            " " << pKorzen->Grupa <<
            " " << pKorzen->Przedmiot << endl;
        WypiszZajeciaProwadzacego(pKorzen->pPrawy);
    }
}
/** funkcja usuwajaca drzewo zajec */
void UsunDrzewo(Zajecia*& pKorzen) {
    //jesli korzen istnieje
          while (pKorzen)
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
void UsunWszystko(Zajecia*& pKorzen, Prowadzacy*& pGlowaListyProwadzacych) {
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

void Wczytaj() {

}
int main()
{


    Prowadzacy* pGlowa = nullptr;
    string kowal = "Kowalski";
    string zbych = "Zbyszek";
    Godzina GodzinaP{ 14,12 };
    Godzina GodzinaK{ 18,21 };
    Godzina GodzinaP1{ 13,14 };
    Godzina GodzinaK1{ 18,21 };
    Godzina GodzinaP2{ 12,17 };
    Godzina GodzinaK2{ 18,21 };
    Godzina GodzinaP3{ 7,17 };
    Godzina GodzinaK3{ 8,14 };
    string grupa = "gr2";
    string przedmiot = "amial";
    string grupa2 = "gr3";
    string przedmiot2 = "tuc";
    Dzien dzien = pt;
    Dzien dzien2 = pn;
    Dzien dzien3 = sr;

    /* DodajProwadzacegoNaPoczatek(pGlowa, kowal);
    DodajZajeciaProwadzacemu(pKorzen, GodzinaP, GodzinaK, dzien, grupa, przedmiot);
    DodajZajeciaProwadzacemu(pKorzen, GodzinaP1, GodzinaK3, dzien2, grupa2, przedmiot2);
    DodajZajeciaProwadzacemu(pKorzen, GodzinaP2, GodzinaK2, dzien, grupa2, przedmiot2);
    DodajZajeciaProwadzacemu(pKorzen, GodzinaP3, GodzinaK1, dzien3, grupa, przedmiot);
    WypiszZajeciaProwadzacego(pKorzen);
    UsunDrzewo(pKorzen);
    cout<<endl;

    DodajProwadzacegoNaPoczatek(pGlowa, zbych);
    DodajZajeciaProwadzacemu(pKorzen, GodzinaP, GodzinaK, dzien, grupa, przedmiot);
    DodajZajeciaProwadzacemu(pKorzen, GodzinaP1, GodzinaK3, dzien2, grupa2, przedmiot2);
    WypiszZajeciaProwadzacego(pKorzen);
    UsunWszystko(pKorzen, pGlowa);
    cout<<endl; */

    auto p = ZnajdzProwadzacegoRekurencyjnie(pGlowa, kowal);
    if (not p) // nie ma goscia
        p = DodajProwadzacegoNaPoczatek(pGlowa, kowal);
    //    DodajZajeciaProwadzacemu(, ... )
    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP, GodzinaK, dzien, grupa, przedmiot);
    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP1, GodzinaK3, dzien2, grupa2, przedmiot2);
    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP2, GodzinaK2, dzien, grupa2, przedmiot2);
    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP3, GodzinaK1, dzien3, grupa, przedmiot);
    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP3, GodzinaK1, dzien3, grupa, przedmiot);

    cout << endl;
    auto x = ZnajdzProwadzacegoRekurencyjnie(pGlowa, zbych);
    if (not x)
        x = DodajProwadzacegoNaPoczatek(pGlowa, zbych);
    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP, GodzinaK, dzien, grupa, przedmiot);
    DodajZajeciaProwadzacemu(x->pKorzenListyZajec, GodzinaP1, GodzinaK3, dzien2, grupa2, przedmiot2);
    WypiszZajeciaProwadzacego(x->pKorzenListyZajec);
    cout << endl;
    WypiszZajeciaProwadzacego(p->pKorzenListyZajec);
    //UsunDrzewo(p->pKorzenListyZajec);
    UsunWszystko(p->pKorzenListyZajec, pGlowa);
    cout << endl;
    cout << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#include "struktury.h"
#include "funkcje.h"

int main()
{
    Prowadzacy * pGlowa = nullptr;
    string kowal = "Kowalski";
    string zbych = "Zbyszek";
    Godzina GodzinaP {14,12};
    Godzina GodzinaK {18,21};
    Godzina GodzinaP1 {13,14};
    Godzina GodzinaK1 {18,21};
    Godzina GodzinaP2 {12,17};
    Godzina GodzinaK2  {18,21};
    Godzina GodzinaP3 {7,17};
    Godzina GodzinaK3  {8,14};
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

    auto p = ZnajdzProwadzacegoRekurencyjnie (pGlowa, kowal);
     if (not p) // nie ma goscia
        p = DodajProwadzacegoNaPoczatek(pGlowa, kowal);
//    DodajZajeciaProwadzacemu(, ... )
    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP, GodzinaK, dzien, grupa, przedmiot);
    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP1, GodzinaK3, dzien2, grupa2, przedmiot2);
    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP2, GodzinaK2, dzien, grupa2, przedmiot2);
    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP3, GodzinaK1, dzien3, grupa, przedmiot);
    WypiszZajeciaProwadzacego(p->pKorzenListyZajec);
    UsunWszystko(p->pKorzenListyZajec, pGlowa);
    cout<<endl;



    return 0;
}

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
    /*
    auto p = ZnajdzProwadzacegoRekurencyjnie (pGlowa, kowal);
     if (not p)
        p = DodajProwadzacegoNaKoniecListy(pGlowa, kowal);

    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP, GodzinaK, dzien, grupa, przedmiot);
    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP1, GodzinaK3, dzien2, grupa2, przedmiot2);
    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP2, GodzinaK2, dzien, grupa2, przedmiot2);
    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP3, GodzinaK1, dzien3, grupa, przedmiot);

    auto x = ZnajdzProwadzacegoRekurencyjnie (pGlowa, zbych);
        if (not x)
            x = DodajProwadzacegoNaKoniecListy(pGlowa, zbych);

    DodajZajeciaProwadzacemu(x->pKorzenListyZajec, GodzinaP, GodzinaK, dzien, grupa, przedmiot);    
    DodajZajeciaProwadzacemu(x->pKorzenListyZajec, GodzinaP2, GodzinaK3, dzien2, grupa2, przedmiot2);
    DodajZajeciaProwadzacemu(x->pKorzenListyZajec, GodzinaP1, GodzinaK1, dzien2, grupa2, przedmiot2);
    DodajZajeciaProwadzacemu(x->pKorzenListyZajec, GodzinaP2, GodzinaK3, dzien2, grupa2, przedmiot2);
    DodajZajeciaProwadzacemu(p->pKorzenListyZajec, GodzinaP2, GodzinaK3, dzien2, grupa2, przedmiot2);

    
    WypiszZajeciaProwadzacego(p->pKorzenListyZajec); cout<<endl;
    WypiszZajeciaProwadzacego(x->pKorzenListyZajec); cout<<endl;
    */

    Wczytaj(pGlowa, kowal, GodzinaP, GodzinaK, dzien, grupa, przedmiot);
    Wczytaj(pGlowa, kowal, GodzinaP2, GodzinaK2, dzien, grupa, przedmiot);
    Wczytaj(pGlowa, kowal, GodzinaP3, GodzinaK3, dzien, grupa, przedmiot);
    Wczytaj(pGlowa, zbych, GodzinaP, GodzinaK, dzien, grupa, przedmiot);
    WypiszZajeciaProwadzacego(pGlowa->pKorzenListyZajec);
            
    UsunWszystko(pGlowa);

    return 0;
}

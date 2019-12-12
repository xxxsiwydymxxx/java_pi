#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#include "struktury.h"
#include "funkcje.h"

int main()
{
    Prowadzacy * pGlowa = nullptr;
    Zajecia * pKorzen = nullptr;
    string kowal = "Kowalski";
    Godzina GodzinaP {14,12};
    Godzina GodzinaK {18,21};
    Godzina GodzinaP1 {13,14};
    Godzina GodzinaK1 {18,21};
    Godzina GodzinaP2 {12,17};
    Godzina GodzinaK2  {18,21};
    Godzina GodzinaP3 {7,17};
    Godzina GodzinaK3  {8,14};
    string grupa = "grupa";
    string przedmiot = "amial";
    string grupa2 = "grupa12";
    string przedmiot2 = "amial12";
    Dzien dzien = pt;
    Dzien dzien2 = pn;
    Dzien dzien3 = sr;

    DodajProwadzacegoNaPoczatek(pGlowa, pKorzen, kowal);
    DodajZajeciaProwadzacemu2(pKorzen, GodzinaP, GodzinaK, dzien, grupa, przedmiot);
    DodajZajeciaProwadzacemu2(pKorzen, GodzinaP1, GodzinaK3, dzien2, grupa2, przedmiot2);
    DodajZajeciaProwadzacemu2(pKorzen, GodzinaP2, GodzinaK2, dzien, grupa2, przedmiot2);
    DodajZajeciaProwadzacemu2(pKorzen, GodzinaP3, GodzinaK1, dzien3, grupa, przedmiot);
    WypiszZajeciaProwadzacego(pKorzen);
    UsunWszystko(pKorzen, pGlowa);
    return 0;
}

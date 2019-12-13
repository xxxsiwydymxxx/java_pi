#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#ifndef FUNKCJE_H
#define FUNKCJE_H

bool Mniejsza(const Zajecia & pLewy, const Zajecia & pPrawy);

string WypiszDzien(Dzien DzienZajec);

Prowadzacy* ZnajdzProwadzacegoRekurencyjnie (Prowadzacy* pGlowaListyProwadzacych, string nazwisko);

Prowadzacy* DodajProwadzacegoNaPoczatek (Prowadzacy*& pGlowaListyProwadzacych,/* Zajecia*& pKorzen,*/ string nazwisko);

void DodajZajeciaProwadzacemu (Zajecia*& pKorzen, Godzina& PoczatekZajec, Godzina& KoniecZajec, Dzien& DzienZajec, string& grupa, string& przedmiot);

void DodajZajeciaProwadzacemu2 (Zajecia*& pKorzen, Godzina PoczatekZajec, Godzina KoniecZajec, Dzien DzienZajec, string grupa, string przedmiot);

void WypiszZajeciaProwadzacego(Zajecia* pKorzen);

void UsunDrzewo(Zajecia*& pKorzen);

void UsunWszystko(Zajecia*& pKorzen, Prowadzacy*& pGlowaListyProwadzacych);

void Wczytaj();

#endif



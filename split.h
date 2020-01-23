/** @file */

#pragma once
#include <string>

#ifndef SPLIT_H
#define SPLIT_H

using namespace std;

/** Funkcja rozdzielajaca podany napis. Zmienia ilosc elementow globalnych (w main).
@param inData co to robi xD
@param ilosc wskaznik na xD 
@param przesuniecie wskaznik na xD
@retrun co zwraca xD */
Node* split(string inData, int* ilosc, int* przesuniecie);

#endif

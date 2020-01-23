/** @file */

#pragma once
#include <string>

#ifndef STRUCTURE_H
#define STRUCTURE_H

using namespace std;

//* Struktura do przechowywania poszczegolnych danych */
struct Data
{
	string tytul; 
	string kategoria; 
	string autor;

	Data(string _tyt, string _kat, string _aut) : tytul(_tyt), kategoria(_kat), autor(_aut) {} //!< przyjmuje dane i je zapisuje
};

//* Struktura do stworzenia dynamicznej listy i ogolnie dynamicznej alokacji pamieci */
struct Node
{
	Node* next; ///< wskaźnik na następny element
	Data data; ///< dane

	Node(Data data) : data(data), next(nullptr){} //!< przyjmuje strukture Data i zapisuje ja oraz przypisuje wskaznikowi na nastepny element wartosc 0
};

//* Struktura galezi, przechowuje wskaznik na pierwszy punkt, wskaznik na kolejna galaz, nazwe i rozmiar */
struct Branch
{
	Node* first; ///< wskaźnik na Node
	Branch* next; ///< wskaźnik na następny element
	string alias;
	int rozmiar;

	Branch() : first(nullptr), next(nullptr),rozmiar(0) {} //!< nie przyjmuje argumentow, rozmiar=0, pierwszy=NULLPTR
	Branch(Node* _it) : first(_it), next(nullptr), rozmiar(1), alias((_it->data).kategoria) {} //!<przyjmuje wskaznik na pierwszy element, ustawia rozmiar na 1, przypisuje sutomatycznie kategorie
};

#endif

#include <iostream>
#include <string>
using namespace std;

struct Book {
	char FirstName[20];
	char LastName[30];
	char City[30];
	char Street[30];
	char Number[10];
	char PostalCode[10];
	char EmailAdress[50];


};

void WpiszDane(Book *bk){

	cout << "Podaj imie: " << endl;
	cin >> bk->FirstName;

/*	cout << "Podaj nazwisko: " << endl;
	cin >> bk->LastName;

	cout << "Podaj miasto: " << endl;
	cin >> bk->City;

	cout << "Podaj ulice: " << endl;
	cin >> bk->Street;

	cout << "Podaj nr domu: " << endl;
	cin >> bk->Number;

	cout << "Podaj kod pocztowy: " << endl;
	cin >> bk->PostalCode;

	cout << "Podaj adres email: " << endl;
	cin >> bk->EmailAdress;
*/
}

void WypiszDane(Book *bk) {
	cout << bk->FirstName << endl;
	/* " " << bk->LastName << " " << bk->City << " " <<
		bk->Street << " " << bk->Number << " " << bk->PostalCode << " " << bk->EmailAdress << endl;
    */
}

void UsunDane(Book *bk) {

}

void Wyszukaj(Book *bk) {

}

int main()
{
	const int maxSize = 100;
	Book bk[maxSize];

    cout<<"1. cos"<<endl;
    cout<<"2. cos"<<endl;
    cout<<"3. cos"<<endl;
    cout<<"4. cos"<<endl;
    int ksiazka;
    int menu;
    while (menu)
    {

    cin >> ksiazka;
    menu;

    switch(ksiazka){
	case 1:

	for (int i = 0; i < 2; i++)
	{
        WpiszDane(bk + i);
	}

	break;


    case 2:
	for (int i = 0; i < 100; i++)
	{
		WypiszDane(bk+i);
	}
	break;

    default:
    menu=true;
    break;
    }
    }
}

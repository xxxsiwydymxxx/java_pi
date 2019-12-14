#include <iostream>
#include <vector>

using namespace std;

double *UtworzTablice(size_t rozmiar)
{
    double *wskaznik = nullptr;
    wskaznik = new double[rozmiar];
    return wskaznik;
}

void WypelnijTablice(double *tablica, size_t rozmiar)
{
    for(size_t i=0; i<rozmiar; i++)
    {
        cin>>tablica[i];
    }
    cout<<endl;
}
void WyswietlTablice(const double *const tablica, size_t rozmiar)
{
    for(size_t i=0; i<rozmiar; i++)
    {
        cout<<tablica[i]<<endl;
    }
    cout<<endl;
}

void MaxElement(double *tablica, size_t rozmiar)
{
    double max=0;
    size_t max_poz=0;

    for (size_t i=0; i<rozmiar; i++)
    {
        if(tablica[i]>max)
        {
            max=tablica[i];
            max_poz=i;
        }
    }

    cout<<"Max elemnt to "<<max<< " na pozycji "<<max_poz<<endl;
}

void MinElement(double *tablica, size_t rozmiar)
{
    double min=0;
    size_t min_poz=0;

    for (size_t i=0; i<rozmiar; i++)
    {
        if(tablica[i]<min)
        {
            min=tablica[i];
            min_poz=i;
        }
    }

    cout<<"Min elemnt to "<<min<< " na pozycji "<<min_poz<<endl;
}


int main(){

    double *mojaTablica = nullptr;
    size_t rozmiar;
    cin>>rozmiar;
    cout<<endl;
    mojaTablica=UtworzTablice(rozmiar);
    WypelnijTablice(mojaTablica,rozmiar);
    WyswietlTablice(mojaTablica,rozmiar);
    MaxElement(mojaTablica, rozmiar);
    MinElement(mojaTablica,rozmiar);
    delete [] mojaTablica;

    return 0;
}

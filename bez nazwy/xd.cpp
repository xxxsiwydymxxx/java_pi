#include <iostream>

using namespace std;

int main()
{
    const int n = 10;
    int max,min;
    
    cout<<"Podaj rozmiar tablicy ";
    int rozmiar;
    cin>>rozmiar;
    if(rozmiar>n || rozmiar < 0)
        cout<<"Wyszlismy poza rozmiar tablicy "<<endl;
    else
    
    {
    
    double tab[n]={};
        max=tab[0];
        min=tab[0];
        
    for(int i=0;i<rozmiar;i++)
        {
            

            cout<<"Tab ["<<i<<"] = ";
            cin>>tab[i];
                         
            if(tab[i]>max)
                {
                    max=tab[i];
                    max_poz=i;
                    
                }
//                     max_poz=i;
            
            if(tab[i]<min)
                {
                    min=tab[i];
                    min_poz=i;
                }
            
        }
        cout<<"Maximum to "<<max<<" na pozycji "<<max_poz<<endl;
        cout<<"Minimium to "<<min<<" na pozycji "<<min_poz<<endl;
    }


}

#include "macierz.hh"

/****************************
*   Funckja liczaca wyznacznik macierzy metoda gaussa
*   Funckja sprowadza macierz do macierzy gornotrojkanej
*   oraz nastepnie wylicza z takiej macierzy wyznacznik mnozac przez siebie
*   liczby na glownej przekatnej
*
****************************/

double macierz::gauss(macierz tmp) const
{
    double liczba = 0;
    
    for(int i(0); i < ROZMIAR; i++)
    {
        if(tmp[0][0] != 0)
        {break; }
        
        std::swap(tmp[0], tmp[i]);
    }

    if(tmp[0][0] == 0)
    {return 0; }
    
    for(int i(1); i < ROZMIAR; i++)
    {   
        if(tmp[0][0] == 0)
        {liczba = 0; }
        else 
        {tmp[i] = tmp[i] - (tmp[0] * (tmp[i][0] / tmp[0][0])); }
    }
    
    for(int i(2); i < ROZMIAR; i++)
    {
        for(int j(1); j < ROZMIAR-1; j++)
        {   
            if(tmp[i-1][j] == 0)
            {liczba = 0; }
            else 
            {
                tmp[i] = tmp[i] - (tmp[i-1] * (tmp[i][j] / tmp[i-1][j]));
            }
        }
   }

   liczba = 1;
   for(int i(0); i < ROZMIAR; i++)
   {
      liczba = liczba * tmp[i][i];
   }

   return liczba;
}

/****************************
*   Funckja liczaca wyznacznik metoda la_placa
*   wyznacznik liczony w tej funkcji jest liczony rekurencyjnie
*
****************************/
double macierz::la_place(int stopien, macierz tmp, int wiersz, Wektor kolumn) const
{
    double suma;
    int m, k;


    if(stopien == 1)
    {
        return tmp[wiersz][kolumn[0]];
    }
    else 
    {   
        Wektor tmp2;
        suma = 0;
        m = 1;
        for(int i(0); i < stopien ; i++)
        {   
            k = 0;
            for(int j(0); j < stopien - 1; j++)
            {
                if(k == i) k++;
                tmp2[j] = kolumn[k++];
            }
            suma += m * tmp[wiersz][kolumn[i]] * la_place(stopien - 1, tmp , wiersz + 1, tmp2);
            m = -m;
        }
    }

    return suma;
}

/****************************
*   Funckja liczaca wyznacznik metoda sarrusa dla macierzy 3 stopnia
*   
*
****************************/

double macierz::sarrus(macierz tmp) const
{
    return (tmp[0][0]*tmp[1][1]*tmp[2][2]+tmp[0][1]*tmp[1][2]*tmp[2][0]+tmp[0][2]*tmp[1][0]*tmp[2][1])
        -(tmp[0][2]*tmp[1][1]*tmp[2][0]+tmp[0][0]*tmp[1][2]*tmp[2][1]+tmp[0][1]*tmp[1][0]*tmp[2][2]);
}
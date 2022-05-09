#include "Macierz.hh"

template<class T, int size>
macierz<T, size>::macierz()
{
    for(int i(0); i < size; i++)
    {
        for(int j(0); j < size; j++)
        {
            this->tab[i][j] = 0;
        }
    } 
}

template<class T, int size>
macierz<T, size>::macierz(Wektor<T, size> tab[])
{
    for(int i(0); i < size; i++)
    {
        this->tab[i] = tab[i];
    } 
}

template<class T, int size>
const Wektor<T, size> &macierz<T, size>::operator[] (unsigned int index1) const
{
    if(index1 < 0 && index1 > size)
    {
        std::cerr << "Zly indeks!" << std::endl;
        exit(1);
    }

    return tab[index1];
}

template<class T, int size>
Wektor<T, size> &macierz<T, size>::operator[](unsigned int index1)
{
    if(index1 < 0 && index1 > size)
    {
        std::cerr << "Zly indeks!" << std::endl;
        exit(1);
    }

    return tab[index1];
}

template<class T, int size>
macierz<T, size> macierz<T, size>::operator + (const macierz<T, size> &Arg1) const
{   
    macierz<T, size> wynik;
    for(int i(0); i < size; i++)
    {
        wynik[i] = this->tab[i] + Arg1[i];
    }
    return wynik;
}

template<class T, int size>
macierz<T, size> macierz<T, size>::operator - (const macierz<T, size> &Arg1) const
{   
    macierz<T, size> wynik;
    for(int i(0); i < size; i++)
    {
        wynik[i] = this->tab[i] - Arg1[i];
    }

    return wynik;
}

template<class T, int size>
macierz<T, size> macierz<T, size>::operator * (const macierz<T, size> &Arg1) const
{
    macierz<T, size> wynik;
    for(int i(0); i < size; i++)
    {
        for(int j(0); j < size; j++)
        {
            T suma(0);
            for(int k(0); k < size; k++)
            { suma = suma + (this->tab[i][k] * Arg1[k][j]); }
            wynik[i][j] = suma;
        }
    }
    return wynik;
}

template<class T, int size>
macierz<T, size> macierz<T, size>::operator * (const T &liczba) const
{
    macierz<T, size> wynik;
    for(int i(0); i < size; i++)
    {
        wynik[i] = this->tab[i] * liczba;
    }

    return wynik;
}

template<class T, int size>
Wektor<T, size> macierz<T, size>::operator * (const Wektor<T, size> & Arg1) const
{
    Wektor<T, size> wynik;
    for(int i(0); i < size; i++)
    {
        T suma(0);
        for(int j(0); j < size; j++)
        {
            suma = suma + (this->tab[i][j] * Arg1[j]);
        }
        wynik[i] = suma;
    }
    
    return wynik;
}

template<class T, int size>
void macierz<T, size>::transponuj()
{   
    macierz<T, size> tmp(*this);
    for(int i(0); i < size; i++)
    {
        for(int j(0); j < size; j++)
        {
            this->tab[j][i] = tmp[i][j];
        }
    }
}

template<class T, int size>
macierz<T, size> macierz<T, size>::transponuj() const
{   
    macierz<T, size> tmp;
    for(int i(0); i < size; i++)
    {
        for(int j(0); j < size; j++)
        {
            tmp[j][i] = this->tab[i][j];
        }
    }

    return tmp;
}

template<class T, int size>
std::ostream &operator << (std::ostream &strm, const macierz<T, size> &Arg1)
{
    for(int i(0); i < size; i++)
    {
        strm << Arg1[i];
        if(i != size - 1)
        {
            strm << std::endl;
        }
    }

    return strm;
}

template<class T, int size>
std::istream &operator >> (std::istream &strm, macierz<T, size> &Arg1)
{
    for(int i(0); i < size; i++)
    {
        strm >> Arg1[i];
    }

    return strm;
}

template<class T, int size>
T macierz<T, size>::wyznacznik() const
{   
    macierz<T, size> lower, upper, tmp(*this);
    T porw(0.0);

    if(tmp[0][0] == porw)
    {return porw; }

    for (int i = 0; i < size; i++) 
    { 
        for (int k = i; k < size; k++)
        { 
            T liczba(0.0);
            for (int j = 0; j < i; j++) 
                liczba = liczba + (lower[i][j] * upper[j][k]); 

            upper[i][k] = tmp[i][k] - liczba; 
        }       
        
        if(upper[i][i] == porw) //dzielenie przez zero, nie wszystkie wyznaczniki liczy dobrze
        {return porw; }
        for (int k = i; k < size; k++) 
        { 
            if (i == k) 
                lower[i][i] = 1; 
            else 
            { 
                T liczba(0.0); 
                for (int j = 0; j < i; j++) 
                    liczba = liczba + (lower[k][j] * upper[j][i]);

                lower[k][i] = (tmp[k][i] - liczba) / upper[i][i]; 
            } 
        } 
    }

   T liczba(upper[0][0]);
   for(int i(1); i < size; i++)
   {
      liczba = liczba * upper[i][i];
   }

   return liczba;
}



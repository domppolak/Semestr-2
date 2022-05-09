#include "macierz.hh"

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

        if(size == 3)
        {
        return (tab[0][0]*tab[1][1]*tab[2][2]+tab[0][1]*tab[1][2]*tab[2][0]+tab[0][2]*tab[1][0]*tab[2][1])
        -(tab[0][2]*tab[1][1]*tab[2][0]+tab[0][0]*tab[1][2]*tab[2][1]+tab[0][1]*tab[1][0]*tab[2][2]);
        }
        else 
        std::cerr << "Tej macierzy nie obliczymy metoda sarrusa!" << std::endl;

}

template<class T,int size>
void macierz<T, size>::jednostkowa()
{
    for(int i(0); i < size; i++)
        for(int j(0); j < size; j++)
        {
            if(i == j)
            {tab[i][j] = 1; }
        }
}

template<class T, int size>
bool macierz<T, size>::operator == (const macierz<T, size> & arg1) const
{
    for(int i(0); i < size; i++)
    {
        if(tab[i] != arg1[i])
        {return false; }
    }

    return true;
}

template<class T, int size>
bool macierz<T, size>::operator != (const macierz<T, size> & arg1) const
{
    return !(*this == arg1);
}
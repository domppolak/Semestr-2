#include "Uklad.hh"

template<class T, int size>
const macierz<T, size> & uklad_rownan<T, size> ::get_arg1() const
{
    return this->arg1;
}

template<class T, int size>
const Wektor<T, size>  & uklad_rownan<T, size> ::get_arg2() const
{
    return this->arg2;
}

template<class T, int size>
void uklad_rownan<T, size> ::set_arg1 (const macierz<T, size>  & arg1)
{
    this->arg1 = arg1;
}

template<class T, int size>
void uklad_rownan<T, size> ::set_arg2 (const Wektor<T, size>  & arg2)
{
    this->arg2 = arg2;
}

template<class T, int size>
std::istream &operator >> (std::istream &strm, uklad_rownan<T, size>  &uklad)
{
    macierz<T, size>  tmp1;
    Wektor<T, size> tmp2;

    strm >> tmp1 >> tmp2;
    tmp1.transponuj();
    uklad.set_arg1(tmp1);
    uklad.set_arg2(tmp2);

    return strm;
}

template<class T, int size>
std::ostream &operator << (std::ostream &strm, const uklad_rownan<T, size>  &uklad)
{
    macierz<T, size>  tmp1(uklad.get_arg1());
    Wektor<T, size>  tmp2(uklad.get_arg2());

    for(int i(0); i < ROZMIAR; i++)
    {
        strm << '|' << tmp1[i] << "||" << "x_" << i+1 << "| = |" << tmp2[i] << '|' << std::endl;
    }
    
    return strm;
}

/****************************
*   Funckja sluzaca do wyliczenia rozwiazan danego ukladu rownan
*   Uklad jest rozwiazywany wzorami cramera
*   wczytuje macierz transponowana i z niej wylicza wartosci
*   najpierw zostaje wyliczany wyznacznik macierzy glownej
*   a nastepnie liczymy wyznaczniki pozostalych macierzy gdzie zamieniamy caly wiersz 
*   z wierszem wyrazow wolnych 
****************************/

template<class T, int size>
Wektor<T, size>  uklad_rownan<T, size> ::Oblicz() const
{
    macierz<T, size> tmp1(this->arg1);
    T det(0.0);
    T const porw(0.0);
    Wektor<T, size> tmp2;

    det = tmp1.wyznacznik();
    for(int i(0); i < size; i++)
    {
        tmp1 = this->arg1;
        for(int j(0); j < size; j++)
        {
            tmp1[j][i] = this->arg2[j];
        }

        tmp2[i] = tmp1.wyznacznik();
    }
    
    if(det == porw)
    {
        for(int i(0); i < size; i++)
        {
            if(tmp2[i] != porw)
            {
                std::string w1 = "wyjatek1";
                throw w1;
            }
            
        }

        std::string w2 = "wyjatek2";
        throw w2;
    }

    for(int i(0); i < size; i++)
    {
        tmp2[i] = tmp2[i] / det;
    }

    return tmp2;
}

template<class T, int size>
Wektor<T, size> wektor_bledu(const uklad_rownan<T, size> &uklad, const Wektor<T, size> &wynik)
{
    return uklad.get_arg1() * wynik - uklad.get_arg2();
}


#include "UkladRownanLin.hh"

uklad_rownan::uklad_rownan()
{

}

/****************************
*   Funckje pozwalajace na odczytanie oraz przypisanie wartosc
*   dla argumentow ukladu rownan
*
****************************/

const macierz & uklad_rownan::get_arg1() const
{
    return this->arg1;
}

const Wektor & uklad_rownan::get_arg2() const
{
    return this->arg2;
}

void uklad_rownan::set_arg1 (const macierz & arg1)
{
    this->arg1 = arg1;
}

void uklad_rownan::set_arg2 (const Wektor & arg2)
{
    this->arg2 = arg2;
}

std::istream &operator >> (std::istream &strm, uklad_rownan &uklad)
{
    macierz tmp1;
    Wektor tmp2;

    strm >> tmp1 >> tmp2;
    uklad.set_arg1(tmp1);
    uklad.set_arg2(tmp2);

    return strm;
}

std::ostream &operator << (std::ostream &strm, const uklad_rownan &uklad)
{
    macierz tmp1(uklad.get_arg1());
    tmp1.transponuj();
    Wektor tmp2(uklad.get_arg2());

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

Wektor uklad_rownan::Oblicz() const
{
    macierz tmp1(this->arg1);
    double det;
    Wektor tmp2;

    det = tmp1.wyznacznik(m_gauss);

    for(int i(0); i < ROZMIAR; i++)
    {
        tmp1 = this->arg1;
        tmp1[i] = this->arg2;
        tmp2[i] = tmp1.wyznacznik(m_gauss);
    }
    
    if(det == 0)
    {
        for(int i(0); i < ROZMIAR; i++)
        {
            if(tmp2[i] != 0)
            {
                std::string w1 = "wyjatek1";
                throw w1;
            }
            
        }

        std::string w2 = "wyjatek2";
        throw w2;
    }

    tmp2[0] = tmp2[0] / det;
    tmp2[1] = tmp2[1] / det;
    tmp2[2] = tmp2[2] / det;

    return tmp2;
}

/****************************
*   Funckja wyliczaja wektor bledu
*   przyjmuje 2 argumenty 
*   uklad rownan oraz wektor wynikow wczesniej wyliczonych tego ukladu
*
****************************/

Wektor wektor_bledu(const uklad_rownan &uklad, const Wektor &wynik)
{
    return uklad.get_arg1() * wynik - uklad.get_arg2();
}


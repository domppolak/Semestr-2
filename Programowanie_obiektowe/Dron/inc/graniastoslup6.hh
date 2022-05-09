#ifndef _GRANIASTOSLUP6_HH
#define _GRANIASTOSLUP6_HH

#include "bryla.hh"

/*!
*  \brief klasa reprezentujaca graniastoslup
*/
class graniastoslup : public bryla
{
protected:
    /*!
    *  \brief tablica 12 punktor reprezentujacyh wierzhcolki
    */
    Wektor3D wierzcholki[12];

public:
    /*!
    *  \brief konstruktor
    *  \param wsk - lacze do gnuplota
    *  \param K - zmienna przechowujaca kolor bryly
    *  \param M - macierz stanowiaca orientacje bryly
    *  \param S - punkt srodka bryly
    *  \param tablica - tablica 12 wektorow reprezentujaca wierzcholki 
    */
    graniastoslup(shared_ptr<Draw3DAPI> wsk, string K, macierz_ob M, Wektor3D S, Wektor3D tablica[])
    : bryla(wsk, K, M, S)
    {
        for(int i(0); i < 12; i++)
        { wierzcholki[i] = tablica[i]; }
    }

    /*!
    *  \brief destruktor
    */
    virtual ~graniastoslup() {}

    /*!
    *  \brief metoda przesuwajaca graniastoslup o podany wektor
    *  \param we - wektor o jaki ma sie przesunac bryla
    */
    void przemiesc(const Wektor3D &we)
    {
        srodek_bryly = srodek_bryly + we;
        
        for(int i(0); i < 12; i++)
        { wierzcholki[i] = we + wierzcholki[i]; }
        
        usun_obiekt();
        rysuj();
    }

    /*!
    *  \brief metoda rysujaca graniastoslup
    */
    void rysuj()
    {
        Wektor3D tmp[12];
        for(int i(0); i < 12; i++)
        { tmp[i] = srodek_bryly + orientacja * wierzcholki[i]; }

        obiekt_id = gnuplot->draw_polyhedron(vector<vector<Point3D>>
        {{
            tmp[0].punkt(), tmp[1].punkt(), tmp[2].punkt(), tmp[3].punkt(), tmp[4].punkt(), tmp[5].punkt()
        },{ 
            tmp[6].punkt(),tmp[7].punkt(),tmp[8].punkt(),tmp[9].punkt(), tmp[10].punkt(), tmp[11].punkt()
        }}, kolor);
        gnuplot->redraw();
    }
};
#endif
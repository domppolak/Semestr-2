#ifndef _PROSTOPADLOSCIAN_HH
#define _PROSTOPADLOSCIAN_HH

#include "bryla.hh"

/*!
*  \brief klasa reprezenujaca prostopadloscian
*/
class prostopadloscian : public bryla
{
protected:
    /*!
    *  \brief tablica 8 punktow reprezentujaca wierzcholki
    */
    Wektor3D wierzcholki[8];
public:
    /*!
    *  \brief konstruktor
    *  \param wsk - lacze do gnuplota
    *  \param K - zmienna przechowujaca kolor bryly
    *  \param M - macierz stanowiaca orientacje bryly
    *  \param S - punkt srodka bryly
    *  \param tablica - tablica 8 wektorow reprezentujaca wierzcholki 
    */
    prostopadloscian(shared_ptr<Draw3DAPI> wsk, string K, macierz_ob M, Wektor3D S, Wektor3D tablica[])
    : bryla(wsk, K, M, S)
    {
        for(int i(0); i < 8; i++)
        { wierzcholki[i] = tablica[i]; }
    }

    /*!
    *  \brief destruktor
    */
    virtual ~prostopadloscian() {}

    /*!
    *  \brief metoda rysujaca prostopadloscian
    */
    void rysuj()
    {
        Wektor3D tmp[8];
        //std::cerr << "Srodek bryly: " << srodek_bryly << std::endl;
        for(int i(0); i < 8; i++)
        { tmp[i] = srodek_bryly + orientacja * wierzcholki[i]; }
        /*std::cerr << "Prostopadloscian" << std::endl;
        for(int i(0); i < 8; i++)
        {
            std::cerr << wierzcholki[i] << std::endl;
        }*/

        obiekt_id = gnuplot->draw_polyhedron(vector<vector<Point3D>>
        {{
            tmp[0].punkt(), tmp[1].punkt(), tmp[2].punkt(), tmp[3].punkt()
        },{ 
            tmp[4].punkt(),tmp[5].punkt(),tmp[6].punkt(),tmp[7].punkt()
        }}, kolor);
        gnuplot->redraw();


    }

    /*!
    *  \brief metoda przesuwajca prostopadloscian o podany wektor
    *  \param we - wektor o jaki ma sie przesunac bryla
    */
    void przemiesc(const Wektor3D &we)
    {
        srodek_bryly = srodek_bryly + we;

        for(int i(0); i < 8; i++)
        { wierzcholki[i] = wierzcholki[i] + we; }

        usun_obiekt();
        //rysuj();


    }
};
#endif
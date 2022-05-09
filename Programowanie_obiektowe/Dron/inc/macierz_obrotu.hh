#ifndef _MACIERZ_OBROTU_HH
#define _MACIERZ_OBROTU_HH

#include "macierz.hh"
using macierz3D = macierz<double, 3>;
using Wektor3D = Wektor<double, 3>;

//wokol jakiej osi ma sie obrocic obiekt
enum wymiar{os_x, os_y, os_z};

class macierz_ob :public macierz<double, 3>
{
public:
    macierz_ob(const wymiar & wokol_os, const double kat) //kat stopnie
    {   
        double kat_rad = M_PI * kat / 180;
        switch(wokol_os)
        {
            case os_x:
            tab[0][0] = 1;
            tab[1][1] = cos(kat_rad); 
            tab[1][2] = (-1) * sin(kat_rad);
            tab[2][1] = sin(kat_rad);
            tab[2][2] = cos(kat_rad); 
            break;

            case os_y:
            tab[1][1] = 1;
            tab[0][0] = cos(kat_rad); 
            tab[0][2] = sin(kat_rad);
            tab[2][0] = (-1) * sin(kat_rad);
            tab[2][2] = cos(kat_rad); 
            break;
            
            case os_z:
            tab[2][2] = 1;
            tab[0][0] = cos(kat_rad); 
            tab[0][1] = (-1) * sin(kat_rad);
            tab[1][0] = sin(kat_rad);
            tab[1][1] = cos(kat_rad);
            break;
        }
    }
    
    macierz_ob(const macierz3D & M) : macierz3D(M) 
    {
        if(abs((*this).wyznacznik() - 1) > FLT_EPSILON)
        {std::cerr << "To nie jest macierz obrotu" << std::endl; exit(1); }

        if(abs(M[0]*M[1]) > FLT_EPSILON)
        {std::cerr << "To nie jest macierz obrotu" << std::endl; exit(1); }

        if(abs(M[1]*M[2]) > FLT_EPSILON)
        {std::cerr << "To nie jest macierz obrotu" << std::endl; exit(1); }

        if(abs(M[1]*M[2]) > FLT_EPSILON)
        {std::cerr << "To nie jest macierz obrotu" << std::endl; exit(1); }
    }

    ~macierz_ob() {}
};
#endif
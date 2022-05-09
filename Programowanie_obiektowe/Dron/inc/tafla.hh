#ifndef _TAFLA_HH
#define _TAFLA_HH

#include "powierzchnia.hh"
#include "przeszkoda.hh"

/*!
*  \brief klasa reprezentujaca tafle
*/
class tafla : public powierzchnia, public przeszkoda
{

public: 
    /*!
    *  \brief konstruktor
    *  \param wsk - lacze do gnuplota
    */
    tafla(shared_ptr<Draw3DAPI> wsk)
    : powierzchnia(wsk ,"blue") {}
    /*!
    *  \brief metoda rysujaca tafle 
    */
    void rysuj()
    {
    obiekt_id = gnuplot->draw_surface(vector<vector<Point3D>>{{
    drawNS::Point3D(-100,-100,100), drawNS::Point3D(-100,100,100)
      },{
    drawNS::Point3D(-80,-100,80), drawNS::Point3D(-80,100,80)
      },{
    drawNS::Point3D(-80,-100,100), drawNS::Point3D(-80,100,100)
      },{
    drawNS::Point3D(-60,-100,80), drawNS::Point3D(-60,100,80)
      },{
    drawNS::Point3D(-60,-100,100), drawNS::Point3D(-60,100,100)
      },{
    drawNS::Point3D(-40,-100,80), drawNS::Point3D(-40,100,80)
      },{
    drawNS::Point3D(-40,-100,100), drawNS::Point3D(-40,100,100)
      },{
    drawNS::Point3D(-20,-100,80), drawNS::Point3D(-20,100,80)
      },{
    drawNS::Point3D(-20,-100,100), drawNS::Point3D(-20,100,100)
      },{
    drawNS::Point3D(-0,-100,80), drawNS::Point3D(-0,100,80)
      },{
    drawNS::Point3D(-0,-100,100), drawNS::Point3D(-0,100,100)
      },{
    drawNS::Point3D(0,-100,80), drawNS::Point3D(0,100,80)
      },{
    drawNS::Point3D(20,-100,100), drawNS::Point3D(20,100,100)
      },{
    drawNS::Point3D(20,-100,80), drawNS::Point3D(20,100,80)
      },{
    drawNS::Point3D(40,-100,100), drawNS::Point3D(40,100,100)
      },{
    drawNS::Point3D(40,-100,80), drawNS::Point3D(40,100,80)
      },{
    drawNS::Point3D(60,-100,100), drawNS::Point3D(60,100,100)
      },{
    drawNS::Point3D(60,-100,80), drawNS::Point3D(60,100,80)
      },{
    drawNS::Point3D(80,-100,100), drawNS::Point3D(80,100,100)
      },{
    drawNS::Point3D(80,-100,80), drawNS::Point3D(80,100,80)
      },{
    drawNS::Point3D(100,-100,100), drawNS::Point3D(100,100,100)
      }}, kolor);
    }

  bool czy_kolizja(const interfejs_drona & Dron)
	{
    Wektor3D tmp;
		tmp = Dron.get_srodek();

		if(tmp[2] > (80 - 0.7 * Dron.get_promien()))
		{	
			std::cerr << "Ruch wstrzymany kolizja z tafla" << std::endl;
			return true;
		}
		
		return false;
	}
};

#endif
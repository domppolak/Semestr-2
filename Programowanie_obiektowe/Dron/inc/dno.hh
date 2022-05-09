#ifndef _DNO_HH
#define _DNO_HH

#include "powierzchnia.hh"
#include "przeszkoda.hh"

/*!
*  \brief klasa reprezentujaca dno
*/
class dno : public powierzchnia, public przeszkoda
{

public:
	/*!
	*  \brief konstruktor
	*  \param wsk - lacze do gnuplota
	*/
    dno(shared_ptr<Draw3DAPI> wsk)
    : powierzchnia(wsk, "yellow") {}
	/*!
	*  \brief metoda rysujaca dno 	
	*/
    void rysuj()
    {
    obiekt_id = gnuplot->draw_surface(vector<vector<Point3D>> {{
  	drawNS::Point3D(-100,-100,-100), drawNS::Point3D(-100,-80,-100), drawNS::Point3D(-100,-40,-100), drawNS::Point3D(-100,0,-100), drawNS::Point3D(-100,40,-100), drawNS::Point3D(-100,80,-100), drawNS::Point3D(-100,100,-100)
  	  },{
  	drawNS::Point3D(-80,-100,-100), drawNS::Point3D(-80,-80,-100), drawNS::Point3D(-80,-40,-100),  drawNS::Point3D(-80,0,-100), drawNS::Point3D(-80,40,-100), drawNS::Point3D(-80,80,-100), drawNS::Point3D(-80,100,-100)
      },{
  	drawNS::Point3D(-40,-100,-100), drawNS::Point3D(-40,-80,-100), drawNS::Point3D(-40,-40,-100), drawNS::Point3D(-40,0,-100), drawNS::Point3D(-40,40,-100), drawNS::Point3D(-40,80,-100), drawNS::Point3D(-40,100,-100)
  	  },{
  	drawNS::Point3D(-0,-100,-100), drawNS::Point3D(-0,-80,-100), drawNS::Point3D(-0,-40,-100), drawNS::Point3D(-0,0,-100), drawNS::Point3D(-0,40,-100), drawNS::Point3D(-0,80,-100), drawNS::Point3D(-0,100,-100)
  	  },{
  	drawNS::Point3D(40,-100,-100), drawNS::Point3D(40,-80,-100), drawNS::Point3D(40,-40,-100), drawNS::Point3D(40,0,-100), drawNS::Point3D(40,40,-100), drawNS::Point3D(40,80,-100), drawNS::Point3D(40,100,-100)
  	  },{
  	drawNS::Point3D(80,-100,-100), 	drawNS::Point3D(80,-80,-100), drawNS::Point3D(80,-40,-100), drawNS::Point3D(80,0,-100), drawNS::Point3D(80,40,-100), drawNS::Point3D(80,80,-100), drawNS::Point3D(80,100,-100)
      },{
  	drawNS::Point3D(100,-100,-100), drawNS::Point3D(100,-80,-100), drawNS::Point3D(100,-40,-100), drawNS::Point3D(100,0,-100), drawNS::Point3D(100,40,-100), drawNS::Point3D(100,80,-100), drawNS::Point3D(100,100,-100)
  	  }}, kolor);
    }

	bool czy_kolizja(const interfejs_drona & Dron)
	{	
		Wektor3D tmp;
		tmp = Dron.get_srodek();

		if(tmp[2] < (-100 + 1.4 * Dron.get_promien()))
		{	
			std::cerr << "Ruch wstrzymany kolizja z dnem" << std::endl;
			return true;
		}
		
		return false;
	}
};

#endif
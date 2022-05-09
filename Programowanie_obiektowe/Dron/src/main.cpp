#include "dron.hh"
#include "dno.hh"
#include "tafla.hh"
#include "przeszkoda_prostopadloscian.hh"

using std::cin;
using std::cout;
using std::endl;

void wait4key();
void menu_wyboru();
void dane();

int main()
{
int max(100);
std::shared_ptr<drawNS::Draw3DAPI> api (new APIGnuPlot3D(-max,max,-max,max,-max,max,-1));
std::ifstream plik_dron;
Wektor3D sr_dron[3], sr1[4];
Wektor3D tab[4][8], tab1[12], tab_dron[3][8];
macierz3D x_dron;
//wczytywanie danych z pliku 
plik_dron.open("test.txt");

  plik_dron >> x_dron;

for(int i(0); i < 1; i++)
{
  for(int j(0); j < 8; j++)
  {
      plik_dron >> tab_dron[i][j];
  }
  plik_dron >> sr_dron[i];
}
for(int i(0); i < 12; i++)
{
      plik_dron >> tab1[i];
}
  plik_dron >> sr1[0];

for(int i(1); i < 4; i++)
{
  for(int j(0); j < 8; j++)
  {
      plik_dron >> tab[i][j];
  }
  plik_dron >> sr1[i];
}
// tworzenie listy przeszkod
std::vector<std::shared_ptr<przeszkoda_prost>> przeszkody_prostokatne
{
  std::make_shared<przeszkoda_prost>(api, "green", x_dron, sr1[1], tab[1]),
  std::make_shared<przeszkoda_prost>(api, "green", x_dron, sr1[2], tab[2]),

};
std::vector<std::shared_ptr<dron>> Dron
{
  std::make_shared<dron>(api, "purple", x_dron, sr_dron[0], sr1[0], sr1[0], tab_dron[0], tab1, tab1),
  std::make_shared<dron>(api, "grey", x_dron, sr_dron[0], sr1[0], sr1[0], tab_dron[0], tab1, tab1),
  std::make_shared<dron>(api, "orange", x_dron, sr_dron[0], sr1[0], sr1[0], tab_dron[0], tab1, tab1)
};

std::vector<std::shared_ptr<przeszkoda>> lista_przeszkod
{
  std::make_shared<dno>(api),
  std::make_shared<tafla>(api)
};

for(auto elem : przeszkody_prostokatne)
{
  lista_przeszkod.push_back(elem);
}

for(auto elem : Dron)
{
  lista_przeszkod.push_back(elem);
}

Dron[1]->obroc(90);
Dron[1]->przesun(30,-10);
Dron[1]->obroc(-90);
Dron[2]->obroc(-90);
Dron[2]->przesun(-30, 20);
Dron[2]->obroc(90);

for(auto elem : lista_przeszkod)
{
  elem->rysuj();
}

char wybor;
double odleglosc, kat, dzielnik;
int n(0);
do
{
  dane();
  menu_wyboru();
  cout << "Twoj wybor: " << endl;
  cin >> wybor;
  
  switch(wybor)
  {
    case 'r': 
      cout << "Podaj odleglosc, kat:" << endl;
      cin >> odleglosc >> kat;
      dzielnik = std::abs(odleglosc * 5);
      for(int i(0); i < dzielnik; i++)
      {
        Dron[n]->przesun(odleglosc / dzielnik, kat); 
        for(auto elem : lista_przeszkod)
        {  
          if(elem == Dron[n]) {} // kolzija z samym soba
          else if(elem->czy_kolizja(*Dron[n]))
          { 
            i = dzielnik;
            Dron[n]->przesun(-odleglosc / dzielnik, kat);
          }
        
        }  
        Dron[n]->rysuj();
      }
    break;

    case 'o': 
      cout << "Podaj kat:" << endl;
      cin >> kat;
      dzielnik = std::abs(kat * 2);
      for(int i(0); i < dzielnik; i++)
      {
      Dron[n]->obroc(kat/dzielnik);
      Dron[n]->rysuj();
      }
    break;

    case 'w':
      cout << "1. Dron fioletowy" << endl;
      cout << "2. Dron szary" << endl;
      cout << "3. Dron pomaranczowy" << endl;
      cin >> wybor;
        if(wybor == '1')
        { n = 0; }
        if(wybor == '2')
        { n = 1; }
        if(wybor == '3')
        { n = 2; }
    break;

    case 'k':
    cout << "Koniec dzialania programu!" << endl;
    return 0;

    default:
    std::cerr << "Nie ma takiego wyboru" << endl;
    break;
  }
}while(wybor != 'k');
return 0;

}

void wait4key() 
{
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

void menu_wyboru()
{
  cout << "----Wybor opcji drona----" << endl;
  cout << "r - Zadaj ruch na wprost" << endl;
  cout << "o - Zadaj zmiane orientacji" << endl;
  cout << "w - wybor drona" << endl;
  cout << "k - Koniec dzialania programu" << endl;
}

void dane()
{
  std::cout << "Aktualna liczba uworzonych wektorow: " << Wektor3D::get_aktualna_liczba_wektorow() << std::endl; 
  std::cout << "Aktualna liczba utworzonych bryl: " << bryla::get_aktualna_liczba_bryl() << std::endl;
  std::cout << "Calkowita liczba utworzonych wektorow: " << Wektor3D::get_calkowita_liczba_wektorow() << std::endl;
  std::cout << "Calkowita liczba utworzonych bryl: " << bryla::get_calkowita_liczba_bryl() << std::endl;
}
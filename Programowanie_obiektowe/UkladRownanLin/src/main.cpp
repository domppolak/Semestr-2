#include "UkladRownanLin.hh"

int main()
{

uklad_rownan uklad;
Wektor we_wynikow, we_bledu;

std::cin >> uklad;
std::cout << uklad << std::endl << std::endl;

try
{
    we_wynikow = uklad.Oblicz();
    std::cout << "Rozwiazanie (x1, x2, x3): " << std::endl << std::endl;
    std::cout << we_wynikow << std::endl << std::endl;

}
catch(std::string wyjatek)
{
    if(wyjatek == "wyjatek1")
    {
        std::cout << "uklad sprzeczny" << std::endl;
    }
    if(wyjatek == "wyjatek2")
    {
        std::cout << "uklad sprzeczny albo nieoznaczony" << std::endl;
    }    
}

we_bledu = wektor_bledu(uklad, we_wynikow);
std::cout << "Wektor bledu: ( " << we_bledu << " )" << std::endl;
std::cout << "Dlugosc wektora beldu: " << we_bledu.dlugosc() << std::endl;

}   
#include "Zespolona.hh"

void LZespolona::set_re (double re)
{
    this->re = re;
}

void LZespolona::set_im (double im)
{
    this->im = im;
}

/*
* Funckje zwracajace wartosci przyjmowane przez Liczbe zespolona
*/

double LZespolona::get_re() const
{
    return this->re;
}
double LZespolona::get_im() const
{
    return this->im;
}

LZespolona &LZespolona::operator = (const LZespolona &Sk1)
{
    this->re = Sk1.re;
    this->im = Sk1.im;

    return *this;
}

LZespolona &LZespolona::operator = (const double & liczba)
{
    this->re = liczba; this->im = 0;
    return *this;
}
/*
*   Funkcja realizuje wyswietlenie liczbe zespolonej
*/

std::ostream &operator << (std::ostream &wyjscie, const  LZespolona &Sk1)
 {  
     if(Sk1.get_re() == 0 && (Sk1.get_im() == 1 || Sk1.get_im() == -1))
     {
         if(Sk1.get_im() == -1)
         {return wyjscie << "(-i)";}
         if(Sk1.get_im() == 1)
         {return wyjscie << "(i)";}
     }
     if(Sk1.get_im() == 1)
     {  
         return wyjscie << '(' << Sk1.get_re() <<"+i)"; 
     }
     if(Sk1.get_im() == 0)
     {
         return wyjscie << '(' << Sk1.get_re() << ')';
     }
     if(Sk1.get_im() == -1)
     {
        return wyjscie << '(' << Sk1.get_re() <<"-i)";
     } 
     if(Sk1.get_re() == 0)
     {
         return wyjscie << '(' << Sk1.get_im() << "i)";
     } 
     return wyjscie << '(' << Sk1.get_re() << std::showpos << Sk1.get_im() << std::noshowpos << "i)"; 
    
 }

/*
*   Funckja realizuje wczytanie liczby zespolonej
*   Pozwala na wczytanie liczby zeposlonej w skroconym formacie np. (2i)
*/
std::istream &operator >> (std::istream &wejscie, LZespolona &Sk1)
{
    char znak, znak1;
    Sk1.set_re(0);   Sk1.set_im(0);
    double im, re;
    wejscie >> znak;
    if((znak == '(') && ((wejscie.peek() >= '0' && wejscie.peek() <= '9') || (wejscie.peek() == '-')))
    {   
        wejscie >> znak;
        if(znak == '-' && wejscie.peek() == 'i')
        {
            Sk1.set_im(-1);
            wejscie >> znak >> znak;
            if(znak != ')')
                {wejscie.setstate(std::ios::failbit);}
        }
        wejscie.putback(znak);
        wejscie >> re >> znak; 
        if(znak == ')')
            {Sk1.set_re(re);
            return wejscie;}
        else
            {Sk1.set_re(re);
            wejscie >> znak1;}
        if((znak == '-' || znak == '+') && znak1 == 'i')
        {
            if(znak == '-')
                {Sk1.set_im(-1);}
            if(znak == '+')
                {Sk1.set_im(1);}
            wejscie >> znak;
            if(znak != ')')
                {wejscie.setstate(std::ios::failbit);}
        }
        if(znak == 'i' && znak1 == ')')
        {
            Sk1.set_im(re); 
            Sk1.set_re(0);
            return wejscie;
        }
        wejscie.putback(znak1);
        wejscie.putback(znak);
        wejscie >> im >> znak >> znak1;
        if(znak == 'i' && znak1 == ')')
            {Sk1.set_im(im);
            return wejscie;}
    }if(wejscie.peek() == 'i' && znak == '(')
    {
        Sk1.set_im(1);
        wejscie >> znak >> znak;
        if(znak != ')')
            {wejscie.setstate(std::ios::failbit);}
    }

    wejscie.setstate(std::ios::failbit);
    return wejscie;
}
/*
* Funkcja realizuje dodawanie do siebie 2 liczb zespolonych 
*/

 LZespolona LZespolona::operator + (const LZespolona &Sk1) const
 {
     LZespolona wynik;
     wynik.re = this->re + Sk1.re;
     wynik.im = this->im + Sk1.im;
     return wynik;
 }
/*
* Funkcja realizuje odejmowanie od siebie 2 liczb zespolonych 
*/

 LZespolona LZespolona::operator - (const LZespolona &Sk1) const
 {
     LZespolona wynik;
     wynik.re = this->re - Sk1.re;
     wynik.im = this->im - Sk1.im;
     return wynik;
 }
/*
*   Funckja realizuje mnozenie przez siebie 2 liczb zepolonych
*   Przyjmuje jako argumenty 2 liczby zespolone
*/
  LZespolona LZespolona::operator * (const LZespolona &Sk1) const
 {
     LZespolona wynik;
     wynik.re = this->re * Sk1.re - this->im * Sk1.im;
     wynik.im = this->re * Sk1.im + this->im * Sk1.re;
     return wynik;
 }

LZespolona LZespolona::operator * (const double &liczba) const
{
     LZespolona wynik;
     wynik.re *= liczba;
     wynik.im *= liczba;
     return wynik;
}
/*
*   Funckja realizuje dzielenie liczby zespolonej 
*   przyjmuje jako argumenty 2 rozne liczby zespolone 
*   
*   Funkcja wykorzystuje wzor na dzielenie liczby zespolonej
*   Pierwsza liczba jest najpierw pomnozona przez sprzeznie drugiej liczby
*     a nastepnie podzielona przez modul 2 liczby zespolonej
*/
 LZespolona LZespolona::operator / (const LZespolona &Sk2) const
 {
    LZespolona wynik;
    wynik = (*this * Sk2.sprzezenie()) / (Sk2.modul() * Sk2.modul());
    return wynik;
 }

/*
*   Funckja, ktora dzieli liczbe zespolona przez liczbe typu double
*Argumenty:
*   Liczba zespolona
*   liczba typu double
* Zwraca wynik dzielenia skaldnikow przekazanych jako argumenty
*/

 LZespolona LZespolona::operator / (const double &liczba ) const
 {
     LZespolona wynik;
     if(liczba == 0)
     {   
         std::string wyjatek = "Dzielenie przez zero!";
         throw wyjatek;
     }
     else 
     {
     wynik.re = this->re / liczba;
     wynik.im = this->im/ liczba;
     }
    return wynik;
 }
/*
*   Funkcje, sprawdzajace czy 2 liczby zespolone sa sobie rowne lub nie
*   Zwaracaja:
    false albo true
*
*/
 bool LZespolona::operator == (const LZespolona &Sk1) const
 {
    if(fabs(this->re - Sk1.re) <= FLT_EPSILON)       /* FLT_EPSILON 1E-5*/
       {
            if(fabs(this->im - Sk1.im) <= FLT_EPSILON)
            {return true;}
       }
        return false;
 }

bool LZespolona::operator != (const LZespolona &Sk1) const
{
    return (!(*this == Sk1));
}

/*
*   Funkcja, ktora liczy modul liczby zespolonej
*   oraz zrawaca pierwiastek z sum kwadrotow czesci rzeczywistej i urojeonej liczby zespolonej
*/
 double LZespolona::modul() const
 {
     return sqrt(this->re * this->re + this->im * this->im);
 }

/*
*   Funckja, wykonujaca sprzezenie liczby zespolonej, ktora zwraca
*   liczbe zespolona ze zmianionym znakiem przy czesci urojonej
*/
LZespolona LZespolona::sprzezenie() const
{
    LZespolona tmp(*this);
    tmp.im *= -1;
    return tmp;
}

void LZespolona::sprzezenie()
{
    this->im *= -1;
}

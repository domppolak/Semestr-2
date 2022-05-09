#include "Uklad_def.cpp"
template class uklad_rownan<double, ROZMIAR>;
template std::istream &operator >> (std::istream &, uklad_rownan<double, ROZMIAR> &);
template std::ostream &operator << (std::ostream &, const uklad_rownan<double, ROZMIAR> &);
template Wektor<double, ROZMIAR> wektor_bledu (const uklad_rownan<double, ROZMIAR> &, const Wektor<double, ROZMIAR> &);
template class uklad_rownan<LZespolona, ROZMIAR>;
template std::istream &operator >> (std::istream &, uklad_rownan<LZespolona, ROZMIAR> &);
template std::ostream &operator << (std::ostream &, const uklad_rownan<LZespolona, ROZMIAR> &);
template Wektor<LZespolona, ROZMIAR> wektor_bledu (const uklad_rownan<LZespolona, ROZMIAR> &, const Wektor<LZespolona, ROZMIAR> &);
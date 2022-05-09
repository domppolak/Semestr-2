#include "Macierz_def.cpp"

template class macierz<double, ROZMIAR>;
template std::istream &operator >> (std::istream &strm, macierz<double, ROZMIAR> &);
template std::ostream &operator << (std::ostream &strm, const macierz<double, ROZMIAR> &);
template class macierz<LZespolona, ROZMIAR>;
template std::istream &operator >> (std::istream &strm, macierz<LZespolona, ROZMIAR> &);
template std::ostream &operator << (std::ostream &strm, const macierz<LZespolona, ROZMIAR> &);

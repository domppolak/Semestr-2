#include "Wektor_def.cpp"

template class Wektor<double, ROZMIAR>;
template std::istream &operator >> (std::istream &strm, Wektor<double, ROZMIAR> &);
template std::ostream &operator << (std::ostream &strm, const Wektor<double, ROZMIAR> &);
template class Wektor<LZespolona, ROZMIAR>;
template std::istream &operator >> (std::istream &strm, Wektor<LZespolona, ROZMIAR> &);
template std::ostream &operator << (std::ostream &strm, const Wektor<LZespolona, ROZMIAR> &);

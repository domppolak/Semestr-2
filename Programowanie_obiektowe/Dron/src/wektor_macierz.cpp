#include "wektor.cpp"
#include "macierz.cpp"

template class Wektor<double, 3>;
template std::istream &operator >> (std::istream &strm, Wektor<double, 3> &);
template std::ostream &operator << (std::ostream &strm, const Wektor<double, 3> &);

template class macierz<double, 3>;
template std::istream &operator >> (std::istream &strm, macierz<double,3 > &);
template std::ostream &operator << (std::ostream &strm, const macierz<double, 3> &);

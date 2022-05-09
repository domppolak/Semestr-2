#
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__:uklad_szablon
	./uklad_szablon

uklad_szablon: obj/main.o obj/Wektor.o obj/Zespolona.o obj/Macierz.o\
				obj/Uklad.o
	g++ -Wall -pedantic -o uklad_szablon obj/main.o obj/Wektor.o obj/Zespolona.o\
				obj/Macierz.o obj/Uklad.o

obj/main.o: src/main.cpp inc/Wektor.hh inc/Zespolona.hh inc/rozmiar.hh 
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Wektor.o: src/Wektor.cpp inc/rozmiar.hh inc/Wektor.hh inc/Zespolona.hh\
			src/Wektor_def.cpp
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

obj/Macierz.o: src/Macierz.cpp inc/rozmiar.hh inc/Wektor.hh inc/Zespolona.hh\
				inc/Macierz.hh src/Macierz_def.cpp
	g++ ${CPPFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/Uklad.o: src/Uklad.cpp inc/rozmiar.hh inc/Wektor.hh inc/Zespolona.hh\
				inc/Macierz.hh inc/Uklad.hh src/Uklad_def.cpp
	g++ ${CPPFLAGS} -o obj/Uklad.o src/Uklad.cpp
			
obj/Zespolona.o: src/Zespolona.cpp inc/rozmiar.hh inc/Zespolona.hh
	g++ ${CPPFLAGS} -o obj/Zespolona.o src/Zespolona.cpp

clean:
	rm -f obj/*.o uklad_rownan

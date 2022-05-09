#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: uklad_rownan
	./uklad_rownan

uklad_rownan: obj/main.o obj/UkladRownanLin.o obj/macierz.o obj/Wektor.o\
				obj/metody_wyznacznikow.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/Wektor.o\
                obj/macierz.o obj/UkladRownanLin.o obj/metody_wyznacznikow.o

obj/main.o: src/main.cpp inc/UkladRownanLin.hh inc/macierz.hh inc/Wektor.hh\
        inc/rozmiar.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/UkladRownanLin.o: src/UkladRownanLin.cpp inc/UkladRownanLin.hh
	g++ ${CPPFLAGS} -o obj/UkladRownanLin.o src/UkladRownanLin.cpp

obj/macierz.o: src/macierz.cpp inc/macierz.hh 
	g++ ${CPPFLAGS} -o obj/macierz.o src/macierz.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh inc/rozmiar.hh
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

obj/metody_wyznacznikow.o: src/metody_wyznacznikow.cpp inc/macierz.hh							
	g++ ${CPPFLAGS} -o obj/metody_wyznacznikow.o src/metody_wyznacznikow.cpp

clean:
	rm -f obj/*.o uklad_rownan
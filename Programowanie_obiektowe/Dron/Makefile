#
#
CPPFLAGS = -c -g -Iinc -Wall -pedantic -std=c++17

__start__: dron.out
	./dron.out

dron.out: obj/Dr3D_gnuplot_api.o obj/wektor_macierz.o obj/dron.o\
	obj/main.o obj/bryla.o
	g++ -o dron.out obj/wektor_macierz.o obj/Dr3D_gnuplot_api.o\
	 obj/main.o obj/dron.o obj/bryla.o -lpthread

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

obj/wektor_macierz.o: src/wektor_macierz.cpp src/wektor.cpp src/macierz.cpp\
	inc/macierz.hh inc/wektor.hh
	g++ ${CPPFLAGS} -o obj/wektor_macierz.o src/wektor_macierz.cpp

obj/dron.o: src/dron.cpp inc/dron.hh inc/inter_rysowania.hh inc/bryla.hh inc/prostopadloscian.hh inc/wirnik.hh inc/graniastoslup6.hh inc/macierz_obrotu.hh\
			inc/inter_drona.hh inc/przeszkoda.hh
	g++ ${CPPFLAGS} -o obj/dron.o src/dron.cpp

obj/main.o: src/main.cpp inc/dron.hh inc/dno.hh inc/tafla.hh inc/dron.hh inc/przeszkoda_prostopadloscian.hh inc/przeszkoda.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/bryla.o: src/bryla.cpp inc/bryla.hh inc/macierz_obrotu.hh inc/inter_rysowania.hh 
	g++ ${CPPFLAGS} -o obj/bryla.o src/bryla.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

inc/dno: inc/inter_rysowania.hh	
	touch inc/powierzchnia.hh inc/przeszkoda.hh inc/dno.hh 

inc/tafla: inc/inter_rysowania.hh	
	touch inc/powierzchnia.hh inc/przeszkoda.hh inc/tafla.hh 
clear:
	rm dron.out obj/*.o

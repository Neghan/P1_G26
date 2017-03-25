#include "Map.hh"
#include <iostream>
#include <ctime>

Map::Map(const int& dificultad) {
	
	srand(time(nullptr));
	filas = (rand() % dificultad * 5 + 1) + dificultad * 5;
	columnas = (rand() % dificultad * 5 + 1) + dificultad * 5;
	
	mapa = new char*[filas];

	for (int i = 0; i < filas; i++) {
		mapa[i] = new char[columnas];
	}

	
	resetMapa();
}

void Map::setCelda(const int & x, const int& y, const char& caracter) {
	mapa[x][y] = caracter;
}

void Map::resetMapa() {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			mapa[i][j] = '.';
		}
	}
}

int Map::getFilas() const {
	return filas;
}

int Map::getColumnas() const {
	return columnas;
}

char Map::getCelda(const int &x, const int & y)  {
	return mapa[x][y];
}

void Map::printMapa() {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			std::cout << mapa[i][j] << std::endl;
		}
		std::cout << "\n";
	}
}

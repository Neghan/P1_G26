#include "CoinManager.hh"
#include <string>
#include <ctime>

CoinManager::CoinManager(const int& filas, const int& columnas) {
	filasMapa = filas;
	columnasMapa = columnas;

	inicializadorMoneda(filasMapa, columnasMapa);
}

void CoinManager::eliminarMoneda(const int &x, const int &y) {
	int posicion;
	for (int i = 0; i < numero_monedas; i++) {
		if (moneda_data[i].x == x && moneda_data[i].y == y) {
			posicion = i;
		}
	}

	if (posicion >= 0 && posicion < numero_monedas) {
		for (int i = posicion; i < numero_monedas - 1; i++) {
			moneda_data[i] = moneda_data[i + 1];
		}
		numero_monedas--;
		if (numero_monedas < 0) {
			inicializadorMoneda(filasMapa, columnasMapa);
		}
	}
};

int CoinManager::getMonedas(const moneda** a) const{
	*a = moneda_data;
	return numero_monedas;
};

void CoinManager::inicializadorMoneda(const int & filas, const int & columnas) {

	srand(time(nullptr));
	numero_monedas = (rand() % (filas*columnas / 10)) + filas*columnas*0.03;
	
	int randomX, randomY;
	bool repetido;
	
	for (int i = 0; i < numero_monedas; i++) {
		
		do {
			repetido = false;
			randomX = rand() % filas;
			randomY = rand() % columnas;
			
			for (int j = 0; j < i; j++) {
				if (moneda_data[j].x == randomX && moneda_data[j].y == randomY) {
					repetido = true;
				}
			}
		} while (repetido);
		moneda_data[i].x = randomX;
		moneda_data[i].y = randomY;
	}
};
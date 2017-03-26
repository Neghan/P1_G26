#include "CoinManager.hh"
#include <string>
#include <ctime>

CoinManager::CoinManager(const int &filas, const int &columnas) {
	filasMapa = filas;
	columnasMapa = columnas;

	inicializadorMonedas(filasMapa, columnasMapa);
}

void CoinManager::eliminarMoneda(const int &x, const int &y) {
	int pos = 0;
	for (int i = 0; i < numero_monedas; i++) {
		if (moneda_data[i].x == x && moneda_data[i].y == y) {
			pos = i;
		}
	}
	if (pos >= 0 && pos < numero_monedas) {
		for (int i = pos; i < numero_monedas - 1; i++) {
			moneda_data[i] = moneda_data[i + 1];
		}
		numero_monedas--;
		if (numero_monedas <= 0) {
			delete[] moneda_data;
			inicializadorMonedas(filasMapa, columnasMapa);
		}
	}
	
};

int CoinManager::getMonedas(const moneda **ptr)const{
	*ptr = moneda_data;
	return numero_monedas;
};

void CoinManager::inicializadorMonedas(const int & filas, const int & columnas) {

	srand(time(nullptr));
	numero_monedas = (rand() % (filas*columnas / 10)) + filas*columnas*0.03;
	moneda_data = new moneda[numero_monedas];

	int randomX, randomY;
	bool repetido;
	
	for (int i = 0; i < numero_monedas; i++) {
		
		do {
			repetido = false;
			randomX = rand() % filas;
			randomY = rand() % columnas;
			
			for (int j = 0; j < i && !repetido; j++) {
				if (moneda_data[j].x == randomX && moneda_data[j].y == randomY) {
					repetido = true;
				}
			}
		} while (repetido);
		moneda_data[i].x = randomX;
		moneda_data[i].y = randomY;
	}
};
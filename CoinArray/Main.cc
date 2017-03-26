#include <iostream>
#include <ctime>
#include "Map.hh"
#include "Player.hh"
#include "CoinManager.hh"
#include "Main.hh"

void actualizarMapa(Map mapa, const Player &player, const CoinManager & coin_manager, int monedas_objetivo) {
	system("cls");
	const moneda *moneda_data;
	int numero_monedas;
	
	numero_monedas = coin_manager.getMonedas(&moneda_data);

	for (int i = 0; i < numero_monedas; ++i) {
		mapa.setCelda(moneda_data[i].x, moneda_data[i].y, '$');
	}

	
	mapa.setCelda(player.getX(), player.getY(), '@');
	mapa.printMapa();
	std::cout << std::endl;
	std::cout << "Score: ";
	std::cout << player.getPuntuacion() << " / " << monedas_objetivo << std::endl;
}

bool verSiguientePosicion( const Map& mapa,const Player &player, const Key& tecla) {
	switch (tecla) {
	case Key::A:
		return player.getY() > 0;
	case Key::W:
		return player.getX() > 0;
	case Key::S:
		return player.getX() < mapa.getFilas() - 1;
	case Key::D:
		return player.getY() < mapa.getColumnas() - 1;
	}
}

int printPresentacion() {
	int dificultad;
	
	std::cout << "////////////////////////////////////////////////" << std::endl;
	std::cout << "COIN RACE" << std::endl;
	std::cout << "////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	std::cout << "Controls: Use WASD to move the player" << std::endl << std::endl;
	std::cout << "Choose a difficulty:" << std::endl;
	std::cout << "1 - EASY" << std::endl;
	std::cout << "2 - MEDIUM" << std::endl;
	std::cout << "3 - HARD" << std::endl;
	std::cin >> dificultad;
	return dificultad;
}

int main() {
	int dificultad, monedas_objetivo;

	dificultad = printPresentacion();

	Map mapa(dificultad);
	CoinManager coin_manager(mapa.getFilas(), mapa.getColumnas());
	Player player(mapa.getFilas() / 2, mapa.getColumnas() / 2);

	srand(time(nullptr));
	monedas_objetivo = (rand() % dificultad * 30 + 1) + dificultad * 30;

	std::cout << "Objective: You have to pick up ";
	std::cout << monedas_objetivo;
	std::cout << " coins" << std::endl;
	

	const moneda  *moneda_data;
	int numero_monedas;

	actualizarMapa(mapa, player, coin_manager, monedas_objetivo);

	clock_t start_time = clock();

	while (player.getPuntuacion() < monedas_objetivo) {
		Key tecla = getKey();
		if (tecla == Key::ESC) {
			return 0;
		}
		else if (tecla == Key::NONE) {
			continue;
		}
		else {
			mapa.setCelda(player.getX(), player.getY(), '.');

			if (verSiguientePosicion(mapa, player, tecla)) {

				player.actualizarPosicion(tecla);
				numero_monedas = coin_manager.getMonedas(&moneda_data);

				for (int i = 0; i < numero_monedas; ++i) {
					if (moneda_data[i].x == player.getX() && moneda_data[i].y == player.getY()) {
						player.setPuntuacion(player.getPuntuacion() + 1);
						coin_manager.eliminarMoneda(player.getX(), player.getY());
						break;
					}
				}
				actualizarMapa(mapa, player, coin_manager, monedas_objetivo);
			}
		}
	}
	clock_t end_time = clock();
	std::cout << std::endl << "You've picked up ";
	std::cout << monedas_objetivo;
	std::cout << " coins in ";
	std::cout << (end_time - start_time) / 1000;
	std::cout << " seconds" << std::endl;
}
#include "Player.hh"

Player::Player(const int & fila, const int & columna) {
	x = fila;
	y = columna;
	puntuacion = 0;
}

int Player::getX()const{
	return x;
}

int Player::getY()const {
	return y;
}

void Player::setPuntuacion(const int &s) {
	puntuacion = s;
}

int Player::getPuntuacion() const{
	return puntuacion;
}

void Player::actualizarPosicion(Key tecla) {
	switch (tecla) {
	case Key::W:
		x--;
		break;
	case Key::A:
		y--;
		break;
	case Key::S:
		x++;
		break;
	case Key::D:
		y++;
		break;
	}
}
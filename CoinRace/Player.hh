#include "Input.hh"

using namespace Input;

class Player {
private:
	int x;
	int y;
	int puntuacion;

public:
	Player::Player(const int & fila, const int & columna);
	int getX() const;
	int getY() const;
	void setPuntuacion(const int &score);
	int getPuntuacion()const;
	void actualizarPosicion(Key tecla);


};

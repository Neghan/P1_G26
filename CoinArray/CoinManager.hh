struct moneda {
	int x;
	int y;
};

class CoinManager {
private:
	void inicializadorMonedas(const int &filas, const int &columnas);

	moneda *moneda_data;
	int numero_monedas;
	int filasMapa, columnasMapa;

public:
	CoinManager::CoinManager(const int& rows, const int& cols);
	void CoinManager::eliminarMoneda(const int &x, const int &y);
	int CoinManager::getMonedas(const moneda **ptr)const;
};
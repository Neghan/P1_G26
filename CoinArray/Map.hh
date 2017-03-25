class Map {
private:
	int filas, columnas;
	char **mapa;

public:
	Map(const int& difficulty);											
	void setCelda(const int & x, const int& y, const char& content);		
	void resetMapa();													
	int getFilas() const;												
	int getColumnas() const;												
	char getCelda(const int &x, const int & y) ;					
	void Map::printMapa();
												
};

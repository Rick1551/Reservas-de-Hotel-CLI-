#include <string>
#include <iostream>

class Habitacion {
	int numero;
	double precio_por_noche;
	std::string tipo, disponible;

public:
	// Constructor por defecto
	Habitacion(int num, double precio, const std::string& tipo_habitacion, const std::string& estado_disponible)
		: numero(num), precio_por_noche(precio), tipo(tipo_habitacion), disponible(estado_disponible) {}
	
	//Getters
	int getNumero() const { return numero; }
	double getPrecioPorNoche() const { return precio_por_noche; }
	std::string getTipo() const { return tipo; }
	std::string getDisponible() const { return disponible; }
	
	//Setters
	void setNumero(int num) { numero = num; }
	void setPrecioPorNoche(double precio) { precio_por_noche = precio; }
	void setTipo(const std::string& tipo_habitacion) { tipo = tipo_habitacion; }
	void setDisponible(const std::string& estado_disponible) { disponible = estado_disponible; }

	void serializarJSON(std::ostream& os) const;

	void cargarDesdeJSON(const std::string& json);
};
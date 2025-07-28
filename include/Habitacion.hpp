#pragma once
#include <string>
#include <ostream>
#include "../include/json.hpp"
using json = nlohmann::json;

class Habitacion {
	int numero_;
	double precio_por_noche_;
	std::string tipo_;
	std::string disponible_;

public:
	// Constructor por defecto
	Habitacion(int numero, double precio, const std::string& tipo_habitacion, const std::string& estado_disponible)
		: numero_(numero), precio_por_noche_(precio), tipo_(tipo_habitacion), disponible_(estado_disponible) {}
	
	//Getters
	int getNumero() const { return numero_; }
	double getPrecioPorNoche() const { return precio_por_noche_; }
	std::string getTipo() const { return tipo_; }
	std::string getDisponible() const { return disponible_; }
	
	//Setters
	void setNumero(int numero) { numero_ = numero; }
	void setPrecioPorNoche(double precio) { precio_por_noche_ = precio; }
	void setTipo(const std::string& tipo_habitacion) { tipo_ = tipo_habitacion; }
	void setDisponible(const std::string& estado_disponible) { disponible_ = estado_disponible; }

	void serializarJSON(std::ostream& os) const;
	void cargarDesdeJSON(const std::string& json);
};
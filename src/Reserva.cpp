#include <stdexcept>
#include <format>
#include "../include/Reserva.hpp"
#include "../include/json.hpp"

void Reserva::validarFechas() const {
	if (fecha_salida_ <= fecha_entrada_) {
		throw std::invalid_argument("Error: La fecha de salida debe ser posterior a la de entrada");
	}
}
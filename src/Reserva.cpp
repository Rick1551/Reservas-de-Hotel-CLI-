#include <stdexcept>
#include <format>
#include "../include/Reserva.hpp"
#include "../include/json.hpp"

void Reserva::validarFechas() const {
	if (fecha_salida_ <= fecha_entrada_) {
		throw std::invalid_argument("Error: La fecha de salida debe ser posterior a la de entrada");
	}
}

//Constructor
Reserva::Reserva(int id, int id_habitacion, const std::string cliente,
	const std::chrono::year_month_day& fecha_entrada,
	const std::chrono::year_month_day& fecha_salida,
	const std::string& estado)
	: id_(id), id_habitacion_(id_habitacion), cliente_(cliente),
	  fecha_entrada_(fecha_entrada), fecha_salida_(fecha_salida), estado_(estado) {
	validarFechas();
}

//Getters
int Reserva::getId() const noexcept { return id_; }
int Reserva::getHabitacionId() const noexcept { return id_habitacion_; }
const std::string& Reserva::getCliente() const noexcept { return cliente_; }
const std::string& Reserva::getEstado() const noexcept { return estado_; }
const std::chrono::year_month_day& Reserva::getFechaEntrada() const noexcept { return fecha_entrada_; }
const std::chrono::year_month_day& Reserva::getFechaSalida() const noexcept { return fecha_salida_; }

//Setters
void Reserva::setEstado(std::string estado) {
	estado_ = std::move(estado);
}
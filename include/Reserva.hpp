#include <iostream>
#include <string>
#include <vector>
#include <chrono>

class Reserva {
	int id, id_habitacion;
	std::string cliente, estado;
	std::chrono::year_month_day fecha_entrada, fecha_salida;
};
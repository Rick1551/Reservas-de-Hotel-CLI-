#include <vector>
#include "../include/Hotel.hpp"

void Hotel::buscarHabitacionesDisponibles(const std::string& tipo, const std::string& fecha_entrada, const std::string& fecha_salida) const {
	std::ranges::for_each(habitaciones, [&](const Habitacion& habitacion) {
		if (habitacion.getTipo() == tipo && habitacion.getDisponible() == "Disponible") {
			std::cout << "Habitación disponible: " << habitacion.getNumero() 
					  << ", Precio por noche: " << habitacion.getPrecioPorNoche() 
					  << ", Tipo: " << habitacion.getTipo() << std::endl;
		}
		});
}

void Hotel::guardarEstadoEnJSON(const std::string& archivo) const {

}

void Hotel::cargarEstadoDesdeJSON(const std::string& archivo) {

}

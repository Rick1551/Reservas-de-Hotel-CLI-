#include <vector>
#include <string>
#include <map>
#include "../include/Habitacion.hpp"
#include "../include/json.hpp"
#include "../include/Reserva.hpp"

class Hotel {
	private:
		std::string nombre;
		std::string direccion;
		std::vector<Habitacion> habitaciones;
		std::map<std::string, Reserva> reservas; // Mapa de reservas por ID

	public:
		void buscarHabitacionesDisponibles(const std::string& tipo, const std::string& fecha_entrada, const std::string& fecha_salida) const;
		void guardarEstadoEnJSON(const std::string& archivo) const;
		void cargarEstadoDesdeJSON(const std::string& archivo);
};
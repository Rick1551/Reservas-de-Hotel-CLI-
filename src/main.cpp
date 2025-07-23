#include <iostream>
#include <string>
#include <vector>
#include "..\include\Habitacion.hpp"
#include "..\include\Hotel.hpp"
#include "..\include\Reserva.hpp"

int main() {
	// Crear una habitación
	Habitacion habitacion(101, 75.0, "Doble", "Disponible");
	
	// Serializar la habitación a JSON
	std::cout << "Habitación en formato JSON:" << std::endl;
	habitacion.serializarJSON(std::cout);
	std::cout << std::endl;
	// Cargar desde un JSON (simulado)
	std::string json = "{\"numero\": 102, \"precio_por_noche\": 85.0, \"tipo\": \"Suite\", \"disponible\": \"No disponible\"}";
	habitacion.cargarDesdeJSON(json);
	// Crear un hotel y agregar la habitación
	Hotel hotel("Hotel Ejemplo", "123 Calle Ficticia");
	hotel.agregarHabitacion(habitacion);
	// Mostrar las habitaciones del hotel
	hotel.mostrarHabitaciones();
	return 0;
}

#include "..\include\Habitacion.hpp"


void Habitacion::serializarJSON(std::ostream& os) const {
	os << "{\n"
		<< "  \"numero\": " << numero << ",\n"
		<< "  \"precio_por_noche\": " << precio_por_noche << ",\n"
		<< "  \"tipo\": \"" << tipo << "\",\n"
		<< "  \"disponible\": \"" << disponible << "\"\n"
		<< "}";
}

void Habitacion::cargarDesdeJSON(const std::string& json) {
	// Implementaci�n de carga desde JSON (no detallada aqu�)
	// Podr�a usar una librer�a como nlohmann/json para parsear el JSON
	std::cout << "Cargando desde JSON: " << json << std::endl;
}
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
	// Implementación de carga desde JSON (no detallada aquí)
	// Podría usar una librería como nlohmann/json para parsear el JSON
	std::cout << "Cargando desde JSON: " << json << std::endl;
}
#include "..\include\json.hpp"
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
	
	// Aquí podrías usar una librería JSON para parsear el string
	// Por simplicidad, solo imprimimos el JSON recibido
	// En un caso real, deberías parsear el JSON y asignar los valores a los atributos de la clase
	// Por ejemplo, usando nlohmann::json:
	//nlohmann::json j = nlohmann::json::parse(json);
	//numero = j["numero"];
	//precio_por_noche = j["precio_por_noche"];
	//tipo = j["tipo"];
	//disponible = j["disponible"];

	std::cout << "Cargando desde JSON: " << json << std::endl;
}
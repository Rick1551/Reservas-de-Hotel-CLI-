#include "..\include\json.hpp"
#include "..\include\Habitacion.hpp"

void Habitacion::serializarJSON(std::ostream& os) const {
	json j;
	j["numero"] = numero_;
	j["precio"] = precio_por_noche;
}

void Habitacion::cargarDesdeJSON(const std::string& json) {
	
	// Aqu� podr�as usar una librer�a JSON para parsear el string
	// Por simplicidad, solo imprimimos el JSON recibido
	// En un caso real, deber�as parsear el JSON y asignar los valores a los atributos de la clase
	// Por ejemplo, usando nlohmann::json:
	//nlohmann::json j = nlohmann::json::parse(json);
	//numero = j["numero"];
	//precio_por_noche = j["precio_por_noche"];
	//tipo = j["tipo"];
	//disponible = j["disponible"];

	std::cout << "Cargando desde JSON: " << json << std::endl;
}
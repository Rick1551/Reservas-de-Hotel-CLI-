#include "..\include\json.hpp"
#include "..\include\Habitacion.hpp"

void Habitacion::serializarJSON(std::ostream& os) const {
	json j;
	j["numero"] = numero_;
	j["precio"] = precio_por_noche_;
	j["tipo"] = tipo_;
	j["disponible"] = disponible_;
	os << j.dump(2);
}

void Habitacion::cargarDesdeJSON(const std::string& json) {
	
	nlohmann::json j = nlohmann::json::parse(json);
	numero_ = j["numero"];
	precio_por_noche_ = j["precio_por_noche"];
	tipo_ = j["tipo"];
	disponible_ = j["disponible"];

	//std::cout << "Cargando desde JSON: " << json << std::endl;
}
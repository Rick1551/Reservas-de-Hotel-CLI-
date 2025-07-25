#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <format>
#include <chrono>
#include "../include/Hotel.hpp"
#include "../include/json.hpp"

using json = nlohmann::json;
namespace fs = std::filesystem;

void Hotel::buscarHabitacionesDisponibles(const std::string& tipo,
										const std::string& fecha_entrada, 
										const std::string& fecha_salida) const {
	//COnvertir strings a fechas (C++20 chrono)
	auto parse_date = [](const std::string& date_str) {
		std::istringstream iss(date_str);
		std::chrono::year_month_day date;
		iss >> std::chrono::parse("%Y-%m-%d", date);
		return date;
	};

	const auto inicio = parse_date(fecha_entrada);
	const auto fin = parse_date(fecha_salida);

	//Filtrar con ranges (C++20)
	auto disponibles = habitaciones_ | std::views::filter([&](const Habitacion& hab) {
		return hab.getTipo() == tipo && hab.getDisponible() == "Disponible";
		});

	//Mostrar resultados con formato(C++20)
	std::ranges::for_each(disponibles, [&](const Habitacion& hab) {
		std::cout << std::format(
			"Habitación {} | Tipo: {} | Precio: ${} | Estado: {}\n",
			hab.getNumero(), hab.getTipo(), hab.getPrecioPorNoche(), hab.getDisponible()
		);
	});
}

// Guardar el estado del hotel en un archivo JSON
void Hotel::guardarEstadoEnJSON(const std::string& archivo) const {
	json j;
	j["metadata"] = {
		{"nombre", nombre_},
		{"direccion", direccion_},
		{"ultima_actualizacion",
			std::format("{:%F %T}", std::chrono::system_clock::now())}
	};

	j["habitaciones"] = json::array();
	for (const auto& hab : habitaciones_) {
		j["habitaciones"].push_back({
			{"numero", hab.getNumero()},
			{"precio_por_noche", hab.getPrecioPorNoche()},
			{"tipo", hab.getTipo()},
			{"disponible", hab.getDisponible()}
			});
	}

	std::ofstream(archivo) << j.dump(4);
}

void Hotel::cargarEstadoDesdeJSON(const std::string& archivo) {
	//Verificar existencia del archivo
	if (!std::filesystem::exists(archivo)) {
		throw std::runtime_error("El archivo JSON no existe: " + archivo);
	}

	try {
		//Leer archivo JSON
		std::ifstream file(archivo);
		json j;
		file >> j;

		//Cargar metadatos con verificación
		if(j.contains("metadata")) {
			nombre_ = j["metadata"].value("nombre", "Desconocido");
			direccion_ = j["metadata"].value("direccion", "");
		} 

		// Cargar habitaciones
		if (j.contains("habitaciones")) {
			habitaciones_.clear();
			for (const auto& item : j["habitaciones"]) {
				try {
					habitaciones_.emplace_back(
						item.at("numero").get<int>(),
						item.at("precio_por_noche").get<double>(),
						item.at("tipo").get<std::string>(),
						item.at("disponible").get<std::string>()
					);
				}catch (const json::exception& e) {
					std::cerr << "Error al cargar habitación: " << e.what() << "\n";
					continue; // Saltar a la siguiente habitación si hay un error
				}
			}
		}

		//Cargar reservas
		if
	}
}

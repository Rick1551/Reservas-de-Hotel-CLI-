#include <iostream>
#include <string>
#include <vector>
#include <chrono>

class Reserva {
	int id_, id_habitacion_;
	std::string cliente_;
	std::string estado_;
	std::chrono::year_month_day fecha_entrada;
	std::chrono::year_month_day fecha_salida;

	void validarFechas() const;

public:
	//Constructor por defecto
	Reserva(int id, int id_habitacion, const std::string cliente,
		const std::chrono::year_month_day& fecha_entrada,
		const std::chrono::year_month_day& fecha_salida,
		const std::string& estado = "Pendiente");

	//Getters
	int getId() const noexcept;
	int getHabitacionId() const noexcept;
	const std::string& getCliente() const noexcept;
	const std::string& getEstado() const noexcept;
	const std::chrono::year_month_day& getFechaEntrada() const noexcept;
	const std::chrono::year_month_day& getFechaSalida() const noexcept;

	//Setters
	void setEstado(const std::string& estado);
	void cambiarFechas(const std::chrono::year_month_day& nueva_fecha_entrada,
		const std::chrono::year_month_day& nueva_fecha_salida);

	//Serializar a JSON
	json toJSON() const;
	static Reserva fromJSON(const json& j);


};
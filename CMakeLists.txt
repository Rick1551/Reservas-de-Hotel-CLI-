cmake_minimum_required(VERSION 3.20)
project(HotelReservas LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# Dependencias
find_package(nlohmann_json REQUIRED)

# Ejecutable principal
add_executable(hotel_reservas
    src/main.cpp
    src/Hotel.cpp
    src/Habitacion.cpp
    src/Reserva.cpp
    src/Utils.cpp
)

target_include_directories(hotel_reservas PRIVATE include)
target_link_libraries(hotel_reservas PRIVATE nlohmann_json::nlohmann_json)

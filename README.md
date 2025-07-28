# 🏨 Sistema de Reservas de Hotel (C++20)

Un sistema de gestión de reservas para hoteles con persistencia en JSON, desarrollado en C++20.

## 🚀 Características
- Gestión de habitaciones (Individual/Suite)
- Reservas con fechas (usando `<chrono>`)
- Persistencia en archivos JSON
- Interfaz CLI interactiva
- Búsquedas con `std::ranges`

### Requisitos
- Compilador con soporte C++20 (g++ 11+, clang 12+, MSVC 2022)
- CMake 3.20+
- Git (opcional)

# Configurar y compilar
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release

## 📂 Estructura del Proyecto
📦 hotel_reservas
├── 📂 include
│ ├── Habitacion.hpp
│ ├── Reserva.hpp
│ ├── Hotel.hpp
│ └── Utils.hpp
├── 📂 src
│ ├── main.cpp
│ ├── Habitacion.cpp
│ ├── Reserva.cpp
│ ├── Hotel.cpp
│ └── Utils.cpp
├── 📂 data # Datos guardados
│ └── reservas.json # Ejemplo
├── CMakeLists.txt
├── .gitignore
└── README.md
#pragma once
#include "Video.hpp"
#include <string>
#include <fstream>
#include <ostream>

class Pelicula : public Video {
    // protected:
    public:
    Pelicula();
    Pelicula(std::string ID, std::string nombre, std::string duracion, std::string genero, std::string  calificacion);
    std::string mostrar();
    //void calificar(std::string calificacion) override;
    std::string getCalificacion() override;
    int getTipo() override;
    std::string getGenero() override;
    ~Pelicula();
};
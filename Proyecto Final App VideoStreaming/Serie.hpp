#pragma once
#include "Video.hpp"
#include <string>
#include <vector>

// Declaración anticipada de la clase Episodio
class Episodio;

class Serie : public Video {
 protected:
    std::vector<Episodio> episodios;
    std::string temporada;

public:
    Serie();
    Serie(std::string ID, std::string nombre, std::string duracion, std::string genero, std::string calificacion, std::string temporada);
    std::string mostrar() override;
    std::string getCalificacion() override;
    int getTipo() override;
    std::string getGenero() override;
    std::string getTemporada();
    ~Serie();
};
#pragma once
#include <iostream>
#include <string>
#include "Video.hpp"
#include "Serie.hpp"

class Episodio: public Video{
   protected:
  //  std::string id;
  //  std::string nombre;
  //  std::string duracion;
  std::string serieID;
  //  std::string caliEp;

    public:
      Episodio();
      Episodio(std::string ID, std::string nombre, std::string duracion, std::string genero, std::string calificacion, std::string serieID);
      std::string getNombre();
      std::string getTemporada();
      std::string getCalificacion();
      std::string getID();
      std::string getSerieID();
      int getTipo() override;
      std::string mostrar() override;
      ~Episodio();

};

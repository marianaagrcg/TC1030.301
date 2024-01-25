#include <iostream>
#include <string>
#include "Episodio.hpp"
#include "Video.hpp"
#include "Serie.hpp"

Episodio::Episodio(){}

Episodio::Episodio(std::string ID, std::string nombre, std::string duracion, std::string genero, std::string calificacion, std::string serieID): Video(ID, nombre, duracion, genero, calificacion)
{
    this -> serieID = serieID;
}

std::string Episodio::getNombre() {
    return nombre;
}

std::string Episodio::getCalificacion(){
    return calificacion;
}

std::string Episodio::getID(){
    return ID;
}

int Episodio::getTipo(){
    return 3;
}

std::string Episodio::mostrar(){
    std::string datos_episodio = "ID: " + ID + " Nombre: " + nombre + " Duración: " + duracion + " Genero: "+ genero+" Calificación: " + calificacion+" Serie ID: " + serieID + "\n";
    return datos_episodio;
}

std::string Episodio::getSerieID(){
    return serieID;
}

Episodio::~Episodio(){}

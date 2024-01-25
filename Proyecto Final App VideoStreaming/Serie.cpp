#include <iostream>
#include "Serie.hpp"
#include "Video.hpp"
#include "Episodio.hpp"
#include <string>

Serie::Serie():Video()
{
}

Serie::Serie(std::string ID, std::string nombre, std::string duracion, std::string genero, std::string calificacion, std::string temporada):
Video(ID,nombre,duracion,genero,calificacion){   
    this-> temporada = temporada; 
}

//definir episodios

std::string Serie::mostrar() {
    std::string video = "ID: " + ID + " Nombre: " + nombre + " Duración: " + duracion + " Genero: "+ genero+" Calificación: " + calificacion+" Temporada: " + temporada + "\n";
    return video;
}

std::string Serie::getCalificacion(){
    return calificacion;
}

int Serie::getTipo(){
    return 2;
}

std::string Serie::getGenero()
{
    return genero;
}

std::string Serie::getTemporada(){
    return temporada;
}

Serie::~Serie(){}
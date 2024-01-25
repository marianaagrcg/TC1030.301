#include <iostream>
#include <string>
#include "Pelicula.hpp"
#include "Video.hpp"
#include <sstream>

Pelicula::Pelicula(){};

Pelicula::Pelicula(std::string ID, std::string nombre, std::string duracion, std::string genero, std::string califiacion) : Video(ID, nombre, duracion, genero, califiacion){
}

/*
void Pelicula::calificar(std::string calificacion){
    Video::calificar(calificacion);
}
*/


std::string Pelicula::mostrar(){
    std::string datos_video = "ID: " + ID + " Nombre: " + nombre + " Duración: " + duracion + " Genero: "+ genero+" Calificación: " + calificacion + "\n";
    return datos_video;
}

std::string Pelicula::getCalificacion(){
    return calificacion;
}

int Pelicula::getTipo(){
    return 1;
}

std::string Pelicula::getGenero()
{
    return genero;
}

Pelicula::~Pelicula(){}
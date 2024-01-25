#include <iostream>
#include "Video.hpp"
#include <ostream>

Video::Video(){}

Video::Video(std::string ID, std::string nombre, std::string duracion, std::string genero, std::string calificacion)
{
    this -> ID = ID;
    this -> nombre = nombre;
    this -> duracion = duracion;
    this -> genero = genero;
    this -> calificacion = calificacion;
}


void Video::calificarV(std::string califica_video){
    this -> calificacion = califica_video;
};

//Output sobrecargado
std::ostream& operator << (std::ostream &out, const Video &v) {
    out << " " << v.ID << " " << v.nombre << std::endl;
    return out;
}

std::string Video::getCalificacion(){
    return calificacion;
}

std::string Video::getGenero(){
    return genero;
};

std::string Video::getNombre(){
    return nombre;
};

std::string Video::mostrar(){
    std::string datos_video = "ID: " + ID + " Nombre: " + nombre + " Duración: " + duracion + " Genero: "+ genero+" Calificación: " + calificacion + "\n";
    return datos_video;
}

int Video::getTipo(){
    return 0;
}

std::string Video::getID(){
    return ID;
}

void Video::setCalificacion(std::string calificacion){
    this -> calificacion = calificacion;
}

Video::~Video(){}
#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <ostream>

class Video 
{
    protected:
    std::string ID; // ("5652252")
    std::string nombre; // ("La sirenita")
    std::string duracion; // ("01:30:05")
    std::string genero; // ("Drama")
    std::string calificacion; //(9.8)

    public:
    Video();
    Video(std::string ID, std::string nombre, std::string duracion, std::string genero, std::string calificacion);
    virtual std::string mostrar()=0;
    void calificarV(std::string);
    friend std::ostream & operator << (std::ostream &, const Video &v);
    virtual std::string getCalificacion()=0;
    virtual std::string getGenero();
    virtual std::string getNombre();
    virtual int getTipo();
    virtual void setCalificacion(std::string calificacion);
    virtual std::string getID();
    //virtual void calificar(std::string calificacion)=0;
    ~Video();

};
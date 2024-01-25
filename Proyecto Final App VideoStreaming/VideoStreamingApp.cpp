#include "VideoStreamingApp.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

 
VideoStreamingApp::VideoStreamingApp()
{
}

void VideoStreamingApp::displayAll()
{
    for (auto& video : dataBase) {
        std::cout << *video << std::endl;
    }
}

void VideoStreamingApp::importData(std::string fileName)
{
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cout << "Failed to open the input file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
//      std::istringstream iss(line);
        std::istringstream iss;
        std::string type, ID, nombre, duracion, genero, calificacion, temporada, serieID;

        iss.str (line);

        // if ((iss >> type >> id >> nombre >> duracion >> genero >> calificacionStr)) {
        //     //std::cout << "Failed to parse the line: " << line << std::endl;

        //     //std::cout << line << std::endl;
        // }

        iss >> type >> ID >> nombre >> duracion >> genero >> calificacion;


        if (type == "Serie") {
            if (iss >> temporada) {
                //std::cout << "Failed to parse the line: " << line << std::endl;

                std::cout << line << std::endl;
                this->dataBase.push_back(std::make_unique<Serie>(ID, nombre, duracion, genero, calificacion, temporada));
            }
        }

        if (type == "Episodio") {
            if (iss >> serieID) {
                //std::cout << "Failed to parse the line: " << line << std::endl;

                std::cout << line << std::endl;
                this->dataBase.push_back(std::make_unique<Episodio>(ID, nombre, duracion, genero, calificacion, serieID));
            }
        }

        if (type == "Pelicula") {
            // if (iss) {
                //std::cout << "Failed to parse the line: " << line << std::endl;

                std::cout << line << std::endl;
                this->dataBase.push_back(std::make_unique<Pelicula>(ID, nombre, duracion, genero, calificacion));
            // }
        }

        if (type == "Episodio") {
            if (iss >> serieID ) {
                //std::cout << "Failed to parse the line: " << line << std::endl;

                std::cout << line << std::endl;
                this->dataBase.push_back(std::make_unique<Episodio>(ID, nombre, duracion, genero, calificacion, serieID));
            }
        }
    }
}

void VideoStreamingApp::run()
{

    int opcion = -1;
    while (opcion != 0) {
        std::cout <<std::endl << "Menú" << std::endl;
        std::cout << "1. Cargar archivo de datos" << std::endl;
        std::cout << "2. Mostrar los videos en general con una cierta calificación o de un cierto género" << std::endl;
        std::cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada" << std::endl;
        std::cout << "4. Mostrar las películas con cierta calificacion" << std::endl;
        std::cout << "5. Calificar un video\n-pedir titulo a calificar\n-pedir valor otorgado" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Ingresa tu opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                {
                    std::cout << std::endl << "Archivo de datos cargados" << std::endl;
                    importData("input");
                    std::cout << std::endl;
                    break;
                }
            case 2:
                {
                std::cout << "¿Quiere que le muestre video en base al genero o en base a la calificación?" << std::endl << "a) genero" << std::endl << "b) calificación" << std::endl;
                char seleccion;
                std::cout<<"Ingresa tu selección: ";
                std::cin >> seleccion;
                if (seleccion == 'a') {
                    std::cout << "Opciones de genero:" << std::endl << "1. Misterio\n2. Drama\n3. Acción" << std::endl;
                    int seleccion_genero;
                    std::cout << "Ingresa el genero: ";
                    std::cin >> seleccion_genero;
                    if (seleccion_genero == 1) {
                        for (size_t i = 0; i < this->dataBase.size(); ++i) {
                            if (this->dataBase[i].get()->getGenero()=="Misterio") {
                                std::cout<<std::endl << this->dataBase[i].get()->mostrar();
                            }
                        }
                    }
                    else if(seleccion_genero == 2){
                        for (size_t i = 0; i < this->dataBase.size(); ++i) {
                            if (this->dataBase[i].get()->getGenero()=="Drama") {
                                std::cout<<std::endl << this->dataBase[i].get()->mostrar();
                            }
                        }
                    }
                    else if(seleccion_genero == 3){
                        for (size_t i = 0; i < this->dataBase.size(); ++i) {
                            if (this->dataBase[i].get()->getGenero()=="Accion") {
                                std::cout<<std::endl << this->dataBase[i].get()->mostrar();
                            }
                        }
                    }
                    break;
                }
                else if (seleccion == 'b') {
                    std::cout << "¿Qué calificación deseas encontrar?: " << std::endl;
                    std::string seleccion_calif;
                    std::cout << "Ingresa la calificación: ";
                    std::cin >> seleccion_calif;
                    for (size_t i = 0; i < this->dataBase.size(); ++i) {
                        if (this->dataBase[i].get()->getCalificacion()==seleccion_calif) {
                            std::cout<<std::endl << this->dataBase[i].get()->mostrar();
                        }
                    }
                }                
                break;
            }
            case 3:
                {   
                    std::cout << "Ingresa el Id de la serie y la calificación del episodio que deseas visualizar: " << std::endl;
                    std::cout<<"ID serie\tNombre"<<std::endl;
                    for (size_t i = 0; i < this->dataBase.size(); ++i) {
                        if (this->dataBase[i].get()->getTipo()== 2) {
                            std::cout<<std::endl << this->dataBase[i].get()->getID() + "\t\t" + this->dataBase[i].get()->getNombre() << std::endl;
                        }
                    }
                    std::string serieID;
                    std::string calificacion_episodio;
                    std::cout << std::endl << "Id serie: " << std::endl;
                    std::cin >> serieID;
                    std::cout << std::endl<< "Calificación: " << std::endl;
                    std::cin >> calificacion_episodio;
                    for (size_t i = 0; i < this->dataBase.size(); ++i) {
                        if(this->dataBase[i].get()->getTipo() == 3){
                            if (this->dataBase[i].get()->getCalificacion()==calificacion_episodio) {
                                std::cout<<std::endl << this->dataBase[i].get()->mostrar();
                             }
                        }
                    }

                    break;
                }
            case 4:
                {   
                    std::cout<<"Peliculas" <<std::endl;
                    std::cout<<"ID serie\tNombre"<<std::endl;
                    for (size_t i = 0; i < this->dataBase.size(); ++i) {
                        if (this->dataBase[i].get()->getTipo()== 1) {
                            std::cout<<std::endl << this->dataBase[i].get()->getNombre() + "\t\t\t" + this->dataBase[i].get()->getCalificacion() << std::endl;
                        }
                    }
                    break;
                }
            case 5:
                {
                int opcion; 
                std::cout<<"¿Qué deseas calificar \n1. Pelicula\n2. Serie \n3. Episodio\nIngresa tu respuesta: ";
                std::cin>>opcion;
                for (size_t i = 0; i < this->dataBase.size(); ++i) {
                    if (this->dataBase[i].get()->getTipo()== opcion) {
                        std::cout<<std::endl << this->dataBase[i].get()->getID() + "\t\t\t" + this->dataBase[i].get()->getNombre() << std::endl;
                    }
                }
                std::cout<<"Ingresa el ID del video: ";
                std::string video_id;
                std::cin>>video_id;
                std::cout<<"Ingresa la calificación del video: ";
                std::string calificacion_v;
                std::cin>>calificacion_v;
                for (size_t i = 0; i < this->dataBase.size(); ++i) {
                    if (this->dataBase[i].get()->getTipo()== opcion && this->dataBase[i].get()->getID()== video_id) {
                        this->dataBase[i].get()->setCalificacion(calificacion_v);
                        std::cout<<"La calificación final del video seleccionado es: " << dataBase[i].get()->getCalificacion();
                        std::cout<<this->dataBase[i].get()->mostrar();
                        break;
                    }
                }
                break;
            }
            case 0:{
                std::cout << "Saliendo..." << std::endl;
                break;}
            default:{
                std::cout << "Opción inválida. Por favor, ingresa una opción válida." << std::endl;
                break;}
        }
    }
}
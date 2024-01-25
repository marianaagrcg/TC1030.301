#pragma once

#include "Video.hpp"
#include "Serie.hpp"
#include "Pelicula.hpp"
#include "Episodio.hpp"
#include <vector>
#include <iostream>
#include <memory>

class VideoStreamingApp{
    private:
    std::vector<std::unique_ptr<Video>> dataBase;

    public:
    VideoStreamingApp();
    void importData(std::string);
    void displayAll();

    void run();
};
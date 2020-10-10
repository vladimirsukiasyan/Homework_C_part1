//
// Created by Vladimir Sukiasyan on 06.10.2020.
//

#include "FileCommander.h"

FileCommander::FileCommander(const std::string &filepath) {
    this->filepath = filepath;

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    gen = std::mt19937(rd());
    distrib = std::uniform_int_distribution<>(-50, 50);
}

void FileCommander::openFile() {
    file.open(filepath, std::fstream::in | std::fstream::out | std::fstream::app);
    if (!file) {
        throw std::exception();
    } else std::cout << "File \"" << filepath << "\" was opened successfully." << std::endl;
}

FileCommander::~FileCommander() {
    file.open(filepath, std::fstream::out | std::fstream::trunc);
    file.close();
}

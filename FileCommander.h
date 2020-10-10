//
// Created by Vladimir Sukiasyan on 06.10.2020.
//

#ifndef TIMURDZ_FILECOMMANDER_H
#define TIMURDZ_FILECOMMANDER_H

#include <vector>
#include <fstream>
#include <random>
#include <iostream>

class FileCommander {
protected:
    const char *delimiter = "\n";

    std::fstream file;
    std::string filepath;
    std::mt19937 gen; //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib;

    explicit FileCommander(const std::string &filepath);

    virtual void outputResult() = 0;

    ~FileCommander();

public:
    void openFile();
};


#endif //TIMURDZ_FILECOMMANDER_H

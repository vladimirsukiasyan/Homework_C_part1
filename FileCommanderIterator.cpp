//
// Created by Vladimir Sukiasyan on 06.10.2020.
//

#include "FileCommanderIterator.h"

void FileCommanderIterator::createData() {
    openFile();

    std::mt19937 gen = this->gen;
    std::uniform_int_distribution<> distrib = this->distrib;

    std::vector<int> data(100);
    std::generate(data.begin(), data.end(), [distrib, gen]() mutable {
        return distrib(gen);
    });

    std::copy(data.begin(), data.end(), std::ostream_iterator<int>(file, delimiter));

    file.close();
}

void FileCommanderIterator::outputResult() {

}

FileCommanderIterator::FileCommanderIterator(const std::string &filepath) : FileCommander(filepath) {}
//
// Created by Vladimir Sukiasyan on 06.10.2020.
//

#include "FileCommanderStream.h"

void FileCommanderStream::createData() {
    openFile();
    for (int i = 0; i < 100; ++i) {
        file << distrib(gen) << delimiter;
    }
    file.close();
}

void FileCommanderStream::outputResult() {
    
}

FileCommanderStream::FileCommanderStream(const std::string &filepath) : FileCommander(filepath) {}

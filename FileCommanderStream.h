//
// Created by Vladimir Sukiasyan on 06.10.2020.
//

#ifndef TIMURDZ_FILECOMMANDERSTREAM_H
#define TIMURDZ_FILECOMMANDERSTREAM_H


#include "FileCommander.h"

class FileCommanderStream : public FileCommander {
public:
    explicit FileCommanderStream(const std::string &filepath);

    void createData();

    template<typename T>
    T loadData() {
        T data;
        openFile();
        file.seekg(0, std::fstream::beg);

        typename T::value_type buffer;
        while (file >> buffer) {
            data.push_back(buffer);
        }
        file.close();

        std::cout << "Data vector for i/o file streams AFTER loading from file to vector" << std::endl;
        std::copy(data.begin(), data.end(), std::ostream_iterator<typename T::value_type>(std::cout, "\n"));

        return data;
    }

    void outputResult() override;
};


#endif //TIMURDZ_FILECOMMANDERSTREAM_H

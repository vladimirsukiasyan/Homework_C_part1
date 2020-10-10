//
// Created by Vladimir Sukiasyan on 06.10.2020.
//

#ifndef TIMURDZ_FILECOMMANDERITERATOR_H
#define TIMURDZ_FILECOMMANDERITERATOR_H


#include "FileCommander.h"

class FileCommanderIterator: public FileCommander{
public:
    explicit FileCommanderIterator(const std::string &filepath);

    void createData();

    template <typename T>
    T loadData() {
        T data;
        openFile();
        file.seekg(0,std::fstream::beg);

        std::copy(std::istream_iterator<typename T::value_type>(file),std::istream_iterator<typename T::value_type>(),std::back_inserter(data));
        file.close();

        std::cout << "Data vector for stream iterators AFTER loading from file to vector" << std::endl;
        std::copy(data.begin(), data.end(), std::ostream_iterator<typename T::value_type>(std::cout, "\n"));

        return data;
    }

    void outputResult() override;
};


#endif //TIMURDZ_FILECOMMANDERITERATOR_H

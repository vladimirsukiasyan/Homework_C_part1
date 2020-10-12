//
// Created by Vladimir Sukiasyan on 10.10.2020.
//

#ifndef TIMURDZ_MODIFY_H
#define TIMURDZ_MODIFY_H

#include <vector>
#include <fstream>

//засовывать только int,float,double!!!
template<typename T>
void modify1(std::vector<T> &vector) {
    int sum = 0;
    int sum_abs = 0;
    for (int elem : vector) {
        sum += elem;
        sum_abs += std::abs(elem);
    }
    vector.push_back(sum);
    vector.push_back(sum_abs / (vector.size() - 1));
}

void modify2(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    int sum = 0;
    for (auto it = begin; it != end; ++it) {
        sum += *it;
    }
    for (auto it = begin; it != end; ++it) {
        (*it) -= sum;
    }
}

void modify3(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    int sum = 0;
    for (auto it = begin; it != end; ++it) {
        sum += *it;
    }
    std::for_each(begin, end, [sum](int &elem) { elem -= sum; });
}

void modify4(const std::string &sourceFileName, const std::string &fileResultName) {
    std::vector<int> data;
    std::fstream resultFile(fileResultName, std::fstream::out|std::fstream::trunc);

    std::fstream sourceFile(sourceFileName, std::fstream::in);
    std::copy(std::istream_iterator<int>(sourceFile), std::istream_iterator<int>(), std::back_inserter(data));

    int sum = 0;
    for (int & elem : data) {
        sum += elem;
    }
    sourceFile.close();
    sourceFile.open(sourceFileName, std::fstream::in);

    std::transform(
            std::istream_iterator<int>(sourceFile),
        std::istream_iterator<int>(),
        std::ostream_iterator<int>(resultFile, "\n"),
                [sum](int elem) { return elem - sum; }
    );
}


#endif //TIMURDZ_MODIFY_H

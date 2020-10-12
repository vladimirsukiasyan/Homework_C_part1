#include "FileCommanderStream.h"
#include "FileCommanderIterator.h"
#include "Modify.h"

#include <map>

int main(){
    FileCommanderStream fileCommanderStream("fileStream.txt");
    fileCommanderStream.createData();
    typedef std::vector<int> Vector_type;
    Vector_type dataStream = fileCommanderStream.loadData<Vector_type>();
    modify1(dataStream);

    //Сюда можно только std::vector<int> вставить, потому что функция не шаблонная
    std::vector<int> dataStream1 = {1,2,3};

    modify2(dataStream1.begin(), dataStream1.end());
    modify3(dataStream1.begin(), dataStream1.end());
    modify4("fileStream.txt", "result_file.txt");

    FileCommanderIterator fileCommanderIterator("fileIterator.txt");
    fileCommanderIterator.createData();
    Vector_type dataIterator = fileCommanderIterator.loadData<Vector_type>();


    typedef std::map<std::string, std::string> RecordType;
    std::vector<RecordType> table;

    for(int i = 0;i<100;i++){
        RecordType record;
        record["Фамилия"] = "Сукиасян";
        record["Numver"] = "134";
        table.push_back(record);
    }

    table[0].at("Фамилия")
    table[0].at("Номер")
}


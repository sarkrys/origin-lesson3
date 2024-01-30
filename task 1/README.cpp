#include <iostream>
#include <fstream>
#include <string>

struct Address {
    std::string city;
    std::string street;
    std::string houseNumber;
    std::string apartmentNumber;
};

int main() {
    std::ifstream inFile("in.txt");

    if (inFile.is_open()) {
        int N;
        inFile >> N;
        inFile.ignore();

        Address* addresses = new Address[N];

        for (int i = 0; i < N; ++i) {
            std::getline(inFile, addresses[i].city);
            std::getline(inFile, addresses[i].street);
            std::getline(inFile, addresses[i].houseNumber);
            std::getline(inFile, addresses[i].apartmentNumber);
        }

        inFile.close();

        std::cout << N << std::endl;

        for (int i = N - 1; i >= 0; --i) {
            std::cout << addresses[i].city << ", " << addresses[i].street << ", " << addresses[i].houseNumber << ", " << addresses[i].apartmentNumber << std::endl;
        }

        delete[] addresses;
    }
    else {
        std::cout << "Unable to open file.";
    }

    return 0;
}

/*
1.у меня возникла проблема с тем что почему то в консоль у меня выводит ся сообщение не русскими символами при запуске прграммы я получаю такой итоговый результат (3
Э╨╛╨▓╨╛╤Б╨╕╨▒╨╕╤А╤Б╨║, ╨Ь╨╕╤А╨░, 85, 64
Ю╨╝╤Б╨║, ╨Я╤Г╤И╨║╨╕╨╜╨░, 2, 13
╨Ь╨╛╤Б╨║╨▓╨░, ╨б╤В╤А╨╛╨╕╤В╨╡╨╗╨╡╨╣, 34, 12) как это можно решить?
2.чем отличается функция в виде метода класса и функция вне метода класса?
3. код я пишу в microsoft visual studio  , а visual studio code использую только для отправки текста на гитхаб и совсем не знаю как с ним работать по этому можете пожалуйста объяснить как добавить файл в проект в visual studio code?
        */

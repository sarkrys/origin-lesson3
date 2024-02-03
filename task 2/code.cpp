#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

struct Address {
    std::string city;
    std::string street;
    std::string houseNumber;
    std::string apartmentNumber;
};

bool comparator(const Address& a, const Address& b) {
    return a.city < b.city;
}

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

        std::sort(addresses, addresses + N, comparator);

        std::cout << N << std::endl;

        for (int i = 0; i < N; ++i) {
            std::cout << addresses[i].city << ", " << addresses[i].street << ", " << addresses[i].houseNumber << ", " << addresses[i].apartmentNumber << std::endl;
        }

        delete[] addresses;
    }
    else {
        std::cout << "Unable to open file.";
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    std::string houseNumber;
    std::string apartmentNumber;

public:
    Address() : city(""), street(""), houseNumber(""), apartmentNumber("") {}

    Address(const std::string& city, const std::string& street, const std::string& houseNumber, const std::string& apartmentNumber)
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {
    }


    std::string getFormattedAddress() const {
        return city + ", " + street + ", " + houseNumber + ", " + apartmentNumber;
    }
};

int main() {
    const int N = 10;
    std::ifstream inFile("in.txt");
    if (inFile.is_open()) {
        int N;
        inFile >> N;
        inFile.ignore();

        Address* addresses = new Address[N];


        for (int i = 0; i < N; ++i) {
            std::string city, street, houseNumber, apartmentNumber;
            std::getline(inFile, city);
            std::getline(inFile, street);
            std::getline(inFile, houseNumber);
            std::getline(inFile, apartmentNumber);
            addresses[i] = Address(city, street, houseNumber, apartmentNumber);
        }

        inFile.close();

        std::ofstream outFile("out.txt");
        if (outFile.is_open()) {
            outFile << N << std::endl;

            for (int i = N - 1; i >= 0; --i) {
                outFile << addresses[i].getFormattedAddress() << std::endl;
            }

            outFile.close();
        }
        else {
            std::cout << "Unable to open file for writing." << std::endl;
        }

        delete[] addresses;
    }
    else {
        std::cout << "Unable to open file for reading." << std::endl;
    }

    return 0;
}

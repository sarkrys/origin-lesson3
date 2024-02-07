#include <iostream>
#include <fstream>
#include <sstream>

class Address {
private:
    std::string city;
    std::string street;
    std::string houseNumber;
    std::string apartmentNumber;

public:
    Address() {}
    Address(const std::string& c, const std::string& s, const std::string& h, const std::string& a) : city(c), street(s), houseNumber(h), apartmentNumber(a) {}

    const std::string& getCity() const {
        return city;
    }

    const std::string& getStreet() const {
        return street;
    }

    const std::string& getHouseNumber() const {
        return houseNumber;
    }

    const std::string& getApartmentNumber() const {
        return apartmentNumber;
    }

    std::string getAddressSummary() const {
        return city + ", " + street + ", " + houseNumber + ", " + apartmentNumber;
    }

    bool comesBefore(const Address& other) const {
        if (city != other.city) {
            return city < other.city;
        }
        if (street != other.street) {
            return street < other.street;
        }
        if (houseNumber != other.houseNumber) {
            return houseNumber < other.houseNumber;
        }
        return apartmentNumber < other.apartmentNumber;
    }
};

void bubbleSort(Address** arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!(*arr[j]).comesBefore(*arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    const int N = 10;

    std::ifstream file("in.txt");
    if (!file) {
        std::cerr << "Failed to open the file" << std::endl;
        return 1;
    }

    Address** addresses = new Address * [N];
    for (int i = 0; i < N; i++) {
        std::string number, city, street, house, apartment;
        if (!(file >> number >> city >> street >> house >> apartment)) {
            break;
        }
        addresses[i] = new Address(city, street, house, apartment);
    }
    file.close();

    bubbleSort(addresses, N);

    for (int i = 0; i < N; i++) {
        std::cout << (*addresses[i]).getAddressSummary() << std::endl;
    }

    for (int i = 0; i < N; i++) {
        delete addresses[i];
    }
    delete[] addresses;

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
    // Конструктор класса Address с параметрами
    Address(const std::string& city, const std::string& street, int houseNumber, int apartmentNumber) 
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

    // Метод для получения строки формата адреса для вывода в файл
    std::string getOutputAddress() const {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }
};

int main() {
    std::ifstream inFile("in.txt");
    if (!inFile) {
        std::cerr << "Не удалось открыть файл in.txt" << std::endl;
        return 1;
    }

    int numAddresses;
    inFile >> numAddresses;
    inFile.ignore(); // Игнорируем оставшийся символ новой строки

    std::vector<Address> addresses;

    // Считываем адреса из файла
    for (int i = 0; i < numAddresses; ++i) {
        std::string city, street;
        int houseNumber, apartmentNumber;
        
        std::getline(inFile, city);
        std::getline(inFile, street);
        inFile >> houseNumber;
        inFile >> apartmentNumber;
        inFile.ignore(); // Игнорируем оставшийся символ новой строки

        addresses.push_back(Address(city, street, houseNumber, apartmentNumber));
    }

    inFile.close();

    std::ofstream outFile("out.txt");
    if (!outFile) {
        std::cerr << "Не удалось открыть файл out.txt" << std::endl;
        return 1;
    }

    outFile << numAddresses << std::endl;

    // Выводим адреса в обратном порядке
    for (int i = numAddresses - 1; i >= 0; --i) {
        outFile << addresses[i].getOutputAddress() << std::endl;
    }

    outFile.close();

    return 0;
}

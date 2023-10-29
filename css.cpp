#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Person {
    std::string name;
    int age;
};

int main() {
    // Создание и запись данных в CSV файл
    std::ofstream csvFile("data.csv");
    if (csvFile.is_open()) {
        std::vector<Person> people = {{"Alice", 30}, {"Bob", 35}, {"Charlie", 40}};

        for (const auto& person : people) {
            csvFile << person.name << "," << person.age << std::endl;
        }

        csvFile.close();
    } else {
        std::cerr << "Не удалось создать CSV файл." << std::endl;
    }

    // Чтение данных из CSV файла и обработка
    std::ifstream inputFile("data.csv");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            std::string name;
            int age;

            // Разделение строки на поля по запятой
            std::getline(ss, name, ',');
            ss >> age;

            // Обработка данных (например, вывод на экран)
            std::cout << "Имя: " << name << ", Возраст: " << age << std::endl;
        }

        inputFile.close();
    } else {
 

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

// Функция для разбора одной строки CSV (учитывает кавычки)
std::vector<std::string> parseCSVLine(const std::string &line, char delimiter = ',') {
    std::vector<std::string> result;
    std::string cell;
    bool inQuotes = false;

    for (size_t i = 0; i < line.size(); ++i) {
        char c = line[i];

        if (c == '"') {
            // Если встречаем двойную кавычку внутри кавычек — добавляем одну
            if (inQuotes && i + 1 < line.size() && line[i + 1] == '"') {
                cell += '"';
                ++i;
            } else {
                inQuotes = !inQuotes; // переключаем режим внутри/вне кавычек
            }
        } else if (c == delimiter && !inQuotes) {
            // Конец поля
            result.push_back(cell);
            cell.clear();
        } else {
            // Добавляем символ в текущее поле
            cell += c;
        }
    }
    result.push_back(cell); // добавляем последнее поле
    return result;
}

// Основная функция чтения CSV-файла
std::vector<std::vector<std::string>> readCSV(const std::string &filename, char delimiter = ',') {
    std::ifstream file(filename);
    std::vector<std::vector<std::string>> data;

    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return data;
    }

    std::string line;
    std::string accumulated;
    bool inQuotes = false;

    while (std::getline(file, line)) {
        // Добавляем строку к накопленной (на случай многострочных полей)
        accumulated += line;

        // Проверяем баланс кавычек
        size_t countQuotes = std::count(accumulated.begin(), accumulated.end(), '"');
        if (countQuotes % 2 != 0) {
            accumulated += "\n"; // продолжаем собирать многострочное поле
            continue;
        }

        // Если кавычки сбалансированы — парсим строку
        auto row = parseCSVLine(accumulated, delimiter);
        data.push_back(row);
        accumulated.clear();
    }

    file.close();
    return data;
}

int main() {
    std::string filename = "data.csv";

    auto table = readCSV(filename);

    // Выводим результат
    std::cout << "=== Содержимое CSV ===" << std::endl;
    for (const auto &row : table) {
        for (const auto &cell : row) {
            std::cout << "[" << cell << "] ";
        }
        std::cout << std::endl;
    }

    return 0;
}


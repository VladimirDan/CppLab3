#include "filemanager.h"
#include <fstream>
#include <exception>
#include <nlohmann/json.hpp>

namespace Records {

    FileManager::FileManager() {}

    std::vector<Employee> FileManager::Read(const std::string& fileName) {
        std::ifstream file(fileName);
        std::vector<Employee> result;

        if (!file) {
            throw std::exception();
        }

        nlohmann::json jsonData;
        file >> jsonData;

        for (const auto& employeeData : jsonData) {
            Employee emp = *(new Employee());
            emp.from_json(employeeData);
            result.push_back(emp);
        }

        return result;
    }

    void FileManager::Write(const std::string& fileName, const std::vector<Employee>& employees) const{
        std::ofstream file(fileName);

        if (!file.is_open()) {
            throw std::runtime_error("Unable to open file: " + fileName);
        }

        nlohmann::json jsonData;

        for (const auto& emp : employees) {
            json employeeJson;
            emp.to_json(employeeJson);
            jsonData.push_back(employeeJson);
        }

        file << std::setw(4) << jsonData << '\n';
    }

}
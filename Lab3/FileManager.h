#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "employee.h"  

namespace Records {

    class FileManager {
    public:
        FileManager();

        std::vector<Employee> Read(const std::string& fileName);
        void Write(const std::string& fileName, const std::vector<Employee>& employees) const;
    };

} 

#endif  
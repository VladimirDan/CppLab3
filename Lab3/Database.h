#pragma once

#include <iostream>
#include "Employee.h"
#include <string>
#include "FileManager.h"

using namespace std;

namespace Records {
	const int kMaxEmployees = 100;
	const int kFirstEmployeeNumber = 1000;
	class Database
	{
	public:
		Database(FileManager _fileManager);
		~Database();
		Employee& addEmployee(
			string firstName,
			string lastName,
			string fathersName,
			int age,
			Sex sex,
			string address,
			int passportNumber,
			PositionCode positionCode,
			int mEmployeeCode);
		Employee& getEmployee(int inEmployeeNumber);
		Employee& getEmployee(std::string inFirstName, std::string inLastName);
		void displayAll();
		void displayCurrent();
		void displayFormer();
		void displayAdult();

		void load();
		void save() const;


	protected:
		std::vector<Employee> mEmployees;
		int mNextSlot;
		int mNextEmployeeNumber;

		FileManager fileManager;
	};
}
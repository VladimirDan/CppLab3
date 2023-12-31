#pragma once


#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

namespace Records {
	const int kDefaultStartingSalary = 30000;

	enum Sex {
		Male,
		Female,
	};

	enum PositionCode {
		Librarian,
		Cataloger,
		Archivist,
	};

	class Employee
	{
	public:
		Employee();
		Employee(string mFirstName,
			string mLastName,
			string fathersName,
			int mEmployeeCode,
			int age,
			Sex sex,
			string address,
			int passportNumber,
			PositionCode positionCode);
		void promote(int inRaiseAmount = 1000);
		void demote(int inDemeritAmount = 1000);
		void hire(); // hires or re-hires the employee
		void fire(); // dismisses the employee
		void display(); // outputs employee info to the console
		// Accessors and setters
		void setFirstName(std::string inFirstName);
		std::string getFirstName();
		void setLastName(std::string inLastName);
		std::string getLastName();
		void setEmployeeNumber(int inEmployeeNumber);
		int getEmployeeNumber();
		void setSalary(int inNewSalary);
		int getSalary();
		bool getIsHired();
		void setIsHired(bool value);
		std::string getFathersName();
		void setFathersName(string name);
		int getEmployeeCode();
		void setEmployeeCode(int code);
		int getAge();
		void setAge(int employeeAge);
		Sex getSex();
		void setSex(Sex employeeSex);
		std::string getAddress();
		void setAddress(string employeeAddress);
		int getPassportNumber();
		void setPassportNumber(int number);
		PositionCode getPositionCode();
		void setPositionCode(PositionCode code);

		bool isAdult();

		Sex convertStringToSex(const std::string& sexString);
		PositionCode convertStringToPositionCode(const std::string& positionCodeString);
		string convertSexToString(Sex sex) const;
		string convertPositionCodeToString(PositionCode positionCode) const;

		void to_json(json& j) const;
		void from_json(const json& j, Employee& emp);

	private:
		std::string mFirstName;
		std::string mLastName;
		std::string fathersName;
		int mEmployeeCode;
		int age;
		Sex sex;
		std::string address;
		int passportNumber;
		PositionCode positionCode;

		int mEmployeeNumber;
		int mSalary;
		bool fHired;
	};
}
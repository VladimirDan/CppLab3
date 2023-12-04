#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;
namespace Records {
	Employee::Employee()
	{
		mFirstName = "";
		mLastName = "";
		fathersName = "";
		mEmployeeNumber = -1;
		mSalary = kDefaultStartingSalary;
		fHired = false;
	}

	Employee::Employee(string mFirstName,
		string mLastName,
		string fathersName,
		int mEmployeeCode,
		int age,
		Sex sex,
		string address,
		int passportNumber,
		PositionCode positionCode)
	{
		this->mFirstName = mFirstName;
		this->mLastName = mLastName;
		this->fathersName = fathersName;
		this->mEmployeeCode = mEmployeeCode;
		this->age = age;
		this->sex = sex;
		this->address = address;
		this->passportNumber = passportNumber;
		this->positionCode = positionCode;
	}

	void Employee::promote(int inRaiseAmount)
	{
		setSalary(getSalary() + inRaiseAmount);
	}
	void Employee::demote(int inDemeritAmount)
	{
		setSalary(getSalary() - inDemeritAmount);
	}
	void Employee::hire()
	{
		fHired = true;
	}
	void Employee::fire()
	{
		fHired = false;
	}
	void Employee::display()
	{
		cout << "Employee Information" << endl;
		cout << "-------------------" << endl;
		cout << "First Name: " << mFirstName << endl;
		cout << "Last Name: " << mLastName << endl;
		cout << "Father's Name: " << fathersName << endl;
		cout << "Age: " << age << endl;
		cout << "Sex: " << (sex == Sex::Male ? "Male" : "Female") << endl;
		cout << "Address: " << address << endl;
		cout << "Passport Number: " << passportNumber << endl;
		cout << "Salary: " << mSalary << endl;
		cout << "Position: ";

		switch (positionCode) {
		case PositionCode::Librarian:
			cout << "Position code - Librarian" << endl;
			break;
		case PositionCode::Cataloger:
			cout << "Position code - Cataloger" << endl;
			break;
		case PositionCode::Archivist:
			cout << "Position code - Archivist" << endl;
			break;
		default:
			cout << "Position code - Unknown" << endl;
			break;
		}
	}
	// Accessors and setters
	void Employee::setFirstName(string inFirstName)
	{
		mFirstName = inFirstName;
	}
	string Employee::getFirstName()
	{
		return mFirstName;
	}
	void Employee::setLastName(string inLastName)

	{
		mLastName = inLastName;
	}
	string Employee::getLastName()
	{
		return mLastName;
	}
	void Employee::setEmployeeNumber(int inEmployeeNumber)
	{
		mEmployeeNumber = inEmployeeNumber;
	}
	int Employee::getEmployeeNumber()
	{
		return mEmployeeNumber;
	}
	void Employee::setSalary(int inSalary)
	{
		mSalary = inSalary;
	}
	int Employee::getSalary()
	{
		return mSalary;
	}
	bool Employee::getIsHired()
	{
		return fHired;
	}

	void Employee::setIsHired(bool value) {
		fHired = value;
	}

	std::string Employee::getFathersName() {
		return fathersName;
	}

	void Employee::setFathersName(string name) {
		fathersName = name;
	}

	int Employee::getEmployeeCode() {
		return mEmployeeCode;
	}

	void Employee::setEmployeeCode(int code) {
		mEmployeeCode = code;
	}

	int Employee::getAge() {
		return age;
	}

	void Employee::setAge(int employeeAge) {
		age = employeeAge;
	}

	Sex Employee::getSex() {
		return sex;
	}

	void Employee::setSex(Sex employeeSex) {
		sex = employeeSex;
	}

	std::string Employee::getAddress() {
		return address;
	}

	void Employee::setAddress(string employeeAddress) {
		address = employeeAddress;
	}

	int Employee::getPassportNumber() {
		return passportNumber;
	}

	void Employee::setPassportNumber(int number) {
		passportNumber = number;
	}

	PositionCode Employee::getPositionCode() {
		return positionCode;
	}

	void Employee::setPositionCode(PositionCode code) {
		positionCode = code;
	}

	bool Employee::isAdult() {
		return age >= 18;
	}

	Sex Employee::convertStringToSex(const std::string& sexString) {
		if (sexString == "Male") {
			return Sex::Male;
		}
		else if (sexString == "Female") {
			return Sex::Female;
		}
		else {
			throw std::invalid_argument("Invalid value for Sex");
		}
	}

	PositionCode Employee::convertStringToPositionCode(const std::string& positionCodeString) {
		if (positionCodeString == "Librarian") {
			return PositionCode::Librarian;
		}
		else if (positionCodeString == "Cataloger") {
			return PositionCode::Cataloger;
		}
		else if (positionCodeString == "Archivist") {
			return PositionCode::Archivist;
		}
		else {
			throw std::invalid_argument("Invalid value for PositionCode");
		}
	}

	std::string Employee::convertSexToString(Sex sex) const {
		switch (sex) {
			case Sex::Male: return "Male";
			case Sex::Female: return "Female";
			default: throw std::invalid_argument("Invalid value for Sex");
		}
	}

	std::string Employee::convertPositionCodeToString(PositionCode positionCode) const {
		switch (positionCode) {
			case PositionCode::Librarian: return "Librarian";
			case PositionCode::Cataloger: return "Cataloger";
			case PositionCode::Archivist: return "Archivist";
			default: throw std::invalid_argument("Invalid value for PositionCode");
		}
	}

	void Employee::to_json(json& j) const {
		j = {
			{"mFirstName", mFirstName},
			{"mLastName", mLastName},
			{"fathersName", fathersName},
			{"mEmployeeCode", mEmployeeCode},
			{"age", age},
			{"sex", convertSexToString(sex)},
			{"address", address},
			{"passportNumber", passportNumber},
			{"positionCode", convertPositionCodeToString(positionCode)},
			{"mEmployeeNumber", mEmployeeNumber},
			{"mSalary", mSalary},
			{"fHired", fHired}
		};
	}


	void Employee::from_json(const json& j, Employee& emp) {
		try {
			emp.mFirstName = j.at("mFirstName").get<std::string>();
			emp.mLastName = j.at("mLastName").get<std::string>();
			emp.fathersName = j.at("fathersName").get<std::string>();
			emp.mEmployeeCode = j.at("mEmployeeCode").get<int>();
			emp.age = j.at("age").get<int>();
			//emp.sex = j.at("sex").get<Sex>();
			emp.setSex(convertStringToSex(j.at("sex").get<std::string>()));
			emp.address = j.at("address").get<std::string>();
			emp.passportNumber = j.at("passportNumber").get<int>();
			//emp.positionCode = j.at("positionCode").get<PositionCode>();
			emp.setPositionCode(convertStringToPositionCode(j.at("positionCode").get<std::string>()));
			emp.mEmployeeNumber = j.at("mEmployeeNumber").get<int>();
			emp.mSalary = j.at("mSalary").get<int>();
			emp.fHired = j.at("fHired").get<bool>();
		}
		catch (const nlohmann::json::exception& e) {
			std::cerr << "Error parsing JSON for Employee: " << e.what() << std::endl;
		}
	}
}
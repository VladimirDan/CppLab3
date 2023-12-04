#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"

using namespace std;
namespace Records {
	Database::Database(FileManager _fileManager)
	{
		mNextSlot = 0;
		mNextEmployeeNumber = kFirstEmployeeNumber;
		fileManager = _fileManager;
		load();
	}
	Database::~Database()
	{
	}
	Employee& Database::addEmployee(
		string firstName,
		string lastName,
		string fathersName,
		int age,
		Sex sex,
		string address,
		int passportNumber,
		PositionCode positionCode,
		int mEmployeeCode) {

		if (mNextSlot >= kMaxEmployees) {
			cerr << "There is no more room to add the new employee!" << endl;
			throw exception();
		}

		Employee theEmployee;
		
		theEmployee.setFirstName(firstName);
		theEmployee.setLastName(lastName);
		theEmployee.setFathersName(fathersName);
		theEmployee.setAge(age);
		theEmployee.setSex(sex);
		theEmployee.setAddress(address);
		theEmployee.setPassportNumber(passportNumber);
		theEmployee.setPositionCode(positionCode);
		theEmployee.setEmployeeCode(mEmployeeCode);
		theEmployee.hire();

		switch (positionCode)
		{
			case Records::Librarian:
				theEmployee.setSalary(100);
				break;
			case Records::Cataloger:
				theEmployee.setSalary(200);
				break;
			case Records::Archivist:
				theEmployee.setSalary(300);
				break;
			default:
				break;
		}

		mEmployees.push_back(theEmployee);
		mNextSlot++;
		
		save();

		return theEmployee;
	}
	Employee& Database::getEmployee(int inEmployeeNumber)
	{
		for (int i = 0; i < mNextSlot; i++) {
			if (mEmployees[i].getEmployeeCode() == inEmployeeNumber) {
				return mEmployees[i];
			}
		}
		cerr << "No employee with employee number " << inEmployeeNumber << endl;
		throw exception();
	}
	Employee& Database::getEmployee(string inFirstName, string inLastName)
	{
		for (int i = 0; i < mNextSlot; i++) {
			if (mEmployees[i].getFirstName() == inFirstName &&
				mEmployees[i].getLastName() == inLastName) {
				return mEmployees[i];
			}
		}
		cerr << "No match with name " << inFirstName << " " << inLastName << endl;
		throw exception();
	}
	void Database::displayAll()
	{
		for (int i = 0; i < mNextSlot; i++) {
			mEmployees[i].display();
		}
	}
	void Database::displayCurrent()
	{
		for (int i = 0; i < mNextSlot; i++) {
			if (mEmployees[i].getIsHired()) {
				mEmployees[i].display();
			}
		}
	}
	void Database::displayFormer()
	{

		for (int i = 0; i < mNextSlot; i++) {
			if (!mEmployees[i].getIsHired()) {
				mEmployees[i].display();
			}
		}
	}

	void Database::displayAdult()
	{
		for (int i = 0; i < mNextSlot; i++) {
			if (mEmployees[i].isAdult()) {
				mEmployees[i].display();
			}
		}
	}

	void Database::load() {
		try {
			mEmployees = fileManager.Read("C:/Users/user/Dropbox/Ìîé ÏÊ (WIN-9HVOQM4TUNA)/Desktop/CppLab3/Lab3/employeeData.json");
			mNextSlot = mEmployees.size();
		}
		catch (const std::exception& e) {
			cerr << "Error loading data from file: " << e.what() << endl;
		}
	}

	void Database::save() const {
		try {
			string filePath = "C:/Users/user/Dropbox/Ìîé ÏÊ (WIN-9HVOQM4TUNA)/Desktop/CppLab3/Lab3/employeeData.json";
			fileManager.Write(filePath, mEmployees);
		}
		catch (const std::exception& e) {
			cerr << "Error saving data to file: " << e.what() << endl;
		}
	}
}
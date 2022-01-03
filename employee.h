#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <fstream>

using namespace std;

class Employee
{
    public:
        Employee();
        Employee(string fName, string lName, string empType, int age, int empID, int nOfLeaves, double hWage);
        string get_empFirstName() const;
        string get_empLasttName() const;
        string get_empType() const;
        int get_employeeAge() const;
        int get_empIdentity() const;
        int get_empNumOfLeaves() const;
        double get_empHourlyWage() const;
        bool checkEmployeeExistenceInFile(ifstream &fin, string fName, string lName);
        bool extractEmpTypeAndHourlyWage(ifstream &fin, string fName, string lName, string &empType, double &hWage);
        void filePrintOut(Employee employeeData, ofstream &fout);
        double calculateEmpHours(ifstream &fin, string fName, string lName);

    private:
        string firstName;
        string lastName;
        string employeeType;
        int employeeAge;
        int identity;
        int numOfLeaves;
        double hourlyWage;
};

class FullTimeEmployee:public Employee
{
    public:
        double calcTotalSalary(double &hrs, double &hrlyWage)
        {
            return ((hrs * hrlyWage) + 200);
        }
};

class PartTimeEmployee:public Employee
{
    public:
        double calcTotalSalary(double &hrs, double &hrlyWage)
        {
            return (hrs * hrlyWage * 1.2);
        }
};

class ContractEmployee:public Employee
{
    public:
        double calcTotalSalary(double &hrs, double &hrlyWage)
        {
            return (hrs * hrlyWage * 1.5);
        }
};
#endif

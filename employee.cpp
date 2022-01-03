#include "employee.h"

using namespace std;

Employee:: Employee()
{
    firstName = "";
    lastName = "";
    employeeType = "";
    employeeAge = 0;
    identity = 0;
    numOfLeaves = 0;
    hourlyWage = 0.0;
}

Employee:: Employee (string fName, string lName, string empType, int age, int empID, int nOfLeaves, double hWage)
{
    firstName = fName;
    lastName = lName;
    employeeType = empType;
    employeeAge = age; 
    identity = empID;
    numOfLeaves = nOfLeaves;
    hourlyWage = hWage;
}

string Employee:: get_empFirstName() const
{
    return firstName;
}

string Employee:: get_empLasttName() const
{
    return lastName;
}

string Employee:: get_empType() const
{
    return employeeType;
}

int Employee:: get_employeeAge() const
{
    return employeeAge;
}

int Employee:: get_empIdentity() const
{
    return identity;
}

int Employee:: get_empNumOfLeaves() const
{
    return numOfLeaves;
}

double Employee:: get_empHourlyWage() const
{
    return hourlyWage;
}

bool Employee:: checkEmployeeExistenceInFile(ifstream &fin, string  fName, string lName)
{
    string fName1 = "", lName1 = "";
    while(fin >> fName1 >> lName1)
    {
        if((fName == fName1) && (lName == lName1))
        {
            cout << "This employee already exists" << endl;
            return true;
        }
    }
    return false;
}

bool Employee:: extractEmpTypeAndHourlyWage(ifstream &fin, string fName, string lName, string &empType, double &hWage)
{
    string fName1 = "", lName1 = "";
    int age = 0, ID = 0, nOfLeave = 0;

    while(fin >> fName1 >> lName1)
    {
        if((fName == fName1) && (lName == lName1))
        {
            fin >> empType >> age >> ID >> nOfLeave >> hWage;
            return true;
        }
        fin.ignore(9999999, '\n');

    }
    return false;
}

void Employee:: filePrintOut(Employee employeeData, ofstream &fout)
{
    fout << employeeData.get_empFirstName() << setw(12) << employeeData.get_empLasttName() << setw(15) << employeeData.get_empType() << setw(11) 
    << employeeData.get_employeeAge() << setw(9) << employeeData.get_empIdentity() << setw(9) << employeeData.get_empNumOfLeaves() << setw(13) << employeeData.get_empHourlyWage() << endl;
}

double Employee::calculateEmpHours(ifstream &fin, string fName, string lName)
{
    string fName1 = "", lName1 = "";
    double hours = 0.0;
    double sum = 0.0;
    while(fin >> fName1 >> lName1 >> hours)
    {
        if((fName == fName1) && (lName == lName1))
        {
            
           sum += hours;
        }
    }
    return sum;
}




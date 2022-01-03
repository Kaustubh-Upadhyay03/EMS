#include <iostream>
#include <fstream>
#include <iomanip>
#include "employee.cpp"
#include "employee.h"

using namespace std;

int adminPortal()
{
        int numberOfEmployees;
        string fName0 = "", lName0 = "", empType0 = "";
        int age0 = 0, empID0 = 0, nOfLeaves0 = 0;
        double hWage0 = 0.0;

        cout << "WELCOME TO ADMIN PORTAL" << endl;
        cout << "***********************" << endl;
        cout << "" << endl;

        cout << "How many employees do you want to enter data for: ";
        cin >> numberOfEmployees;
        
        //fout << "FirstName" << setw(11) <<"LastName" << setw(15) << "EmployeeType" << setw(8) << "Age" << setw(14) << "EmployeeID" << setw(16) << "NumberOfLeaves" << setw(11) << "HourlyWage" << endl;

        for(int i = 0; i < numberOfEmployees; i++)
        {
            cout << "Enter first name of employee " << i+1 << ": ";
            cin >> fName0;
            cout << "Enter last name of employee " << i+1 << ": ";
            cin >> lName0;

            ifstream fin("EmployeeData.txt");
            if(!fin)
            {
                cout << "Unable to open file" << endl;
                return EXIT_FAILURE;
            }
            else
            {
                Employee emp;
                emp.checkEmployeeExistenceInFile(fin, fName0, lName0);

                fin.close();
                if(emp.checkEmployeeExistenceInFile(fin, fName0, lName0))
                {
                    i--;
                }
                else
                {
                    cout << "Enter 1 if " << fName0 << " is a full time employee, otherwise enter 2 and 3 if part time or contract employee: ";
                    cin >> empType0;
                
                    while ((empType0 != "1") && (empType0 != "2") && (empType0 != "3"))                  
                    {
                        cout << "Incorrect input! Please enter 1 for full time, 2 for part time or 3 for contract employee: ";
                        cin >> empType0;
                    }
                    if(empType0 == "1")
                    {
                        empType0 = "FULLTIME";
                    }
                    else if(empType0 == "2")
                    {
                        empType0 = "PARTTIME";
                    }
                    else if(empType0 == "3")
                    {
                        empType0 = "CONTRACT";
                    }

                    cout << "What is " << fName0 << "'s age: ";
                    cin >> age0;
                    cout << "What is " << fName0 << "'s ID: ";
                    cin >> empID0;
                    cout << "How many holidays can " << fName0 << " have: ";
                    cin >> nOfLeaves0;
                    cout << "What is " << fName0 << "'s hourly wage: ";
                    cin >> hWage0;

                    system("cls");

                    Employee empData(fName0, lName0, empType0, age0, empID0, nOfLeaves0, hWage0);

                    ofstream fout("EmployeeData.txt", std::ofstream::app);
                    if(!fout)
                    {
                        cout << "Unable to open file" << endl;
                        return EXIT_FAILURE;
                    }


                    empData.filePrintOut(empData, fout);

                    fout.close();
                
                }
            }
        }
    return 0;
}

int employeePortal()
{
    string fName0 = "", lName0 = "";

    cout << "WELCOME TO EMPLOYEE PORTAL" << endl;
    cout << "**************************" << endl;
    cout << "" << endl;

    cout << "Please enter your first name: ";
    cin >> fName0;
    cout << "Please enter your last name: ";
    cin >> lName0;

    ifstream fin("EmployeeData.txt");
    if(!fin)
    {
        cout << "Unable to open file" << endl;
        return EXIT_FAILURE;
    }

    Employee emp;

    string empType = "";
    double hourlyWage = 0.0;

    if(emp.extractEmpTypeAndHourlyWage(fin, fName0, lName0, empType, hourlyWage))
    {
        int empChoice = 0;
        cout << "To record the number of hours you worked today enter 1, or to check your total earnings enter 0: ";
        cin >> empChoice;

        while((empChoice != 1) && (empChoice != 0))
        {
            cout << "Incorrect input! Please enter 1 to record the number of hours you worked today or 0 to check your total earnings: ";
            cin >> empChoice;
        }
        if(empChoice == 1)
        {
            double numOfHours = 0.0;
            cout << "Enter the number of hours worked today: ";
            cin >> numOfHours;

            ofstream fout("EmployeeHours.txt", std::ofstream::app);
            if(!fout)
            {
                cout << "Unable to open file" << endl;
                return EXIT_FAILURE;
            }

            fout << fName0 << setw(6) << lName0 << setw(6) << numOfHours << endl;
            fout.close();
        }
        else
        {
            ifstream fin("EmployeeHours.txt");
            if(!fin)
            {
                cout << "Unable to open file" << endl;
                return EXIT_FAILURE;
            }

            Employee emp;
            
            double hours = emp.calculateEmpHours(fin, fName0, lName0);
            
            if(empType == "FULLTIME")
            {
                FullTimeEmployee fullTime;
                cout << fName0 << "'s total earnings to date is $" << fullTime.calcTotalSalary(hours, hourlyWage) << endl;
            }
            else if(empType == "PARTTIME")
            {
                PartTimeEmployee partTime;
                cout << fName0 << "'s total earnings to date is $" << partTime.calcTotalSalary(hours, hourlyWage) << endl;
            }
            else if(empType == "CONTRACT")
            {
                ContractEmployee contr;
               cout << fName0 << "'s total earnings to date is $" << contr.calcTotalSalary(hours, hourlyWage) << endl;
            }
        }
    }
    else
    {
        cout << "Please ask admin to enter your first and last name" << endl;
    }
    return 0;
}

int homePortal()
{
    int adminOrEmployee = 0;

    cout << "Do you want to access program as ADMIN, Please Enter 1" << endl;
    cout << "Do you want to access program as EMPLOYEE, Please Enter 0" << endl;
    cin >> adminOrEmployee;

    while((adminOrEmployee != 1) && (adminOrEmployee != 0))
    {
        system("cls");
        cout << "Incorrect input" << endl;
        cout << "Do you want to access program as ADMIN, Please Enter 1" << endl;
        cout << "Do you want to access program as EMPLOYEE, Please Enter 0" << endl;
        cin >> adminOrEmployee;
    }

    cout << " " << endl;

    if(adminOrEmployee == 1)
    {
       adminPortal();
    }
    else if(adminOrEmployee == 0)
    {
        employeePortal();
    }
    return 0;
}

int main()
{ 
    
    homePortal();

    return 0;
}
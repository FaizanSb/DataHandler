#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int employeeID;
    string name;
    float salary;

public:
    Employee(int empID, const string& empName, float empSalary)
        : employeeID(empID), name(empName), salary(empSalary) {}

    virtual void calculatePay() = 0;
};

class FullTimeEmployee : public Employee {
public:
    FullTimeEmployee(int empID, const string& empName, float empSalary)
        : Employee(empID, empName, empSalary) {}

    void calculatePay() override {
        // Implement the calculation for full-time employees here
    }
};

class PartTimeEmployee : public Employee {
public:
    PartTimeEmployee(int empID, const string& empName, float empSalary)
        : Employee(empID, empName, empSalary) {}

    void calculatePay() override {
        // Implement the calculation for part-time employees here
    }
};

int main() {
    FullTimeEmployee fullTimeEmployee(1, "John Doe", 50000.0);
    fullTimeEmployee.calculatePay();

    PartTimeEmployee partTimeEmployee(2, "Jane Smith", 20.0);
    partTimeEmployee.calculatePay();

    return 0;
}



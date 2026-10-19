#pragma once
#include<iostream>
#include<list>
using namespace std;



class Employee
{
protected:
	string job;
	string name;
	int years;
	int salary;
	int totalSalary;
public:
	Employee() : job("Employee"), name("NAME"), years(0), salary(0), totalSalary(0){}
	Employee(string j, int s) : job(j), name("NAME"), years(0), salary(s), totalSalary(0) {}
	Employee(string j, string n, int y,int s) : job(j), name(n),years(y), salary(s), totalSalary(0) {}

	string GetJob() { return job; }
	string GetName() { return name; }

	virtual operator int() {
		return salary;
	}

	virtual void PrintInfo() {
		cout << "Job: " << job 
			<< "\tName: " << name 
			<< "\tYears: " << years
			<< "\tSalary: " << salary << endl;
	}
	virtual void AddReport(Employee* p) {}

	virtual void LetsWork() = 0;
	virtual void TotalSalary() = 0;
};

class Programmer : public Employee
{
public:
	Programmer() : Employee("Programmer", 10000) {}
	Programmer(string j,int s) : Employee(j,s) {}
	Programmer(string j, string n, int y, int s) : Employee(j, n, y,s) {}

	void LetsWork() {
		cout << "(" << job << ") " << name << " start codding." << endl;
		totalSalary += salary;
	}
	void TotalSalary(){
		cout << "(" << job << ") " << name << ": total salary is " << totalSalary << endl;
	}
};

class Tester : public Employee
{
public:
	Tester() : Employee("Tester", 10000) {}
	Tester(string j, string n, int y, int s) : Employee(j, n, y,s) {}

	void LetsWork() {
		cout << "(" << job << ") " << name << " start testing." << endl;
		totalSalary += salary;
	}
	void TotalSalary() {
		cout << "(" << job << ") " << name << ": total salary is " << totalSalary << endl;
	}
};

class ProjectManager: public Employee
{
public:
	ProjectManager() : Employee("ProjectManager", 10000) {}
	ProjectManager(string j, string n, int y, int s) : Employee(j, n, y,s) {}

	void LetsWork() {
		cout << "(" << job << ") " << name << " start organizing." << endl;
		totalSalary += salary;
	}
	void TotalSalary() {
		cout << "(" << job << ") " << name << ": total salary is " << totalSalary << endl;
	}
};


class TeamLead : public Programmer
{
	list<Employee*> reports;
	int repCounts;
	int extra;
public:
	TeamLead() : Programmer("TeamLead", 10000) 
	{ 
		extra = 0; 
		repCounts = 0; 
	}
	TeamLead(string j, string n, int y, int s, int e) : Programmer(j, n, y,s) {
		extra = e;
		repCounts = 0;
	}

	void AddReport(Employee* p) {
		reports.push_back(p);
		repCounts++;
	}

	void PrintInfo() {
		cout << "Job: " << job
			<< "\tName: " << name
			<< "\tYears: " << years
			<< "\tSalary: " << salary
			<< "\nReports count: " << repCounts << endl;
		if (repCounts == 0)return;
		cout << "Reports: " << endl;
		for (auto ptr = reports.begin(); ptr != reports.end(); ptr++) {
			(*ptr)->PrintInfo();
			cout << "------------------" << endl;
		}
		cout << "end tl" << endl;
	}

	operator int() {
		return salary+extra;
	}

	void LetsWork() {
		cout << "(" << job << ") " << name << " start leading." << endl;
		totalSalary += salary + extra;
	}
	void TotalSalary() {
		cout << "(" << job << ") " << name << ": total salary is " << totalSalary << endl;
	}
	~TeamLead() {
		for (auto ptr = reports.begin(); ptr != reports.end(); ptr++) {
			delete (*ptr);
		}
		reports.clear();
	}
};
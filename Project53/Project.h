#pragma once
#include<iostream>
#include<list>
using namespace std;
#include"Employee.h"

class Project
{
	string title;
	int budget;
	list<Employee*> reports;
	int repCout;
public:
	Project():title("TITLE"),budget(10000) , repCout(0){}
	Project(string t, int b) :title(t), budget(b), repCout(0) {}

	void AddReport(Employee* p) {
		reports.push_back(p);
		repCout++;
	}

	void PrintInfo() {
		cout << "Titleob: " << title
			<< "\tBudget: " << budget
			<< "\nReports: " << endl;
		for (auto ptr = reports.begin(); ptr != reports.end(); ptr++) {
			(*ptr)->PrintInfo();
			cout << "------------------" << endl;
		}
		cout << "end" << endl;
	}

	void Work() {
		cout << endl;
		for (auto ptr = reports.begin(); ptr != reports.end(); ptr++) {
			(*ptr)->LetsWork();
		}
		cout << endl;
	}

	void ShowTotalS() {
		cout << endl;
		for (auto ptr = reports.begin(); ptr != reports.end(); ptr++) {
			(*ptr)->TotalSalary();
		}
		cout << endl;
	}

	Employee* operator[](int idx) {
		if (idx >= repCout || idx < 0) return nullptr;
		auto temp = reports.begin();
		for (int i = 0; i != idx; i++) {
			temp++;
		}
		return *temp;
	}

	Employee* FindEmpMaxSalary() {
		Employee* ret = *(reports.begin());
		for (auto ptr = reports.begin(); ptr != reports.end(); ptr++) {
			if (&(*ptr) > &ret) ret = (*ptr);
		}
		return ret;
	}



	Employee* FindByName(string n) {
		Employee* ret = nullptr;
		for (auto ptr = reports.begin(); ptr != reports.end(); ptr++) {
			if ((*ptr)->GetName() == n) ret = (*ptr);
		}
		if (ret == nullptr)cout << "NotFound\n";
		return ret;
	}

	/*void AddReportByName(string n, Employee* e) {
		Employee* ret = FindByName(n);
		for (auto ptr = reports.begin(); ptr != reports.end(); ptr++) {
			if ((*ptr)->GetName() == n) ret = (*ptr);
		}
		if (ret == nullptr)
		{
			cout << "NotFound\n";
			return;
		}
		ret->AddReport(e);
	}*/

	~Project() {
		for (auto ptr = reports.begin(); ptr != reports.end(); ptr++) {
			delete (*ptr);
		}
		reports.clear();
	}

};
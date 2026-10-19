#include<iostream>
#include<vector>
using namespace std;
#include"Employee.h";
#include"Project.h";




int main() {
	Project p;
	p.AddReport(new Programmer("Programmer", "PR1", 2, 13000));
	p.AddReport(new Programmer("Programmer", "PR2", 1, 11000));
	p.AddReport(new Programmer("Programmer", "PR3", 1, 10000));
	p.AddReport(new ProjectManager("ProjectManager", "PM", 2, 13000));
	p.AddReport(new Tester("Tester", "T", 1, 9000));
	p.AddReport(new TeamLead("TeamLead", "TM", 3, 13000, 5000));


	p.FindByName("TM")->AddReport(p[0]);
	p.FindByName("TM")->AddReport(p[1]);
	p.FindByName("TM")->AddReport(p[2]);

	p.PrintInfo();

	cout << endl;
	cout << "FindEmpMaxSalary\n";


	p.FindEmpMaxSalary()->PrintInfo();

	p.Work();
	p.Work();

	p.ShowTotalS();

	return 0;
}
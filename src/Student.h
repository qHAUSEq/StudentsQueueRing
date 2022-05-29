#pragma once
#include "Header.h"

class Student
{
	string name;
	string surname;
	int age;

public:
	vector<double> result;
	Student();
	Student(string name, string surname, int age);

	void Set_Name(string name);
	void Set_Surname(string surname);
	void Set_Age(int age);
	void Set_Res(vector<double> result);
	string Get_Name();
	string Get_Surname();
	int Get_Age();

	friend ostream& operator << (ostream& os, Student& st);
};
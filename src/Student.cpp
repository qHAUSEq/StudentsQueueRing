#include "Student.h"

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

Student::Student()
{
	name = "";
	surname = "";
	age = 0;
	result.resize(3, 0);
}

Student::Student(string name, string surname, int age)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
	result.resize(3, 0);
}

void Student::Set_Name(string name)
{
	this->name = name;
}

void Student::Set_Surname(string surname)
{
	this->surname = surname;
}

void Student::Set_Age(int age)
{
	this->age = age;
}

void Student::Set_Res(vector<double> result)
{
	this->result = result;
}

string Student::Get_Name()
{
	return name;
}

string Student::Get_Surname()
{
	return surname;
}

int Student::Get_Age()
{
	return age;
}

ostream& operator<<(ostream& os, Student& st)
{
	SetColor(12, 0);
	cout << "===================================================\n";
	SetColor(14, 0);

	os << "Name & Surname: " << st.name << " " << st.surname << endl << "Age: " << st.age << endl;

	return os;
}
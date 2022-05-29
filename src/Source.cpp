#include "QueueRing.h"
#include "Student.h"

void PrintExam(QueueRing<Student>& qr, int n, vector<Student>& st, vector<double> grade, int NE);
void RewritingQueue(QueueRing<Student>& qr, vector<Student>& st, int* n, int NE);

int main()
{
 	srand(static_cast <unsigned> (time (NULL) ) );

	int n, random, age;
	vector<double> grade(3, 0);
	string name, surname;
	cout << "How many students take exams? " << endl;
	cin >> n;

	QueueRing<Student> qr(n);
	vector<Student> st;

	for (int i = 0; i < n; i++)
	{
		random = rand() % 115 + 1;
		ifstream in("..\\StudentData\\Name.txt");
		for (int j = 0; j < random; j++) getline(in, name);

		random = rand() % 115 + 1;
		ifstream inn("..\\StudentData\\Surname.txt");
		for (int j = 0; j < random; j++) getline(inn, surname);

		age = rand() % 6 + 18;

		st.push_back(Student{ name, surname, age });
	}

	system("cls");
	cout << "All students: " << endl << endl;
	for (int i = 0; i < st.size(); i++) cout << st[i];
	Sleep(5000);
	
	for (int i = 0; i < n; i++) qr.Add(st[i]);

	system("cls");
	PrintExam(qr, n, st, grade, FirstExam);
	RewritingQueue(qr, st, &n, FirstExam);

	system("cls");
	PrintExam(qr, n, st, grade, SecondExam);
	RewritingQueue(qr, st, &n, SecondExam);

	system("cls");
	PrintExam(qr, n, st, grade, ThirdExam);

	qr.Clear();
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i].result[2] <= 2.5)
		{
			st.erase(st.begin() + i);
			i = 0;
		}
	}

	cout << "Students who passed all (3) exams: " << endl;
	for (auto &elem : st)
	{
		cout << elem;
		cout << "All grade: " << "\n1.  " << elem.result[0] << "\n2.  " << elem.result[1] << "\n3.  " << elem.result[2] << endl << endl;
		cout << "Total grade: " << elem.result[0] + elem.result[1] + elem.result[2] << endl;
	}

	return 0;
}


void PrintExam(QueueRing<Student>& qr, int n, vector<Student>& st, vector<double> grade, int NE)
{
	for (int i = 0; i < n; i++)
	{
		grade.clear();
		grade.push_back(rand() % 4 + 1 + rand() % 100 / 100.0);
		qr.Extract(grade, NE);
		st[i].result[NE] = grade[0];

		cout << "Exam takers: " << endl;
		qr.Show();
		Sleep(5000);
		system("cls");
	}
}

void RewritingQueue(QueueRing<Student>& qr, vector<Student>& st, int* n, int NE)
{
	qr.Clear();
	for (int i = 0; i < *n; i++)
	{
		if (st[i].result[NE] <= 2.5)
		{
			st.erase(st.begin() + i);
			i = 0;
			(*n)--;
		}
	}

	qr.ReInit(*n);
	for (int i = 0; i < *n; i++) qr.Add(st[i]);
}
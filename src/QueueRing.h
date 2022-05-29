#pragma once
#include "Header.h"
#include "Student.h"

template <class T>
class QueueRing
{
	T* Wait;
	int MaxQueueLength;
	int QueueLength;

public:

	QueueRing(int m);
	~QueueRing();
	void ReInit(int m);
	void Add(T st);
	bool Extract(vector<double> grade, int n);
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	void Show();

};


template <class T> void QueueRing<T>::Show()
{

	for (int i = 0; i < QueueLength; i++)
	{
		cout << Wait[i] << endl;
		if (Wait[i].result[0] != 0)
		{
			cout << "First grade: " << Wait[i].result[0] << endl;
		}
		if (Wait[i].result[1] != 0)
		{
			cout << "Second grade: " << Wait[i].result[1] << endl;
		}
		if (Wait[i].result[2] != 0)
		{
			cout << "Third grade: " << Wait[i].result[2] << endl;
		}

		SetColor(12, 0);
		cout << "===================================================\n";
		SetColor(15, 0);
	}
}

template <class T> QueueRing<T>::~QueueRing()
{
	delete[]Wait;
}

template <class T> void QueueRing<T>::ReInit(int m)
{
	MaxQueueLength = m;
	Wait = new Student[MaxQueueLength];
	QueueLength = 0;
}

template <class T> QueueRing<T>::QueueRing(int m)
{
	MaxQueueLength = m;
	Wait = new Student[MaxQueueLength];
	QueueLength = 0;
}

template <class T> void QueueRing<T>::Clear()
{
	QueueLength = 0;
}

template <class T> bool QueueRing<T>::IsEmpty()
{
	return QueueLength == 0;
}

template <class T> bool QueueRing<T>::IsFull()
{
	return QueueLength == MaxQueueLength;
}

template <class T> int QueueRing<T>::GetCount()
{
	return QueueLength;
}

template <class T> void QueueRing<T>::Add(T st)
{

	if (!IsFull()) Wait[QueueLength++] = st;
}

template <class T> bool QueueRing<T>::Extract(vector<double> grade, int n)
{

	if (!IsEmpty())
	{

		Student temp = Wait[0];
		for (int i = 1; i < QueueLength; i++)
		{
			Wait[i - 1] = Wait[i];
		}

		Wait[QueueLength - 1] = temp;
		if (n == FirstExam)
		{
			Wait[QueueLength - 1].result[0] = grade[0];
		}
		if (n == SecondExam)
		{
			Wait[QueueLength - 1].result[1] = grade[0];
		}
		if (n == ThirdExam)
		{
			Wait[QueueLength - 1].result[2] = grade[0];
		}
		return 1;
	}
	else return 0;
}
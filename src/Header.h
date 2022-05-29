#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <string>
#include <fstream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::ifstream;
using std::ostream;
using std::vector;

void SetColor(int text, int background);

enum numEXAM
{
	FirstExam,
	SecondExam,
	ThirdExam
};
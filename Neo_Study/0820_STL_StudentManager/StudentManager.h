#pragma once
#include "Student.h"
#include <vector>
using namespace std;

class StudentManager
{
private:
	vector<Student*> st;
	shared_ptr<StudentManager> sptr = make_shared<StudentManager>();
public:

	void LoadFile();
	void InputStudent();
	void OutputStudent();
	void SaveFile();
	void PrintMenu();
	void Sort();
	void Less();
	void Greater();

	StudentManager();
	~StudentManager();
};


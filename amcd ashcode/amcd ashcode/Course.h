#pragma once
#include <vector>

using namespace std;


class Course
{
public:
	Course(int, int, int, int, int, int, int);
	~Course();
	
	int getId();
	int a, b, x, y, s, f; // a,b = start. x,y = finish. s = time start. f = time finish

	void affiche();
private:
	int id;
};


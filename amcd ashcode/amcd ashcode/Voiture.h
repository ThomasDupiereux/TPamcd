#pragma once
#include "Course.h"
#include <vector>

using namespace std;

class Voiture
{
public:
	Voiture(int);
	~Voiture();
	void SelectCourse(vector<Course>&);
	bool getStatut();
	void affiche();

	int tour;

private:
	int id;
	bool onCourse;
	int a, b;
	vector<int> lesCourses;
};


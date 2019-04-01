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
	void affiche2();
	int tour;
	bool operator<(Voiture v);
	
private:
	bool onCourse;
	int a, b;
	int id;
	vector<int> lesCourses;
};

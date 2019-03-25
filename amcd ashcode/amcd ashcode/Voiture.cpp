#include "Voiture.h"
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;


Voiture::Voiture(int id)
{
	this->id = id;
	a = 0;
	b = 0;
	tour = 0;
	onCourse = true;
}


Voiture::~Voiture()
{
}

int dist(int a, int b, int x, int y) {
	return abs(a - x) + abs(b - y);
}

void Voiture::SelectCourse(vector<Course> &lesCourses)
{
	int leChoix = 0;
	int ta = 0;
	int ti = 0;
	int t = 0;

	for (int i = 0; i < (int)lesCourses.size(); i++) {
		ta = tour + dist(a, b, lesCourses[i].a, lesCourses[i].b);
		ti = max(ta, lesCourses[i].s);

		// test possibilité
		if ((ti < t || t==0) && (ti + dist(lesCourses[i].a, lesCourses[i].b, lesCourses[i].x, lesCourses[i].y) <= lesCourses[i].f)) {
			t = ti;
			leChoix = i;
		}
	}

	if (t == 0) {
		onCourse = false;
	}
	else {
		Course laCourse = lesCourses[leChoix];
		lesCourses.erase(lesCourses.begin() + leChoix);

		a = laCourse.x;
		b = laCourse.y;
		tour += t + dist(laCourse.a, laCourse.b, laCourse.x, laCourse.y);
		this->lesCourses.push_back(laCourse.getId());
	}

}

bool Voiture::getStatut()
{
	return onCourse;
}

void Voiture::affiche()
{
	cout << lesCourses.size() << " ";
	for (int i = 0; i < (int)lesCourses.size(); i++) {
		cout << lesCourses[i]<< " ";
	}
	cout << endl;
}

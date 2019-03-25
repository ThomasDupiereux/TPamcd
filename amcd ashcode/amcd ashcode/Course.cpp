#include "Course.h"
#include <iostream>



Course::Course(int a, int b, int x, int y, int s, int f, int ID)
{
	this->a = a;
	this->b = b;
	this->x = x;
	this->y = y;
	this->s = s;
	this->f = f;
	this->id = ID;
}


Course::~Course()
{
}

int Course::getId()
{
	return this->id;
}

void Course::affiche() {
	cout << a << "," << b << " " << x << "," << y << endl;
}
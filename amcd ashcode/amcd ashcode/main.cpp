#include <iostream>
#include <fstream>
#include <vector>
#include <list> 
#include "Voiture.h"
#include "Course.h"
#include <algorithm>    // std::sort
using namespace std;

bool Compare(Voiture A, Voiture B) {
	return A.tour < B.tour;
}

int main() {
	int R, C, F, N, B, T;
	vector <Course> listCourses;

	ifstream fichier("e_high_bonus.in");
	if (fichier) {
		int a, b, c, d, e, f;
		int i = 0;
		fichier >> R;
		fichier >> C;
		fichier >> F;
		fichier >> N;
		fichier >> B;
		fichier >> T;
		while (i < N) {
			fichier >> a;
			fichier >> b;
			fichier >> c;
			fichier >> d;
			fichier >> e;
			fichier >> f;
			Course course(a, b, c, d, e, f, i);
			i++;
			listCourses.push_back(course);
		}
		fichier.close();

	}
	else {
		cout << "Impossible ouvrir fichier\n";

	}


	vector<Voiture> lesVoitures;
	vector<Voiture> lesVoituresFinies;
	for (int i = 0; i < F; i++) {
		Voiture laVoiture(i+1);
		lesVoitures.push_back(laVoiture);
	}

	for (int i = 0; i < (int)lesVoitures.size(); i++)
	{
		lesVoitures[i].affiche();
	}
	cout << "============================" << endl;
	//int comp = 0;
	//while (comp < F && listCourses.size()>0) {
	while (lesVoitures.size()>0 && listCourses.size()>0){
		lesVoitures[0].SelectCourse(listCourses);
		sort(lesVoitures.begin(), lesVoitures.end());
		//lesVoitures[0].affiche();
		
		/*for (int i = 0; i < (int)lesVoitures.size(); i++)
		{
			lesVoitures[i].affiche2();
		}
		cout << "=============" << endl;
		*/
		if (!lesVoitures[0].getStatut())
		{
			//comp++;
			lesVoituresFinies.push_back(lesVoitures[0]);
			lesVoitures.erase(lesVoitures.begin());
		}
	}
	cout << "============================" << endl;
	for (int i = 0; i < (int)lesVoituresFinies.size(); i++)
	{
		lesVoituresFinies[i].affiche();
	}
	
	system("pause");
	return 0;
}
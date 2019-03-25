#include <iostream>
#include <fstream>
#include "Course.h"
#include "Voiture.h"
#include <vector>
#include <list> 
#include <algorithm>    // std::sort
using namespace std;

bool Compare(Voiture A, Voiture B) {
	return A.tour < B.tour;
}

int main() {
	int R, C, F, N, B, T;
	vector <Course> lesCourses;



	ifstream fichier("b_should_be_easy.in");
	if (fichier) {
		int a, b, c, d, e, f;
		int i = 0;
		fichier >> R;
		fichier >> C;
		fichier >> F;
		fichier >> N;
		fichier >> B;
		fichier >> T;
		while (/*!fichier.eof()*/ i<N) {
			fichier >> a;
			fichier >> b;
			fichier >> c;
			fichier >> d;
			fichier >> e;
			fichier >> f;
			Course course(a, b, c, d, e, f, i);
			i++;
			lesCourses.push_back(course);
		}
		fichier.close();

	}
	else {
		cout << "Impossible ouvrir fichier\n";

	}
	//lesCourses.erase(lesCourses.end());

	vector<Voiture> lesVoitures;
	vector<Voiture> lesVoituresFinies;
	for (int i = 0; i < F; i++) {
		Voiture laVoiture(i + 1);
		lesVoitures.push_back(laVoiture);
	}
	//cout << lesVoitures.size(); // check
	int test = 0;
	/*while ((int)lesVoitures.size() > 0 || (int)lesCourses.size() > 0) {
		//list<Voiture>::iterator it;

		cout << (int)lesCourses.size() << endl;
		if((int)lesCourses.size()>0)
			lesVoitures[0].SelectCourse(lesCourses);
		if (lesVoitures[0].getStatut() == false) {
		//if (test == 2) {
			lesVoituresFinies.push_back(lesVoitures[0]);
			lesVoitures.erase(lesVoitures.begin());
		}
		//cout << test;
		}
		sort(lesVoitures.begin(), lesVoitures.end(), Compare);
		//lesVoitures.sort();
	//cout << lesVoituresFinies.size(); // check
	*/
	int comp = 0;
	while (comp <100 && lesCourses.size()>0) {
		lesVoitures[comp].SelectCourse(lesCourses);
		lesVoitures[comp].affiche();
		if (!lesVoitures[comp].getStatut())
			comp++;
	}
	cout << "============================" << endl;
	for(int i = 0; i < (int)lesVoitures.size(); i++)
	{
		lesVoitures[i].affiche();
	}

	system("pause");
	return 0;
}
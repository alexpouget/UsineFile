#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include "File.cpp"
#include "Piece.h"
#include "Axe.h"
#include "Jupe.h"
#include "Tete.h"
#include "Piston.h"

using namespace std;

mutex locker;
int mp[4] = { 0,0,0,0 };

void remplirFile(File<Tete> &mt, File<Axe> &ma, File<Jupe> &mj) {
	for (int i = 0; i < 1000; i++) {
		int random = rand() % 3;
		if (0 == random) {
			Tete p;
			p.setId(i);
			locker.lock();
			mt.enfiler(p);
			locker.unlock();
		}
		else if (1 == random)
		{
			Jupe p;
			p.setId(i);
			locker.lock();
			mj.enfiler(p);
			locker.unlock();
		}
		else
		{
			Axe p;
			p.setId(i);
			locker.lock();
			ma.enfiler(p);
			locker.unlock();
		}
	}
	

}

template <typename T>
void usinePiece(File<T> &fileIn, File<T> &fileOut, int time) {
	while (fileOut.taille()<100) {
		if (!fileIn.estVide()) {
			this_thread::sleep_for(chrono::seconds(time));
			locker.lock();
			fileOut.enfiler(fileIn.defiler());
			locker.unlock();
		}
	}
	return;
}

void depannage(int &m,int time) {
	this_thread::sleep_for(chrono::seconds(time));
	//m = 0;

}

void Assemble(int &m) {
	this_thread::sleep_for(chrono::seconds(1));
	//possible panne
	if (0 == rand() % 4) {
		m = 1;
		int sec = (rand() % 4) + 5;
		thread t(depannage, ref(m), sec);
		t.join();
	}
	m = 0;

}

void usinePiston(File<Tete> &mt_usine, File<Axe> &ma_usine, File<Jupe> &mj_usine,File<Piston> &pt) {
	
	int i = 0;
	while(100 > pt.taille()) {
		while(mj_usine.estVide() || ma_usine.estVide() || mt_usine.estVide()) {
			//tant que pas de piece dispo dans les usines.
		}
		while (0 != mp[0] && 0 != mp[1] && 0 != mp[2] && 0 != mp[3]) {
			//tant que pas de machine en etat de fonctionnement
		}
		for (int y = 0; y < 4; y++) {
			if (0 == mp[y]) {
				
				//lock variable multithread
				locker.lock();
				pt.enfiler(Piston(i, ma_usine.defiler(), mj_usine.defiler(), mt_usine.defiler()));
				locker.unlock();

				i++;

				thread t(Assemble, ref(mp[y]));
				t.detach();
				
				break;
			}
		}
	}
}

int main()
{
	File<Tete> mt;
	File<Jupe> mj;
	File<Axe> ma;
	File<Tete> mt_usine;
	File<Jupe> mj_usine;
	File<Axe> ma_usine;
	File<Piston> pt;

	chrono::steady_clock::time_point start = chrono::steady_clock::now();
	
	remplirFile(mt,ma,mj);
	
	cout << mt << endl;
	//passer la reference pas une copie

	thread t(usinePiece<Axe>, ref(ma), ref(ma_usine), 2);
	thread t1(usinePiece<Jupe>, ref(mj), ref(mj_usine), 3);
	thread t2(usinePiece<Tete>, ref(mt), ref(mt_usine), 2);
	thread t3(usinePiston, ref(mt_usine), ref(ma_usine), ref(mj_usine), pt);
	
	t.detach();
	cout << "start usine Axe" << endl;
	t1.detach();
	cout << "start usine Jupe" << endl;
	t2.detach();
	cout << "start usine Tete" << endl;
	t3.join();
	cout << "start Assemblage Pistons" << endl;
	//time calcul
	chrono::steady_clock::time_point stop = chrono::steady_clock::now();
	chrono::steady_clock::duration time = stop - start ;
	
	cout <<"duree : "<< chrono::duration_cast<chrono::seconds>(time).count() <<" second"<< endl;
	t.~thread();
	t1.~thread();
	t2.~thread();
	system("PAUSE");
	return 0;
}


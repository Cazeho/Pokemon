#include "Pokemon.h"
#include <iostream>
using namespace std;


void powerup(Pokemon* p) {
	p->cp = p->cp * 1.25;


}
void evolve(Pokemon* p) {
	p->evolution = p->evolution + 1;

}



void display(const Pokemon p) {
	cout << "PV : " << p.pv << endl;
	cout << "XP : " << p.xp << endl;
	cout << "CP : " << p.cp << endl;
	
	cout << "CP : " << p.cp << endl;
	cout << "EVOLVE : " << p.evolution << endl;




}

void pikachu() {
	Pokemon pikachu;
	pikachu.xp = 2;
	pikachu.pv = 50;
	pikachu.evolution = 0;
	pikachu.cp = 1;


	Pokemon* ptr_pikachu = &pikachu;

	powerup(ptr_pikachu);
	evolve(ptr_pikachu);
	evolve(ptr_pikachu);

	display(pikachu);
}


void Custom_rand(){
	string Names[5] = { "a", "b", "C", "d", "e" };
	int randomName = rand() % 5;
	cout<< Names[randomName]<<endl;
}








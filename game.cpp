#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <MMsystem.h>
#include "Pokemon.h"

using namespace std;










////////
char map[15][25] = {"#######################",
				    "#        **           #",
				    "#            @        #",
				    "#                     #",
					"#                     #",
					"#                     #",
					"#                     #",
					"#                     #",
					"#                     #",
					"#   $                 #",
					"#                     #",
					"#                     #",
					"#            *        #",
					"#                    H#",
				    "#######################"

	//4,5


};

//
char map2[15][25] = { "#######################",
					"#        ***    **    #",
					"#            @        #",
					"#                     #",
					"#   $$                #",
					"#                     #",
					"#                     #",
					"#                     #",
					"#                     #",
					"#   $                 #",
					"#                     #",
					"#                     #",
					"#            *        #",
					"#                    H#",
					"#######################"

	//4,5


};
const int gamespeed = 100;
int level;
bool stopgame = false;
int health = 100;
int point = 0;
bool exit_door = false;
int entry;

void map_level() {
	
	cout << R"(
				############################################
				########___#################################
				########| |#################################
				#########*##################################
				#########*##################################
				#########***********(1)***********(2)******#
				##########################################*#
				##########################################*#
				##################################*********#
				^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^--^^^^^^^^
				^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^--^^^^^^^^
				^^^^^^^^^^^|||||||||||||||||||||||--^^^^^^^^
				^^^^^^^^^^^--^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
				^^^^^^^^^^^##########^^^^^^^^^^^^^^^^^^^^^^^
				^^^^^^^^^^^####/\####^^^^^^^^^^^^^^^^^^^^^^^^
				^^^^^^^^^^^####[]####^^^^^^^^^^^^^^^^^^^^^^^^
				^^^^^^^^^^^##########^^^^^^^^^^^^^^^^^^^^^^^^
        )";
	cout << "\n" << endl;


}

void fctswitch() {
	
	cout << "Choississez votre level" << endl;
	cout << "1: Level 0" << endl;
	cout << "2: Level 1" << endl;
	cout << "3: Level 2" << endl;
	cout << "4: Level F" << endl;
	

	do {
		cin >> level;
		if (level !=1 && level !=2 && level !=3 && level !=4) {
			cout <<"mauvais choix, saisir 1,2,3 et 4" << endl;
		}
	} while (level != 1 && level != 2 && level != 3 && level != 4);


}






int main() {

	//music
	

	//objet
	//struct pokemon{
		//string name;
		//int pv;
		//int energy=10;
		//int attack;
		//int niveau;
		//int faiblesse;
		//int resistance;
	
	//}player, Computer ;

	//cout << player.energy << endl;

	//prob -> objet poke decouverte + custom random
	
	pikachu();
	Custom_rand();
	//////////////////
	PlaySound(TEXT("poke.wav"), NULL, SND_ASYNC);

	//intro
	system("Color 80");
	cout << R"(
				  _ __ ___ | | _____ _ __ ___ ___ _ __  
			 | '_ \ / _ \ | | / / _ \ '_ `_ \ / _ \ | '_ \
			 | | _) | (_) | <__ / | | | | | (_) | | | |
			 | .__ / \ ___ / | _ | \ _ \ ___ | _ | | _ | | _ | \ ___ / | _ | | _ |
			 | _ |          
        )";
	cout << "\n" << endl;

	
	

	//
	cout << "1: Jouer" << endl;
	cout << "2: Regles" << endl;
	cout << "3: Credit" << endl;
	cin >> entry;
	

	switch (entry) {
	case 1:
		map_level();
		fctswitch();
		break;



	}

	

	//
	while (stopgame == false && level == 1) {
		system("cls");
		//
		
		for (int i = 0;i < 15;i++) {
			for (int x = 0;x < 25;x++) {
				switch (map[i][x]) {
				case '#': {
					map[i][x] = 219;
				}break;

				case '@':
				{
					if (GetAsyncKeyState(VK_UP) != 0) {
						int i2 = (i - 1);
						switch (map[i2][x]) {
						case ' ':
						{
							map[i][x] = ' ';
							i -= 1;
							map[i2][x] = '@';

						}break;

						case '*': {
							point += rand() % 20;
							map[i][x] = ' ';
							i -= 1;
							map[i2][x] = '@';
						}break;
						case '$': {
							health -= 1;

						}break;
						case 'H': {

							exit_door = true;
						}
						}
					}
					if (GetAsyncKeyState(VK_DOWN) != 0) {
						int i2 = (i + 1);
						switch (map[i2][x]) {
						case ' ':
						{
							map[i][x] = ' ';
							i += 1;
							map[i2][x] = '@';

						}break;
						case '*': {
							point += rand() % 20 ;
							map[i][x] = ' ';
							i -= 1;
							map[i2][x] = '@';
						}break;
						case '$': {
							health -= 1;
							
						}break;
						case 'H': {
							
							exit_door = true;
						}
						}
					}
					if (GetAsyncKeyState(VK_RIGHT) != 0) {
						int x2 = (x + 1);
						switch (map[i][x2]) {
						case ' ':
						{
							map[i][x] = ' ';
							i -= 0;
							map[i][x2] = '@';

						}break;

						case '*': {
							point += rand() % 20;
							map[i][x] = ' ';
							i -= 0;
							map[i][x2] = '@';
						}break;


						case '$': {
							health -= 1;
						}break;
						case 'H': {

							exit_door = true;
						}
						}
					}


					if (GetAsyncKeyState(VK_LEFT) != 0) {
						int x2 = (x - 1);
						switch (map[i][x2]) {
						case ' ':
						{
							map[i][x] = ' ';
							i -= 0;
							map[i][x2] = '@';

						}break;
						
						case '*': {
							point += rand() % 20;
							map[i][x] = ' ';
							i -= 0;
							map[i][x2] = '@';
						}break;


						case '$': {
							health -= 1;
						}break;
						case 'H': {

							exit_door = true;
						}
						}
					}


				}
				}
			}
		}
		if (health > 0 && exit_door != true) {
			cout << "salut" << endl;
			for (int i = 0;i < 15;i++) {
				cout << map[i] << endl;
			}
			cout << "health: "<< health << " level: " << level - 1 << "     point: " << point << endl;
		}
		if (health <= 0) {
			printf("Vous avez perdus");

		}
		if (exit_door == true) {
			system("cls");
			fctswitch();

			while (level == 2) {
				printf("ok");
			}

		}
		

	}
	


	while (stopgame == false && level == 2) {
		system("cls");
		//

		for (int i = 0;i < 15;i++) {
			for (int x = 0;x < 25;x++) {
				switch (map2[i][x]) {
				case '#': {
					map2[i][x] = 219;
				}break;

				case '@':
				{
					if (GetAsyncKeyState(VK_UP) != 0) {
						int i2 = (i - 1);
						switch (map2[i2][x]) {
						case ' ':
						{
							map2[i][x] = ' ';
							i -= 1;
							map2[i2][x] = '@';

						}break;

						case '*': {
							point += rand() % 20;
							map2[i][x] = ' ';
							i -= 1;
							map2[i2][x] = '@';
						}break;
						case '$': {
							health -= 1;

						}break;
						case 'H': {

							exit_door = true;
						}
						}
					}
					if (GetAsyncKeyState(VK_DOWN) != 0) {
						int i2 = (i + 1);
						switch (map2[i2][x]) {
						case ' ':
						{
							map2[i][x] = ' ';
							i += 1;
							map2[i2][x] = '@';

						}break;
						case '*': {
							point += rand() % 20;
							map2[i][x] = ' ';
							i -= 1;
							map2[i2][x] = '@';
						}break;
						case '$': {
							health -= 1;

						}break;
						case 'H': {

							exit_door = true;
						}
						}
					}
					if (GetAsyncKeyState(VK_RIGHT) != 0) {
						int x2 = (x + 1);
						switch (map2[i][x2]) {
						case ' ':
						{
							map2[i][x] = ' ';
							i -= 0;
							map2[i][x2] = '@';

						}break;
						case '*': {
							point += rand() % 20;
							map2[i][x] = ' ';
							i -= 0;
							map2[i][x2] = '@';
						}break;
						case '$': {
							health -= 1;
						}break;
						case 'H': {

							exit_door = true;
						}
						}
					}


					if (GetAsyncKeyState(VK_LEFT) != 0) {
						int x2 = (x - 1);
						switch (map2[i][x2]) {
						case ' ':
						{
							map2[i][x] = ' ';
							i -= 0;
							map2[i][x2] = '@';

						}break;

						case '*': {
							point += rand() % 20;
							map2[i][x] = ' ';
							i -= 0;
							map2[i][x2] = '@';
						}break;

						case '$': {
							health -= 1;
						}break;
						case 'H': {

							exit_door = true;
						}
						}
					}


				}
				}
			}
		}
		if (health > 0 && exit_door != true) {
			cout << "salut" << endl;
			for (int i = 0;i < 15;i++) {
				cout << map2[i] << endl;
			}
			cout <<"health: "<< health << "           level: " << level - 1 << "     point: " << point << endl;
		}
		if (health <= 0) {
			printf("Vous avez perdus");

		}
		if (exit_door == true) {
			system("cls");
			fctswitch();

		}

	}
	
	return 0;
}
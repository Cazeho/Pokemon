#pragma once
#include <string>
enum PokemonType { Normal, Fighting, Flying, Poison, Ground, Rock, Bug, Ghost, Steel, Fire, Grass, Water, Electric, Psychic, Ice, Dragon, Dark, Fairy };

typedef struct Pokemon {
    char nom;
    int xp;
    int evolution;
    int pv;
    double cp;
} Pokemon;

void pikachu();

void evolve(Pokemon* p);//

void powerup(Pokemon* p);//fait

void display(const Pokemon p);//fait


void Custom_rand();




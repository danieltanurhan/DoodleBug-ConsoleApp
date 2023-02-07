#include "Organism.h"
#include <iostream>

using namespace std;

Organism::Organism() {
	xPosition = 0;
	yPosition = 20;
	life = 0;
}

Organism::Organism(int x, int y) {
	xPosition = x;
	yPosition = y;
	life = 0;
}

void Organism::move(char** move) {
	cout << "base move" << endl;
}
bool Organism::reproduce(char** grid) {
	cout << "base reproduce" << endl;
	return false;
}
bool Organism::starve(char** grid) {
	cout << "base starve" << endl;
	return false;
}

void Organism::setX(int x) {
	xPosition = x;
}

void Organism::setY(int y) {
	yPosition = y;
}

void Organism::setLife() {
	life++;
}

int Organism::getX() {
	return xPosition;
}
int Organism::getY() {
	return yPosition;
}
int Organism::getLife() {
	return life;
}
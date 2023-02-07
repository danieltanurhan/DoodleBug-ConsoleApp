#include "Doodlebug.h"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

const int SIZE = 20;

Doodlebug::Doodlebug() :Organism() {
	//index = 0;
	srand(time(NULL));

};

Doodlebug::Doodlebug(int x, int y) :Organism(x, y) {
	//index = i;
}

void Doodlebug::move(char** grid) {

	int r = rand() % 4;
	//cout << "Random number for move: " << r << endl;
	switch (r % 4) {
	case 0: //move down
		if (getX() + 1 > SIZE || grid[getX() + 1][getY()] == 'X') {
			//cout << "down blocked" << endl;
		}
		else {
			if (grid[getX()][getY()] == 'o') {
				eaten++;
			}
			grid[getX()][getY()] = '+';
			setX(getX() + 1);
			grid[getX()][getY()] = 'X';
		}
		break;
	case 1: //move left
		if (getY() - 1 < 0 || grid[getX()][getY() - 1] == 'X') {
			//cout << "left blocked" << endl;
		}
		else {
			if (grid[getX()][getY()] == 'o') {
				eaten++;
			}
			grid[getX()][getY()] = '+';
			setY(getY() - 1);
			grid[getX()][getY()] = 'X';
		}

		break;
	case 2: //move up
		if (getX() - 1 < 0 || grid[getX() - 1][getY()] == 'X') {
			//cout << "up is blocked" << endl;
		}
		else {
			if (grid[getX()][getY()] == 'o') {
				eaten++;
			}
			grid[getX()][getY()] = '+';
			setX(getX() - 1);
			grid[getX()][getY()] = 'X';
		}
		break;
	case 3: //move right
		if (getY() + 1 > SIZE || grid[getX()][getY() + 1] == 'X') {

		}
		else {
			if (grid[getX()][getY()] == 'o') {
				eaten++;
			}
			grid[getX()][getY()] = '+';
			setY(getY() + 1);
			grid[getX()][getY()] = 'X';

		}

		break;
	default:
		cout << "randomizer error" << endl;
		break;
	}
}

bool Doodlebug::reproduce(char** grid) {
	if (getLife() % 8 == 0) {
		return true;
	}
	return false;
}

bool Doodlebug::starve(char** grid) {
	bool s;
	//check down
	if (getX() + 1 < SIZE || grid[getX() + 1][getY()] == '+') {
		s = false;
	}
	//check up
	else if (getX() - 1 >= 0 || grid[getX() - 1][getY()] == '+') {
		s = false;
	}
	//check left
	else if (getY() - 1 >= 0 || grid[getX()][getY() - 1] == '+') {
		s = false;
	}
	//check right
	else if (getY() + 1 < SIZE || grid[getX()][getY() + 1] == '+') {
		s = false;
	}
	else {
		s = true;
	}

	if (s) {
		return true;
	}
	else {
		setLife();
		return false;
	}
}
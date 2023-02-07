#include "World.h"
#include <iostream>
#include <vector>

using namespace std;

const int ANTLISTSIZE = 35;
const int DOODLEBUGSIZE = 6;

World::World() {

	grid = new char* [SIZE];
	antList = vector<Ants>();
	doodleList = vector<Doodlebug>();

	for (int i = 0; i < SIZE; i++) {
		*(grid+i) = new char[SIZE];
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			grid[i][j] = '+';
		}
	}

	int j = 0;
	for (int i = 0; i < ANTLISTSIZE; i++) {
		if (i % 20 == 2) {
			j += 1;
		}
		antList.push_back( Ants(i % 20, j % 20));
		grid[i%20][j % 20] = 'o';
	}
	j = 0;
	for (int i = 0; i < DOODLEBUGSIZE; i++) {
		j++;
		doodleList.push_back(Doodlebug(i*2 % 20, j*2 % 20));
		grid[i % 20][j*2 % 20] = 'X';
	}

}

void World::removeDoodle(unsigned i) {
	grid[doodleList[i].getX()][doodleList[i].getY()] = '+';
	doodleList.erase(doodleList.begin() + i);
}

void World::addDoodle(int x, int y) {
	doodleList.push_back(Doodlebug(x, y));
	grid[x][y] = 'X';
}

void World::removeAnt(unsigned i) {
	grid[antList[i].getX()][antList[i].getY()] = '+';
	antList.erase(antList.begin() + i);
}

void World::addAnt(int x, int y) {
	
	antList.push_back(Ants(x, y));
	grid[x][y] = 'o';
}

char**  World::getGrid() {
	return grid;
}
void World::makeGrid() {
	for (int i = 0; i < ANTLISTSIZE; i++) {
		grid[antList[i].getX()][antList[i].getY()] = 'o';
	}
}

void World::print() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << grid[i][j];
		}
		cout << "\n";
	}
	cout << "\n\n\n" << endl;
}

int World::xNeighbor(Ants a) {
	if (a.getX() + 1 < SIZE || grid[a.getX() + 1][a.getY()] == '+') {
		return a.getX()+1;
	}
	else if (a.getX() - 1 >= 0 || grid[a.getX() - 1][a.getY()] == '+') {
		return a.getX() - 1;
	}
	else {
		return -1;
	}
}

int World::yNeightbor(Ants a) {
	if (a.getY() - 1 >= 0 || grid[a.getX()][a.getY() - 1] == '+') {
		return a.getY() - 1;
	}
	else if (a.getY() + 1 < SIZE || grid[a.getX()][a.getY() + 1] == '+') {
		return a.getY() + 1;
	}
	else {
		return -1;
	}
}

int World::xNeighbor(Doodlebug a) {
	if (a.getX() + 1 < SIZE || grid[a.getX() + 1][a.getY()] == '+') {
		return a.getX() + 1;
	}
	else if (a.getX() - 1 >= 0 || grid[a.getX() - 1][a.getY()] == '+') {
		return a.getX() - 1;
	}
	else {
		return -1;
	}
}

int World::yNeightbor(Doodlebug a) {
	if (a.getY() - 1 >= 0 || grid[a.getX()][a.getY() - 1] == '+') {
		return a.getY() - 1;
	}
	else if (a.getY() + 1 < SIZE || grid[a.getX()][a.getY() + 1] == '+') {
		return a.getY() + 1;
	}
	else {
		return -1;
	}
}

void World::runAnts() {
	for (int as = 0; as < antList.size(); as++) {
		antList.at(as).move(grid);
		if (antList.at(as).starve(grid)) {
			removeAnt(as);
		}
		else if (antList.at(as).reproduce(grid)) {
			if (xNeighbor(antList.at(as)) != -1) {

				addAnt(xNeighbor(antList.at(as)), antList[as].getY());
			}
			else {
				addAnt(antList[as].getX(), yNeightbor(antList.at(as)));
			}
		}
	}
}

void World::runDoodles() {
	for (int as = 0; as < doodleList.size(); as++) {
		doodleList.at(as).move(grid);
		if (doodleList.at(as).starve(grid)) {
			removeDoodle(as);
		}
		else if (doodleList.at(as).reproduce(grid)) {
			if (xNeighbor(doodleList.at(as)) != -1) {

				addDoodle(xNeighbor(doodleList.at(as)), doodleList[as].getY());
			}
			else {
				addDoodle(doodleList[as].getX(), yNeightbor(doodleList.at(as)));
			}
		}
	}
}

void World::run() {
	//makeGrid();
	print();
	cout << "\n" << endl;
	for (int i = 0; i < 7; i++) {

		runAnts();
		runDoodles();
		
		print();
		cout << "\n" << endl;
	}
}
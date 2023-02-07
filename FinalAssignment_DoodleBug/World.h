#pragma once
#include "Organism.h"
#include "Ants.h"
#include "Doodlebug.h"
#include <vector>
using namespace std;

const int SIZE = 20;
class World
{
private:
	char** grid;
	vector<Ants> antList;
	vector<Doodlebug> doodleList;
public:
	World();
	char**  getGrid();
	void print();
	void makeGrid();
	int xNeighbor(Ants a);
	int yNeightbor(Ants a);
	int xNeighbor(Doodlebug a);
	int yNeightbor(Doodlebug a);
	void removeAnt(unsigned i);
	void addAnt(int x, int y);
	void removeDoodle(unsigned i);
	void addDoodle(int x, int y);
	void run();
	void runAnts();
	void runDoodles();
};


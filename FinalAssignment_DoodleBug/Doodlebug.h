#pragma once
#include "Organism.h"
using namespace std;
class Doodlebug : public Organism
{

private:
	int eaten;
public:
	Doodlebug();
	Doodlebug(int x, int y);
	void move(char** grid);
	bool reproduce(char** grid);
	bool starve(char** grid);

};


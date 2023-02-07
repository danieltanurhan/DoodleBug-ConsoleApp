#pragma once
#include "Organism.h"
using namespace std;
class Ants : public Organism
{

private:
	
public:
	Ants();
	Ants(int x, int y);
	void move(char** grid);
	bool reproduce(char** grid);
	bool starve(char** grid);

};


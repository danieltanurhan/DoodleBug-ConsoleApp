#pragma once
using namespace std;
class Organism
{
private:
	int xPosition, yPosition;
	int life;
public:
	Organism();
	Organism(int x, int y);
	virtual void move(char** grid) = 0;
	virtual bool reproduce(char** grid) = 0;
	virtual bool starve(char** grid) = 0;
	//mutators
	void setX(int x);
	void setY(int y);
	void setLife();
	//accessors
	int getX();
	int getY();
	int getLife();

};


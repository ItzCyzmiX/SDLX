#include <iostream>
#include <vector>
#include <ctime>


int randInt(int min, int max) {

	srand(time(0));

	int random = ((rand() % max) -1) + min;

	return random;
	
};

int randInt(int max) {

	srand(time(0));

	int random = rand() % (max-1);

	return random;
};

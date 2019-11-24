#include <iostream>
#include "gametetrix.h"
using namespace std;

int main(int argc, char *argv[])
{
	std::cout << "started\n";
	GameTetrix tetrix;

	tetrix.start();
	return 0;
}
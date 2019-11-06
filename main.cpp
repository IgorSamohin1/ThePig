#include "CApp.h"
#include <ctime>

int main(int argc, char* argv[]) {
	srand(time(0));
	CApp theApp;
	int a = theApp.OnExecute();
	return a;
}
#include "helloworld.h"
#include <iostream>

using namespace std;

void helloworld::print() {
	cout << "helloworld" << endl;
}

helloworld::helloworld() {
	cout << "construct" << endl;
}

helloworld::~helloworld() {
	cout << "destruct" << endl;
}
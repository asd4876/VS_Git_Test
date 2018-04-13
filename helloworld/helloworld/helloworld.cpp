#include "helloworld.h"
#include <iostream>

using namespace std;

void helloworld::print() {
	cout << "helloworld" << endl;
}

void helloworld::print() const {
	cout << "const helloworld" << endl;
}
void helloworld::setNum(int num) {
	cout << "construct" << endl;
	num = 100;
	cout << num<<" "<<this->num << endl;
}

helloworld::helloworld():num(1),cint(4),ci(num){
	//num = 1;
	cout << "construct" << endl;
}
int helloworld::si = 2;
helloworld::~helloworld() {
	cout << "destruct" << endl;
}
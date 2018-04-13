#pragma once
class helloworld {
public:
	void print() const;
	void setNum(int num);
	void print();
	helloworld();
	~helloworld();
	int num=3;
	const int cint;
	const int& ci;
	static int si;
};
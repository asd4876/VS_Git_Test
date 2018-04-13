#pragma once
#include <iostream>
using namespace std;
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

class node {
public:
    int val;

    node(int v) :val(v) {
        cout << val << "born" << endl;
    }
    ~node() {
        cout << val << "dead" << endl;
    }
    node(const node& a) {
        val = a.val+2;
        cout << val << "copy born" << endl;
    }
    node& operator=(const node& a) {
        cout << val << "= born" << endl;
        val = a.val;
        return *this;
    }
};
#include "helloworld.h"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
extern const int aaa = 1;
void test() {
    helloworld hello;
    helloworld h2;
    cout << hello.num << endl;
    cout << hello.ci << endl;
    cout << hello.si << endl;
}
void swap(int& a, int& b);
void qsort(vector<int>& data, int l, int h);
void threeqsort(vector<int>& data, int l, int h);
/*
int main() {
    test();
    int xx;
    int yy = 1;
    xx = yy;
    vector<int> data = { 7,8,2,7,3,4,1,0,9 };
    threeqsort(data, 0, data.size() - 1);
    for (auto d : data) cout << d << " ";
    system("pause");
    return 0;
}
*/
void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void qsort(vector<int>& data, int l, int h) {
    if (l >= h) return;
    int i = l + 1;
    int j = h;
    int key = data[l];
    while (i <= j) {
        while (i <= j && data[i] <= key) i++;
        while (i <= j && data[j] > key) j--;
        if (i < j) swap(data[i++],data[j--]);
    }
    swap(data[l],data[j]);
    qsort(data, l, j - 1);
    qsort(data, j + 1, h);
}

void threeqsort(vector<int>& data, int l, int h) {
    if (l >= h) return;
    int t = l;
    int i = l + 1;
    int j = h;
    int key = data[t];
    while (i <= j) {
        if (data[i] == key) {
            i++;
        }
        else if (data[i] < key) {
            swap(data[i++],data[t++]);
        }
        else {
            swap(data[i],data[j--]);
        }
    }
    threeqsort(data, l, t - 1);
    threeqsort(data, j + 1, h);
}
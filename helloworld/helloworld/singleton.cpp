#include <iostream>
#include <cstdlib>
using namespace std;
class singleton {
private:
    singleton():a(100) {
        p = new int[100];
        cout << a << " born" << endl;
    }
    ~singleton() {
        cout << a << "delete" << endl;
        delete[] p;
        p = nullptr;
    }
    singleton(const singleton& a) = delete;
    singleton& operator=(const singleton& a) = delete;
public:
    static singleton & getInstance() {
        static singleton cur;
        return cur;
    }

    int a;
    int* p;
};

void tt() {
    singleton& a = singleton::getInstance();
}
/*
int main() {
    singleton& b = singleton::getInstance();
    system("pause");
    return 0;
}
*/
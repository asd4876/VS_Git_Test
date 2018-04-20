#include <iostream>
#include <cstdlib>
template<typename T>
class sptr {
private:
    T * src;
    size_t* cnt;
public:
    explicit sptr(T* a = nullptr):src(a), cnt(nullptr) {
        if (a) {
            cnt = new size_t(1);
        }
    }
    ~sptr() {
        if(src){
            (*cnt)--;
            if ((*cnt) == 0) {
                delete src;
                delete cnt;
            }
        }
    }
    sptr(const sptr& a) {
        if (this != &a) {
            src = a.src;
            cnt = a.cnt;
            (*cnt)++;
        }
    }
    sptr& operator=(const sptr& a) {
        if (a.src == src) {
            return *this;
        }
        if (src) {
            (*cnt)--;
            if ((*cnt) == 0) {
                delete src;
                delete cnt;
            }
        }
        src = a.src;
        cnt = a.cnt;
        (*cnt)++;
        return *this;
    }
    T& operator*() {
        assert(src == nullptr);
        return *src;
    }
    T* operator->() {
        assert(src == nullptr);
        return src;
    }
    size_t use_count() {
        if(cnt) return *cnt;
        else return 0;
    }
};
extern const int aaa;
int main() {
    std::cout << aaa << std::endl;
    sptr<int> a(new int(1));
    sptr<int> b(a);
    sptr<int> c = a;
    c = b;
    sptr<int> d;
    d = c;
    std::cout << c.use_count() << std::endl;
    system("pause");
    return 0;
}
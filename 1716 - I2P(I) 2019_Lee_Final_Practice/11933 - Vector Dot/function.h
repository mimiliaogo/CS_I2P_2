#include <iostream>

class Vector {
private:
    int v_size;
    int *v;
public:
    Vector() {
        v_size = 0;
        v = NULL;
    }
    Vector(int n) {
        v_size = n;
        v = new int[n];
    }
    ~Vector() {
        delete [] v;
    }
    void read() {
        for (int i = 0; i < v_size; i++) {
            std::cin >> v[i];
        }
    }
    void set(int index, int value) {
        if (index < 0 || index >= v_size) {
            std::cout << "OUT OF BOUND\n";
            return;
        }
        else v[index] = value;
    }
    const int size() const {
        return v_size;
    };

    // return the value of v[index]
    const int operator[](int index) const;

    // Dot product
    int operator*(const Vector& a);
};

// Print the Vector
std::ostream& operator<<(std::ostream& os, const Vector& v);

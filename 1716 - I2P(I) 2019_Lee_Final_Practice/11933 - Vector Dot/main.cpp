#include "function.h"
#include <string>
int main() {
    int m, size;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        std::string op;
        std::cin >> op >> size;
        Vector A(size);
        Vector B(size);
        A.read();
        B.read();
        if (op == "DOT")
            std::cout << A*B  << ' ' << '\n';
    }
    return 0;
}

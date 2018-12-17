#include <iostream>

namespace my {
double pow(double x, int n) {
    if (!n) {
        return 1;
    } else {
        return x * my::pow(x, n - 1);
    }
}

}  // namespace my

int main() {
    std::cout << my::pow(5, 2) << '\n';
}
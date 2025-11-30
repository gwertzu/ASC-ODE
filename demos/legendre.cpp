#include <iostream>
#include <autodiff.hpp>
#include <cmath>
#include <vector>

using namespace ASC_ode;

template <typename T>
void LegendrePolynomials(int n, T x, std::vector<T>& P) {
    if (n < 0) {
        P.clear();
        return;
    }
    P.resize(n + 1);
    P[0] = T(1);
    if (n == 0) return;
    P[1] = x;
    for (int k = 2; k <= n; ++k) {
        P[k] = ((T(2 * k - 1) * x * P[k - 1]) - T(k - 1) * P[k - 2]) / T(k);
    }
}

int main() {
    //Write header
    int n = 5;
    std::cout << "x ";
    for (int i = 0; i <= n; i++) {
        std::cout << "L_" << i << "(x) " << "L'_" << i << "(x) ";
    }
    std::cout << std::endl;

    for (double i = -1; i <= 1; i += 0.01) {
        //std::cout << "-------" << i << "-------" << std::endl;
        std::vector<AutoDiff<1>> polys;
        AutoDiff<1> adx = Variable<0>(i);
        LegendrePolynomials<AutoDiff<1>>(n,adx,polys);
        std::cout << i << " ";
        for (auto elem: polys) {
            std::cout << elem.value() << " " << elem.deriv()[0] << " ";
        }
        std::cout << std::endl;
        /*
        for (auto elem: polys) {
            std::cout << elem << std::endl;
        }
        */
    }
    return 0;
}

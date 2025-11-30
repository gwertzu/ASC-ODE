#include <iostream>
#include <fstream> 

#include <nonlinfunc.hpp>
#include <timestepper.hpp>
#include <implicitRK.hpp>
#include <cmath>

using namespace ASC_ode;


class ElectricNetwork : public NonlinearFunction
{
private:
    double resistivity;
    double capacity;

public:
    ElectricNetwork(double r, double c) : resistivity(r), capacity(c) {}

    size_t dimX() const override { return 3; }
    size_t dimF() const override { return 3; }

    void evaluate(VectorView<double> x, VectorView<double> f) const override
    {
        f(0) = (x(1) - x(0)) / (resistivity * capacity);
        f(1) = x(2);
        f(2) = -x(1) * 10000 * M_PI * M_PI;
    }

    void evaluateDeriv(VectorView<double> x, MatrixView<double> df) const override
    {
        df = 0.0;
        df(0, 0) = -1 / (resistivity * capacity);
        df(0, 1) = 1 / (resistivity * capacity);
        df(1, 2) = 1;
        df(2, 1) = -1 * 10000 * M_PI * M_PI;
    }
};


int main()
{
    double tend = 1;
    int steps = 1000;
    double tau = tend / steps;

    Vector<> y = { 0, 1, 0 };  // initializer list
    auto rhs = std::make_shared<ElectricNetwork>(1.0, 1.0);

    //ExplicitEuler stepper(rhs);
    //ImplicitEuler stepper(rhs);
    //ImprovedEuler stepper(rhs);
    CrankNicolson stepper(rhs);



    std::ofstream outfile("output_electric_network.txt");
    std::cout << 0.0 << "   " << y(0) << "  " << y(1) << "  " << y(2) << std::endl;
    outfile << 0.0 << "   " << y(0) << "  " << y(1) << "  " << y(2) << std::endl;

    for (int i = 0; i < steps; i++)
    {
        stepper.DoStep(tau, y);


        std::cout << (i + 1) * tau << "   " << y(0) << "  " << y(1) << "  " << y(2) << std::endl;
        outfile << (i + 1) * tau << "   " << y(0) << "  " << y(1) << "  " << y(2) << std::endl;
    }
}

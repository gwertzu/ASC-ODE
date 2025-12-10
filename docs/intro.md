# Welcome to ASC-ODE's documentation!


ASC-ODE is is a C++ library for solving ordinary differential equations (ODEs).
The equation is defined by the right hand side function.
ASC-ODE provides various time-steppers which may be used for odes with right hand sides
given by a function object.

A small demo for solving a mass-spring model as first order ODE
\begin{eqnarray*}
y_0^\prime & = & y_1 \\
y_1^\prime & = & -\frac{k}{m} y_0
\end{eqnarray*}
is here:

```cpp
double tend = 4*M_PI;
int steps = 100;
double tau = tend/steps;

Vector<> y = { 1, 0 };  // initial conditions
shared_ptr<NonlinearFunction> rhs = std::make_shared<MassSpring>(mass, stiffness);
  
ExplicitEuler stepper(rhs);

std::cout << 0.0 << "  " << y(0) << " " << y(1) << std::endl;
for (int i = 0; i < steps; i++)
  {
     stepper.DoStep(tau, y);
     std::cout << (i+1) * tau << "  " << y(0) << " " << y(1) << std::endl;
  }
```    

The result of this simulation in phase space is shown here:

```{image} pictures/massspring_phase.png
:width: 40%
:align: center
```




## Installation

Clone ASC-ODE via `git clone`:

    git clone https://github.com/gwertzu/ASC-ODE.git


To configure and build some tests and demos do

```bash
    cd ASC-ODE
    mkdir build
    cd build
    cmake ..
    make
```

## Available time-stepping methods are
 - Explicit Euler
 - Implicit Euler
 - Improved Euler
 - Crank-Nicholson
 - Implicit Runge-Kutta
 - Explicit Runge-Kutta




   

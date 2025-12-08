# Runge-Kutta methods

## implicit Methods
### Gauss-Legendre 2 & two-point Radau
Using the c-coefficients from Gauss-Legendre 2 and two-point Radau IIA for calculating a- and b-coefficients brings following values: 

Radau IIa gives following Output:
c = 0.333333, 1
weight = 1, 1.11022e-16

ComputeABfromC for Radau IIa gives:
a = 0.416667, -0.0833333
[comment]: <> (0.75 0.25 (weights))
b = 0.75, 0.25

same for GaussLegendre2:
a = 0.25, -0.0386751 
[comment]: <> (0.538675, 0.25 (weights))

b = 0.25 -0.0386751 
[comment]: <> (0.538675 0.25 (weights))

As one can see, the a and b coefficients for both schemes are different.

### Gauss-Legendre 3 & three-point Raudau
c-coefficients for different Runge-Kutta schemes can easlily be taken out of [this website](https://en.wikipedia.org/wiki/List_of_Runge%E2%80%93Kutta_methods). Following the a- and b-coefficients for the Gauss-Legendre 3 and three-point Raudau are calculated with this library.
Gauss Legendre 3:
a = 0.138889 -0.0359767 0.00978944 
[comment]: <> (0.300263 0.222222 -0.0224854)
[comment]: <> (0.267988 0.480421 0.138889)

b = 0.138889 -0.0359767 0.00978944 
[comment]: <> (0.300263 0.222222 -0.0224854)
[comment]: <> (0.267988 0.480421 0.138889)

3-point Radau IIa:
a = 0.336001 0.383173 -0.0583286 
[comment]: <> (-0.0551008 0.17626 0.0214456)
[comment]: <> (0.542571 0.36854 0.0888893)
b = 0.542571, 0.36854, 0.0888893

As in the chapter before, the parameter of Gauss-Legendre 3 are three-point Raudau again different, as expected.

# explicit Method
In this package, also an explicit Runge-Kutta method is implemented.
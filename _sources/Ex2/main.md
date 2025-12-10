# Implicit Runge-Kutta methods

The implementation of the implicit Runge-Kutta methods can handle any Butcher tableu. There is also a useful utility included, `ComputeABfromC`, that allows the calculation of the $a$ and $b$ coefficients of such a tableu from the known $c$ coefficients.

## Gauss-Legendre 2 & two-point Radau
Using the $c$-coefficients from Gauss-Legendre 2 and two-point Radau IIA for calculating $a$- and $b$-coefficients give the following values: 

 - For the Radau IIa:
   ```
   c = 0.333333, 1
   weight = 1, 1.11022e-16
   ```

 - `ComputeABfromC` for Radau IIa gives:
   ```
   a = 0.416667, -0.0833333
       0.75 0.25 (weights)
   b = 0.75, 0.25
   ```

 - The same for Gauss-Legendre 2:
   ```
   a = 0.25, -0.0386751 
       0.538675, 0.25 (weights)
   b = 0.25 -0.0386751 
       0.538675 0.25 (weights)
   ```
   FIX: $b$ musn't be a matrix, it should be a vector!!!

As one can see, the $a$ and the $b$ coefficients for the schemes are different.

## Gauss-Legendre 3 & three-point Raudau
$c$-coefficients for different Runge-Kutta schemes can easily be read out of [this website](https://en.wikipedia.org/wiki/List_of_Runge%E2%80%93Kutta_methods). Following the $a$- and $b$-coefficients for the Gauss-Legendre 3 and three-point Raudau are calculated with this library.

 - Gauss-Legendre 3:
   ```
   a = 0.138889 -0.0359767 0.00978944 
       0.300263 0.222222 -0.0224854
       0.267988 0.480421 0.138889
   b = 0.138889 -0.0359767 0.00978944 
   [comment]: <> (0.300263 0.222222 -0.0224854)
   [comment]: <> (0.267988 0.480421 0.138889)
   ```
   FIX: $b$ musn't be a matrix, it should be a vector!!!

 - 3-point Radau IIa:
   ```
   a = 0.336001 0.383173 -0.0583286 
       -0.0551008 0.17626 0.0214456
       0.542571 0.36854 0.0888893
   b = 0.542571, 0.36854, 0.0888893
   ```

As in the section before, the parameter of Gauss-Legendre 3 are three-point Raudau again different, as expected.

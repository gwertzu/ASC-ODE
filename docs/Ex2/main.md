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
   a = 0.249931 -0.038652 
       0.538652 0.250069 (weights)
   b = 0.5, 0.5 
   ```
   FIX: $b$ musn't be a matrix, it should be a vector!!!

As one can see, the $a$ and the $b$ coefficients for the schemes are different.

## Gauss-Legendre 3 & three-point Raudau
$c$-coefficients for different Runge-Kutta schemes can easily be read out of [this website](https://en.wikipedia.org/wiki/List_of_Runge%E2%80%93Kutta_methods). Following the $a$- and $b$-coefficients for the Gauss-Legendre 3 and three-point Raudau are calculated with this library.

 - Gauss-Legendre 3:
   ```
   a = 0.138812 -0.0359386 0.00977867  
       0.300207 0.222293 -0.0225003
       0.267928 0.480525 0.138895
   b = 0.277707, 0.444587, 0.277707
   ```

 - 3-point Radau IIa:
   ```
   a = 0.336001 0.383173 -0.0583286 
       -0.0551008 0.17626 0.0214456
       0.542571 0.36854 0.0888893
   b = 0.542571, 0.36854, 0.0888893
   ```

As in the section before, the parameter of Gauss-Legendre 3 are three-point Raudau again different, as expected.

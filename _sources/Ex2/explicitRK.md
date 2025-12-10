# Explicit Runge-Kutta methods

The explicit Runge-Kutta solver was implemented by Team 5, it wasn't supplied from upstream. It can solve for any Butcher tableu of the proper format (=lower triangular $a$ part).

## Testing for the mass-spring system

The `demos/test_ode.cpp` was extended to include a test for the explicit Runge-Kutta method of order 4 (a.k.a. RK4). Building and running this test with the runtime of $4 \pi$ and and 500 steps gives these results:

```{image} ../../plots/ExplicitRK4.png
:width: 70%
:align: center
```

```{image} ../../plots/ExplicitRK4PhasePlot.png
:width: 70%
:align: center
```

It can be seen that this method is less accurate than the Crank-Nicholson, but this very likely can be fixed by using higher order methods, like the RK5. On the other hand, it's more physically accurate than both of the Euler methods (looses less energy over time than the implicit Euler, doesn't gain energy).

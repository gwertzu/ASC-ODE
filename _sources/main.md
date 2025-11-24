# Simulating the mass-spring system with different time-stepping methods
The first exercise focused on the different time-stepping methods and their behavior for different runtimes and number of steps. All the simulations were done on the same mass-spring system, ensuring ease of comparison.

## Explicit Euler method
First the mass-spring system was simulated with the explicit Euler method that was supplied with the upstream version of `ASC-ODE`, with a simulation time of $10\pi$, and 100 steps. The attached plots of the time evolution and the phase plot show that this method is susceptible to numerical instability, resulting in physically impossible behavior (that is, gaining energy).

```{image} ../../plots/ExplicitEuler.png
:width: 70%
:align: center
```

```{image} ../../plots/ExplicitEulerPhasePlot.png
:width: 70%
:align: center
```

Furthermore, the longer the runtime, the more likely it is that the values reach the maximal storable value, resulting in `inf` in the file storing the results, and also `nan` values if run further. This can be avoided by selecting lower runtimes or more steps.

But it is also possible to use different methods, allowing these limitations to be bypassed without such compromises.

## The `ImprovedEuler` method
One of these methods is the `ImprovedEuler` method, that is defined in a way such that these errors are lower. The system, that was simulated above, seems to conserve the energy better with this method, as shown by the time evolution and the phase plot too, without changing the runtime or the number of steps.

```{image} ../../plots/ImprovedEuler.png
:width: 70%
:align: center
```

```{image} ../../plots/ImprovedEulerPhasePlot.png
:width: 70%
:align: center
```

## Implicit Euler method
Another method that seems promising was the implicit Euler method. This time-stepping method was run for shorter times ($4\pi$) than the previous two, because it suffers from numerical inaccuracies, resulting in system behaving in an unexpected way. In this case, however, instead of *gaining* energy, the system *loses* energy, as shown below.

```{image} ../../plots/ImplicitEuler.png
:width: 70%
:align: center
```

```{image} ../../plots/ImplicitEulerPhasePlot.png
:width: 70%
:align: center
```

## Crank-Nicolson method
The last method tested was the Crank-Nicolson method. This one seems to preserve the energy of the system for the same runtime as the implicit Euler method, making it look like a promising candidate for accurate numerical simulation of the system.

```{image} ../../plots/CrankNicolson.png
:width: 70%
:align: center
```

```{image} ../../plots/CrankNicolsonPhasePlot.png
:width: 70%
:align: center
```

# Conclusion
Based on the above plots, only 2 methods were able to conserve the energy for the entire runtime, with these being the `ImprovedEuler` and the Crank-Nicolson. The two other Euler methods either gained or lost a significant amount of energy during the runtime, making them unsuitable for simulating systems with a long runtime without having a large number of steps, that would result in a long calculation.

# Simulating an electric network

It is possible to simulate other physical systems than mass-spring systems. To demonstrate this, a simple electric network of an AC power source, a capacitor and a resistance were simulated.

## Results

The three previously implemented time stepping methods were used to realise the solution of the ODE. All three solvers were used with 2 different time steps: 5000 and 20000 steps.

### Explicit Euler method
```{image}../../plots/EN_Explicit_5000steps.png
:width: 70%
:align: center
```

```{image}../../plots/EN_Explicit_20000steps.png
:width: 70%
:align: center
```

### Implicit Euler method

```{image}../../plots/EN_Implicit_5000steps.png
:width: 70%
:align: center
```

```{image}../../plots/EN_Implicit_20000steps.png
:width: 70%
:align: center
```

### Crank-Nicholson method

```{image}../../plots/EN_CN_5000steps.png
:width: 70%
:align: center
```

Since this method deviates the least from a physically accurate result, this method was tested with 10000 steps too:

```{image}../../plots/EN_CN_10000steps.png
:width: 70%
:align: center
```

```{image}../../plots/EN_CN_20000steps.png
:width: 70%
:align: center
```

## Conclusion

The above plots are similar to those seen for the mass-spring system in the previous section: the explicit Euler method "blows up", the implicit Euler converges to 0, and the Crank-Nicholson is the most physically accurate time-stepping method.

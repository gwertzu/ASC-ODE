# Simulating an electric network

It is possible to simulate other physical systems than mass-spring systems. To demonstrate this, a simple electric network of an AC power source, a capacitor and a resistance were simulated. The source code for this resides in `src/electric_network_demo.cpp`.

## Results

The three previously implemented time stepping methods were used to realise the solution of the ODE. All three solvers were used with 2 different time steps (unless mentioned otherwise): 5000 and 20000 steps.

### Explicit Euler method

```{image} ../../plots/0EN_Expl_5000steps.png
:width: 70%
:align: center
```

```{image} ../../plots/0EN_Expl_20000steps.png
:width: 70%
:align: center
```

### Implicit Euler method

```{image} ../../plots/0EN_Impl_5000steps.png
:width: 70%
:align: center
```

```{image} ../../plots/0EN_Impl_20000steps.png
:width: 70%
:align: center
```

### Crank-Nicholson method

Since this method deviates the least from a physically accurate result, this method was tested with 1000 steps too:

```{image} ../../plots/0EN_CN_1000steps.png
:width: 70%
:align: center
```

The other two, larger step sizes don't show any significant signs of deviation from the physically accurate result:

```{image} ../../plots/0EN_CN_5000steps.png
:width: 70%
:align: center
```

```{image} ../../plots/0EN_CN_20000steps.png
:width: 70%
:align: center
```

## Conclusion

The above plots are similar to those seen for the mass-spring system in the previous section: the explicit Euler method "blows up" as time goes on, the implicit Euler converges to 0, and the Crank-Nicholson is the most physically accurate time-stepping method, with unwelcome effects only becoming noticable with lower step sizes.

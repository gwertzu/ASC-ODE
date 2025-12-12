# Experminents using the extended implementation

## Automatic differentiation

The upstream version didn't use automatic differentiation, instead it relied on numeric diffrentiation. Changing this to use the `src/autodiff.hpp` from this library ensures better accuracy.

## Experiments

The experiments below are implemented in the `mechsystem/*.ipynb`.

### Crane

This is implemented in `mechsystem/crane.ipynb`. In the renderer window one can see this *(running speed depends on the computer's speed)*:

```{image} ../../plots/crane_vibration.gif
:width: 40%
:align: center
```

### Chain

This is implemented in `mechsystem/mass_spring.ipynb`. In the renderer window one can see this *(running speed depends on the computer's speed)*:

```{image} ../../plots/chain.gif
:width: 40%
:align: center
```

### Spinning top
Not done yet!

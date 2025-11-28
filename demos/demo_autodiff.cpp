#include <iostream>
#include <autodiff.hpp>
#include <cmath>

using namespace ASC_ode;


template <typename T>
T func1 (T x, T y)
{
  return x * sin(y);
  // return 1e6 + y;
}

template <typename T>
T test_cos (T x)
{
  return cos(x);
}

template <typename T>
T test_log (T x)
{
  return log(x);
}

template <typename T>
T test_log2 (T x)
{
  return log2(x);
}

template <typename T>
T test_log10 (T x)
{
  return log10(x);
}

template <typename T, typename U = double>
T test_pow_1 (T x, U y)
{
  return pow(x,y);
}

template <typename T>
T test_div (T x, T y)
{
  return x/y;
}

template <typename T>
T test_minus (T x, T y)
{
  return x-y;
}

/*
template <typename T = double, typename U>
T test_pow_2 (T x, U y)
{
  return pow(x,y);
}
*/

int main()
{
  double x = 1, y = 2;
  AutoDiff<2> adx = Variable<0>(x);
  AutoDiff<2> ady = Variable<1>(y);

  std::cout << "adx = " << adx << std::endl;
  std::cout << "ady = " << ady << std::endl;

  AutoDiff<2> prod = adx * ady;
  std::cout << "prod = " << prod << std::endl;

  std::cout << "func1(adx, ady) = " << func1(adx, ady) << std::endl;
  std::cout << "test_cos(adx) = " << test_cos(adx) << std::endl;
  std::cout << "test_log(adx) = " << test_log(adx) << std::endl;
  std::cout << "test_log2(adx) = " << test_log2(adx) << std::endl;
  std::cout << "test_log10(adx) = " << test_log10(adx) << std::endl;
  std::cout << "test_pow_1(adx, 3) = " << test_pow_1(adx, 3.0) << std::endl;
  std::cout << "test_div(adx, ady) = " << test_div(adx, ady) << std::endl;
  std::cout << "test_minus(adx, ady) = " << test_minus(adx, ady) << std::endl;
  //std::cout << "test_pow_2(3, ady) = " << test_pow_2(3.0, ady) << std::endl;

  /*
  double eps = 1e-8;
  std::cout << "numdiff df/dx = " << (func1(x + eps, y) - func1(x-eps, y)) / (2*eps) << std::endl;
  std::cout << "numdiff df/dy = " << (func1(x, y + eps) - func1(x, y-eps)) / (2*eps) << std::endl;
  */


  {
    // we can do second derivatives:
    AutoDiff<1, AutoDiff<1>> addx{Variable<0>(2)};
    std::cout << "addx = " << addx << std::endl;
    // func = x*x
    // func' = 2*x
    // func'' = 2
    std::cout << "addx*addx = " << addx * addx << std::endl;

    // std::cout << "sin(addx) = " << sin(addx) << std::endl;
  }
  return 0;
}

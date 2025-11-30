#ifndef EXPLICITRK_HPP
#define EXPLICITRK_HPP

#include <vector.hpp>
#include <matrix.hpp>
#include <cmath>
#include <vector>

namespace ASC_ode {
  using namespace nanoblas;

  class ExplicitRungeKutta : public TimeStepper
  {
    Matrix<> m_a;
    Vector<> m_b, m_c;
    std::shared_ptr<NonlinearFunction> m_equ;
    std::shared_ptr<Parameter> m_tau;
    int m_stages;
    int m_n;
    Vector<> m_k, m_y;
    Vector<> m_yold;
  public:
    ExplicitRungeKutta(std::shared_ptr<NonlinearFunction> rhs,
      const Matrix<> &a, const Vector<> &b, const Vector<> &c) 
    : TimeStepper(rhs), m_a(a), m_b(b), m_c(c),
    m_tau(std::make_shared<Parameter>(0.0)),
    m_stages(c.size()), m_n(rhs->dimX()), m_k(m_stages*m_n), m_y(m_stages*m_n), m_yold(m_stages*m_n)
    {

    }
    void DoStep(double tau, VectorView<double> y) override {
      for (int j = 0; j < m_stages; j++) {
          m_y.range(j * m_n, (j + 1) * m_n) = y;
      }
      m_yold = m_y;

      m_tau->set(tau);
      m_k = 0.0;

      Vector<> rhs(m_stages * m_n);
      for (int i = 0; i < m_stages; i++) {
          m_equ->evaluate(m_y.range(i * m_n, (i + 1) * m_n), rhs.range(i * m_n, (i + 1) * m_n));
      }

      NewtonSolver(m_equ, m_k);

      // next step:
      for (int j = 0; j < m_stages; j++) {
          y += tau * m_b(j) * m_k.range(j * m_n, (j + 1) * m_n);
      }
    }
  };

}  

#endif // EXPLICITRK_HPP

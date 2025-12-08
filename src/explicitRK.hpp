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
    int m_stages;
    int m_n;
    Vector<> m_k, m_y;
    //Vector<> m_yold;
  public:
    ExplicitRungeKutta(std::shared_ptr<NonlinearFunction> rhs,
      const Matrix<> &a, const Vector<> &b, const Vector<> &c) 
    : TimeStepper(rhs), m_a(a), m_b(b), m_c(c),
    m_stages(c.size()), m_n(rhs->dimX()), m_k(m_stages*m_n), m_y(m_stages*m_n)
    {

    }
    void DoStep(double tau, VectorView<double> y) override {
      for (int j = 0; j < m_stages; j++) {
          m_y.range(j * m_n, (j + 1) * m_n) = y;
      }

      for (int j = 0; j < m_stages; j++) {
          VectorView<> stage_in = m_y.range(0,m_n);
          for (int i = 0; i < j; i++) {
            stage_in += tau*m_a(j,i)*m_k.range(i*m_n, (i+1)*m_n);
          }
          this->m_rhs->evaluate(stage_in, m_k.range(j * m_n, (j + 1) * m_n));
      }

      // next step:
      for (int j = 0; j < m_stages; j++) {
          y += tau * m_b(j) * m_k.range(j * m_n, (j + 1) * m_n);
      }
    }
  };

}  

#endif // EXPLICITRK_HPP

#ifndef TIMERSTEPPER_HPP
#define TIMERSTEPPER_HPP

#include <functional>
#include <exception>
#include <memory>

#include "Newton.hpp"


namespace ASC_ode
{

    class TimeStepper
    {
    protected:
        std::shared_ptr<NonlinearFunction> m_rhs;
    public:
        TimeStepper(std::shared_ptr<NonlinearFunction> rhs) : m_rhs(rhs) {}
        virtual ~TimeStepper() = default;
        virtual void DoStep(double tau, VectorView<double> y) = 0;
    };

    class ExplicitEuler : public TimeStepper
    {
        Vector<> m_vecf;
    public:
        ExplicitEuler(std::shared_ptr<NonlinearFunction> rhs)
            : TimeStepper(rhs), m_vecf(rhs->dimF()) {
        }
        void DoStep(double tau, VectorView<double> y) override
        {
            this->m_rhs->evaluate(y, m_vecf);
            y += tau * m_vecf;
        }
    };

    class ImplicitEuler : public TimeStepper
    {
        std::shared_ptr<NonlinearFunction> m_equ;
        std::shared_ptr<Parameter> m_tau;
        std::shared_ptr<ConstantFunction> m_yold;
    public:
        ImplicitEuler(std::shared_ptr<NonlinearFunction> rhs)
            : TimeStepper(rhs), m_tau(std::make_shared<Parameter>(0.0))
        {
            m_yold = std::make_shared<ConstantFunction>(rhs->dimX());
            auto ynew = std::make_shared<IdentityFunction>(rhs->dimX());
            m_equ = ynew - m_yold - m_tau * m_rhs;
        }
        void DoStep(double tau, VectorView<double> y) override
        {
            m_yold->set(y);
            m_tau->set(tau);
            NewtonSolver(m_equ, y);
        }
    };

    class CrankNicolson : public TimeStepper
    {
        ExplicitEuler m_explicitEuler;
        ImplicitEuler m_implicitEuler;

    public:
        CrankNicolson(std::shared_ptr<NonlinearFunction> rhs)
            : TimeStepper(rhs), m_explicitEuler(rhs), m_implicitEuler(rhs) {}

        void DoStep(double tau, VectorView<double> y) override
        {
            Vector<double> y_explicit = y;
            m_explicitEuler.DoStep(tau, y_explicit);

            Vector<double> y_implicit = y;
            m_implicitEuler.DoStep(tau, y_implicit);

            y = 0.5 * (y_explicit + y_implicit);
        }
    };


    class ImprovedEuler : public TimeStepper
    {
        Vector<> m_vecf;
        Vector<> m_vecftilde;
        Vector<> m_ytilde;

    public:
        ImprovedEuler(std::shared_ptr<NonlinearFunction> rhs)
            : TimeStepper(rhs), m_vecf(rhs->dimF()), m_vecftilde(rhs->dimF()),
            m_ytilde(rhs->dimF()) {
        }
        void DoStep(double tau, VectorView<double> y) override
        {
            this->m_rhs->evaluate(y, m_vecf);
            m_ytilde = y + tau * 0.5 * m_vecf;

            this->m_rhs->evaluate(m_ytilde, m_vecftilde);
            y += tau * m_vecftilde;
        }
    };

/*
    class CrankNicholson : public TimeStepper
    {
        std::shared_ptr<NonlinearFunction> m_equ;
        std::shared_ptr<Parameter> m_tau;
        std::shared_ptr<ConstantFunction> m_yold;
        std::shared_ptr<ConstantFunction> m_ynew;
        Vector<> m_vecf_old;
        Vector<> m_vecf_new;

    public:
        CrankNicholson(std::shared_ptr<NonlinearFunction> rhs)
            : TimeStepper(rhs), m_tau(std::make_shared<Parameter>(0.0)),
            m_yold(std::make_shared<ConstantFunction>(rhs->dimX())),
            m_ynew(std::make_shared<ConstantFunction>(rhs->dimX())),
            m_vecf_old(rhs->dimF()), m_vecf_new(rhs->dimF())
        {
            auto ynew = std::make_shared<IdentityFunction>(rhs->dimX());
            double tau_value = m_tau->get(); 
            //m_equ = ynew - m_yold - tau_value * 0.5 * (m_rhs + m_rhs);
            //m_equ = ynew->get() - m_yold->get() - tau_value * 0.5 * (
            //    m_rhs->evaluate(ynew->get(), m_vecf_new) + 
            //    m_rhs->evaluate(m_yold->get(), m_vecf_old)
            //);

        }

        void DoStep(double tau, VectorView<double> y) override
        {
            // Setze alten Wert
            m_yold->set(y);
            m_tau->set(tau);

            // Berechne f(y^n) für den alten Wert (explizit)
            this->m_rhs->evaluate(y, m_vecf_old);

            // Berechne f(y^{n+1}) für den neuen Wert (implizit)
            m_ynew->set(y);
            this->m_rhs->evaluate(y, m_vecf_new);

            // Crank-Nicholson-Gleichung: (y^{n+1} - y^n) = tau / 2 * (f(y^{n+1}) + f(y^n))
            // Das wird zu: y^{n+1} - tau/2 * f(y^{n+1}) = y^n + tau/2 * f(y^n)
            // Numerische Lösung der Gleichung für den nächsten Wert y^{n+1}
            
            // Implementiere hier einen numerischen Löser, z. B. Newton-Verfahren, um y^{n+1} zu berechnen
            NewtonSolver(m_equ, y);
        }
    };

*/  

}


#endif

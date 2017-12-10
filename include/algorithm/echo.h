//
// Created by Mohammed Boujemaoui on 10/12/2017.
//

#ifndef EDSP_ECHO_H_H
#define EDSP_ECHO_H_H

#include "delay.h"
EDSP_BEGIN_NAMESPACE
    namespace algorithm {
        class Echo {
            explicit Echo(std::size_t maximum_delay) : m_delay(maximum_delay/3, maximum_delay) {
                this->set_maximum_delay(maximum_delay);
                this->reset();
            }

            template <class InputIterator, class OutputIterator>
            void compute(InputIterator first, InputIterator last, OutputIterator out) {
                for (; first != last; ++first, ++out) {
                    compute(*first, *out);
                };
            }

            template <typename T>
            void compute(const T input, T& out) {
                m_delay.compute(input, out);
                out = m_gain * (out - input) + input;
            }

            void reset() {
                m_delay.reset();
            }

            double delay() const { return m_delay.delay(); }
            double maximum_delay() const { return m_delay.maximum_delay(); }
            double gain() const { return m_gain; }

            void set_delay(const std::size_t value) {
                m_delay.set_delay(value);
            }

            void set_maximum_delay(const std::size_t value) {
                m_delay.set_maximum_delay(value);
            }

            void set_gain(const double value) {
                m_gain = value;
            }

        private:
            Delay       m_delay;
            double      m_gain;
        };
    }

EDSP_END_NAMESPACE


#endif //EDSP_ECHO_H_H

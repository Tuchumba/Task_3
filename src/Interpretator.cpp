#include "Interpretator.hpp"

void Interpretator::interpretation() {
    pars.analyze();
    pars.output_poliz();
    E.execute(pars.poliz);
}
#include "interpretator.hpp"

void Interpretator::interpretation() {
    pars.analyze();
    E.execute(pars.poliz);
}
#ifndef INTERPRETATOR_HPP
#define INTERPRETATOR_HPP

#include "parser.hpp"
#include "executer.hpp"

class Interpretator {
    Parser pars;
    Executer E;
public:
    Interpretator(const char* program) : pars(program) {}
    void interpretation();
};

#endif
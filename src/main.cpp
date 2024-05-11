#include "Interpretator.hpp"

#include <iostream>

using namespace std;

int main() {
    try {
        Interpretator I ( "program.mlg" ); //mlg - Model Language
        I.interpretation ();
        return 0;
    }
    catch (char& c) {
        cout << "unexpected symbol " << c << endl;
        return 1;
    }
    catch (Lex& l) {
        cout << "unexpected lexeme " << l << endl;
        return 1;
    }
    catch (const char *source) {
        cout << source << endl;
        return 1;
    }
}
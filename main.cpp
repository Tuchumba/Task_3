#include "interpretator.hpp"

#include <iostream>

using namespace std;

int main() {
    try {
        Interpretator I ( "prog.txt" );
        I.interpretation ();
        return 0;
    }
    catch (char c) {
        cout << "unexpected symbol " << c << endl;
        return 1;
    }
    catch (Lex l) {
        cout << "unexpected lexeme " << l << endl;
        return 1;
    }
    catch (const char *source) {
        cout << source << endl;
        return 1;
    }
}
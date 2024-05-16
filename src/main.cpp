#include "Interpretator.hpp"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    if (argc!= 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    try {
        Interpretator I(argv[1]); //.mlg - Model Language
        I.interpretation();
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
    catch (const string& source) {
        cout << source << endl;
        return 1;
    }
    catch(const char* source) {
        cout << source << endl;
    }
}
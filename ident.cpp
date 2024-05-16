#include "ident.hpp"

#include <algorithm>
#include <vector>


using namespace std;

Ident::Ident(const string n) {
    name = n;
    declare = false; 
    assign  = false;
}

bool Ident::operator==(const string& s) const { 
    return name == s; 
}

string Ident::get_name() const { 
    return name; 
}

bool Ident::get_declare() const { 
    return declare; 
}

void Ident::put_declare() { 
    declare = true; 
}

type_of_lex Ident::get_type() const { 
    return type; 
}

void Ident::put_type(type_of_lex t) { 
    type = t; 
}

bool Ident::get_assign() const { 
    return assign; 
}

void Ident::put_assign() { 
    assign = true; 
}

int Ident::get_value() const { 
    return value; 
}

void Ident::put_value(int v) { 
    value = v; 
}

vector<Ident> TID;

int put(const string& buf) {
    vector<Ident>::iterator k;
    if ((k = find(TID.begin(), TID.end(), buf)) != TID.end())
        return k - TID.begin();
    TID.push_back(Ident(buf));
    return TID.size() - 1;
}
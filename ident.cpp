#include "ident.hpp"
#include "lex.hpp"

#include <algorithm>
#include <vector>
#include <functional>


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

// int put(const string& buf) {
//     vector<Ident>::iterator k;
//     if ((k = find(TID.begin(), TID.end(), buf)) != TID.end())
//         return k - TID.begin();
//     TID.push_back(Ident(buf));
//     return TID.size() - 1;
// }

int get(const string& buf) {
    vector<Ident>::iterator k;
    if ((k = find(TID.begin(), TID.end(), buf)) != TID.end())
        return k - TID.begin();
    else {
        return -1;
    }
}

void TID_declare(std::vector<std::vector<std::string>>& vars, type_of_lex type) {
    int size = vars.size();
    std::vector<string> combs;

    function<void(int, string)> get_combs = [&](int index, string comb) {
        // If we have reached the end of the vectors, add the combination to the vector of combinations
        if (index == size) {
            combs.push_back(comb);
            return;
        }

        // For each vector at the current index, add its string to the combination and recursively get the remaining combinations
        for (string& s : vars[index]) {
            get_combs(index + 1, comb + s + ".");
        }
    };

    get_combs(0, "");

    for (string& s : combs) {
        s.pop_back();
        Ident id(s);
        id.put_declare();
        id.put_type(type);
        
        TID.push_back(id);
    }
    
}
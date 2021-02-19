#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "evaluator.hpp"

using namespace std;


vector<string> split_input(string &s) {
    vector<string> ret;
    istringstream tmp(s);
    for (string aux; getline(tmp, aux, ' ');)
        ret.push_back(aux);
    return ret;
}

int main() {
    while (true) {
        string s;
        getline(cin, s);
        vector<string> inp = split_input(s);

        if (inp[0].compare("EVAL") == 0) {
            inp.erase(inp.begin());
            if (inp[0].compare("POST") == 0) {
                inp.erase(inp.begin());
                printf("%d\n", eval_post(inp));
            }

            else if (inp[0].compare("PRE") == 0) {
                inp.erase(inp.begin());
                printf("%d\n", eval_pre(inp));
            }
            else
                printf("ORDEN NO VALIDO\n");
        }
        else if (inp[0].compare("MOSTRAR") == 0) {
            inp.erase(inp.begin());
            if (inp[0].compare("POST") == 0) {
                inp.erase(inp.begin());
                show_post(inp);
            }
            else if (inp[0].compare("PRE") == 0) {
                inp.erase(inp.begin());
                show_pre(inp);
            }
            else
                printf("ORDEN NO VALIDO\n");
        }
        else if (inp[0].compare("SALIR") == 0)
            break;
        else
            printf("COMANDO DESCONOCIDO\n");
    }
    return 0;
}
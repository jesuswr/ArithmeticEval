#ifndef _EVALUATOR_HPP
#define _EVALUATOR_HPP

#include <vector>
#include <string>

using namespace std;

// struct to represent the nodes of the expression tree
struct exp_node {
    // sons to the left and right
    exp_node *l, *r;
    // boolean if the node is an operand
    bool is_op;
    // operation
    char op;
    // number
    int num;
};


int eval_post(const vector<string> &exp);

int eval_pre(vector<string> &exp);

void show_post(const vector<string> &exp);

void show_pre(vector<string> &exp);

#endif
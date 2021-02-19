#include "evaluator.hpp"
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;


// function to swap left and right sons of a subtree
void swaps(exp_node* root) {
    if (!root->is_op) return;
    swap(root->l, root->r);
    swaps(root->l), swaps(root->r);
}

// function to build the expression tree from the given preorder expression
exp_node* build(const vector<string> &exp) {
    if (exp.size() == 0)
        return NULL;

    stack<exp_node*> stck;
    for (auto e : exp) {
        exp_node *curr = new exp_node;
        // if the current string represents a number, push it to the stack
        if (isdigit(e[0])) {
            curr->is_op = false;
            curr->num = atoi(e.data());
            stck.push(curr);
        }
        // else pop two nodes, connect them and push the new one to the stack
        else {
            curr->is_op = true;
            curr->op = e[0];
            if (stck.size() < 2)
                return NULL;

            curr->r = stck.top(); stck.pop();
            curr->l = stck.top(); stck.pop();
            stck.push(curr);
        }
    }

    // if there is more than 1 node remaining in the stack the expression
    // its not correct
    if (stck.size() > 1)
        return NULL;

    return stck.top();
}

// simple recursive funcion to evaluate a tree
int eval(exp_node *root) {
    // if it is a number return it
    if (!root->is_op) return root->num;

    // else get the result from the subtrees and evaluate them
    int left = eval(root->l), right = eval(root->r);
    int ret = 0;
    switch (root->op) {
    case '+':
        ret = left + right;
        break;
    case '-':
        ret = left - right;
        break;
    case '*':
        ret = left * right;
        break;
    case '/':
        ret = left / right;
        break;
    }
    return ret;
}


int eval_post(const vector<string> &exp) {
    // create expression tree
    exp_node *tree = build(exp);
    if (tree == NULL) {
        printf("LA EXPRESION DADA NO ES VALIDA\n");
        return 0;
    }

    // evaluate the tree
    return eval(tree);
}

int eval_pre(vector<string> &exp) {
    // reverse the expression to manage it as a post order exp
    reverse(exp.begin(), exp.end());
    exp_node *tree = build(exp);
    reverse(exp.begin(), exp.end());

    if (tree == NULL) {
        printf("LA EXPRESION DADA NO ES VALIDA\n");
        return 0;
    }

    // swap the left and right sons of the tree so it becomes
    // the expected tree of the given expression
    swaps(tree);

    // evaluate the tree
    return eval(tree);
}

// simple function to traverse and print the tree
void show_dfs(exp_node *root) {
    if (!root->is_op) {
        printf("%d", root->num);
        return;
    }

    // check if there are necessary parentheses in childs
    bool put_left = false, put_right = false;
    if (root->op == '*' || root->op == '/') {
        put_left =
            root->l->is_op && (root->l->op == '+' || root->l->op == '-');
        put_right =
            root->r->is_op && (root->r->op == '+' || root->r->op == '-');
    }

    // traverse left and put parentheses if neeeded
    if (put_left)
        printf("(");
    show_dfs(root->l);
    if (put_left)
        printf(")");

    // print current node
    printf("%c", root->op);

    // traverse right and put parentheses if neeeded
    if (put_right)
        printf("(");
    show_dfs(root->r);
    if (put_right)
        printf(")");
}

void show_post(const vector<string> &exp) {
    // create tree
    exp_node *tree = build(exp);
    if (tree == NULL) {
        printf("LA EXPRESION DADA NO ES VALIDA\n");
        return;
    }

    // print tree
    show_dfs(tree);
    printf("\n");
}

void show_pre(vector<string> &exp) {
    // reverse exp to manage it as post order
    reverse(exp.begin(), exp.end());
    exp_node *tree = build(exp);
    reverse(exp.begin(), exp.end());

    if (tree == NULL) {
        printf("LA EXPRESION DADA NO ES VALIDA\n");
        return;
    }

    // swap the left and right sons of the tree so it becomes
    // the expected tree of the given expression
    swaps(tree);

    // print tree
    show_dfs(tree);
    printf("\n");
}
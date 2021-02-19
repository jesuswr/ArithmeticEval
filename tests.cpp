#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"
#include "evaluator.hpp"
#include <vector>
#include <string>

using namespace std;

TEST_CASE("pre eval tests") {

    vector<string> pre_expr = {"+", "*", "+", "3", "4", "5", "7"};
    REQUIRE( eval_pre( pre_expr ) == 42 );

    pre_expr = {"0"};
    REQUIRE( eval_pre( pre_expr ) == 0 );

    pre_expr = {"/", "1", "2"};
    REQUIRE( eval_pre( pre_expr ) == 0 );

    pre_expr = {"/", "2", "1"};
    REQUIRE( eval_pre( pre_expr ) == 2 );

    pre_expr = {"*", "+", "1", "2", "-", "3", "4"};
    REQUIRE( eval_pre(pre_expr) == -3 );
}

TEST_CASE("post eval tests") {

    vector<string> post_expr = {"8", "3", "-", "8", "4", "4", "+", "*", "+"};
    REQUIRE( eval_post( post_expr ) == 69 );

    post_expr = {"0"};
    REQUIRE( eval_post( post_expr ) == 0 );

    post_expr = {"1", "2", "/"};
    REQUIRE( eval_post( post_expr ) == 0 );

    post_expr = {"2", "1", "/"};
    REQUIRE( eval_post( post_expr ) == 2 );

    post_expr = {"1", "2", "+", "3", "4", "-", "*"};
    REQUIRE( eval_post(post_expr) == -3 );
}
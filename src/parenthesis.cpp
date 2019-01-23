/*
Given a string containing just the characters '(', ')', '{', ')', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
*/
#include "catch2.hpp"
#include <string>
#include <vector>
#include <set>
#include <iostream>

bool validParenthesis(const std::string& text)
{
    static const std::vector<char> beginParenthesis = {'(', '[', '{'};
    static const std::vector<char> endParenthesis{')', ']', '}'};
    std::vector<char> stack;
    for (const auto& c : text)
    {
        auto bp = std::find(beginParenthesis.begin(), beginParenthesis.end(), c);
        if (bp != beginParenthesis.end())
        {
            stack.push_back(c);
            continue;
        }

        auto ep = std::find(endParenthesis.begin(), endParenthesis.end(), c);
        if (ep != endParenthesis.end())
        {
            if (stack.empty())
                return false;
            auto bpTemp = std::find(beginParenthesis.begin(), beginParenthesis.end(), stack.back());
            if (!(std::distance(beginParenthesis.begin(), bpTemp) == std::distance(endParenthesis.begin(), ep)))
                return false;
            stack.pop_back();
        }
    }

    return stack.empty();
}

TEST_CASE( "Parenthesis should be valid", "[parenthesis]" ) {
    REQUIRE(validParenthesis("{[()]}") == true);
    REQUIRE(validParenthesis("{[(a)]}") == true);
    REQUIRE(validParenthesis("") == true);
    REQUIRE(validParenthesis("()") == true);
    REQUIRE(validParenthesis("({})") == true);
    REQUIRE(validParenthesis("aaaa") == true);
}

TEST_CASE( "Parenthesis should be invalid", "[parenthesis]" ) {
    REQUIRE(validParenthesis("{[(]))") == false);
    REQUIRE(validParenthesis("{{{{{{{") == false);
    REQUIRE(validParenthesis("[[[[[[[[") == false);
    REQUIRE(validParenthesis("(((((((") == false);
    REQUIRE(validParenthesis("))))))))") == false);
    REQUIRE(validParenthesis("]]]]]]]]") == false);
    REQUIRE(validParenthesis(")))))))") == false);
}
/*
turn backward every word in a pahase. only char array can be used
example:
input: what the hack its doing
output: tahw eht kcah sti gniod
*/
#include "catch2.hpp"
#include <string>

void turnPhaseBackward(char phase[], size_t length)
{
    size_t startIndex = 0;
    size_t nextWordLength = 0;
    for(size_t i = 0; i<length; ++i)
    {
        if(phase[i] == ' ' || phase[i] == '\0')
        {
            nextWordLength = i - startIndex;
            for(size_t j = 0; j < nextWordLength/2; ++j)
            {
                auto firstIndex = startIndex + j;
                auto lastIndex = startIndex + nextWordLength-j-1;
                
                char tmp = phase[firstIndex];
                phase[firstIndex] = phase[lastIndex];
                phase[lastIndex] = tmp;
            }
            startIndex = i + 1;
        }
    }
}

TEST_CASE( "Mirror every word in a phase", "[phasebackward]" ) {
    char example1[] = "What the hack";
    char expectedExample1[] = "tahW eht kcah";
    turnPhaseBackward(example1, sizeof(example1));
    REQUIRE(std::string(example1) == std::string(expectedExample1));

    char example2[] = "";
    char expectedExample2[] = "";
    turnPhaseBackward(example2, sizeof(example2));
    REQUIRE(std::string(example2) == std::string(expectedExample2));

    char example3[] = "aaaaaaaaaaaaaaaaaaaaaa";
    char expectedExample3[] = "aaaaaaaaaaaaaaaaaaaaaa";
    turnPhaseBackward(example3, sizeof(example3));
    REQUIRE(std::string(example3) == std::string(expectedExample3));
}

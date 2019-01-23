/*
turn backward every word in a pahase. only char array can be used
example:
input: what the hack its doing
output: tahw eht kcah sti gniod
*/
#include "catch2.hpp"
#include <string>
#include <iostream>

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
    char example[] = "What the hack";
    char expectedExample[] = "tahW eht kcah";
    turnPhaseBackward(example, sizeof(example));
    REQUIRE(std::string(example) == std::string(expectedExample));
}

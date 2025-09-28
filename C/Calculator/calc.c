#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"


int main(int argc, char *argv[]) // Will determine if user wants a basic calc or advanced calc with extra features ex. long equation etc
{
    if(strcmp(argv[1], "advanced") == 0) // must make an input for advanced feature default is basic
    {
        advancedCalc();
    }
    else{
        simpleCalc();
    }
}
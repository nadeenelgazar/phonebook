#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"
#include "variables.h"
#include "main.h"
#include "mainfunction.c"
#include "helping.h"
#include "helping.c"

int main()
{
    int c = 1;
    printf("\t\t\t\t\t**WELCOME TO THE PHONEBOOK**\n");
    LOAD();
    while (c!=0)
    {
    MENU();
    }
    return 0;
}

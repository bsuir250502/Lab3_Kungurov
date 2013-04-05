#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdarg.h>
#include "mystdlib.h"

int main(int argc, char **argv)
{
    if (argc == 2) {
        if ((strcmp(argv[1], "-h")) == 0) {
            puts("Instructions for use:");
            puts("1.Start the program (cd drive :/ place / location / file / -> make -> ./lab1).");
            puts("2. Company name. Our offers to enter the business name, type a name (no more than 30 characters)");
            puts("then click <enter>. Entering stop when you enter the 50 firms, or if you need a stop earlier,");
            puts("just type 'end' (without the quotes). You will then proceed to enter personal information");
            puts("for each firm.");
            puts("3. PERSONAL INFORMATION FOR EACH OF COMPANIES.");
            puts("    3.1. To offer input tax (tax), enter the number (not more than 7 digits).");
            puts("    3.2. Next, enter the date of the offer closing date (deadline), type the date in");
            puts("         format DD MMM YYYY (Ex. 01 jan 1970) or write the month when you enter a fully");
            puts("         {Ex. 01 january 1970). If you enter the wrong program will tell you.");
            puts("    3.3. Next on the proposal to introduce the date of actual payment, enter the date (see section 3.2)");
            puts("    or '0' (zero), if the payment of the tax has not been made.");
            puts("Items 3.1 - 3.2 is repeated for all input firms.");
            puts("4. DATE AT THE TIME TRACKING be produced by the debtor. The proposal to introduce");
            puts("date monitoring of debtors (monitor_date), enter in the mentioned format (see section 3.2).");
            return 0;
        }
    }
    return 0;
}
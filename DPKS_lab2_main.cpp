//
//  main.cpp
//  DPKS2
//
//  Created by Kostianikov Vladyslav on 09.03.2020.
//

#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>

int
main(int argc, char **argv)
{
    int c;
    int digit_optind = 0;
    bool aFlag = true;
    bool lFlag = true;
    bool vFlag = true;
    bool hFlag = true;
    bool VFlag = true;

   while (1) {
        int this_option_optind = optind ? optind : 1;
        int option_index = 0;
        static struct option long_options[] = {
          {"author",    no_argument,     0, 'a'},
          {"list",    optional_argument, 0, 'l'},
          {"version", no_argument,       0, 'v'},
          {"help",    no_argument,       0, 'h'},
          {"value",   required_argument, 0, 'V'}
        };

       c = getopt_long(argc, argv, "al:vhV:",
                 long_options, &option_index);
        if (c == -1)
            break;

       switch (c) {
           
        case 'a':
            if (aFlag){
            printf("option Author: Author is Kostianikov V. IO-91mp\n");
            aFlag=false;
            }
            break;
        
       case 'v':
        if (vFlag){
            printf("option version version=0.01\n");
            vFlag=false;
            }
            break;

       case 'h':
        if (hFlag){
            printf("option help\n");
            printf("This program have next argument: \n -a for --author  \n -l [arg] for --list  \n -v for --version \n -h for --help \n -V [arg] for --value \n");
            hFlag=false;
            }
            break;

       case 'V':
            if (VFlag){
            printf("option Value with value '%s'\n", optarg);
            VFlag=false;
            }
            break;

       case 'l':
            if (lFlag){
            printf("option list with value '%s'\n", optarg);
              lFlag=false;
            }
            break;

       
       default:
            printf("?? getopt returned character code -h%o ??\n", c);
        }
    }

   if (optind < argc) {
        printf("non-option ARGV-elements: ");
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
    }

   exit(EXIT_SUCCESS);
}
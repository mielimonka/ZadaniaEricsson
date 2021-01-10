//
// Program can be started in two modes.
// Mode "dec" converts decimal number to binary number.
// Mode "bin" converst binary number to decimal number.
// Mode shall be entered as argument 1 of the program.
// Example: ./zadanie2 bin
//

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>


// Function handles keyboard interrupt and exits program.
void handle_interrupt(int sig) {
    printf("Ctrl-C\n");
    fflush(stdout);
    exit(0);
}

// Function converts string bin_str to decimal number and prints the result.
void print_decimal(char *bin_str) {
    int dec_number = 0;
    int str_size = strlen(bin_str);
    for(int i = 0; i < str_size; i++) {
        if(bin_str[i] == '1') {
            dec_number = dec_number | (1 << (str_size - i - 1));
        }
    }

    printf("Decimal:\n");
    printf("%d\n", dec_number);
}

// Function prints dec_number in binary format. 
void print_binary(int dec_number) {

    int size = 8 * sizeof(dec_number);
    int bin_char;
    printf("Binary:\n");
    for(int i = size - 1; i >= 0; i--){
        bin_char = (dec_number >> i) & 1; 
        printf("%d", bin_char);
    }
    printf("\n\n");
}

int main(int argc, char *argv[]) {
    signal(SIGINT, handle_interrupt);
    int ret;

    if(argc == 2) {
        if(strcmp(argv[1],"bin") == 0) {
            printf("Running app in the mode: \"bin->dec\"\n");
            char input_str[33];
            while(1) {
                printf("Enter binary number to be converted to decimal.\n");
                fflush(stdout);
                ret = scanf("%s", input_str);
                if(ret != 1){ 
                    printf("Wrong input. Exiting...\n");
                    break;
                }
                print_decimal(input_str);                
            }

        }else if(strcmp(argv[1],"dec") == 0) {
            printf("Running app in the mode: \"dec->bin\"\n");
            int input_number;
            while(1) {
                printf("Enter decimal number to be converted to binary.\n");
                fflush(stdout);
                ret = scanf("%d", &input_number);
                if(ret != 1){
                    printf("Wrong input. Exiting...\n");
                    break;
                }
                print_binary(input_number);
            }

        }else {
            printf("Wrong argument.\n");
            return 1;
        }
    }else if(argc > 2){
        printf("Too many arguments\n");
        return 2;
    }else{
        printf("No arguments. Please provide the mode you want the application to run in\n");
        return 3;
    }

    return 0;
}
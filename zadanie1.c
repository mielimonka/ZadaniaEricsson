#include <stdio.h>
#include <stdlib.h>    

typedef struct node {
    int value;
    struct node *next;
} node;

// Function checks if object is correct.
// It returns 1 if the object has errors.
// If object is correct it returns 0 and adds it to the end of the list check
int check_object(node *check, int value) {
    int msg = (value & 14) >> 1;
    if(msg != 0) {
        int ctrl = value & 1;
        int id = (value & 240) >> 4; 
        if(id%2 == ctrl) {
            check->value = value;
            check->next = (node *) malloc(sizeof(node));
            if(check->next == NULL) {
                return 0;
            }
            check->next->next = NULL;
            return 0;
        } else {
            return 1;
        }
    } else {
        return 1;
    }
}


int main() {

    int obj_count = 0;
    int failed_count = 0;

    FILE *inputfile = fopen("input.txt","rb");

    if(inputfile == NULL) {
        printf("File input.txt wasn't found.\n");
        return 1;
    }
    
    node *object = (node *) malloc(sizeof(node));
    if(object == NULL) {
        return 3;
    }
    object->next=NULL;
    node *saved = object;
    
    int input_char = fgetc(inputfile);
    while(input_char != EOF) {
        obj_count++;
        failed_count += check_object(object, input_char);
        input_char = fgetc(inputfile);
        if(object->next != NULL) {
            object = object->next;
        }
    }

    fclose(inputfile);

    FILE *outfile = fopen("output.txt","w");
    
    if(outfile == NULL) {
        return 2;
    }

    // Writing result to output.txt file
    fprintf(outfile, "%d\n", obj_count);
    fprintf(outfile, "%d\n", failed_count);
    
    node *free_object;

    while(saved->next != NULL) {
        free_object = saved;        
        fputc(saved->value, outfile);
        saved = saved->next;
        free(free_object);
    }
    free(saved);

    fclose(outfile);

    return 0;   
}
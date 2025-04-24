#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * get_array(int rule){

    int * array = malloc(sizeof(int) * 8);

    int bit;

    for(int i = 0; i < 8; i++){
            bit = (rule >> i) & 1;
            array[i] = bit;        
    }

    return array;
}

char * bitfy(char * arg){
    int length = strlen(arg);
    char * bitfrmt = malloc(length * 8 + 1);
    char bit;

    for(int i = 0; i < length; i++){
        for(int j = 0; j < 8; j++){
            bit = ((arg[i] >> j) & 1) + '0';
                bitfrmt[i * 8 + (7 - j)] = bit;           
        }
    }

    bitfrmt[length * 8] = '\0';

    return bitfrmt; 
}

char * charfy(char * arg){
    int length = strlen(arg);

    char * charfied = malloc((length / 8) + 1);
    charfied[length / 8] = '\0';

    char character[9];
    character[8] = '\0';

    for(int i = 0; i < length; i = i + 8){
        for(int j = 0; j < 8; j++){
            character[j] = arg[i + j];        
        }
        charfied[i / 8] = strtol(character, NULL, 2);
    }

    return charfied;
}

void apply_rule(char * frame, int n_rule) {

    int frame_size = strlen(frame);

    int * rule = get_array(n_rule);

    char next[frame_size + 1]; // +1 para o '\0'
    next[frame_size] = '\0';

    for(int i = 0; i < frame_size; i++) {
        char left  = (i == 0) ? '0' : frame[i - 1];
        char self  = frame[i];
        char right = (i == frame_size - 1) ? '0' : frame[i + 1];

        char cell_constructor[4] = {left, self, right, '\0'};
        int pos = strtol(cell_constructor, NULL, 2);
        next[i] = rule[pos] + '0';
    }

    strcpy(frame, next);
}

int main(int argc, char * argv[]){

    char * bit = bitfy(argv[1]);

    int rule = 110;

    printf("%s\n", argv[1]);

    for(int i = 0; i < 100; i++){
        apply_rule(bit, rule);
    }

    unsigned long hash = strtol(bit, NULL, 2);

    printf("%ld", hash); 

    free(bit);

    return 0;
}

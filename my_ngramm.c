#include <stdio.h>

int my_strlen(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length += 1;
    }
    return length;
}

int main(int argc, char** argv) {
    if (argc == 1) {
        return 0;
    }

    // length
    int length = 0;
    for (int k = 1; k < argc; k ++) {
        length += my_strlen(argv[k]);
    }

    // char string
    char string[length];
    
    length = 0;
    for (int k = 1; k < argc; k ++) {
        int index = 0;
        index = my_strlen(argv[k]);
        for (int i = 0; i < index; i ++) {
            string[length] = argv[k][i];
            length += 1;
        }
    }
    string[length] = '\0';

    // count
    int i;
    int j;
    char array[length];
    int array_int[length];
    int index = 0;
    for (i = 0; i < length; i ++) {
        int count = 0;
        for (j = 0; j < length; j ++) {
            if (string[i] == string[j] && i == j && string[i] != '"') {
                count +=1;
            }
            if (string[i] == string[j] && i < j && string[i] != '"') {
                count += 1;
            }
            if (string[i] == string[j] && i > j) {
                j = length;
            }
        }
        array[index] = string[i];
        array_int[index] = count;
        index += 1;
    }
    array[index] = '\0';

    // sort
    char *letter = " !*,-.0123456789:;?ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int length_letter = my_strlen(letter);
    
    for (i = 0; i < length_letter; i ++) {
        for (j = 0; j < length; j ++) {
            if (letter[i] == array[j] && array_int[j] > 0) {
                printf("%c:%d\n", array[j], array_int[j]);
            }
        }
    }
    return 0;
}
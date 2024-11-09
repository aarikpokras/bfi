#include <stdio.h>

int main() {
    int mem[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int mempos = 0;
    FILE *fptr;
    fptr = fopen("main.bf", "r");
    if (fptr == NULL) {
        printf("main.bf not found.\n");
        return 1;
    }

    fseek(fptr, 0, SEEK_END);
    long size = ftell(fptr);
    rewind(fptr);

    char prog[size+1];
    prog[size] = '\0';
    fread(prog, 1, size, fptr);
    fclose(fptr);

    for (int x = 0; x < size; x++) {
        int i = prog[x];
        if (i == '+') {
            mem[mempos]++;
        } else if (i == '-') {
            mem[mempos]--;
        } else if (i == '>') {
            if (mempos >= 16) {
                mempos = 0;
            } else {
                mempos++;
            }
        } else if (i == '<') {
            if (mempos < 0) {
                mempos = 15;
            } else {
                mempos--;
            }
        } else if (i == '.') {
            printf("%c", mem[mempos]);
        } else if (i == ',') {
            mem[mempos] = getchar();
        } else if (i == '[') {
            if (mem[mempos] == 0) {
                int count = 1;
                while (count > 0) {
                    x++;
                    if (prog[x] == '[') count++;
                    if (prog[x] == ']') count--;
                }
            }
        } else if (i == ']') {
            if (mem[mempos] != 0) {
                int count = 1;
                while (count > 0) {
                    x--;
                    if (prog[x] == '[') count--;
                    if (prog[x] == ']') count++;
                }
            }
        }
    }
    return 0;
}

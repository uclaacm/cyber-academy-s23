#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int regs[8] = {0};
unsigned char bytecode[] = {'m', 2, 1, 's', 2, 0, 'M', 3, 7, 'c', 2, 3, 'j', 'n', 'q', 'm', 5, 0, 'c', 5, 1, 'j', 'l', 's', 'j', 'i', 9, 'a', 6, 5, 'A', 5, 1, 'j', 'i', -18, 'M', 7, 0x05, 'M', 7, 0x39, 'c', 6, 7, 'j', 'n', 'q'};

int main(void) {
    puts("Please input 2 numbers:");
    if (scanf("%d %d", &regs[0], &regs[1]) != 2) {
        puts("Invalid numbers.");
        return 1;
    }
    int flags = 0;
    int shouldJump = 0;
    for (int i = 0; i < sizeof(bytecode) / sizeof(bytecode[0]); i += 3) {
        unsigned char opcode = bytecode[i];
        unsigned char arg1 = bytecode[i + 1];
        unsigned char arg2 = bytecode[i + 2];
        if (opcode == 'm') {
            regs[arg1] = regs[arg2];
        }
        else if (opcode == 'a') {
            regs[arg1] += regs[arg2];
        }
        else if (opcode == 'A') {
            regs[arg1] += (char) arg2;
        }
        else if (opcode == 's') {
            regs[arg1] -= regs[arg2];
        }
        else if (opcode == 'M') {
            regs[arg1] <<= 8;
            regs[arg1] |= arg2;
        }
        else if (opcode == 'c') {
            flags = regs[arg1] - regs[arg2];
        }
        else if (opcode == 'j') {
            shouldJump = 0;
            if (arg1 == 'n') {
                shouldJump = flags != 0;
            } else if (arg1 == 'l') {
                shouldJump = flags < 0;
            } else if (arg1 == 'i') {
                i += (char) arg2;
            }
            if (shouldJump) {
                if (arg2 == 'q') {
                    puts("That's not it!");
                    return 1;
                } else if (arg2 == 's') {
                    i += 3;
                }
            }
        }
    }
    FILE* flagfile = fopen("flag.txt", "r");
    if (flagfile == NULL) {
        puts("Couldn't read flag file. Try connecting to the server to run instead.");
    } else {
        char buf[256];
        fgets(buf, 256, flagfile);
        buf[strcspn(buf, "\n")] = '\0';
        puts("Here's the flag:");
        puts(buf);
    }
    return 0;
}

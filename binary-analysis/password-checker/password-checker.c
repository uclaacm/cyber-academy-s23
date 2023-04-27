#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
    puts("What's the password?");
    fflush(stdout);
    char inp[64];
    fgets(inp, 64, stdin);
    inp[strcspn(inp, "\n")] = '\0';
    unsigned char secret[33] = {247, 67, 187, 99, 211, 162, 81, 220, 88, 86, 147, 142, 133, 255, 230, 174, 60, 28, 65, 96, 20, 180, 224, 108, 141, 146, 35, 243, 142, 38, 63, 125, 0};
    for (int i = 0; i < 50; i ++) {
        for (int j = 0; j < 32; j += 8) {
            long long* ptr = (long long*) (secret + j);
            *ptr *= 1337;
        }
        unsigned char tmp[32];
        for (int j = 0; j < 32; j ++) {
            int offset = j / 4;
            int chunk = j % 4;
            tmp[j] = secret[chunk * 8 + offset];
        }
        memcpy(secret, tmp, 32);
    }
    if (strcmp(inp, (char*) secret) != 0) {
        puts("Nope! My password encryption algorithm proves too good for you!");
        return 1;
    }
    puts("You got the password!");
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

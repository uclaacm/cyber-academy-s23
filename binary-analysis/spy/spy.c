#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(char message[]){
    int secret_message[22] = {68, 111, 117, 98, 108, 101, 79, 104, 83, 101, 118, 101, 110, 82, 101, 112, 111, 114, 116, 105, 110, 103};
    for (int i = 0; i < 22; i++){
        if((int)message[i] != (secret_message[i] + 3)){ //caesar cipher, Shift DoubleOhSevenReporting right by 3 (get GrxeohRkVhyhqUhsruwlqj) 
            return 0;
        }
    }
    return 1;
}

void send_message(){
    puts("I guess it really is you. You know what to do now.");
    FILE* flagfile = fopen("flag.txt", "r");
    if (flagfile == NULL) {
        puts("Couldn't read flag file. Try connecting to the server to run instead.");
    } else {
        char buf[256];
        fgets(buf, 256, flagfile);
        buf[strcspn(buf, "\n")] = '\0';
        puts("Here's the info:");
        puts(buf);
    }
    exit(0);
}

int main(void){
    setbuf(stdout, NULL);
    char buf[256];
    puts("So you've finally discovered this program agent, well done.\nBefore I share this top-secret info with you, I need you to confirm your identity. Make sure to encrypt your response, we never know who's watching...");
    fgets(buf, 256, stdin);
    int test = compare(buf);
    if (test){
        send_message();
    }
    puts("I knew there was somethin sus about you... suck it imposter >:(");
    return 0;
}
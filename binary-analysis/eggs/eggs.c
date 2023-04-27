#include <stdio.h>
#include <string.h>

int func1(int number);
int func2(int number);

int func1(int number){ //odd
	if (number==0) 
		return 0;
	else
		return func2(number-1);
}
int func2(int number){ //even
	if(number==0) 
		return 1;
	else
		return func1(number-1);
}

int main(void){
    fflush(stdout);
    char buf[256];
    printf("hmmm I'm hungry... please feed me one (1) flag. I'm kinda picky so you better make sure it still tastes good, even when it's all scrambled up.\n");
    fgets(buf, 256, stdin);
    buf[strlen(buf)-1] = '\0';
    for(int i = 0; i < 46; i++){
        if(i > (45 - i)){
            char temp = buf[i]; //reverses string
            buf[i] = buf[45-i];
            buf[45-i] = temp;
        }
        else {
           if (func2((int)buf[i])){ //if even.
                buf[i] = buf[i]+8;
           }
           else {
                buf[i] = buf[i]-4;
           }
        }
    }
    if(strcmp(buf, "}mah_emos_ekil_i_dna_mao[oe[ai]v[ui[kttapwc]tn") == 0){
        printf("wow... that was so tasty... looks like you just gave me the perfect flag!\n");
        return 0;
    }
    printf("everybody's so creative! hard pass from me man, cook me up another flag next time.\n");
    return 0;
}

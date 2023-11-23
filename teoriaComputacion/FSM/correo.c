#include <stdio.h>

int ord(char c);
char chr(int n);

typedef enum{
    SEARCH_BEFORE_AT,
    SEARCH_AT,
    SEARCH_AFTER_AT,
    SEARCH_DOT,
    SEARCH_AFTER_DOT,
    SEARCH_FINAL
} MACHINE_STATE;

int main(int argc, char **argv){
    int works = 0;
    MACHINE_STATE state = SEARCH_BEFORE_AT;

    for(int character = 0; argv[1][character] != '\0'; character++){
        switch (state)
        {
            case SEARCH_BEFORE_AT:
                if ((ord(argv[1][character]) >= 65 && ord(argv[1][character]) <= 90) || (ord(argv[1][character]) >= 97 && ord(argv[1][character]) <= 122)){
                    state = SEARCH_AT;
                }
                else{
                    printf("The mail doesn't works\n");
                    return 0;
                }
                break;
            
            case SEARCH_AT:
                if (ord(argv[1][character]) == 64){
                    state = SEARCH_AFTER_AT;
                }
                else if ((ord(argv[1][character]) >= 65 && ord(argv[1][character]) <= 90) || (ord(argv[1][character]) >= 97 && ord(argv[1][character]) <= 122) || (ord(argv[1][character]) == 46) || (ord(argv[1][character]) == 95) || (ord(argv[1][character]) >= 48 && ord(argv[1][character]) <= 57)){
                    state = SEARCH_AT;
                }
                else{
                    printf("The mail doesn't works\n");
                    return 0;
                }

                break;

            case SEARCH_AFTER_AT:
                if((ord(argv[1][character]) >= 65 && ord(argv[1][character]) <= 90) || (ord(argv[1][character]) >= 97 && ord(argv[1][character]) <= 122) || (ord(argv[1][character]) >= 48 && ord(argv[1][character]) <= 57)){
                    state = SEARCH_DOT;
                }
                else{
                    printf("The mail doesn't works\n");
                    return 0;
                }
                break;


            case SEARCH_DOT:
                if(ord(argv[1][character]) == 46){
                    state = SEARCH_AFTER_DOT;
                }
                else if((ord(argv[1][character]) >= 65 && ord(argv[1][character]) <= 90) || (ord(argv[1][character]) >= 97 && ord(argv[1][character]) <= 122) || (ord(argv[1][character]) >= 48 && ord(argv[1][character]) <= 57)){
                    state = SEARCH_DOT;
                }
                else{
                    printf("The mail doesn't works\n");
                    return 0;
                }
                break;
            
            case SEARCH_AFTER_DOT:
                if((ord(argv[1][character]) >= 65 && ord(argv[1][character]) <= 90) || (ord(argv[1][character]) >= 97 && ord(argv[1][character]) <= 122)){
                    state = SEARCH_FINAL;
                }
                else{
                    printf("The mail doesn't works\n");
                    return 0;
                }
                break;

            case SEARCH_FINAL:
                if((ord(argv[1][character]) >= 65 && ord(argv[1][character]) <= 90) || (ord(argv[1][character]) >= 97 && ord(argv[1][character]) <= 122)){
                    state = SEARCH_FINAL;
                    works = 1;
                }
                else if(ord(argv[1][character]) == 46){
                    state = SEARCH_AFTER_DOT;
                    works = 0;
                }
                else{
                    printf("The mail doesn't works\n");
                    return 0;
                }
                break;
        }
    }

    if(works == 0){
        printf("The mail doesn't works\n");
    }
    else{
        printf("The mail works\n");
    }

    return 0;
}

int ord(char c) { 
    return (int)c; 
}

char chr(int n) { 
    return (char)n; 
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void solve(unsigned long long int num);

int main(int argc, char **argv){

    FILE *file = fopen(argv[1], "r"); 
    
    if (file == NULL){
        fprintf(stderr, "Error: couldn't open the fiel\n");
        return (EXIT_FAILURE);
    }

    char line[100];

    while (fgets(line, sizeof(line), file)){
        unsigned long long int number = strtoll(line, NULL, 10);

        solve(number);
    }
    
    fclose(file);
    
    return (EXIT_SUCCESS);
}


void solve(unsigned long long int num){

    for (int i = 2; i < 10; i++){
        if (num%i == 0){
            printf("%llu=%llu*%d\n", num, num/i, i);
            return;
        }
    }
}

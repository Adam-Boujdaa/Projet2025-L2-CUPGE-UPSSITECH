 #include <stdio.h>
 #include <stdlib.h>
 #include "lorenz.h"

void ask_parametres_lorentz (){
    float sigma;
    float beta;
    printf("Choisir parametre sigma : ");
    scanf("%f", &sigma);
    printf("Choisir parametre beta : ");
    scanf("%f", &beta);
}

void ask_coordonnees(){
    float x;
    float y;
    float z;
    printf("Choisir coordonnee x : ");
    scanf("%f", &x);
    printf("Choisir coordonnee y : ");
    scanf("%f", &y);
    printf("Choisir coordonnee z : ");
    scanf("%f", &z);
}

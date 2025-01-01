 #include <stdio.h>
 #include <stdlib.h>
 #include "lorenz.h"

Params *ask_parametres_lorentz (){
    Params *params = malloc (sizeof(struct lorenz_settings));
    printf("Choisir parametre sigma : \n");
    scanf("%lf", &(params->sigma));
    printf("Choisir parametre rho : \n");
    scanf("%lf", &(params->rho));
    printf("Choisir parametre beta : \n");
    scanf("%lf", &(params->beta));
    printf("Choisir parametre dt : \n");
    scanf("%lf", &(params->dt));
    return params;
}

Coord *ask_position_initiale(){       // Permet de demander la position initiale
    Coord* position = malloc(sizeof(struct coord));
    printf("Choisir coordonnee x : \n");
    scanf("%lf", &(position->x));
    printf("Choisir coordonnee y : \n");
    scanf("%lf", &(position->y));
    printf("Choisir coordonnee z : \n");
    scanf("%lf", &(position->z));
    return position;
}

void init_ltz(Coord *point) {
    point->x = x;
    point->y = y;
    point->z = z;
}

void actualiser_ltz(Coord *point, Params *para) {
    double dx = para->sigma * (point->y - point->x);
    double dy = point->x * (para->rho - point->z) - point->y;
    double dz = point->x * point->y - para->beta * point->z;

    point->x += dx * para->dt;
    point->y += dy * para->dt;
    point->z += dz * para->dt;
}

void creation_ltz(SysDynamique *systeme) {
    systeme->pt_initial = init_ltz;
    systeme->pt_actualiser = actualiser_ltz;

    Params *param = ask_parametres_lorentz();
    
    systeme->param.sigma = params->sigma;
    systeme->param.rho = params->rho;
    systeme->param.beta = params->beta;
    systeme->param.dt = params->dt;
}

void choisir_sys(SysDynamique *systeme) {
    printf("Liste du choix du système dynamique :\n");
    printf("1 : Système de Lorentz.\n");
    printf("Votre choix :\n");

    int choix;

    scanf("%d",&choix);

    if (choix == 1) {
        printf("Vous avez choisi le système de Lorenz.\n");
        creation_ltz(systeme);
    }
}



#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

struct gameDifficulty {
    int size;
    int index;
    int lenght;
};

void menu(void);

int main(){//MAINMIANMAINMIANMAINMIANMAINMIANMAINMIANMAINMIANMAINMIANMAINMIANMAINMIAN

int eleccion, doNotProcess, i;

char *facil_palabraOculta[]={
"casa", "perro", "gato", "mesa", "silla", "libro", "arbol", "agua", "fuego", "cielo", "luna", "sol", "mar", "flor", "pan", "queso", "leche", "arroz", "playa", "calle", "coche", "tren", "avion", "amigo", "noche"
};
char *medio_palabraOculta[]={
"ventana", "escuela", "comida", "camisa", "zapatos", "familia", "trabajo", "ciudad", "verano", "invierno", "jardin", "camino", "musica", "pelicula", "telefono", "teclado", "pantalla", "programa", "escuela", "mercado", "dinero", "tiempo", "estrella", "cuchara", "botella"
};
char *dificil_palabraOculta[]={
"vacaciones", "ordenador", "tecnologia", "habitacion", "estudiante", "biblioteca", "documento", "fotografia", "primavera", "septiembre", "chocolate", "desayuno", "aeropuerto", "bicicleta", "aplicacion", "calendario", "transporte", "seguridad", "comunidad", "desarrollo", "impresora", "ventilador", "dispositivo", "television", "ingeniero"
};
char hiddenWord[20], enteredGuess[20];
char playAgain='Y';
bool status=true, allLettersAreGuessed=false;

while (status==true){

system("cls");
menu();
scanf("%d",&eleccion);

while (eleccion<0 || eleccion>3){//checking the correctness of the entered number
    system("cls");
    printf("\nMUST BE AN ERROR. TRY AGAIN\n\n");
    menu();
    scanf("%d",&eleccion);
}

switch (eleccion){
case 1://NIVEL FACIL
    struct gameDifficulty facil;
    playAgain='Y';

    while (playAgain=='Y' || playAgain=='y'){
    system("cls");
    facil.size = sizeof(facil_palabraOculta) / sizeof(facil_palabraOculta[0]);
    srand(time(NULL));
    facil.index = rand() % facil.size;
    strcpy(hiddenWord, facil_palabraOculta[facil.index]);
    facil.lenght = strlen(facil_palabraOculta[facil.index]);

    printf("\nTHE WORD IS: %s",facil_palabraOculta[facil.index]);
    printf("\nEASY MODE\n");

    allLettersAreGuessed=false;

    while(allLettersAreGuessed==false){
        for (i=0; i<facil.lenght; i++){
        printf("_ ");
        }

        i=6;
        while (i>1){
        printf("\nYou have %d more guesses!",i);
        printf("\nEnter a letter or try to guess the complete word!\n\n");
        scanf("%19s",enteredGuess);

        //for (int n=0; n>25; n++){
            //if (enteredLetter)
        //}

        if (strcmp(hiddenWord, enteredGuess) == 0){
            printf("\nYou won! The word was:  %s",hiddenWord);
            allLettersAreGuessed=true;
            break;
        }
        i--;
        }
    }

    printf("\n\n\nDesire to play again? (Y/N): ");
    scanf(" %c",&playAgain);
    }
    break;

case 2://NIVEL MEDIO
    struct gameDifficulty medio;
    system("cls");

    break;
case 3://NIVEL DIFICIL
    struct gameDifficulty dificil;
    system("cls");

    break;
case 0://END OF PROGRAMM
    system("cls");
    printf("\nSEE YA\n\n");
    return 0;
        }
    }

return 0;
}



void menu(void){//MENUU
printf("\nWELCOME TO THE AHORCADO GAME");
printf("\nPRESS 1 TO SELECT EASY DIFFICULTY");
printf("\nPRESS 2 TO SELECT MEDIUM DIFFICULTY");
printf("\nPRESS 3 TO SELECT HARD DIFFICULTY YO");
printf("\nOR PRESS 0 IFF U WANNA LEAVE");
printf("\n\nUR CHOICE??:  ");
}

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

int eleccion, contGuesses=6;

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
bool status=true, endGame=false;

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

    char guessedLetters[25]={0};
    contGuesses=6;
    endGame=false;

    while(endGame==false){
        system("cls");

        printf("\n- - - EASY MODE - - -\n");
        printf("\nTHE WORD IS: %s\n\n",facil_palabraOculta[facil.index]);//DELETE THIS

        for (int i=0; i<facil.lenght; i++){ //ENTERING THE  HIDDEN WORD

        if (guessedLetters[i]!='\0')
            printf(" %c",guessedLetters[i]);
        else
            printf(" _");
        }

        printf("\n\nYou have %d more guesses!",contGuesses);
        printf("\nEnter a letter or try to guess the word completely!\n\n");
        scanf("%19s",enteredGuess);

        for (int i=0; i<facil.lenght; i++){
            if (enteredGuess[0]==hiddenWord[i])
                guessedLetters[i]=enteredGuess[0];
        }

        if (strcmp(hiddenWord, enteredGuess) == 0 || strcmp(hiddenWord, guessedLetters) == 0){//checking if the word has been guessed
            printf("\nYou won! The word was:  %s",hiddenWord);
            endGame=true;
            break;
        }
        contGuesses--;
        if (contGuesses<1 && strcmp(hiddenWord, enteredGuess) != 0){ //game ends when player is out of guesses
            printf("\n\nYou lost :c\n\nThe word was:  %s",hiddenWord);
            endGame=true;
            break;
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

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

bool status=true;

while (status==true){

system("cls");
menu();
scanf("%d",&eleccion);

while (eleccion<0 || eleccion>3){//verificando si el numero ingresado es correcto
    system("cls");
    printf("\nDEBE HABER UN ERROR. INTENTA DE NUEVO.\n\n");
    menu();
    scanf("%d",&eleccion);
}

switch (eleccion){
case 1://NIVEL FACIL
    struct gameDifficulty facil;

    char playAgain='Y';

    while (playAgain=='Y' || playAgain=='y'){
    system("cls");
    facil.size = sizeof(facil_palabraOculta) / sizeof(facil_palabraOculta[0]);
    srand(time(NULL));
    facil.index = rand() % facil.size;
    strcpy(hiddenWord, facil_palabraOculta[facil.index]);
    facil.lenght = strlen(facil_palabraOculta[facil.index]);

    char guessedLetters[25]={0};
    contGuesses=6;
    bool endGame=false;

    while(endGame==false){
        system("cls");

        printf("\n- - - MODO FACIL - - -\n");
        printf("\nLA PALABRA ES: %s\n\n",facil_palabraOculta[facil.index]);//BORRAR ESTO DESPUES

        for (int i=0; i<facil.lenght; i++){ //INGRESE LA PALABRA OCULTA

        if (guessedLetters[i]!='\0')
            printf(" %c",guessedLetters[i]);
        else
            printf(" _");
            }

        printf("\n\nTe quedan %d intentos mas!",contGuesses);
        printf("\nIngresa una letra o intenta adivinar la palabra completa!\n\n");
        scanf("%19s",enteredGuess);

        bool letterFound=false;

        for (int i=0; i<facil.lenght; i++){
            if (enteredGuess[0]==hiddenWord[i]){
                guessedLetters[i]=enteredGuess[0];
                letterFound=true;
                }
            }

        if (letterFound==false)
            contGuesses--;

        if (strcmp(hiddenWord, enteredGuess) == 0 || strcmp(hiddenWord, guessedLetters) == 0){//verificando si la palabra ha sido adivinada
            printf("\nGanaste! La palabra era:  %s",hiddenWord);
            endGame=true;
            break;
            }

        if (contGuesses<1){ //el juego termina cuando el jugador se queda sin intentos
            printf("\n\nPerdiste :c\n\nLa palabra era:  %s",hiddenWord);
            endGame=true;
            break;
            }

        }

    printf("\n\n\nQueres jugar de nuevo? (Y/N): ");
    scanf(" %c",&playAgain);
    }
    break;

case 2://MODO MEDIO
    struct gameDifficulty medio;
    system("cls");

    break;
case 3://MODO DIFICIL
    struct gameDifficulty dificil;
    system("cls");

    break;
case 0://SALIR DEL PROGRAMA
    system("cls");
    printf("\nGRACIAS POR PARTICIPAR\n\n");
    return 0;
        }
    }

return 0;
}



void menu(void){//MENUU
printf("\n- - - BIENVENIDO AL JUEGO DEL AHORCADO - - -\n");
printf("\n  INGRESE 1 PARA SELECCIONAR LA DIFICULTAD FACIL");
printf("\n  INGRESE 2 PARA SELECCIONAR LA DIFICULTAD MEDIO");
printf("\n  INGRESE 3 PARA SELECCIONAR LA DIFICULTAD DIFICIL");
printf("\n  O INGRESE 0 SI QUERES SALIR");
printf("\n\nINGRESE LA OPCION DESEADA:  ");
}

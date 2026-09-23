#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void menu(void);
void dibujo(int a);

int main(){//MAINMIANMAINMIANMAINMIANMAINMIANMAINMIANMAINMIANMAINMIANMAINMIANMAINMIAN

int eleccion;

char *facil_palabraOculta[]={
"casa", "perro", "gato", "mesa", "silla", "libro", "arbol", "agua", "fuego", "cielo", "luna", "sol", "mar", "flor", "pan", "queso", "leche", "arroz", "playa", "calle", "coche", "tren", "avion", "amigo", "noche"
};
char *medio_palabraOculta[]={
"ventana", "escuela", "comida", "camisa", "zapatos", "familia", "trabajo", "ciudad", "verano", "invierno", "jardin", "camino", "musica", "pelicula", "telefono", "teclado", "pantalla", "programa", "escuela", "mercado", "dinero", "tiempo", "estrella", "cuchara", "botella"
};
char *dificil_palabraOculta[]={
"vacaciones", "ordenador", "tecnologia", "habitacion", "estudiante", "biblioteca", "documento", "fotografia", "primavera", "septiembre", "chocolate", "desayuno", "aeropuerto", "bicicleta", "aplicacion", "calendario", "transporte", "seguridad", "comunidad", "desarrollo", "impresora", "ventilador", "dispositivo", "television", "ingeniero"
};

char *modoString[]={"\033[32mFACIL\033[0m", "\033[33mMEDIO\033[0m", "\033[31mDIFICIL\033[0m"};
char modo[20];

char **palabraOculta;
int palabraOcultaSize;

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

switch (eleccion){//seleccion del modo
case 0://SALIR DEL PROGRAMA
    system("cls");
    printf("\nGRACIAS POR PARTICIPAR\n\n");
    return 0;
case 1://NIVEL FACIL
    palabraOculta=facil_palabraOculta;
    palabraOcultaSize = sizeof(facil_palabraOculta) / sizeof(facil_palabraOculta[0]);

    strcpy(modo, modoString[0]);
    break;
case 2://medio
    palabraOculta=medio_palabraOculta;
    palabraOcultaSize = sizeof(medio_palabraOculta) / sizeof(medio_palabraOculta[0]);

    strcpy(modo, modoString[1]);
    break;
case 3://dificil
    palabraOculta=dificil_palabraOculta;
    palabraOcultaSize = sizeof(dificil_palabraOculta) / sizeof(dificil_palabraOculta[0]);

    strcpy(modo, modoString[2]);
    break;
    }

    char playAgain='Y';

    while (playAgain=='Y' || playAgain=='y'){

    char hiddenWord[20], enteredGuess[20];

    srand(time(NULL));
    int index = rand() % palabraOcultaSize;
    strcpy(hiddenWord, palabraOculta[index]);
    int lenght = strlen(palabraOculta[index]);

    char guessedLetters[25]={0};
    char wrongLetters[26] = {0};

    int contGuesses=6;
    int contWrong = 0;

    bool endGame=false;

while(endGame==false){//juego
    system("cls");
    printf("\n- - - - - - - - - MODO %s - - - - - - - - -\n",modo);
    //printf("\nLA PALABRA ES: %s\n",palabraOculta[index]); // <-------------------------------BORRAR ESTO DESPUES (esto es para mostrar la palabra)
    dibujo(contGuesses);

    printf("\nLa palabra es: ");
    for (int i=0; i<lenght; i++){//muestra las letras correctas o espacio
        if (guessedLetters[i]!='\0')
            printf("\033[32m %c\033[0m",guessedLetters[i]);
        else
            printf(" _");
    }

    printf("\n\nLetras \033[31mincorrectas\033[0m: ");
    for (int i=0; i<contWrong; i++){//muestra las letras incorrectas
    printf("\033[31m %c\033[0m ", wrongLetters[i]);
    }

    printf("\n\nTe quedan %d intentos mas!",contGuesses);
    printf("\nIngresa una letra o intenta adivinar la palabra completa!\n\n\n");
    scanf("%19s",enteredGuess);

    bool letterFound=false;
    for (int i=0; i<lenght; i++){//verifica si la letra esta en la palabra oculta
        if (enteredGuess[0]==hiddenWord[i]){
            guessedLetters[i]=enteredGuess[0];
            letterFound=true;
        }
    }

    if (letterFound==false){//si la letra no esta en la palabra reduce el contador de intentas y guarde la letra
        contGuesses--;
        wrongLetters[contWrong] = enteredGuess[0];
        contWrong++;
        }

    if (strcmp(hiddenWord, enteredGuess) == 0 || strcmp(hiddenWord, guessedLetters) == 0){//verefica si la palabra ya esta adivinada completamente
        system("cls");
        dibujo(contGuesses);
        printf("\n\033[32mGanaste!\033[0m La palabra era:  \033[32m%s\033[0m",hiddenWord);
        endGame=true;
        break;
    }

    if (contGuesses<1){//termina el juego cunado no quedan intentos
        system("cls");
        dibujo(contGuesses);
        printf("\n\n\033[31mPerdiste\033[0m :c\n\nLa palabra era:  \033[31m%s\033[0m",hiddenWord);
        endGame=true;
        break;
    }
}

    printf("\n\n\nQueres jugar de nuevo? (Y/N): ");
    scanf(" %c",&playAgain);
    }

    }

return 0;
}



void menu(void){//MENUU
    printf("\nX--------------- BIENVENIDO AL JUEGO DEL AHORCADO ---------------- X");
    printf("\n|                                                                  |");
    printf("\n|  INGRESE \033[32m1\033[0m PARA SELECCIONAR LA DIFICULTAD \033[32mFACIL\033[0m (3-5 letras)     |");
    printf("\n|  INGRESE \033[33m2\033[0m PARA SELECCIONAR LA DIFICULTAD \033[33mMEDIO\033[0m (6-8 letras)     |");
    printf("\n|  INGRESE \033[31m3\033[0m PARA SELECCIONAR LA DIFICULTAD \033[31mDIFICIL\033[0m (9-10 letras)  |");
    printf("\n|                                                                  |");
    printf("\n|  O INGRESE 0 SI QUERES SALIR                                     |");
    printf("\n|                                                                  |");
    printf("\nX ---------------------------------------------------------------- X");
    printf("\n\n        INGRESE LA OPCION DESEADA:    ");
}

void dibujo(int a){

    switch (a){
    case 6:
        printf("\n ___________.._______");
        printf("\n| .__________))______|");
        printf("\n| | / /      ||");
        printf("\n| |/ /       ||");
        printf("\n| | /        ||");
        printf("\n| |/         ||");
        printf("\n| |          ||");
        printf("\n| |         ( _ )");
        printf("\n| |\n| |\n| |\n| |\n| |\n| |\n| |\n| |\n| |");
        printf("\n| |       ___________");
        printf("\neternal\"\"\"|_________|\"\"\"|");
        printf("\n|\"|\"\"\"\"\"\"\"          '\"|\"|");
        printf("\n| |                   | |");
        printf("\n: :                   : :");
        printf("\n. .                   . .\n\n");

        break;
    case 5:
        printf("\n ___________.._______");
        printf("\n| .__________))______|");
        printf("\n| | / /      ||");
        printf("\n| |/ /       ||");
        printf("\n| | /        ||.-''.");
        printf("\n| |/         |/  _  \\ ");
        printf("\n| |          ||  O/o| ");
        printf("\n| |          (\\\\`_.' ");
        printf("\n| |\n| |\n| |\n| |\n| |\n| |\n| |\n| |\n| |");
        printf("\n| |       ___________");
        printf("\neternal\"\"\"|_________|\"\"\"|");
        printf("\n|\"|\"\"\"\"\"\"\"          '\"|\"|");
        printf("\n| |                   | |");
        printf("\n: :                   : :");
        printf("\n. .                   . .\n\n");

        break;
    case 4:
        printf("\n ___________.._______");
        printf("\n| .__________))______|");
        printf("\n| | / /      ||");
        printf("\n| |/ /       ||");
        printf("\n| | /        ||.-''.");
        printf("\n| |/         |/  _  \\ ");
        printf("\n| |          ||  O/o| ");
        printf("\n| |          (\\\\`_.' ");
        printf("\n| |         .-`--'.");
        printf("\n| |         | . . |");
        printf("\n| |          |   |");
        printf("\n| |          | . |");
        printf("\n| |          | _ |");
        printf("\n| |          \\   / ");
        printf("\n| |\n| |\n| |");
        printf("\n| |       ___________");
        printf("\neternal\"\"\"|_________|\"\"\"|");
        printf("\n|\"|\"\"\"\"\"\"\"          '\"|\"|");
        printf("\n| |                   | |");
        printf("\n: :                   : :");
        printf("\n. .                   . .\n\n");

        break;
    case 3:
        printf("\n ___________.._______");
        printf("\n| .__________))______|");
        printf("\n| | / /      ||");
        printf("\n| |/ /       ||");
        printf("\n| | /        ||.-''.");
        printf("\n| |/         |/  _  \\ ");
        printf("\n| |          ||  O/o| ");
        printf("\n| |          (\\\\`_.' ");
        printf("\n| |         .-`--'.");
        printf("\n| |         | . . Y\\ ");
        printf("\n| |          |   | \\\\");
        printf("\n| |          | . |  \\\\");
        printf("\n| |          | _ |   (`");
        printf("\n| |          \\   / ");
        printf("\n| |\n| |\n| |");
        printf("\n| |       ___________");
        printf("\neternal\"\"\"|_________|\"\"\"|");
        printf("\n|\"|\"\"\"\"\"\"\"          '\"|\"|");
        printf("\n| |                   | |");
        printf("\n: :                   : :");
        printf("\n. .                   . .\n\n");

        break;
    case 2:
                printf("\n ___________.._______");
        printf("\n| .__________))______|");
        printf("\n| | / /      ||");
        printf("\n| |/ /       ||");
        printf("\n| | /        ||.-''.");
        printf("\n| |/         |/  _  \\ ");
        printf("\n| |          ||  O/o| ");
        printf("\n| |          (\\\\`_.' ");
        printf("\n| |         .-`--'.");
        printf("\n| |        /Y . . Y\\ ");
        printf("\n| |       // |   | \\\\ ");
        printf("\n| |      //  | . |  \\\\ ");
        printf("\n| |     ')   | _ |   (`");
        printf("\n| |          \\   / ");
        printf("\n| |\n| |\n| |");
        printf("\n| |       ___________");
        printf("\neternal\"\"\"|_________|\"\"\"|");
        printf("\n|\"|\"\"\"\"\"\"\"          '\"|\"|");
        printf("\n| |                   | |");
        printf("\n: :                   : :");
        printf("\n. .                   . .\n\n");

        break;
    case 1:
        printf("\n ___________.._______");
        printf("\n| .__________))______|");
        printf("\n| | / /      ||");
        printf("\n| |/ /       ||");
        printf("\n| | /        ||.-''.");
        printf("\n| |/         |/  _  \\ ");
        printf("\n| |          ||  O/o| ");
        printf("\n| |          (\\\\`_.' ");
        printf("\n| |         .-`--'.");
        printf("\n| |        /Y . . Y\\ ");
        printf("\n| |       // |   | \\\\ ");
        printf("\n| |      //  | . |  \\\\ ");
        printf("\n| |     ')   | _ |   (`");
        printf("\n| |          ||  /");
        printf("\n| |          ||");
        printf("\n| |          ||");
        printf("\n| |          ||");
        printf("\n| |         / |");
        printf("\neternal\"\"\"|_________|\"\"\"|");
        printf("\n|\"|\"\"\"\"\"\"\"          '\"|\"|");
        printf("\n| |                   | |");
        printf("\n: :                   : :");
        printf("\n. .                   . .\n\n");

        break;
    case 0:
        printf("\n ___________.._______");
        printf("\n| .__________))______|");
        printf("\n| | / /      ||");
        printf("\n| |/ /       ||");
        printf("\n| | /        ||.-''.");
        printf("\n| |/         |/  _  \\ ");
        printf("\n| |          ||  `/,| ");
        printf("\n| |          (\\\\`_.' ");
        printf("\n| |         .-`--'.");
        printf("\n| |        /Y . . Y\\ ");
        printf("\n| |       // |   | \\\\ ");
        printf("\n| |      //  | . |  \\\\ ");
        printf("\n| |     ')   | _ |   (`");
        printf("\n| |          || ||");
        printf("\n| |          || ||");
        printf("\n| |          || ||");
        printf("\n| |          || ||");
        printf("\n| |         / | | \\");
        printf("\neternal\"\"\"|_`-' `-' |\"\"\"| ");
        printf("\n|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"| ");
        printf("\n| |        \\ \\        | |");
        printf("\n: :         \\ \\       : : ");
        printf("\n. .          `'       . .\n\n");

        break;
        }

}

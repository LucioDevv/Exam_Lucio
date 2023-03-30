#include <string>
#include <iostream>

using namespace std;

int JugarSalir = 0;
int SalirConfirm;

int askNumber(string question, int high, int low)
{
    int number = 0;

    do {
        cout << question << "entre " << low << " y " << high << endl;
        cin >> number;
    } while (number > high || number < low);

    return number;
}

void ExitFunc() {
    cout << endl << "Seguro que quiere salir?" << endl;
    cout << "1. Salir" << endl << "2. Regresar" << endl << endl;
    cin >> SalirConfirm;

    system("clear");

    if (SalirConfirm == 1)
    {
        cout << endl << "Saliendo del programa...";
    }
    else if (SalirConfirm == 2) {

    }
    else {
        cout << endl << "Escoja una opcion valida." << endl << endl;

    }
}

void JuegoRango()
{
    int SalirDelJuego = 0;
    int menor = 0;
    int mayor = 0;

    int srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    int secretNumber = (randomNumber % ((mayor + 1) - menor)) + menor;
    int guess;
    int tries = 0;
    int veryClose;

    do {
        cout << endl << "Ingrese el rango menor:" << endl;
        cin >> menor;
        cout << endl << "Ingrese el rango mayor:" << endl;
        cin >> mayor;

        if (menor < mayor) {
            do {
                secretNumber = (randomNumber % ((mayor + 1) - menor)) + menor;
                guess = askNumber("\nIngresa un numero\n", mayor, menor);

                tries++;

                veryClose = secretNumber - guess;


                if (veryClose <= 5 && veryClose >= -5 && veryClose != 0)
                {
                    cout << "Muy cerca!!\n";
                }

                if (guess > secretNumber) {
                    cout << "Muy Alto\n\n";
                }
                else if (guess < secretNumber) {
                    cout << "Muy Bajo\n\n";
                }
                else {
                    cout << "Felicidades! Lo adviniaste en -- " << tries << "-- intentos" << endl;
                    cout << endl << "Desea seguir jugando?" << endl;
                    cout << "1. Intentar otra vez." << endl << "2. Salir del programa." << endl << endl;
                    cin >> SalirDelJuego;

                    system("clear");

                    if (SalirDelJuego == 1)
                    {
                        JuegoRango();
                    }
                    else if (SalirDelJuego == 2) {
                        ExitFunc();
                    }
                    else {
                        cout << endl << "Escoja una opcion valida." << endl;
                        system("pause");
                    }

                }

            } while (guess != secretNumber && SalirDelJuego != 1);

            break;

        }
        else {
            system("clear");
            JuegoRango();
        }

    } while (menor < mayor);

}


int main()
{

    do {
        cout << endl << "GUESS MY NUMBER MENU!" << endl;
        cout << "1. Jugar" << endl << "2. Salir" << endl << endl;
        cin >> JugarSalir;
        if (JugarSalir == 1)
        {
            JuegoRango();
        }
        else if (JugarSalir == 2) {
            ExitFunc();
        }
        else {
            cout << endl << "Escoja una opcion valida." << endl << endl;
        }
    } while (SalirConfirm != 1);
}

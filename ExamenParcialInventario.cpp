#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void vectorsPart1();

int main()
{
    vectorsPart1();
}

void vectorsPart1()
{

    vector<string> inventory;
    vector<string> words;

    int currentInvSize;
    int nextItem;
    int maxInvSize = 5;
    int opcion;
    int gemas = 250;
    int objeto1;
    int objeto2;

 
    words.push_back("Bomba");
    words.push_back("Rifle");
    words.push_back("Antorcha");
    words.push_back("Capa");
    words.push_back("Espada");
    words.push_back("Escudo");
    words.push_back("Martillo");

    srand(time(NULL));
    int randomNumber = rand();
    int wordsRandomIndex = (randomNumber % words.size());
    string wordSelected = words[wordsRandomIndex];

    inventory.push_back("Espada");
    inventory.push_back("Escudo");
    inventory.push_back("Martillo");

    currentInvSize = inventory.size();

    do {

        if (currentInvSize >= maxInvSize) {
            randomNumber = rand();
            wordsRandomIndex = (randomNumber % words.size());
            wordSelected = words[wordsRandomIndex];
            cout << "Tienes " << inventory.size() << " items en tu inventario" << endl;
            cout << "Te queda " << maxInvSize - inventory.size() << " items de espacio." << endl;
            cout << "Te encontraste un/a: " << wordSelected << endl;
            cout << "Ya no tiene espacio, desea:" << endl << "1. Reemplazar el objeto con algun objeto de su inventario." << endl << "2. Continuar sin el objeto recogido." << endl << "3. Mejorar su inventario por 50 gemas." << endl << endl;
            for (unsigned int i = 0; i < inventory.size(); i++)
            {
                cout << inventory[i] << endl;
            }
            cout << endl << "Gemas disponibles: " << gemas << " gemas." << endl;
            cin >> opcion;

            do {
                if (opcion == 1)
                {
                    cout << "Cual objeto desea cambiar?" << endl;
                    cin >> objeto1;
                    objeto2 = objeto1 - 1;
                    cout << "\nCambiaste tu " << inventory[objeto2] << " por una " << wordSelected << endl;
                    inventory[objeto2] = wordSelected;
                    break;

                }
                else if (opcion == 2) {
                    cout << "Dejaste " << wordSelected << " en el piso y continuaste caminando." << endl;
                    break;
                }
                else if (opcion == 3) {
                    cout << "Gastando 50 gemas para mejorar tu inventario!" << endl;
                    gemas = gemas - 50;
                    maxInvSize = maxInvSize + 1;
                    currentInvSize = inventory.size();
                    cout << "Ahora te queda " << maxInvSize - inventory.size() << " items de espacio." << endl;
                    break;
                }
                else {
                    cout << "Escoga una opcion valida." << endl;
                    break;
                }
            } while (opcion != 3);

        }
        else {

            if (currentInvSize >= maxInvSize) {
                break;
            }
            else {

                cout << "Tienes " << inventory.size() << " items en tu inventario" << endl;
                cout << "Te queda " << maxInvSize - inventory.size() << " items de espacio." << endl;

                currentInvSize = inventory.size();

                cout << "Ha encontrado " << wordSelected << endl;
                inventory.push_back(wordSelected);

                //Iteration FOR
                for (unsigned int i = 0; i < inventory.size(); i++)
                {
                    cout << inventory[i] << endl;
                }

                currentInvSize = inventory.size();

                randomNumber = rand();
                wordsRandomIndex = (randomNumber % words.size());
                wordSelected = words[wordsRandomIndex];
            }

            }
            
        } while (maxInvSize < 10);

        cout << endl << "Ha llegado al final del juego, gracias por jugar!" << endl;
    }
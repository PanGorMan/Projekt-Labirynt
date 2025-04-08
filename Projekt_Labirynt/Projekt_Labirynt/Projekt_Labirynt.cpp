#include <iostream>
#include <random>
#include <cstdlib>  //do kasowania konsoli
#include <conio.h> //do natychmiastowego cin

using namespace std;

class KLASA_RENDEROWANIE_MAPY {
public:
    void MAPA_RENDER(string(&tablica)[25][21]) {

        random_device rd;  // Pobiera losowe wartości od systemu
        mt19937 gen(rd()); // Generator liczb pseudolosowych
        uniform_int_distribution<int> dist(0, 99); // Zakres 1-100

        int losowa = dist(gen);
        int wybor;

        for (int i = 0; i < 25; i++) {
            fill_n(tablica[i], 21, "_");
        }
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 21; j++) {

                if (((i == 24) or (j == 20)) or ((i == 0) or (j == 0))) {
                    tablica[i][j] = "#";
                }
                if (((i % 2 == 0) && (j % 2 == 0)) or ((i % 2 == 0) && (j % 2 == 0))) {
                    tablica[i][j] = "#";
                }
                if (((i % 2 != 0) && (j % 2 == 0)) or ((i % 2 == 0) && (j % 2 != 0))) {
                    losowa = dist(gen);
                    if (losowa < 43) {
                        tablica[i][j] = "#";
                    }
                }
                if (((i == 2) or (i == 22)) && ((j < 19) && (j > 1))) {
                    tablica[i][j] = "#";
                }
                if (((i == 1) or (i == 23)) && ((j < 20) && (j > 0))) {
                    tablica[i][j] = "_";
                }
                else if (((i == 2) or (i == 22)) && ((j == 1) or (j == 9) or (j == 19))) {
                    tablica[i][j] = "_";
                }
                cout << tablica[i][j] << " ";


            }
            cout << endl;
        }
    }
};

class PORUSZANIE_SIĘ {
public:
    void Ruch(string(&tablica)[25][21], int LG_X, int LG_Y) {


        // PAMIĘTAJ DZBANIE ŻE JEST TO DO GÓRY NOGAMI !!!

        cout << "Lokalizacja X = " << LG_X << endl;
        cout << "Lokalizac = " << LG_Y << endl;

        char odpowiedź = _getch();

        system("cls");

        if (odpowiedź == 's') {
            if ((LG_X != 23) && (tablica[LG_X + 1][LG_Y] != "#")) {
                LG_X++;
            }
        }
        else if (odpowiedź == 'w') {
            if ((LG_X != 1) && (tablica[LG_X - 1][LG_Y] != "#")) { // <- poprawione
                LG_X--;
            }
        }
        else if (odpowiedź == 'd') {
            tablica[LG_X][LG_Y - 1] = "_";
            if ((LG_Y != 19) && (tablica[LG_X][LG_Y + 1] != "#")) { // <- poprawione
                LG_Y++;
            }
        }
        else if (odpowiedź == 'a') {
            if ((LG_Y != 1) && (tablica[LG_X][LG_Y - 1] != "#")) { // <- poprawione
                LG_Y--;
            }
        }
        //Wipisanie Wyniku

        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 21; j++) {
                if ((tablica[i][j] == "A") or (tablica[i][j] == "V") or (tablica[i][j] == "<") or (tablica[i][j] == ">"))
                    tablica[i][j] = "_";
            }
        }

        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 21; j++) {
                if ((i == LG_X) && (j == LG_Y)) {


                    if (odpowiedź == 's') {
                        tablica[i][j] = "V";

                    }
                    else if (odpowiedź == 'w') {
                        tablica[i][j] = "A";

                    }
                    else if (odpowiedź == 'd') {
                        tablica[i][j] = ">";

                    }
                    else if (odpowiedź == 'a') {
                        tablica[i][j] = "<";

                    }
                }
            }

        }

        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 21; j++) {
                cout << tablica[i][j] << " ";
            }
            cout << endl;
        }


        Ruch(tablica, LG_X, LG_Y);


    }
};

int main()
{
    // wartości
    string tablica[25][21];
    int lokalizacja_gracza_X = 23;
    int lokalizacja_gracza_Y = 11;


    KLASA_RENDEROWANIE_MAPY myObj;
    myObj.MAPA_RENDER(tablica);

    PORUSZANIE_SIĘ ruchObj;
    ruchObj.Ruch(tablica, lokalizacja_gracza_X, lokalizacja_gracza_Y);


    return 0;
    cout << "KONIEC!\n";
}

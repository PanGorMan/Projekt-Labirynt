#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <cstdlib>  //do kasowania konsoli
#include <conio.h> //do natychmiastowego cin

using namespace std;

class KLASA_RENDEROWANIE_MAPY {
public:
    void MAPA_RENDER(string(&tablica)[25][21] ,int LP) {

        random_device rd;  // Pobiera losowe wartości od systemu
        mt19937 gen(rd()); // Generator liczb pseudolosowych
        uniform_int_distribution<int> dist(0, 99); // Zakres 1-100

        int losowa = dist(gen);

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

    void Ruch(string(&tablica)[25][21], int LG_X, int LG_Y, int LP) {

        random_device rd;  // Pobiera losowe wartości od systemu
        mt19937 gen(rd()); // Generator liczb pseudolosowych
        uniform_int_distribution<int> dist(0, 99); // Zakres 1-100

        int losowa = dist(gen);

        // PAMIĘTAJ DZBANIE ŻE JEST TO DO GÓRY NOGAMI !!!

        cout << "Lokalizacja X = " << LG_X << endl;
        cout << "Lokalizacja Y =" << LG_Y << endl;
        cout << "Poziom = " << LP << endl;

        char odpowiedź = _getch();
        ifstream plik("grafiki.txt");
        string linia;
        int nr_linii = 0;
        int startLinia = 5;

        system("cls");

        if (odpowiedź == 's') {
            if ((LG_X != 23) && (tablica[LG_X + 1][LG_Y] != "#")) {
                LG_X++;
            }
        }
        else if (odpowiedź == 'w') {
            if ((LG_X != 1) && (tablica[LG_X - 1][LG_Y] != "#")) { 
                LG_X--;
            }
        }
        else if (odpowiedź == 'd') {
            if ((LG_Y != 19) && (tablica[LG_X][LG_Y + 1] != "#")) { 
                LG_Y++;
            }
        }
        else if (odpowiedź == 'a') {
            if ((LG_Y != 1) && (tablica[LG_X][LG_Y - 1] != "#")) {
                LG_Y--;
            }
        }
        else if (odpowiedź == 'x') {

            LG_X = 23;
            LG_Y = 11;

            for (int i = 0; i < 25; i++) {

                for (int j = 0; j < 21; j++) {
                    if (((i == 0) or (i == 24)) or ((j == 0) or (j == 20))) {
                        tablica[i][j] = "#";
                    }
                    else if ((i % 2 != 0) or (j % 2 != 0)) {
                        tablica[i][j] = "_";
                    }

                }
                cout << endl;
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
            Ruch(tablica, LG_X, LG_Y, LP);

        }
        else {


            Ruch(tablica, LG_X, LG_Y, LP);
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
        // system oceniania lokacji
        if ((LG_X == 1) && (LG_Y == 1)) {

            system("cls");

            cout << "QWEQWEQWEQWEQWEQWEQWE";



            while (nr_linii < startLinia - 1 && getline(plik, linia)) {
                nr_linii++;
            }



            for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 21; j++) {
                    cout << tablica[i][j] << " ";
                    if (j == 20) {
                        if (getline(plik, linia)) {
                            cout << linia;
                        }
                    }
                }
                cout << endl;
            }

            Ruch(tablica, LG_X, LG_Y, LP);
            
        }

        if (odpowiedź == 'w') { 
            //cout << (tablica[LG_X - 1][LG_Y - 1]) << (tablica[LG_X - 1][LG_Y]) << (tablica[LG_X - 1][LG_Y + 1]) << "\n" << (tablica[LG_X][LG_Y - 1]) << "A" << (tablica[LG_X][LG_Y + 1]);

            cout << "\n \n \n";
            if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "_") && (tablica[LG_X - 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y - 1] == "#") && (tablica[LG_X][LG_Y + 1] == "#")) {
                startLinia = 2;
            }
            else if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "#") && (tablica[LG_X - 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y - 1] == "_") && (tablica[LG_X][LG_Y + 1] == "#")) {
                startLinia = 28;
            }
            else if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "#") && (tablica[LG_X - 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y - 1] == "#") && (tablica[LG_X][LG_Y + 1] == "_")) {
                startLinia = 54;
            }
            else if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "_") && (tablica[LG_X - 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y - 1] == "_") && (tablica[LG_X][LG_Y + 1] == "#")) {
                startLinia = 80;
            }
            else if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "_") && (tablica[LG_X - 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y - 1] == "#") && (tablica[LG_X][LG_Y + 1] == "_")) {
                startLinia = 106;
            }
            else if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "_") && (tablica[LG_X - 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y - 1] == "_") && (tablica[LG_X][LG_Y + 1] == "_")) {
                startLinia = 132;
            }
            else if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "#") && (tablica[LG_X - 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y - 1] == "#") && (tablica[LG_X][LG_Y + 1] == "#")) {
                startLinia = 158;
            }
            else if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "#") && (tablica[LG_X - 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y - 1] == "_") && (tablica[LG_X][LG_Y + 1] == "_")) {
                startLinia = 184;
            }
            else {
                startLinia = 2;;
            }
        }
                else if (odpowiedź == 's') {
                //cout  << (tablica[LG_X][LG_Y - 1]) << "V" << (tablica[LG_X][LG_Y + 1]) << "\n" << (tablica[LG_X + 1][LG_Y - 1]) << (tablica[LG_X + 1][LG_Y]) << (tablica[LG_X + 1][LG_Y + 1]) << "\n";

            if ((tablica[LG_X][LG_Y - 1] == "#") && (tablica[LG_X][LG_Y + 1] == "#") && (tablica[LG_X + 1][LG_Y - 1] == "#") && (tablica[LG_X + 1][LG_Y] == "_") && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 2;
            }
                else if ((tablica[LG_X][LG_Y - 1] == "_") && (tablica[LG_X][LG_Y + 1] == "#") && (tablica[LG_X + 1][LG_Y - 1] == "#") && (tablica[LG_X + 1][LG_Y] == "#") && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 28;
            }
                    else if ((tablica[LG_X][LG_Y - 1] == "#") && (tablica[LG_X][LG_Y + 1] == "_") && (tablica[LG_X + 1][LG_Y - 1] == "#") && (tablica[LG_X + 1][LG_Y] == "#") && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 54;
            }
                    else if ((tablica[LG_X][LG_Y - 1] == "_") && (tablica[LG_X][LG_Y + 1] == "#") && (tablica[LG_X + 1][LG_Y - 1] == "#") && (tablica[LG_X + 1][LG_Y] == "_") && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 80;
            }
                    else if ((tablica[LG_X][LG_Y - 1] == "#") && (tablica[LG_X][LG_Y + 1] == "_") && (tablica[LG_X + 1][LG_Y - 1] == "#") && (tablica[LG_X + 1][LG_Y] == "_") && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 106;
            }
                    else if ((tablica[LG_X][LG_Y - 1] == "_") && (tablica[LG_X][LG_Y + 1] == "_") && (tablica[LG_X + 1][LG_Y - 1] == "#") && (tablica[LG_X + 1][LG_Y] == "_") && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 132;
            }
                    else if ((tablica[LG_X][LG_Y - 1] == "#") && (tablica[LG_X][LG_Y + 1] == "#") && (tablica[LG_X + 1][LG_Y - 1] == "#") && (tablica[LG_X + 1][LG_Y] == "#") && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 158;
            }
                    else if ((tablica[LG_X][LG_Y - 1] == "_") && (tablica[LG_X][LG_Y + 1] == "_") && (tablica[LG_X + 1][LG_Y - 1] == "#") && (tablica[LG_X + 1][LG_Y] == "#") && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 184;
            }
                    else {
                startLinia = 2;;
            }
        }
                else if (odpowiedź == 'd') {
                //cout << (tablica[LG_X - 1][LG_Y]) <<  (tablica[LG_X - 1][LG_Y + 1]) << "\n" <<  ">" << (tablica[LG_X][LG_Y + 1]) << "\n" << (tablica[LG_X + 1][LG_Y]) << (tablica[LG_X + 1][LG_Y + 1]) << "\n";
            
            if ((tablica[LG_X - 1][LG_Y] == "#") && (tablica[LG_X - 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y + 1] == "_") && (tablica[LG_X + 1][LG_Y] == "#")  && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 2;
            }
            else if ((tablica[LG_X - 1][LG_Y] == "_") && (tablica[LG_X - 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y + 1] == "#") && (tablica[LG_X + 1][LG_Y] == "#")  && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 28;
            }
                      else if ((tablica[LG_X - 1][LG_Y] == "#") && (tablica[LG_X - 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y + 1] == "#") && (tablica[LG_X + 1][LG_Y] == "_")  && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 54;
            }
                      else if ((tablica[LG_X - 1][LG_Y] == "_") && (tablica[LG_X - 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y + 1] == "_") && (tablica[LG_X + 1][LG_Y] == "#")  && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 80;
            }
                      else if ((tablica[LG_X - 1][LG_Y] == "#") && (tablica[LG_X + 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y + 1] == "_") && (tablica[LG_X + 1][LG_Y] == "_")  && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 106;
            }
                      else if ((tablica[LG_X - 1][LG_Y] == "_") && (tablica[LG_X + 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y + 1] == "_") && (tablica[LG_X + 1][LG_Y] == "_")  && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 132;
            }
                      else if ((tablica[LG_X - 1][LG_Y] == "#") && (tablica[LG_X + 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y + 1] == "#") && (tablica[LG_X + 1][LG_Y] == "#")  && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 158;
            }
                      else if ((tablica[LG_X - 1][LG_Y] == "_") && (tablica[LG_X + 1][LG_Y + 1] == "#") && (tablica[LG_X][LG_Y + 1] == "#") && (tablica[LG_X + 1][LG_Y] == "_")  && (tablica[LG_X + 1][LG_Y + 1] == "#")) {
                startLinia = 184;
            }
                      else {
                startLinia = 2;
            }
        }
        
                else if (odpowiedź == 'a') {
        
            if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "#") && (tablica[LG_X][LG_Y - 1] == "_") && (tablica[LG_X + 1][LG_Y - 1] == "#")  && (tablica[LG_X + 1][LG_Y] == "#")) {
                startLinia = 2;
            }
                    else if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "#") && (tablica[LG_X][LG_Y - 1] == "#") && (tablica[LG_X + 1][LG_Y - 1] == "#")  && (tablica[LG_X + 1][LG_Y] == "#")) {
                startLinia = 28;
            }
                                else if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "#") && (tablica[LG_X][LG_Y - 1] == "#") && (tablica[LG_X + 1][LG_Y - 1] == "#")  && (tablica[LG_X + 1][LG_Y] == "_")) {
                startLinia = 54;
            }
                                else if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "_") && (tablica[LG_X][LG_Y - 1] == "#") && (tablica[LG_X + 1][LG_Y - 1] == "#")  && (tablica[LG_X + 1][LG_Y] == "#")) {
                startLinia = 80;
            }
                                else if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "#") && (tablica[LG_X][LG_Y - 1] == "_") && (tablica[LG_X + 1][LG_Y - 1] == "#")  && (tablica[LG_X + 1][LG_Y] == "_")) {
                startLinia = 106;
            }
                                else if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "_") && (tablica[LG_X][LG_Y - 1] == "_") && (tablica[LG_X + 1][LG_Y - 1] == "#")  && (tablica[LG_X + 1][LG_Y] == "_")) {
                startLinia = 132;
            }
                                else if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "#") && (tablica[LG_X][LG_Y - 1] == "#") && (tablica[LG_X + 1][LG_Y - 1] == "#")  && (tablica[LG_X + 1][LG_Y] == "#")) {
                startLinia = 158;
            }
                                else if ((tablica[LG_X - 1][LG_Y - 1] == "#") && (tablica[LG_X - 1][LG_Y] == "_") && (tablica[LG_X][LG_Y - 1] == "_") && (tablica[LG_X + 1][LG_Y - 1] == "#")  && (tablica[LG_X + 1][LG_Y] == "_")) {
                startLinia =  184;
            }
                                else {
                startLinia = 2;
            }
        }
        


        // rysowanie widoku


        while (nr_linii < startLinia - 1 && getline(plik, linia)) {
            nr_linii++;
        }



        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 21; j++) {
                cout << tablica[i][j] << " ";
                if (j == 20) {
                    if (getline(plik, linia)) {
                        cout << linia;
                    }
                }
            }
            cout << endl;
        }

        Ruch(tablica, LG_X, LG_Y , LP);


    }
};

int main()
{

    char strona_tytułowa = 'x';
    ifstream plik("grafiki.txt");
    string Okładka;
    int numer = 5;


    while (getline(plik, Okładka)) {
        if ((numer > 245) && (numer < 304)) {
            cout << Okładka  << "\n";

            numer++;
        }
        numer++;

    }

    while ((strona_tytułowa != 'e')) {
        cout << "                                  ----------> Press e to start <----------";
        strona_tytułowa = _getch();
    }
    strona_tytułowa = 'x';
    system("cls");
    cout << "instrukcja:\n Sterwoanie - w , s , a , d \n restart mapy - x\n cle gry : dostan sie na parter \n Fabula : \n Jako tani pracownik , nadzorujesz stacje 53 .\n Z powodu braku zasilania musisz zrestartowac generatoey ale winda nie dizala. \n Musisz jisc drabinami na samo dno i zrestartowac generatory.\n powodzenia ; ) ";

    while ((strona_tytułowa != 'e')) {
        strona_tytułowa = _getch();
    }

    system("cls");

    // wartości
    string tablica[25][21];
    int lokalizacja_gracza_X = 23;
    int lokalizacja_gracza_Y = 11;
    int Liczba_Poziomu = 30;


    KLASA_RENDEROWANIE_MAPY myObj;
    myObj.MAPA_RENDER(tablica , Liczba_Poziomu);

    PORUSZANIE_SIĘ ruchObj;
    ruchObj.Ruch(tablica, lokalizacja_gracza_X, lokalizacja_gracza_Y, Liczba_Poziomu);


    return 0;
    cout << "KONIEC!\n";
}

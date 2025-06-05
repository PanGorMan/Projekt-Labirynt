#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <cstdlib>  //do kasowania konsoli
#include <conio.h> //do natychmiastowego cin

using namespace std;

class Gra_1 {
private:
    // - graty zaimportowane -
    string(*tablica)[25][21];
    int LG_X;
    int LG_Y;
    int LP;

    // - graty lokalne  -

    random_device rd;
    mt19937 gen;
    uniform_int_distribution<int> dist;

    int losowa;

public:

    Gra_1() : gen(rd()), dist(0, 99), losowa(0) {}  // inicjalizacja generatora

    void Seter(string(&t)[25][21], int LG_X, int LG_Y, int LP) {
        this->tablica = &t;
        this->LG_X = LG_X;
        this->LG_Y = LG_Y;
        this->LP = LP;
        losowa = dist(gen);
    }

    void Generowanie_terenu() {

        losowa = dist(gen);
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 21; j++) {
                (*tablica)[i][j] = "_";
            }
        }
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 21; j++) {

                if (((i == 24) or (j == 20)) or ((i == 0) or (j == 0))) {
                    (*tablica)[i][j] = "#";
                }
                if (((i % 2 == 0) && (j % 2 == 0)) or ((i % 2 == 0) && (j % 2 == 0))) {
                    (*tablica)[i][j] = "#";
                }
                if (((i % 2 != 0) && (j % 2 == 0)) or ((i % 2 == 0) && (j % 2 != 0))) {
                    losowa = dist(gen);
                    if (losowa < 43) {
                        (*tablica)[i][j] = "#";
                    }
                }
                if (((i == 2) or (i == 22)) && ((j < 19) && (j > 1))) {
                    (*tablica)[i][j] = "#";
                }
                if (((i == 1) or (i == 23)) && ((j < 20) && (j > 0))) {
                    (*tablica)[i][j] = "_";
                }
                else if (((i == 2) or (i == 22)) && ((j == 1) or (j == 9) or (j == 19))) {
                    (*tablica)[i][j] = "_";
                }
                cout << (*tablica)[i][j] << " ";

            }
            cout << endl;
        }
    };


    void Ruch() {

        losowa = dist(gen);


    }
};





int  main()
{
    // - okładka -
    char strona_tytułowa = 'x';
    ifstream plik("grafiki.txt");
    string Okładka;
    int numer = 5;

    while (getline(plik, Okładka)) {
        if ((numer > 245) && (numer < 304)) {
            cout << Okładka << "\n";

            numer++;
        }
        numer++;

    }


    cout << "                                  ----------> Press e to start <----------";
    strona_tytułowa = _getch();

    while ((strona_tytułowa != 'e')) {
        strona_tytułowa = _getch();
    }


    strona_tytułowa = 'x';
    system("cls");
    cout << "instrukcja:\n Sterwoanie - w , s , a , d \n restart mapy - x\n cle gry : dostan sie na parter \n Fabula : \n Jako tani pracownik , nadzorujesz stacje 53 .\n Z powodu braku zasilania musisz zrestartowac generatoey ale winda nie dizala. \n Musisz jisc drabinami na samo dno i zrestartowac generatory.\n powodzenia ; ) ";

    while ((strona_tytułowa != 'e')) {
        strona_tytułowa = _getch();
    }

    system("cls");
    // - początkowe komędy :

    string tablica[25][21];
    int lokalizacja_gracza_X = 23;
    int lokalizacja_gracza_Y = 11;
    int Liczba_Poziomu = 10;

    Gra_1* gierka1 = new Gra_1();
    gierka1-> Seter(tablica, lokalizacja_gracza_X, lokalizacja_gracza_Y, Liczba_Poziomu);
    gierka1->Generowanie_terenu();
    gierka1 -> Ruch() ;
}
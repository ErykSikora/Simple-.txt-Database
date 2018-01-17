#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
    char wybor;

    cout << "BAZA DANYCH" << endl;
    cout << "##############" << endl << endl;
    for(;;){
    cout << "Co chcesz dodac do bazy?" << endl;
    cout << "1. Samochod" << endl;
    cout << "2. Ksiazke" << endl;
    cout << "3. Film" << endl;
    cout << "4. Opusc program" << endl << endl;
    wybor=getch();

        switch(wybor){
            case '1': {
                char wyborS;
                string marka, model, kolor;
                int rok;
                float przebieg;
                for (;;){
                    cout << "Marka samochodu: ";        getline(cin,marka);
                    if (marka.empty()) marka="nieznana";
                    cout << "Model: ";        getline(cin,model);
                    if (model.empty()) model="nieznany";
                    cout << "Rok produkcji: ";          cin >> rok;
                    while (rok <= 1900 || rok > 2018) {
                        cout << "Niepoprawne dane! Podaj prawidlowy rok produkcji: ";
                        cin >> rok;
                    }
                    cout << "Przebieg (w tys. km): ";        cin >> przebieg;
                    cout << "Kolor: ";        cin >> kolor;
                    if (kolor.empty()) kolor="nieznany";

                    fstream samochod;
                    samochod.open("samochody.txt", ios::out | ios::app);

                    samochod << "----------------------------" << endl;
                    samochod << "Marka samochodu: " << marka << endl;
                    samochod << "Model: " << model << endl;
                    samochod << "Rok produkcji: " << rok << endl;
                    samochod << "Przebieg: " << przebieg << " tys. km." << endl;
                    samochod << "Kolor: " << kolor << endl;
                    samochod << "----------------------------" << endl << endl;

                    samochod.close();

                    system("cls");
                    for (int i=0;i<=12;i++){
                        cout << ". ";
                        Sleep(300);
                        if (i%3==0){
                            system("cls");
                        }
                    }
                    cout << "Dokonano zapisu!" << endl << endl; Sleep(500);
                    cout << "Wcisnij 1, aby dodac kolejne samochody" << endl;
                    cout << "Wcisnij 2, aby wrocic do menu glownego" << endl;
                    cin >> wyborS;
                        if (wyborS=='1') continue;
                        else if (wyborS=='2') break;
                        else {
                          while (wyborS !='1' || wyborS !='2'){
                            cout << "Niepoprawny wybor! Sprobuj ponownie"; cin >> wyborS;
                          }
                        }
                } break;
            }
            case '2': {
                char wyborK;
                string autor, tytul, gatunek, ile;
                int rok, strony;
                for (;;){
                    cout << "Autor: ";        getline(cin,autor);
                    if (autor.empty()) autor="Autor nieznany";
                    cout << "Tytul: ";                  getline(cin,tytul);
                    if (tytul.empty()) tytul="Tytul nieznany";
                    cout << "Gatunek: ";                  getline(cin,gatunek);
                    if (gatunek.empty()) gatunek="Gatunek nieznany";
                    cout << "Rok wydania: ";          cin >> rok;
                    while (rok <= -1000 || rok > 2018) {
                        cout << "Niepoprawne dane! Podaj prawidlowy rok wydania: ";
                        cin >> rok;
                    }
                    cout << "Ilosc stron: ";   cin >> strony;
                    while(strony<0) {
                        cout << endl << "Niepoprawne dane! Podaj prawidlowa ilosc stron: ";
                        cin >> strony;
                    }
                    if (strony == 0) ile="Nieznana ilosc stron";
                    else if (strony == 1) ile=" strona";
                    else if (strony > 4) ile=" stron";
                    else if (strony >= 2 || strony <= 4) ile=" strony";

                    fstream ksiazki;
                    ksiazki.open("ksiazki.txt", ios::out | ios::app);

                    ksiazki << "----------------------------" << endl;
                    ksiazki << "Autor: " << autor << endl;
                    ksiazki << "Tytul: " << "\"" << tytul << "\"" << endl;
                    ksiazki << "Gatunek: " << gatunek << endl;
                    ksiazki << "Rok wydania: " << rok << " r." << endl;
                    ksiazki << "Ilosc stron: " << strony << ile << endl;
                    ksiazki << "----------------------------" << endl << endl;

                    ksiazki.close();

                    system("cls");
                    for (int i=0;i<=12;i++){
                        cout << ". ";
                        Sleep(300);
                        if (i%3==0){
                            system("cls");
                        }
                    }
                    cout << "Dokonano zapisu!" << endl << endl; Sleep(500);
                    cout << "Wcisnij 1, aby dodac kolejne ksiazki" << endl;
                    cout << "Wcisnij 2, aby wrocic do menu glownego" << endl;
                    cin >> wyborK;
                        if (wyborK=='1') continue;
                        else if (wyborK=='2') break;
                        else {
                          while (wyborK !='1' || wyborK !='2'){
                            cout << "Niepoprawny wybor! Sprobuj ponownie"; cin >> wyborK;
                          }
                        }
                } break;
            }
            case '3': {
                char wyborF;
                string tytul, rezyser, gatunek;
                int rok;
                float czas;
                for (;;){
                    cout << "Tytul filmu: ";        getline(cin,tytul);
                    if (tytul.empty()) tytul="nieznany";
                    cout << "Rezyser: ";        getline(cin,rezyser);
                    if (rezyser.empty()) rezyser="nieznany";
                    cout << "Rok produkcji: ";          cin >> rok;
                    while (rok <= 1700 || rok > 2018) {
                        cout << "Niepoprawne dane! Podaj prawidlowy rok produkcji: ";
                        cin >> rok;
                    }
                    cout << "Czas trwania (w godz.): ";      cin >> czas;

                    fstream filmy;
                    filmy.open("filmy.txt", ios::out | ios::app);

                    filmy << "----------------------------" << endl;
                    filmy << "Tytul: " << tytul << endl;
                    filmy << "Rezyser: " << rezyser << endl;
                    filmy << "Gatunek: " << gatunek << endl;
                    filmy << "Rok produkcji: " << rok << " r." << endl;
                    filmy << "Czas trwania filmu: " << czas << " godz." << endl;
                    filmy << "----------------------------" << endl << endl;

                    filmy.close();

                    system("cls");
                    for (int i=0;i<=12;i++){
                        cout << ". ";
                        Sleep(300);
                        if (i%3==0){
                            system("cls");
                        }
                    }
                    cout << "Dokonano zapisu!" << endl << endl; Sleep(500);
                    cout << "Wcisnij 1, aby dodac kolejne filmy" << endl;
                    cout << "Wcisnij 2, aby wrocic do menu glownego" << endl;
                    cin >> wyborF;
                        if (wyborF=='1') continue;
                        else if (wyborF=='2') break;
                        else {
                            cout << "Niepoprawny wybor! Sprobuj ponownie"; cin >> wyborF;
                          while (wyborF !='1' || wyborF !='2'){
                          }
                        }
                } break;
            }
            case '4': {
                cout << "paaaa!";
                exit(0);
            }
            default: {
                cout << "Niepoprawny wybor! Sprobuj ponownie!";
                break;
            }
        }
        getchar();
        system("cls");
    }

    return 0;
}

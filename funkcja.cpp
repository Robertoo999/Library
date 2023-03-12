#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>
#include <string>
#include <sstream>
#include <conio.h>
using namespace std;

struct czytelnik
{
    string imie;
    string nazwisko;
    string email;
    int telefon;
};
void koniec_wyswietlania()
{
    cout << endl << "Wpisz cokolwiek, aby wrócić do menu głównego." << endl;
    char x = getch();
}
void dodawanie_czytelnika()
{
    int ilecyfr;
    fstream plik;
    fstream czytelnikinfo;
    czytelnik system1[50];
    int n;
    cout<<"Ilu chcesz dodać czytelników: ";
    cin>>n;
    czytelnikinfo.open("dane.txt",ios::out|ios::app);
    plik.open("Czytelnicy.txt",ios::out|ios::app );
    for(int i=0; i<n; i++)
    {
        cout<<"Podaj imię "<<i+1<<" czytelnika: ";
        cin>>system1[i].imie;
        cout<<"Podaj nazwisko "<<i+1<<" czytelnika: ";
        cin>>system1[i].nazwisko;
        cout<<"Podaj 9-cyfrowy numer telefonu "<<i+1<<" czytelnika: ";
        cin>>system1[i].telefon;
        cout<<"Wprowadź adres email "<<i+1<<" czytelnika: ";
        cin>>system1[i].email;
          if (system1[i].email.find('@') == string::npos)
        {
            cout<<"Wprowadzono nieprawidłowy adres e-mail. Podaj poprawny: ";
            cin>>system1[i].email;
        }
        plik<<system1[i].imie<<" ";
        plik<<system1[i].nazwisko<<endl;
        plik<<"<<Puste_miejsce>>"<<endl<<endl;
        czytelnikinfo<<"Imie: "<<system1[i].imie<<endl;
        czytelnikinfo<<"Nazwisko: "<<system1[i].nazwisko<<endl;
        czytelnikinfo<<"Numer_telefonu: "<<system1[i].telefon<<endl;
        czytelnikinfo<<"E-mail: "<<system1[i].email<<endl<<endl;
    }
    czytelnikinfo.close();
    plik.close();
    cout<<"Dodano pomyślnie czytelnika/ów do biblioteki."<<endl;
    koniec_wyswietlania();
}

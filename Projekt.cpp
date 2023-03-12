#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>
#include <string>
#include <sstream>
#include <conio.h>
#include "funkcja.cpp"

using namespace std;

struct ksiazka
{
    string tytul;
    string autor;
    int indeks;
    string wydawnictwo;
    int cena;
};
void wprowadzksiazke();
void pokazksiazki();
void wypozycz();
void oddaj();
void dodawanie_czytelnika();
void wupozyczone();
void czyszczenie_czytelnikow();
void czyszczenie_ksiazek();
void dokladnedane();
void wyczyscdokladnedane();
void usunksiazke();
void koniec_wyswietlania();
void koniec();
void kup();
void pokazdane();
void pokazkupione();
void cofnij();

void intro()
{
    cout<<"Witaj w bibliotece! Wybierz jedną z poniższych opcji wpisując liczbę (1-3)."<<endl;
}

int menu()
{
    int wybor;
    cout<<"MENU GŁÓWNE"<<endl;
    cout<<"1.Zarządzanie książkami."<<endl;
    cout<<"2.Zarządzanie czytelnikami."<<endl;
    cout<<"3.Zakończ program."<<endl;
    cin>>wybor;
    return wybor;
}
int menu1()
{
    int wybor;
    cout << "Co chcesz zrobić?" << endl;
    cout<<"(1) Wprowadź książki do biblioteki."<<endl;
    cout<<"(2) Pokaż jakie są obecnie dostępne książki w bibliotce."<<endl;
    cout<<"(3) Wypożycz książkę z biblioteki."<<endl;
    cout<<"(4) Oddaj książkę do biblioteki."<<endl;
    cout<<"(5) Wyczyść listę książek z biblioteki."<<endl;
    cout<<"(6) Pokaż dokładne dane książek, które kiedykolwiek były w bibliotece."<<endl;
    cout<<"(7) Usuń książkę z biblioteki."<<endl;
    cout<<"(8) Wyczyść listę książek, które kiedykolwiek były w bibliotece i ich dane."<<endl;
    cout<<"(9) Zamów brakujące książki do biblioteki."<<endl;
    cout<<"(10) Wróć do menu początkowego."<<endl;
    cout<<"Co chcesz zrobić? Wpisz odpowiednią cyfrę: "<<endl;
    cin>>wybor;
    return wybor;
}
int menu2()
{
    int wybor;
    cout << "Co chcesz zrobić?" << endl;
    cout<<"(1) Dodaj czytelników do systemu."<<endl;
    cout<<"(2) Pokaż liste czytelników i ich wypożyczone książki."<<endl;
    cout<<"(3) Pokaż dokładne dane czytelników."<<endl;
    cout<<"(4) Wyczyść listę czytelników."<<endl;
    cout<<"(5) Wróć do menu początkowego."<<endl;
    cout<<"Co chcesz zrobić? Wpisz odpowiednią cyfrę: "<<endl;
    cin>>wybor;
    return wybor;
}

void cofnij()
{
}
void wprowadzksiazke()
{
    int n;
    int szukaj;
    string tekst;
    ksiazka baza[100];
    cout<<"Podaj ilość książek jaką chcesz wprowadzić do biblioteki: ";
    cin>>n;
    fstream plik;
    fstream ksiazki;
    for(int i=0; i<n; i++)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Podaj tytuł książki: ";
        getline(cin,baza[i].tytul);
        cout<<"Podaj imię i nazwisko autora książki: ";
        getline(cin,baza[i].autor);
        cout<<"Podaj cene książki: ";
        cin>>baza[i].cena;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Podaj wydawnictwo książki: ";
        getline(cin,baza[i].wydawnictwo);
        cout<<"Podaj 3-cyfrowy indeks książki : ";
        cin>>baza[i].indeks;
        if ((baza[i].indeks)/100>=10||(baza[i].indeks)/100<1)
        {
            cout<<"Proszę podać 3-cyfrowy indeks: ";
            cin>>baza[i].indeks;
        }
        plik.open("Biblioteka.txt",ios::in);

        while(plik>>szukaj)
        {
            if(szukaj==baza[i].indeks)
            {
                cout << "Podany indeks jest zajęty, podaj inny: ";
                cin>>baza[i].indeks;
            }
        }
        plik.close();
        ksiazki.open("Ksiazki.txt",ios::out | ios::app);
        ksiazki<<baza[i].tytul<<endl;
        ksiazki.close();
        plik.open("Biblioteka.txt",ios::out | ios::app);
        plik<<"Wydawnictwo: "<<baza[i].wydawnictwo<<endl;
        plik<<"Tytuł: "<<baza[i].tytul<<endl;
        plik<<"Autor: "<<baza[i].autor<<endl;
        plik<<"Indeks: "<<baza[i].indeks<<endl;
        plik<<"Cena: "<<baza[i].cena<<" zł"<< endl<<endl;
        plik.close();
    }
    cout<<"Dodano pomyślnie książkę/i do biblioteki."<<endl;
    koniec_wyswietlania();
}
void czyszczenie_ksiazek()
{
    fstream ksiazki;
    ksiazki.open("Ksiazki.txt",ios::out);
    cout<<"Wyczyszczono bibliotekę z książek."<<endl;
    ksiazki.close();
    koniec_wyswietlania();
}
void dokladnedane()
{
    int i=0;
    int dlugosc;
    int nr_ksiazki=0;
    string linia;
    int numer_linii=1;
    fstream plik;
    plik.open("Biblioteka.txt",ios::in);
    if (plik.good()==false)
    {
        cout <<"Plik nie istnieje!"<<endl;
        koniec_wyswietlania();
    }
    if (plik.good() )
    {
        plik.open("Biblioteka.txt",ios::in);
        plik.seekg(0, ios::end);
        dlugosc = plik.tellg();
        if(dlugosc==0)
            cout<<"Nie było żadnych książek w bibliotece!"<<endl;
        plik.close();
        plik.open("Biblioteka.txt",ios::in);
        string linia;
        while (getline(plik,linia))
            cout<<linia<<endl;
        plik.close();
        koniec_wyswietlania();
    }
}
void czyszczenie_czytelnikow()
{
    fstream plik1;
    fstream plik;
    plik1.open("dane.txt",ios::out);
    plik1.close();
    plik.open("Czytelnicy.txt",ios::out);
    plik.close();
    cout<<"Wyczyszczono listę czytelników."<<endl;
    koniec_wyswietlania();
}
void pokazksiazki()
{
    int dlugosc;
    int nr_ksiazki=0;
    string linia;
    int numer_linii=1;
    fstream plik;
    plik.open("Ksiazki.txt",ios::in);
    if (plik.good()==false)
    {
        cout <<"Plik nie istnieje!"<<endl;
        koniec_wyswietlania();
    }
    while(getline(plik,linia))
    {
        cout<<linia<<endl;
    }
    plik.close();
    plik.open("Ksiazki.txt",ios::in);
    plik.seekg(0, ios::end);
    dlugosc = plik.tellg();
    if(dlugosc==0)
    {
        cout<<"Biblioteka jest pusta!"<<endl;
    }
    plik.close();
    koniec_wyswietlania();
}
void wypozyczone()
{
    int dlugosc;
    int nr_ksiazki=0;
    string linia;
    int numer_linii=1;
    fstream plik;
    plik.open("Czytelnicy.txt",ios::in);
    if (plik.good()==false)
    {
        cout <<"Plik nie istnieje!"<<endl;
        koniec_wyswietlania();
    }
    while(getline(plik,linia))
    {
        cout<<linia<<endl;
    }
    plik.close();
    plik.open("Czytelnicy.txt",ios::in);
    plik.seekg(0, ios::end);
    dlugosc = plik.tellg();
    if(dlugosc==0)
    {
        cout<<"Lista czytelników jest pusta!"<<endl;
    }
    plik.close();
    koniec_wyswietlania();
}
void wypozycz()
{
    fstream temp;
    fstream temp1;
    fstream plik;
    int op=0;
    string wypozyczenie;
    int m=0;
    int n=0;
    string tekst;
    string imie;
    string nazwisko;
    fstream ksiazka;
    string tekst1;
    string str;
    string puste="<<Puste_miejsce>>";
    int znalezionaPozycjaksiazki;
    int znalezionapozycjanazwiska;
    int znalezionapozycjaimienia;
    cout<<"Aby wypożyczyć książkę prosze podaj swoje imię: ";
    cin>>imie;
    cout<<"Podaj swoje nazwisko: ";
    cin>>nazwisko;
    string linia;
    cout<<"Podaj tytuł książki, jaką chcesz wypożyczyć: ";
    cin>>wypozyczenie;
    temp.open("temp.txt",ios::out);
    ksiazka.open("Ksiazki.txt",ios::in | ios::out);
    plik.open("Czytelnicy.txt",ios::in | ios::out);
    znalezionaPozycjaksiazki = tekst.find(wypozyczenie);
    znalezionapozycjanazwiska = tekst1.find(nazwisko);
    znalezionapozycjaimienia = tekst1.find(imie);
    if(znalezionaPozycjaksiazki == string::npos&&znalezionapozycjanazwiska == string::npos&&znalezionapozycjaimienia == string::npos)
    {
        int ods=1;
        int sa=0;

        while (ksiazka>>linia)
        {
            if(linia==wypozyczenie)
                sa++;
            if(sa==1)
            {
                if(linia != wypozyczenie)
                    temp << linia<<endl;
            }
            else if(sa!=1)
                temp << linia<<endl;
        }
        plik.close();
        ksiazka.close();
        temp.close();
        remove("Ksiazki.txt");
        rename("temp.txt", "Ksiazki.txt");
        ksiazka.open("Ksiazki.txt",ios::in | ios::out);
        plik.open("Czytelnicy.txt",ios::in);
        temp1.open("temporary.txt",ios::out);
        while(plik >> str)
        {
            if (str==nazwisko)
                m++;
            if (str==imie)
                n++;
            if(m==1&&n==1)
            {
                if(str == puste)
                {
                    str = wypozyczenie;
                    m++;
                    n++;
                }
            }
            str += " ";
            temp1 << str;
            if(str==puste || str==wypozyczenie)
                temp1<<endl;
            if(op%3!=0)
                temp1<<endl;
            if(ods%3==0)
                temp1<<endl;
            op++;
            ods++;
        }
        plik.close();
        temp1.close();
        ksiazka.close();
        remove("Czytelnicy.txt");
        rename("temporary.txt", "Czytelnicy.txt");
        cout<<"Wypozyczono książke."<<endl;
        koniec_wyswietlania();
    }
    else
    {
        cout<<"Nie znaleziono podanej książki w bibliotece lub czytelnika w systemie."<<endl;
        ksiazka.close();
        koniec_wyswietlania();
    }
}
void oddaj()
{
    fstream temp1;
    fstream plik;
    int op=0;
    string wypozyczenie;
    int m=0;
    int n=0;
    string tekst;
    string szukimie;
    string szuknazw;
    fstream ksiazka;
    string tekst1;
    string str;
    string puste="<<Puste_miejsce>>";
    int znalezionaPozycjaksiazki;
    int znalezionapozycjanazwiska;
    int znalezionapozycjaimienia;
    cout<<"Aby oddać książkę prosze podaj swoje imię: ";
    cin>>szukimie;
    cout<<"Podaj swoje nazwisko: ";
    cin>>szuknazw;
    cout<<"Podaj tytuł książki, jaką chcesz oddać: ";
    cin>>wypozyczenie;
    temp1.open("temporary.txt",ios::out);
    ksiazka.open("Ksiazki.txt",ios::in | ios::out);
    plik.open("Czytelnicy.txt",ios::in | ios::out);
    znalezionaPozycjaksiazki = tekst.find(wypozyczenie);
    znalezionapozycjanazwiska = tekst1.find(szuknazw);
    znalezionapozycjaimienia = tekst1.find(szukimie);
    if(znalezionaPozycjaksiazki == string::npos&&znalezionapozycjanazwiska == string::npos&&znalezionapozycjaimienia == string::npos)
    {
        int ods=1;
        while(plik >> str)
        {
            if (str==szuknazw)
                m++;
            if (str==szukimie)
                n++;
            if(m==1&&n==1)
            {
                if(str == wypozyczenie)
                {
                    str = puste;
                    m++;
                    n++;
                }
            }
            str += " ";
            temp1 << str;
            if(str==puste || str==wypozyczenie)
                temp1<<endl;
            if(op%3!=0)
                temp1<<endl;
            if(ods%3==0)
                temp1<<endl;
            op++;
            ods++;
        }
        plik.close();
        temp1.close();
        ksiazka.close();
        remove("Czytelnicy.txt");
        rename("temporary.txt", "Czytelnicy.txt");
        ksiazka.open("Ksiazki.txt",ios::in | ios::out|ios::app);
        ksiazka<<wypozyczenie<<endl;
        ksiazka.close();
        cout<<"Oddano książke do biblioteki."<<endl;
        koniec_wyswietlania();
    }
    else
    {
        cout<<"Nie znaleziono podanej książki w bibliotece lub czytelnika w systemie."<<endl;
        ksiazka.close();
        koniec_wyswietlania();
    }
}
void zamow()
{
    string wydawnictwo;
    int wybor;
    fstream dane;
    int x=1,z=1,p=0;
    fstream ksiazki;
    string str,str1;
    string tytul;
    string tekst;
    string wyraz;
    int znalezionaPozycjaksiazki;
    dane.open("Biblioteka.txt",ios::in);
    ksiazki.open("Ksiazki.txt",ios::in|ios::out|ios::app);
    while(!dane.eof())
    {
        dane>>str;
        dane>>str1;
        if(str=="Wydawnictwo:")
        {
            wydawnictwo=str1;
        }
        if(str1=="Wydawnictwo:")
        {
            wydawnictwo=str;
        }
        if(str=="Tytuł:")
        {
            p=0;
            tytul=str1;
            ksiazki.seekg( 0,ios::beg );
            while(!ksiazki.eof())
            {
                ksiazki>>wyraz;
                if(wyraz==tytul)
                    p++;
            }
            if(p==0)
            {
                cout<<"Brakuje w bibliotece książki z wydawnictwa "<<wydawnictwo<<" o tytule: "<<tytul<<"."<<endl;
                cout<<"Jeżeli chcesz ją zamówić napisz 1 - TAK lub 2 - NIE."<<endl;
                cin>>wybor;
                if(wybor==1)
                {
                    cout<<"Zamówiono i dodano do biblioteki książkę o tytule: "<<tytul<<"."<<endl<<endl;
                    ksiazki.close();
                    ksiazki.open("Ksiazki.txt",ios::in|ios::out|ios::app);
                    ksiazki<<endl<<tytul;
                }
                else if(wybor==2)
                {
                    cout<<"Anulowano zakup książki o tytule "<<tytul<<"."<<endl;
                }
            }
        }
        else if(str1=="Tytuł:")
        {
            p=0;
            tytul=str;
            ksiazki.seekg( 0,ios::beg );

            while(!ksiazki.eof())
            {
                ksiazki>>wyraz;
                if(wyraz==tytul)
                    p++;
            }
            if(p==0)
            {
                cout<<"Brakuje w bibliotece książki z wydawnictwa "<<wydawnictwo<<" o tytule: "<<tytul<<"."<<endl;
                cout<<"Jeżeli chcesz ją zamówić napisz 1 - TAK lub 2 - NIE."<<endl;
                cin>>wybor;
                if(wybor==1)
                {
                    cout<<"Zamówiono i dodano do biblioteki książkę o tytule: "<<tytul<<"."<<endl;
                    ksiazki.close();
                    ksiazki.open("Ksiazki.txt",ios::in|ios::out|ios::app);
                    ksiazki<<endl<<tytul;
                }
                else if(wybor==2)
                {
                    cout<<"Anulowano zakup książki o tytule "<<tytul<<"."<<endl;
                }
            }
        }
    }

    dane.close();
    ksiazki.close();
    koniec_wyswietlania();
}
void usunksiazke()
{
    fstream ksiazka;
    fstream temp;
    int p=0;
    string wypozyczenie;
    size_t znalezionaPozycjaksiazki;
    string tekst;
    string linia;
    cout<<"Podaj tytuł książki, jaką chcesz usunąć z biblioteki (nie może być ona wypożyczona): ";
    cin>>wypozyczenie;
    temp.open("temp.txt",ios::out);
    ksiazka.open("Ksiazki.txt",ios::in | ios::out);

        if ((znalezionaPozycjaksiazki = tekst.find(wypozyczenie)) == string::npos)
        {
            int ods=1;
            int sa=0;
            while (ksiazka>>linia)
            {
                if(linia==wypozyczenie)
                    sa++;
                if(sa==1)
                {
                    if(linia != wypozyczenie)
                        temp << linia<<endl;
                }
                else if(sa!=1)
                    temp << linia<<endl;
            }
            ksiazka.close();
            temp.close();
            remove("Ksiazki.txt");
            rename("temp.txt", "Ksiazki.txt");
            cout<<"Pomyślnie usunięto książkę."<<endl;
        }

        else
        cout<<"Podana książka nie jest aktualnie dostępna."<<endl;
    koniec_wyswietlania();
}
void wyczyscdokladnedane()
{
    fstream plik;
    plik.open("Biblioteka.txt",ios::out);
    plik.close();
    cout<<"Wyczyszczono listê książek i ich dane."<<endl;
    koniec_wyswietlania();
}
void pokazdane()
{
    int dlugosc;
    int nr_ksiazki=0;
    string linia;
    int numer_linii=1;
    fstream plik;
    plik.open("dane.txt",ios::in);
    if (plik.good()==false)
    {
        cout <<"Plik nie istnieje!"<<endl;
        koniec_wyswietlania();
    }
    while(getline(plik,linia))
    {
        cout<<linia<<endl;
    }
    plik.close();
    plik.open("dane.txt",ios::in);
    plik.seekg(0, ios::end);
    dlugosc = plik.tellg();
    if(dlugosc==0)
    {
        cout<<"Nie ma zarejestrowanych czytelników w systemie!"<<endl;
    }
    plik.close();
    koniec_wyswietlania();
}
void czytelnicy()
{
    int wybor=-1;
    while(wybor!=5)
    {
        wybor=menu2();
        switch(wybor)
        {
            case 1:
                {
                    dodawanie_czytelnika();
                    break;
                }
            case 2:
                {
                    wypozyczone();
                    break;
                }
            case 3:
                    {
                    pokazdane();
                    break;
                }
            case 4:
                {
                    czyszczenie_czytelnikow();
                    break;
                }
            case 5:
                {
                    cofnij();
                    break;
                }
        }
    }
}
void ksiazki()
{
    int wybor=-1;
    while(wybor!=10)
    {
        wybor=menu1();
        switch(wybor)
        {
            case 1:
                {
                    wprowadzksiazke();
                    break;
                }
            case 2:
                {
                    pokazksiazki();
                    break;
                }
            case 3:
                {
                    wypozycz();
                    break;
                }
            case 4:
                {
                    oddaj();
                    break;
                }
            case 5:
                {
                    czyszczenie_ksiazek();
                    break;
                }
            case 6:
                {
                    dokladnedane();
                    break;
                }
            case 7:
                {
                    usunksiazke();
                    break;
                }
            case 8:
                {
                    wyczyscdokladnedane();
                    break;
                }
            case 9:
                {
                    zamow();
                    break;
                }
            case 10:
                {
                    cofnij();
                    break;
                }
        }
    }
}
void koniec()
{
    cout<<"Dziękujemy za skorzystanie z naszej biblioteki.";
    exit(0);
}
int main()
{
    system("chcp 65001>>NULL");
    intro();
    int wybor=-1;
    while(wybor!=3)
    {
        wybor=menu();
        switch(wybor)
        {
            case 1:
                {
                    ksiazki();
                    break;
                }
            case 2:
                {
                    czytelnicy();
                    break;
                }
                case 3:
                {
                    koniec();
                    break;
                }
        }
    }
    return 0;
}

#include <iostream>
#include <random>

using namespace std;

std::random_device generator; // Määritellään random generaattori hotellihuoneiden määrää varten.
std::uniform_int_distribution<int> distribution(20, 150); // Laitetaan rangeksi puolet halutusta.
int numberOfRooms = distribution(generator) * 2; // Kerrotaan se kahdella saadaksemme parillisen luvun joka kerta.

struct Room {
    int price;
    int fitsPeople;

};

int menu() {
    string input;
    int action;
    while (true) {
        cout << "Syota haluamasi toiminto (1 = Varaa huone, 2 = lopeta ohjelman kaytto)" << endl;
        cin >> input;
        try{
            action = stoi(input);
            return action;
                }
        catch(exception& err ){
            cout << "Virheellinen syöte!" << endl;
        }
        }
}

int main() {
    cout << "Tervetuloa hotelli hevonbarse varausjarjestelmaan!" << endl;
    cout << "Meilla on kaynnissa talla hetkella kampanja, jossa jarjestelmamme arpoo sinulle 0, 10% tai 20% alennuksen!"
         << endl;
    cout << endl;

    menu();

    cout << numberOfRooms;
}
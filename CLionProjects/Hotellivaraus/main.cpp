#include <iostream>
#include <random>

using namespace std;


struct Room {
    int price;
    int fitsPeople;
    bool available;
};


random_device generator;                                           // Määritellään random generaattori hotellihuoneiden määrää varten.
uniform_int_distribution<int> distribution(40 / 2, 300 / 2); // Jaetaan raja-arvot kahdella.

const int numberOfRooms = distribution(generator) * 2;               // Kerrotaan tulos kahdella saadaksemme parillisen luvun joka kerta.
const int halfRooms = numberOfRooms / 2;
vector<Room> rooms(numberOfRooms);


void empty() { // Printtaa tyhjä line
    cout << endl;
}



int menu() {
    string input;
    while (true) {
        cout << "Syota haluamasi toiminto (1 = Varaa huone, 2 = lopeta ohjelman kaytto)" << endl;
        cin >> input;
        if (input == "1") {

        }
    }
}

int main() {
    for (int i = 1; i <= numberOfRooms; ++i) {  // Luodaan huoneet
        if (i <= (numberOfRooms/2)){
            rooms[i].price = 100;
            rooms[i].fitsPeople = 1;
            rooms[i].available = true;
        } else {
            rooms[i].price = 150;
            rooms[i].fitsPeople = 2;
            rooms[i].available = true;
        }
    }


    cout << "Tervetuloa hotelli hevonbarse varausjarjestelmaan!" << endl;
    empty();
    cout << "Hotellissamme on " << numberOfRooms << " huonetta, joista puolet yhden ja puolet kahden hengen huoneita."
         << endl;
    empty();
    cout << "Meilla on kaynnissa talla hetkella kampanja, jossa jarjestelmamme arpoo sinulle 0, 10% tai 20% alennuksen!"
         << endl;
    empty();
}

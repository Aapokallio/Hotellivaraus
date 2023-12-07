#include <iostream>
#include <random>

using namespace std;


struct Room {
    int price;
    int fitsPeople;
    bool available;
};

int randomizerWithMinMax(int min, int max) { //random generaattori joka arpoo raja-arvojen välisen arvon
    random_device generator;
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}


const int numberOfRooms = randomizerWithMinMax(20, 150) *
                          2; // Lähetetään puolet halutusta ja tuplataan lopputulos saadaksemme parillisen luvun
const int halfRooms = numberOfRooms / 2;
vector<Room> rooms(numberOfRooms);


void empty() { // Printtaa tyhjä line
    cout << endl;
}

bool availabilityChecker(int roomtype) {  // checkeri jolla selvitetään onko huonetyyppiä 1 tai 2 vapaana.
    if (roomtype == 1) {
        for (int i = 1; i <= halfRooms; i++) {
            if (rooms[i].available) {
                return true;
            }
        }
        return false;
    }
    if (roomtype == 2) {
        for (int i = halfRooms + 1; i <= numberOfRooms; i++) {
            if (rooms[i].available) {
                return true;
            }
        }
        return false;
    }
}

void reservation() {
    string input;

    while (true) {
        cout << "Valitse halauamasi toiminto (1 = yhden hengen huone, 2 = kahden hengen huone, 3 = takaisin)" << endl;
        cin >> input;

        empty();
        if (input == "1") {
            if (availabilityChecker(1)) {

            }
        } else if (input == "2") {
            availabilityChecker(2);
        } else if (input == "3") {
            break;
        } else {
            cout << "Virheellinen syote!" << endl;
            empty();
        }
    }
}


void menu() {
    string input;
    while (true) {
        cout << "Syota haluamasi toiminto (1 = Varaa huone, 2 = lopeta ohjelman kaytto)" << endl;
        cin >> input;
        if (input == "1") {
            reservation();
        } else if (input == "2") {
            break;
        } else {
            cout << "Virheellinen komento!" << endl;
        }
    }
}

void createRooms(){
    for (int i = 1; i <= numberOfRooms; ++i) {  // Luodaan huoneet
        if (i <= (numberOfRooms / 2)) {
            rooms[i].price = 100;
            rooms[i].fitsPeople = 1;
            rooms[i].available = true;
        } else {
            rooms[i].price = 150;
            rooms[i].fitsPeople = 2;
            rooms[i].available = true;
        }
    }
}

int main() {
    createRooms();
    cout << "Tervetuloa hotelli hevonbarse varausjarjestelmaan!" << endl;
    empty();
    cout << "Hotellissamme on " << numberOfRooms << " huonetta, joista puolet yhden ja puolet kahden hengen huoneita."
         << endl;
    empty();
    cout << "Meilla on kaynnissa talla hetkella kampanja, jossa jarjestelmamme arpoo sinulle 0, 10% tai 20% alennuksen!"
         << endl;
    empty();

    menu();


    cout << "Kiitos ja tervetuloa uudestaan!";
}

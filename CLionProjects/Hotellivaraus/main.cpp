#include <iostream>
#include <random>

using namespace std;


struct Room {    //Objektimme huone
    int price;
    int fitsPeople;
    bool available;
};

int randomizerWithMinMax(int min, int max) { //random generaattori joka arpoo raja-arvojen välisen arvon
    random_device generator;
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}


const int numberOfRooms =
        randomizerWithMinMax(20, 150) *  // Luodaan satunnainen määrä huoneita hotelliin väliltä 40 - 300
        2; // Lähetetään puolet halutusta ja tuplataan lopputulos saadaksemme parillisen luvun
const int halfRooms = numberOfRooms / 2;
vector<Room> rooms(numberOfRooms);  //Vektorimme, jossa säilömme huoneobjektejamme

void empty() { // Printtaa tyhjä line
    cout << endl;
}

bool availabilityChecker(int roomtype) {  // Checkeri jolla selvitetään onko huonetyyppiä 1 tai 2 vapaana.
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

int getFirstAvailableRoom(
        int roomtype) {  // Käy läpi huoneet ja valitsee käyttäjälle ensimmäisen vapailla olevan sitä huonetyyppiä jota halutaan.
    for (int i = 1; i <= numberOfRooms; ++i) {
        if (rooms[i].fitsPeople == roomtype) {
            if (rooms[i].available) {
                rooms[i].available = false;
                return i;
            }
        }
    }
}

int calculatePrice(float nights, float price,
                   float discount) {  // Loppusumman laskuri tapauksessa, jossa on saatu alennusta.
    return nights * price * (1 - (discount / 100));
}

bool testForInt(string input) {   // Kokeilee onko käyttäjän syöte numero ja fiksu sellainen
    if (input.length() == 0 || input.length() > 8) {
        return false;
    }
    for (char c: input) {
        if (isdigit(c)) {
            return true;
        }
    }
    return false;
}

int randomizeRoom(int roomtype) {
    int randomedNumber;
    while (true) {
        if (roomtype == 1) {
            randomedNumber = randomizerWithMinMax(1, halfRooms);
            if (rooms[randomedNumber].available) {
                rooms[randomedNumber].available = false;
                return randomedNumber;
            }
        }
        if (roomtype == 2) {
            randomedNumber = randomizerWithMinMax(halfRooms + 1, numberOfRooms);
            if (rooms[randomedNumber].available) {
                rooms[randomedNumber].available = false;
                return randomedNumber;
            }
        }
    }
}


void reservation() {  // Varausohjelmamme pihvi.
    string input;
    string nightsInput;
    int roomNumber;
    int price;
    int discount;

    while (true) {
        cout << "Valitse halauamasi toiminto (1 = yhden hengen huone, 2 = kahden hengen huone, 3 = takaisin)" << endl;
        cin >> input;
        empty();

        if (input == "1") {
            if (availabilityChecker(1)) {
                cout << "Montako yota haluaisit varata?" << endl;
                cin >> nightsInput;

                if (testForInt(nightsInput)) {
                    if (stoi(nightsInput) > 0) {
                        roomNumber = randomizeRoom(1);
                        discount = randomizerWithMinMax(0, 2);
                        if (discount !=
                            0) {                                                     // Katsotaan saiko asiakas alennuksen ja lasketaan loppusumma sen mukaan.
                            price = calculatePrice(stoi(nightsInput), rooms[roomNumber].price, discount * 10);
                        } else {
                            price = stoi(nightsInput) * rooms[roomNumber].price;
                        }
                        cout << "Huoneesi numero " << roomNumber << " on varattu " << stoi(nightsInput) << " yoksi."
                             << endl;
                        cout << "Sait " << discount * 10 << "% alennuksen ja loppusummasi on " << price << " euroa."
                             << endl;
                        cout << "Kiitos varauksesta! Viemme sinut takaisin etusivulle." << endl;
                        empty();
                    } else {
                        cout << "Virheellinen syote, koita uudestaan!" << endl;
                    }
                } else {
                    cout << "Virheellinen syote, koita uudestaan!" << endl;
                }
            } else {
                cout << "Valitettavasti yhden hengen huoneita ei ole saatavilla!" << endl;
            }
        } else if (input == "2") {         // Samat kuin edellä, mutta kahden hengen huoneille.
            if (availabilityChecker(2)) {
                cout << "Montako yota haluaisit varata?" << endl;
                cin >> nightsInput;
                if (testForInt(nightsInput)) {
                    if (stoi(nightsInput) <= numberOfRooms && stoi(nightsInput) > 0) {
                        roomNumber = randomizeRoom(2);
                        discount = randomizerWithMinMax(0, 2);
                        if (discount != 0) {
                            price = calculatePrice(stoi(nightsInput), rooms[roomNumber].price, discount * 10);
                        } else {
                            price = stoi(nightsInput) * rooms[roomNumber].price;
                        }
                        cout << "Huoneesi numero " << roomNumber << " on varattu " << stoi(nightsInput) << " yoksi."
                             << endl;
                        cout << "Sait " << discount * 10 << "% alennuksen ja loppusummasi on " << price << " euroa."
                             << endl;
                        cout << "Kiitos varauksesta! Viemme sinut takaisin etusivulle." << endl;
                        empty();
                    } else {
                        cout << "Virheellinen syote, koita uudestaan!" << endl;
                    }
                } else {
                    cout << "Virheellinen syote, koita uudestaan!" << endl;
                }
            } else {
                cout << "Valitettavasti kahden hengen huoneita ei ole saatavilla!" << endl;
            }
        } else if (input == "3") {
            break;
        } else {
            cout << "Virheellinen syote!" << endl;
            empty();
        }
    }
}


void menu() {      // Päävalikon eka menu
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

void createRooms() {    // Luodaan huoneet
    for (int i = 1; i <= numberOfRooms; ++i) {
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
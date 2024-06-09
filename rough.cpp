#include <iostream>
#include <vector>
#include <memory>
#include <conio.h> // Include conio.h for getch()

using namespace std;

// Define the base class for items
class Item {
public:
    virtual void print() const = 0;
    virtual ~Item() = default;
};

// Define specific item classes
class Torch : public Item {
public:
    void print() const override {
        cout << "Torch" << endl;
    }
};

class Rod : public Item {
public:
    void print() const override {
        cout << "Rod" << endl;
    }
};

class Nuts : public Item {
public:
    void print() const override {
        cout << "Nuts" << endl;
    }
};

class Wrench : public Item {
public:
    void print() const override {
        cout << "Wrench" << endl;
    }
};

class Battery : public Item {
public:
    void print() const override {
        cout << "Battery" << endl;
    }
};

class Suite : public Item {
public:
    void print() const override {
        cout << "Cartel Suite" << endl;
    }
};

// Define the player class
class Player {
    int health = 100;
    int items = 0;
    string stamina = "medium";
    int moves = 0;
    vector<shared_ptr<Item>> inventory; // Player's inventory to store items

public:
    void addItem(shared_ptr<Item> item) {
        inventory.push_back(item);
        items++;
    }

    void playerStat() {
        cout << "|Player Status|" << endl;
        cout << "Player Health  : " << health << endl;
        cout << "Player Stamina : " << stamina << endl;
        cout << "Items          : " << items << endl;
        cout << "Moves          : " << moves << endl;
    }

    void printInventory() const {
        cout << "|Inventory|" << endl;
        for (const auto& item : inventory) {
            item->print();
        }
    }
};

// Define crate classes
class Crate1 {
public:
    vector<shared_ptr<Item>> items;

    Crate1() {
        items.push_back(make_shared<Torch>());
        items.push_back(make_shared<Rod>());
    }
};

class Crate2 {
public:
    vector<shared_ptr<Item>> items;

    Crate2() {
        items.push_back(make_shared<Nuts>());
        items.push_back(make_shared<Wrench>());
        items.push_back(make_shared<Battery>());
    }
};

class Crate3 {
public:
    vector<shared_ptr<Item>> items;

    Crate3() {
        items.push_back(make_shared<Nuts>());
        items.push_back(make_shared<Suite>());
    }
};

// Game logic
int main() {
    Player player;
    Crate1 crate1;
    Crate2 crate2;
    Crate3 crate3;

    cout << endl << "|The Island Adventure|" << endl;
    cout << "You wake up disoriented in a dimly lit basement, the cold concrete floor beneath you. "
         << "Memories flood back as you realize you've been kidnapped by a notorious cartel operating "
         << "on an isolated island in the Arabian Peninsula. The cartel is involved in the illegal trade "
         << "of smuggling organs, and you fear for your life as you realize the gravity of the situation." << endl << endl;

    cout << "Objective:" << endl << "Your primary objective is to escape the basement and seek help before the cartel carries out their sinister plans." << endl << endl;
    cout << "Press \"Enter\" to start the game or any other key to exit the game." << endl << endl;
    char start = getch();

    if (start == 13) { // Asking user to start the game or exit
        cout << "|Game is started|" << endl;

        while (true) {
            cout << "L look around\tE Open the door\tS Check status\tI Check inventory" << endl;
            cout << "What will you do next, brave adventurer? Enter your move: ";
            char move = getch();

            if (move == 'L' || move == 'l') {
                cout << "You look around the room and there are some boxes and a door in the room." << endl;
                cout << "What would you like to do?" << endl;
                cout << "E Open the door\tC Check the boxes" << endl;
            } else if (move == 'E' || move == 'e') {
                cout << "The door is locked." << endl;
                cout << "Press \"Escape\" to go back" << endl;
                char opt = getch();
                if (opt == 27) continue; // Go back to previous options
            } else if (move == 'C' || move == 'c') {
                cout << "Look what you found there are three crates. Which one do you want to search first?" << endl;
                cout << "1. Crate 1\t2. Crate 2\t3. Crate 3\tPress \"Escape\" to go back." << endl;
                char crateChoice = getch();

                if (crateChoice == '1') {
                    cout << "Crate 1 contains:" << endl;
                    for (std::size_t i = 0; i < crate1.items.size(); ++i) {
                        cout << i + 1 << ". ";
                        crate1.items[i]->print();
                    }
                    cout << "Select an item to add to your inventory: ";
                    int itemChoice;
                    cin >> itemChoice;
                    if (itemChoice > 0 && itemChoice <= crate1.items.size()) {
                        player.addItem(crate1.items[itemChoice - 1]);
                        cout << "Item added to your inventory." << endl;
                    } else {
                        cout << "Invalid choice." << endl;
                    }
                } else if (crateChoice == '2') {
                    cout << "Crate 2 contains:" << endl;
                    for (std::size_t i = 0; i < crate2.items.size(); ++i) {
                        cout << i + 1 << ". ";
                        crate2.items[i]->print();
                    }
                    cout << "Select an item to add to your inventory: ";
                    int itemChoice;
                    cin >> itemChoice;
                    if (itemChoice > 0 && itemChoice <= crate2.items.size()) {
                        player.addItem(crate2.items[itemChoice - 1]);
                        cout << "Item added to your inventory." << endl;
                    } else {
                        cout << "Invalid choice." << endl;
                    }
                } else if (crateChoice == '3') {
                    cout << "Crate 3 contains:" << endl;
                    for (std::size_t i = 0; i < crate3.items.size(); ++i) {
                        cout << i + 1 << ". ";
                        crate3.items[i]->print();
                    }
                    cout << "Select an item to add to your inventory: ";
                    int itemChoice;
                    cin >> itemChoice;
                    if (itemChoice > 0 && itemChoice <= crate3.items.size()) {
                        player.addItem(crate3.items[itemChoice - 1]);
                        cout << "Item added to your inventory." << endl;
                    } else {
                        cout << "Invalid choice." << endl;
                    }
                } else if (crateChoice == 27) {
                    continue; // Go back to previous options
                }
            } else if (move == 'S' || move == 's') {
                player.playerStat();
            } else if (move == 'I' || move == 'i') {
                player.printInventory();
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    } else {
        cout << "You exit the game." << endl;
    }

    return 0;
}

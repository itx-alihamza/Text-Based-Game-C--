#include <iostream>
#include <vector>
#include <memory>
#include <conio.h>

using namespace std;

class item {
public:
    virtual void print() const = 0;
    virtual string getName() const = 0;
    virtual ~item() = default;
};

class Torch : public item {
public:
    void print() const override {
        cout << "Torch" << endl;
    }
    string getName() const override {
        return "Torch";
    }
};

class Rod : public item {
public:
    void print() const override {
        cout << "Rod" << endl;
    }
    string getName() const override {
        return "Rod";
    }
};

class Nuts : public item {
public:
    void print() const override {
        cout << "Nuts" << endl;
    }
    string getName() const override {
        return "Nuts";
    }
};

class Wrench : public item {
public:
    void print() const override {
        cout << "Wrench" << endl;
    }
    string getName() const override {
        return "Wrench";
    }
};

class Battery : public item {
public:
    void print() const override {
        cout << "Battery" << endl;
    }
    string getName() const override {
        return "Battery";
    }
};

class Suite : public item {
public:
    void print() const override {
        cout << "Suite" << endl;
    }
    string getName() const override {
        return "Suite";
    }
};

struct crate_1 {
    vector<shared_ptr<item>> items;
    crate_1() {
        items.push_back(make_shared<Torch>());
        items.push_back(make_shared<Rod>());
    }
};

struct crate_2 {
public:
    vector<shared_ptr<item>> items;
    crate_2() {
        items.push_back(make_shared<Wrench>());
        items.push_back(make_shared<Battery>());
        items.push_back(make_shared<Nuts>());
    }
};

struct crate_3 {
public:
    vector<shared_ptr<item>> items;
    crate_3() {
        items.push_back(make_shared<Nuts>());
        items.push_back(make_shared<Suite>());
    }
};

class player {
public:
    int health = 100;
    int items = 0;
    string stamina = "medium";
    int moves = 0;

    vector<shared_ptr<item>> inventory;

    void addItems(shared_ptr<item> item) {
        inventory.push_back(item);
        items++;
    }

    void showInventory() {
        cout << "|Inventory|" << endl;
        for (const auto& invent : inventory) {
            invent->print();
        }
    }

    bool hasItem(const string& itemName) const {
        for (const auto& invent : inventory) {
            if (invent->getName() == itemName) {
                return true;
            }
        }
        return false;
    }

    void playerStat() {
        cout << "|Player Status|" << endl;
        cout << "Player Health  : " << health << endl;
        cout << "Player Stamina : " << stamina << endl;
        cout << "Items          : " << items << endl;
        cout << "Moves          : " << moves << endl;
    }
};

void gameLoop(player& p1, crate_1& crat1, crate_2& crat2, crate_3& crat3) {
    char move;

    while (true) {
        cout << "L look around\tE Open the door\tC Check Status\nN Check Inventory" << endl;
        cout << "Enter your move: ";
        move = getch();
        cout << endl;

        if (move == 'L' || move == 'l') {
            cout << "You look around the room and there are some boxes and a door in the room." << endl;
            while (true) {
                cout << "What would you like to do?" << endl;
                cout << "E Open the door\tS Check the boxes" << endl;
                move = getch();
                cout << endl;
                if (move == 'E' || move == 'e') {
                    cout << "The door is locked." << endl;
                    cout << "Press any key to go back." << endl;
                    getch();
                    break;
                }
                else if (move == 's' || move == 'S') {
                    while (true) {
                        cout << "Look what you found! There are three crates." << endl;
                        cout << "Which one do you want to search first?" << endl;
                        cout << "(1) Crate_1" << endl;
                        cout << "(2) Crate_2" << endl;
                        cout << "(3) Crate_3" << endl;
                        cout << "Press \"Escape\" to go back." << endl;
                        move = getch();
                        cout << endl;

                        if (move == '1') {
                            cout << "You found a Torch and a Rod." << endl;
                            for (unsigned int i = 0; i < crat1.items.size(); i++) {
                                cout << i + 1 << ". ";
                                crat1.items[i]->print();
                            }
                            while (true) {
                                cout << "TO ADD ITEMS IN INVENTORY SELECT" << endl;
                                cout << "Or press escape to go back." << endl;
                                unsigned int itemChoice = getch();
                                if (itemChoice == 27) break; //End while loop if press escape 
                                itemChoice -= '0'; //To convert ASCII number to its value
                                if (itemChoice > 0 && itemChoice <= crat1.items.size()) {
                                    p1.addItems(crat1.items[itemChoice - 1]);
                                    crat1.items[itemChoice - 1]->print();
                                    cout << "is added to inventory." << endl;
                                }
                            }
                        }
                        else if (move == '2') {
                            cout << "You found a Wrench, a Battery, and some Nuts." << endl;
                            for (unsigned int i = 0; i < crat2.items.size(); i++) {
                                cout << i + 1 << ". ";
                                crat2.items[i]->print();
                            }
                            while (true) {
                                cout << "TO ADD ITEMS IN INVENTORY SELECT" << endl;
                                cout << "Or press escape to go back." << endl;
                                unsigned int itemChoice = getch();
                                if (itemChoice == 27) break; //End while loop if press escape 
                                itemChoice -= '0'; //To convert ASCII number to its value
                                if (itemChoice > 0 && itemChoice <= crat2.items.size()) {
                                    p1.addItems(crat2.items[itemChoice - 1]);
                                    crat2.items[itemChoice - 1]->print();
                                    cout << "is added to inventory." << endl;
                                }
                            }
                        }
                        else if (move == '3') {
                            cout << "You found some Nuts and a Suite." << endl;
                            for (unsigned int i = 0; i < crat3.items.size(); i++) {
                                cout << i + 1 << ". ";
                                crat3.items[i]->print();
                            }
                            while (true) {
                                cout << "TO ADD ITEMS IN INVENTORY SELECT" << endl;
                                cout << "Or press escape to go back." << endl;
                                unsigned int itemChoice = getch();
                                if (itemChoice == 27) break; //End while loop if press escape 
                                itemChoice -= '0'; //To convert ASCII number to its value
                                if (itemChoice > 0 && itemChoice <= crat3.items.size()) {
                                    p1.addItems(crat3.items[itemChoice - 1]);
                                    crat3.items[itemChoice - 1]->print();
                                    cout << "is added to inventory." << endl;
                                }
                            }
                        }
                        else if (move == 27) {
                            break;
                        }
                        else {
                            cout << "Invalid choice. Try again." << endl;
                        }
                    }
                    break;
                }
                else {
                    cout << "Invalid action. Try again." << endl;
                }
            }
        }
        else if (move == 'c' || move == 'C') p1.playerStat();
        else if (move == 'n' || move == 'N') p1.showInventory();
        else if (move == 'E' || move == 'e') {
            cout << "The door is locked." << endl;
            cout << "Press any key to go back." << endl;
            getch();
        } 
        // else if (move == 'S' || move == 's') {
        //     p1.showInventory();
        // } 
        else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

int main() {
    player p1;
    crate_1 crat1;
    crate_2 crat2;
    crate_3 crat3;

    cout<<"Inventory outside : "<<endl;
    p1.showInventory();
    cout << endl << "|The Island Adventure|" << endl;
    cout << "You wake up disoriented in a dimly lit basement, the cold concrete floor beneath you. Memories flood back as you realize you've been kidnapped by a notorious cartel operating on an isolated island in the Arabian Peninsula. The cartel is involved in the illegal trade of smuggling organs, and you fear for your life as you realize the gravity of the situation." << endl << endl;
    cout << "Objective:" << endl << "Your primary objective is to escape the basement and seek help before the cartel carries out their sinister plans." << endl << endl;
    cout << "Press \"Enter\" to start the game or any key to exit the game." << endl << endl;

    char start = getch();

    if (start == 13) {
        cout << "|Game is started|" << endl;
        gameLoop(p1, crat1, crat2, crat3);
    } else {
        cout << "You exit the game." << endl;
    }

    return 0;
}
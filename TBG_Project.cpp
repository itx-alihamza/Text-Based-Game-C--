#include <iostream>
#include <vector>
#include <memory>
#include <conio.h>

using namespace std;

class item {
public:
    virtual string getitem() const = 0;
    virtual void print() const = 0;
    virtual ~item() = default;
};

class Torch : public item {
public:

    void print() const override {
        cout << "Torch" << endl;
    }
    string getitem() const override {
        return "Torch";
    }
};

class Rod : public item {
public:
    void print() const override {
        cout << "Rod" << endl;
    }
    string getitem() const override {
        return "Rod";
    }
};

class Nuts : public item {
public:
    void print() const override {
        cout << "Nuts" << endl;
    }
    string getitem() const override {
        return "Nuts";
    }
};

class Wrench : public item {
public:
    void print() const override {
        cout << "Wrench" << endl;
    }
    string getitem() const override {
        return "Wrench";
    }
};

class Battery : public item {
public:
    void print() const override {
        cout << "Battery" << endl;
    }
    string getitem() const override {
        return "Battery";
    }
};

class Suite : public item {
public:
    void print() const override {
        cout << "Suite" << endl;
    }
    string getitem() const override {
        return "Suite";
    }
};

class doorKey : public item{
    public:
    void  print() const override {
        cout << "Door key" <<endl;
    }
    string getitem() const override {
        return "Door key";
    }
};

class cigratteBox : public item{
    public:
    void  print() const override {
        cout << "Cigratte box" <<endl;
    }
    string getitem() const override {
        return "Cigratte box";
    }
};

class boatKey : public item{
    public:
    void  print() const override {
        cout << "Boat key" <<endl;
    }
    string getitem() const override {
        return "Boat key";
    }
};

class weapon_1 : public item{
    public:
    void print() const override{
        cout<<"Pistol"<<endl;
    }
    string getitem() const override{
        return "Pistol";
    }
};

class papers : public item{
    public:
    void print() const override{
        cout<<"papers"<<endl;
    }
    string getitem() const override{
        return "papers";
    }
};

class player {
public:
    int health = 100;
    int items = 0;
    string stamina = "medium";
    string itemEquipped = "null";
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

    void equipItem(){

    }

    void playerStat() {
        cout << "|Player Status|" << endl;
        cout << "Player Health  : " << health << endl;
        cout << "Player Stamina : " << stamina << endl;
        cout << "Items          : " << items << endl;
        cout << "Moves          : " << moves << endl;
        cout << "Item equipped  : " << itemEquipped << endl;
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

struct cartelBody_1{
    public:
    vector<shared_ptr<item>> items;
    cartelBody_1() {
        items.push_back(make_shared<Suite>());
        items.push_back(make_shared<doorKey>());
        items.push_back(make_shared<cigratteBox>());
    }
};

struct cartelBody_2{
    public:
    vector<shared_ptr<item>> items;
    cartelBody_2() {
        items.push_back(make_shared<Suite>());
        items.push_back(make_shared<weapon_1>());
        items.push_back(make_shared<cigratteBox>());
    }
};

struct cartelBody_3{
    public:
    vector<shared_ptr<item>> items;
    cartelBody_3(){
        items.push_back(make_shared<Suite>());
        items.push_back(make_shared<weapon_1>());
        items.push_back(make_shared<cigratteBox>());
    }
};

struct recpDesk{
    vector<shared_ptr<item>> items;
    recpDesk(){
        items.push_back(make_shared<papers>());
        items.push_back(make_shared<boatKey>());
    }
};

void Basement(string itemEquipped, bool& playerLife, bool& bdoorUnlock, player& p1, crate_1& crat1, crate_2& crat2, crate_3& crat3) {
    cout<<"|BASEMENT|"<<endl;
    char move;
    while (true) {
        cout << "L look around\tE Open the door\tC Check Status\nN Check Inventory" << endl;
        cout << "Enter your move: ";
        move = getch();
        cout << endl;

        if (move == 'L' || move == 'l') {
        cout <<endl<< "You look around the room and there are some boxes and a door in the room." << endl;
        while (true) {
            cout << "What would you like to do?" << endl;
            cout << "E Open the door\tS Check the boxes" << endl;
            move = getch();
            cout << endl;
            if (move == 'E' || move == 'e') {
            while(bdoorUnlock){
                cout << "Hurry! Door is unlocked." << endl;
                cout << "Objective 1 is completed." << endl;
                return;
            }
                cout << "The door is locked." << endl;
                cout << "Press any key. Go back <-" << endl;
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
                    cout << "Escape. Go back <-" << endl;
                    move = getch();
                    cout << endl;

                    if (move == '1') {
                        cout << "You found a Torch and a Rod." << endl;
                        for (unsigned int i = 0; i < crat1.items.size(); i++) {
                            cout << i + 1 << ". ";
                            crat1.items[i]->print();
                        }
                        while (true) {// while loop to add selected items in the invevntory.
                            cout << "To add items to inventory, select the number or Escape. Go back <-"<<endl;
                            int itemChoice = getch();
                            if (itemChoice == 27) break; // End while loop if press escape
                            itemChoice -= '0'; // Convert ASCII number to its value
                            if (itemChoice > 0 && itemChoice <= crat1.items.size()) {
                                p1.addItems(crat1.items[itemChoice - 1]);
                                crat1.items[itemChoice - 1]->print();
                                cout << " added to inventory." << endl;
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
                            cout << "To add items to inventory, select the number or press escape to go back: ";
                            int itemChoice = getch();
                            if (itemChoice == 27) break; // End while loop if press escape
                            itemChoice -= '0'; // Convert ASCII number to its value
                            if (itemChoice > 0 && itemChoice <= crat2.items.size()) {
                                p1.addItems(crat2.items[itemChoice - 1]);
                                crat2.items[itemChoice - 1]->print();
                                cout << " added to inventory." << endl;
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
                            cout << "To add items to inventory, select the number or press escape to go back: ";
                            int itemChoice = getch();
                            if (itemChoice == 27) break; // End while loop if press escape
                            itemChoice -= '0'; // Convert ASCII number to its value
                            if (itemChoice > 0 && itemChoice <= crat3.items.size()) {
                                p1.addItems(crat3.items[itemChoice - 1]);
                                crat3.items[itemChoice - 1]->print();
                                cout << " added to inventory." << endl;
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
        else if (move == 'c' || move == 'C') {
            cout<<endl;
            p1.playerStat();
        } 
        else if (move == 'n' || move == 'N') {
            cout<<endl;
            p1.showInventory();
        } 
        else if (move == 'E' || move == 'e') {
            while(bdoorUnlock){
                cout << endl << "Hurry! Door is unlocked. ";
                cout << "Objective 1 is completed." <<endl;
                return;
            }
            cout <<endl<< "The door is locked." << endl;
            cout << "Press \"Tab\" to use somthing from inventory." <<endl;
            cout << "Press any key. Go back <-" << endl;
            move = getch();
            if(move == 9){
                cout << endl;
                p1.showInventory();
                while(true){
                cout <<endl<< "Select an item to use.\"Escape\" Go back"<<endl;
                int selectItem = getch();
                if (selectItem == 27) break;
                cout<<endl;
                selectItem -= '0';// TO convert character digit '1' to numeric value 1.
                if(selectItem <= p1.inventory.size() && selectItem > 0){
                        while(true){
                            cout<<"Equipped : ";
                            p1.inventory[selectItem - 1]->print();
                            if(p1.inventory[selectItem - 1]->getitem() == "Rod"){
                                itemEquipped = p1.inventory[selectItem - 1]->getitem();
                                cout<<"Debug"<<itemEquipped; //Debug
                                bdoorUnlock = true;
                            }
                            cout<<"Escape. Go back <-";
                            move = getch();
                            cout<<endl;
                            if (move == 27) break;   
                        }
                }
                }
            } 
            else{}
        }
        else{
            cout << "Invalid move. Try again." << endl;
        }
    }
}

void recepArea(bool& botKey, string& suiteEquipped, string& itemEquipped, bool& playerLife, bool& rdoorUnlock, bool& bdoorUnlock, player p1, cartelBody_1 cb1, cartelBody_2 cb2, cartelBody_3 cb3, recpDesk rDesk){
    itemEquipped = "Rod"; // Temporary

    cout << "|RECEPTIONIST AREA|" << endl;
    int move;
    bool   recpCartel = true;// reception cartel status alive or not.
    while (true)
    {
        cout << endl << "\"E\" Open reception exit door\n\"C\" Crouch, avoiding detection\n\"Tab\" Use something from inventory" << endl;
        move = getch();
        if (move == 69 || move == 101){ // 'E' key
            if (recpCartel == false) {
                cout << "Objective 2 Completed. Congratulations!" << endl;
                return;
            } else {
                cout << endl << "Oh, the cartel member sitting at the reception sees you and calls out, 'Where are you going, little bastard?'" << endl;
                cout << "He stands up quickly, his eyes narrowing as he reaches for his weapon." << endl;
                cout << "'You think you can just walk out of here? You're not going anywhere!'" << endl;
                cout << "You try to make a run for it, but it's too late. The cartel member overpowers you and you're dragged back." << endl;
                cout << "You lose. Game Over." << endl;
                playerLife = false;//Player dead
                return;
            }
        }
        else if(move == 67 || move == 99){ // 'C' key
            while (true){
                cout << endl << "\"W\" Move toword reception gate\n\"D\" Move toword reception.\n\"S\" Move toword basement \n\"A\" Move toword left wall.\n\"Escape\" Go back."<<endl;
                move = getch();
                if (move == 27) break;
                if (move == 87 || move == 119) { // 'W' key
                    while (true)
                    {
                        cout << endl << "\"E\" Open reception door.\n\"Escape\" Go back." << endl;
                        move = getch();
                        if (move == 27) break;
                        else if(move == 101 || move == 69)// 'E' key
                        {
                            if (recpCartel == false){
                                cout << endl << "Door opened."<<endl;
                                cout << "Objective 2 Completed. Congratulations!"<<endl;
                                return;
                            }
                            else if(recpCartel == true){
                                cout << endl << "Oh, the cartel member sitting at the reception sees you and calls out, 'Where are you going, little bastard?'" << endl;
                                cout << "He stands up quickly, his eyes narrowing as he reaches for his weapon." << endl;
                                cout << "'You think you can just walk out of here? You're not going anywhere!'" << endl;
                                cout << "You try to make a run for it, but it's too late. The cartel member overpowers you and you're dragged back." << endl;
                                cout << "You lose. Game Over." << endl;
                                playerLife = false;//Player dead
                                return;
                            }
                        }
                        else cout<<"Invalid. Try again.";
                    }           
                }
                else if (move == 68 || move == 100) { // 'D' key
                    cout << endl << "You move cautiously toward the reception, keeping an eye on the cartel member." << endl;
                    while (true)
                    {
                        cout << "\"Tab\" Use something from inventory\n\"R\" Kill the cartel sitting in reception.\n\"Escape\" Go back."<< endl;
                        move = getch();
                        if(move == 27) break;
                        if (move == 9){// 'Tab' key
                            cout << endl;
                            p1.showInventory();// Displaying inventory
                            while (true)
                            {
                                cout << endl <<"Select from inventory.\n\"Escape\" Go back." << endl;
                                move = getch();
                                if (move == 27) break;
                                cout << endl;
                                move -= '0';// TO convert character digit '1' to numeric value 1.
                                if(move <= p1.inventory.size() && move > 0){
                                        while(true){
                                            cout<<"Equipped : "<<p1.inventory[move - 1]->getitem();
                                            itemEquipped = p1.inventory[move - 1]->getitem();// item equipped 
                                            cout<<"Escape. Go back <-";
                                            move = getch();
                                            cout<<endl;
                                            if (move == 27) break;   
                                        }
                                }
                                else cout<<"Invalid. Try again." << endl;
                            }
                        }
                        else if(move == 82 || move == 114){// 'R' key
                            while (true)
                            {
                                if (itemEquipped == "Rod")
                                {
                                    cout << endl << "You have cautiouslly killd the cartel sitting in reception." << endl;
                                    recpCartel = false;
                                    cout << "\"1\" Search cartel body.\n\"2\" Search Desk.\"Escape\" Go back." << endl ;
                                    move = getch();
                                    if(move == 27) break;
                                    move -= '0';// Converting character(digitd) to numeric value.
                                    if (move == 1)// '1' key
                                    {
                                        cout << endl << "|Reception cartel body|" << endl;
                                        for (const auto invent : cb1.items)
                                        {
                                            invent->print();
                                        }
                                        while (true) {
                                            cout << endl << "To add items to inventory, select the number.\n\"Escape\" Go back." << endl ;
                                            int itemChoice = getch();
                                            if (itemChoice == 27) break; // End while loop if press escape
                                            itemChoice -= '0'; // Convert ASCII number to its value
                                            if (itemChoice > 0 && itemChoice <= cb1.items.size()) {
                                                p1.addItems(cb1.items[itemChoice - 1]);
                                                cout << endl << "|" <<cb1.items[itemChoice - 1]->getitem() << " added to inventory.|" << endl;
                                                if (cb1.items[itemChoice - 1]->getitem() == "Suite") suiteEquipped = "Suite";
                                                else if(cb1.items[itemChoice - 1]->getitem() == "Boat key") botKey = true;
                                            }
                                            else cout << "Invalid. Try again.";
                                        }
                                    }                                
                                    if (move == 2)// '2' key
                                    {
                                        cout << endl << "|Reception desk|" << endl;
                                        for (const auto invent : rDesk.items)
                                        {
                                            invent->print();
                                        }
                                        while (true) {
                                            cout << endl << "To add items to inventory, select the number.\n\"Escape\" Go back." << endl ;
                                            int itemChoice = getch();
                                            if (itemChoice == 27) break; // End while loop if press escape
                                            itemChoice -= '0'; // Convert ASCII number to its value
                                            if (itemChoice > 0 && itemChoice <= rDesk.items.size()) {
                                                p1.addItems(rDesk.items[itemChoice - 1]);
                                                cout << endl << "|" <<rDesk.items[itemChoice - 1]->getitem() << " added to inventory.|" << endl;
                                                if (rDesk.items[itemChoice - 1]->getitem() == "Suite") suiteEquipped = "Suite";
                                                else if(rDesk.items[itemChoice - 1]->getitem() == "Boat key") botKey = true;
                                            }
                                            else cout << "Invalid. Try again.";
                                        }
                                    } 
                                }
                                else if (itemEquipped != "Rod") {
                                    cout << "You attempt to attack the cartel member, but without a suitable weapon, you are quickly overpowered." << endl;
                                    cout << "The cartel member calls for backup, and you are apprehended. Game Over." << endl;
                                    return;
                                }
                                else cout<<"invalid. Try again."<<endl;  
                            }
                        }         
                    }
                }
                else if (move == 83 || move == 115) { // 'S' key
                    cout << endl << "You move back toward the basement, trying to find another way out." << endl;
                    // Implement the logic for moving back toward the basement
                }
                else if (move == 65 || move == 97) { // 'A' key
                    cout << endl << "You move toward the left wall, looking for anything that might help you escape.";
                    while (true)
                    {

                        cout << "\n\"Escape\" Go back." << endl;
                        move = getch();
                        if (move == 27)break;
                        else cout << "Invalid. Try again." << endl;
                    }  
                }
                else {
                    cout << "Invalid move. Try again." << endl;
                }
            }
        }
        else if(move == 9){ //'Tab' key
            while (true)
            {
            }
            
        }
        else cout << endl << "Invalid. Try again." << endl;
    }
}
void outsideComp(bool& botKey, string& suiteEquipped, string& itemEquipped, bool& playerLife, bool& rdoorUnlock){
    int move;
    
    while (true) {
        cout << endl << "\"W\" Toword north shoreline. \n\"S\" Toword reception. \n\"A\" Toword east shoreline. \n\"D\" Toword boat on shoreline." << endl;
        move = getch();
        if (move == 'W' || move == 'w') { // 'W' key
            if(suiteEquipped == "Suite") {
                while (true)
                {
                    cout << "You walk north towards the shoreline." << endl;
                    cout << endl << "\n\"Escape\" Go back." << endl;
                    move = getch();
                    if (move == 27)break;
                }
            }
            else{
                cout << "You are spotted by cartel members and quickly captured. Game Over." << endl;
                playerLife = false;
                return;
            }
        } else if (move == 'S' || move == 's') { // 'S' key
            cout << "You move back towards the reception area." << endl;
            // Return to reception function (if implemented)
            return;
        } else if (move == 'A' || move == 'a') { // 'A' key
            if(suiteEquipped == "Suite") {
                while (true)
                {
                    cout << "You walk east towards the shoreline." << endl;
                    cout << endl << "\n\"Escape\" Go back." << endl;
                    move = getch();
                    if (move == 27)break;
                }
            }
            else{
                cout << "You are spotted by cartel members and quickly captured. Game Over." << endl;
                playerLife = false;
                return;
            }
        } else if (move == 'D' || move == 'd') {
            cout << "You move towards the boat on the shoreline." << endl;
            if (suiteEquipped == "Suite") {
                cout << "You blend in with the cartel members and reach the boat." << endl;
                while (true)
                {
                    cout << endl << "Press \"Enter\" to start the boat. \n\"Escape\" Go back." <<endl;
                    move == getch();
                    if(move == 27) break;
                    if (move == 13)
                    {
                        if (botKey == true){
                            cout << "You start the boat and sail away to safety. Congratulations, you have won the game!" << endl;
                            playerLife = true;
                            return;
                        }
                        else if(botKey == false){
                            cout << "You cant start the boat key is missing.\n\"Escape\" Go back." << endl;
                        }
                    }
                }
            } else {
                cout << "You are spotted by cartel members and quickly captured. Game Over." << endl;
                playerLife = false;
                return;
            }
        } else {
            cout << "Invalid input. Try again." << endl;
        }
    }
}

int main(){

    player p1;
    crate_1 crat1;
    crate_2 crat2;
    crate_3 crat3;
    cartelBody_1 cb1;
    cartelBody_2 cb2;
    cartelBody_3 cb3;
    recpDesk rDesk;
    bool bdoorUnlock = false;
    bool rdoorUnlock = false;
    bool playerLife      = true ;//player life status alive or not.
    string itemEquipped = "";
    string suiteEquipped = "";
    bool botKey = false;

    cout << endl << "|The Island Adventure|" << endl;
    cout << "You wake up disoriented in a dimly lit basement, the cold concrete floor beneath you. Memories flood back as you realize you've been kidnapped by a notorious cartel operating on an isolated island in the Arabian Peninsula. The cartel is involved in the illegal trade of smuggling organs, and you fear for your life as you realize the gravity of the situation." << endl << endl;
    cout << "Press \"Enter\" to start the game or any key to exit the game." << endl << endl;
    
    char start = getch();
    if (start == 13) {
        cout << "|Game is started|" << endl;
        // if (playerLife == true)
        // {
        //     cout << "|Objective|" << endl << "Your primary objective is to escape the basement and seek help before the cartel carries out their sinister plans." << endl << endl;
        //     Basement(itemEquipped, playerLife, bdoorUnlock, p1, crat1, crat2, crat3);
        // }

        if (playerLife == true){
            cout << endl <<"|New Objective|"<<endl<<"Now you have to kill the reception guy and take his stuff." << endl << endl;
            recepArea(botKey, suiteEquipped, itemEquipped, playerLife, rdoorUnlock, bdoorUnlock, p1, cb1, cb2, cb3, rDesk);
        }
        if (playerLife == true){
            cout << endl << "|New Objective|" << endl << "Bypass security and go to the bank of the island where the boat is standing." << endl << endl;
            outsideComp(botKey, suiteEquipped, itemEquipped, playerLife, rdoorUnlock);
        } 
    } else {
        cout << "You exit the game." << endl;
    }

    return 0;
}

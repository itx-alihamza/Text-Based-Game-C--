void Basement(string itemEquipped, bool& playerLife, bool& bdoorUnlock, player& p1, crate_1& crat1, crate_2& crat2, crate_3& crat3) {
//     cout<<"|BASEMENT|"<<endl;
//     char move;
//     while (true) {
//         cout << "L look around\tE Open the door\tC Check Status\nN Check Inventory" << endl;
//         cout << "Enter your move: ";
//         move = getch();
//         cout << endl;

//         if (move == 'L' || move == 'l') {
//         cout <<endl<< "You look around the room and there are some boxes and a door in the room." << endl;
//         while (true) {
//             cout << "What would you like to do?" << endl;
//             cout << "E Open the door\tS Check the boxes" << endl;
//             move = getch();
//             cout << endl;
//             if (move == 'E' || move == 'e') {
//             while(bdoorUnlock){
//                 cout << "Hurry! Door is unlocked." << endl;
//                 cout << "Objective 1 is completed." << endl;
//                 return;
//             }
//                 cout << "The door is locked." << endl;
//                 cout << "Press any key. Go back <-" << endl;
//                 getch();
//                 break;
//             } 
//             else if (move == 's' || move == 'S') {
//                 while (true) {
//                     cout << "Look what you found! There are three crates." << endl;
//                     cout << "Which one do you want to search first?" << endl;
//                     cout << "(1) Crate_1" << endl;
//                     cout << "(2) Crate_2" << endl;
//                     cout << "(3) Crate_3" << endl;
//                     cout << "Escape. Go back <-" << endl;
//                     move = getch();
//                     cout << endl;

//                     if (move == '1') {
//                         cout << "You found a Torch and a Rod." << endl;
//                         for (unsigned int i = 0; i < crat1.items.size(); i++) {
//                             cout << i + 1 << ". ";
//                             crat1.items[i]->print();
//                         }
//                         while (true) {// while loop to add selected items in the invevntory.
//                             cout << "To add items to inventory, select the number or Escape. Go back <-"<<endl;
//                             int itemChoice = getch();
//                             if (itemChoice == 27) break; // End while loop if press escape
//                             itemChoice -= '0'; // Convert ASCII number to its value
//                             if (itemChoice > 0 && itemChoice <= crat1.items.size()) {
//                                 p1.addItems(crat1.items[itemChoice - 1]);
//                                 crat1.items[itemChoice - 1]->print();
//                                 cout << " added to inventory." << endl;
//                             }
//                         }
//                     } 
//                     else if (move == '2') {
//                         cout << "You found a Wrench, a Battery, and some Nuts." << endl;
//                         for (unsigned int i = 0; i < crat2.items.size(); i++) {
//                             cout << i + 1 << ". ";
//                             crat2.items[i]->print();
//                         }
//                         while (true) {
//                             cout << "To add items to inventory, select the number or press escape to go back: ";
//                             int itemChoice = getch();
//                             if (itemChoice == 27) break; // End while loop if press escape
//                             itemChoice -= '0'; // Convert ASCII number to its value
//                             if (itemChoice > 0 && itemChoice <= crat2.items.size()) {
//                                 p1.addItems(crat2.items[itemChoice - 1]);
//                                 crat2.items[itemChoice - 1]->print();
//                                 cout << " added to inventory." << endl;
//                             }
//                         }
//                     } 
//                     else if (move == '3') {
//                         cout << "You found some Nuts and a Suite." << endl;
//                         for (unsigned int i = 0; i < crat3.items.size(); i++) {
//                             cout << i + 1 << ". ";
//                             crat3.items[i]->print();
//                         }
//                         while (true) {
//                             cout << "To add items to inventory, select the number or press escape to go back: ";
//                             int itemChoice = getch();
//                             if (itemChoice == 27) break; // End while loop if press escape
//                             itemChoice -= '0'; // Convert ASCII number to its value
//                             if (itemChoice > 0 && itemChoice <= crat3.items.size()) {
//                                 p1.addItems(crat3.items[itemChoice - 1]);
//                                 crat3.items[itemChoice - 1]->print();
//                                 cout << " added to inventory." << endl;
//                             }
//                         }
//                     } 
//                     else if (move == 27) {
//                         break;
//                     } 
//                     else {
//                         cout << "Invalid choice. Try again." << endl;
//                     }
//                 }
//                 break;
//             } 
//             else {
//                 cout << "Invalid action. Try again." << endl;
//             }
//         }
//         } 
//         else if (move == 'c' || move == 'C') {
//             cout<<endl;
//             p1.playerStat();
//         } 
//         else if (move == 'n' || move == 'N') {
//             cout<<endl;
//             p1.showInventory();
//         } 
//         else if (move == 'E' || move == 'e') {
//             while(bdoorUnlock){
//                 cout << endl << "Hurry! Door is unlocked. ";
//                 cout << "Objective 1 is completed." <<endl;
//                 return;
//             }
//             cout <<endl<< "The door is locked." << endl;
//             cout << "Press \"Tab\" to use somthing from inventory." <<endl;
//             cout << "Press any key. Go back <-" << endl;
//             move = getch();
//             if(move == 9){
//                 cout << endl;
//                 p1.showInventory();
//                 while(true){
//                 cout <<endl<< "Select an item to use.\"Escape\" Go back"<<endl;
//                 int selectItem = getch();
//                 if (selectItem == 27) break;
//                 cout<<endl;
//                 selectItem -= '0';// TO convert character digit '1' to numeric value 1.
//                 if(selectItem <= p1.inventory.size() && selectItem > 0){
//                         while(true){
//                             cout<<"Equipped : ";
//                             p1.inventory[selectItem - 1]->print();
//                             if(p1.inventory[selectItem - 1]->getitem() == "Rod"){
//                                 itemEquipped = p1.inventory[selectItem - 1]->getitem();
//                                 cout<<"Debug"<<itemEquipped; //Debug
//                                 bdoorUnlock = true;
//                             }
//                             cout<<"Escape. Go back <-";
//                             move = getch();
//                             cout<<endl;
//                             if (move == 27) break;   
//                         }
//                 }
//                 }
//             } 
//             else{}
//         }
//         else{
//             cout << "Invalid move. Try again." << endl;
//         }
//     }
// }
#include <iostream>
#include <unistd.h>
#include "journal.h"

int main() {
    std::string username;
    std::cout << "Enter your username: ";
    std::cin >> username;

    Journal journal(username);
    journal.login();

    char choice;
    do {
           std::cout << "\n Hi, What do you want to do? \n";
        std::cout << "\n[1] Write Today's Journal.\n";
        std::cout << "[2] Search And Read Journal.\n";
        std::cout << "[3] Exit\n\n";
        std::cout << "______________________________________________________________________________\n";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline character left in the input buffer

        switch (choice) {
            case '1':
                journal.writeEntry();
                break;
            case '2': {
                std::string date;
                std::cout << "\nEnter date (YYYY-MM-DD): ";
                std::cin >> date;
                sleep(1);
                //std::cout << system("clear");
                std::cout << "\033[2J\033[H";
                journal.readEntriesByDate(date);
                break;
            }
            case '3':
                sleep(1);
                //std::cout << system("clear");
                std::cout << "\033[2J\033[H";
            	  std::cout << "\nThank you for using our Journal app :)"
            			<< "\nSee you tomorrow!" << std::endl;
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != '3');

    return 0;
}


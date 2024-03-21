#include "journal.h"
#include <unistd.h> // for sleep

Journal::Journal(std::string username) {
    this->username = username;
}

std::string Journal::getCurrentDate() {
    time_t now = time(0);
    struct tm *timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d", timeinfo);
    return buffer;
}

std::string Journal::getFileName(const std::string &date) {
    return username + "_" + date + ".txt";
}

void Journal::login() {
    std::cout << "\n\n";
    std::cout << "\n*************** Welcome to the Journal app, " << username << "!" << "***************" << std::endl;
 
   
}

void Journal::writeEntry() {
    std::string date = getCurrentDate();
    std::string fileName = getFileName(date);

    std::ofstream file(fileName);
    if (file.is_open()) {
        std::string entry;
        std::cout << "\nEnter your journal entry for today (" << date << "):\n";
        std::cout << "(Note: Type 'END' on a new line to finish)\n\n";
        std::cout << "-->";

        while (true) {
            std::string line;
            std::getline(std::cin, line);

            if (line == "END") {
                break;
            }

            entry += line + '\n';
        }

        file << date << ":\n" << entry << std::endl;
        file.close();
        std::cout << "\n***Your Journal was added successfully!***" << std::endl;
        sleep(1);
        //std::cout << system("clear");
        std::cout << "\033[2J\033[H";
    } else {
        std::cout << "Unable to open journal file." << std::endl;
    }
}

void Journal::readEntriesByDate(const std::string &date) {
    std::string fileName = getFileName(date);

    std::ifstream file(fileName);
    if (file.is_open()) {
        std::cout << "Journal written on: " << date << std::endl;
        std::cout << "________________________________________________________\n" << std::endl;
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "No entries found for the specified date." << std::endl;
    }
}


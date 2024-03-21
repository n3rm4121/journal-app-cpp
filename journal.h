#ifndef JOURNAL_H
#define JOURNAL_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Journal {
private:
    std::string username;
    std::string getCurrentDate();
    std::string getFileName(const std::string &date);

public:
    Journal(std::string username);

    void login();
    void writeEntry();
    void readEntriesByDate(const std::string &date);
};

#endif /* JOURNAL_H */


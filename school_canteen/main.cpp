#include <sqlite3.h>
#include <fstream>
#include <iostream>
#include <string>

typedef struct {
    int id;
    char lunch;
} Menu_system;

typedef struct {
    int val = 0;
    char type;
} Highest;

int count(sqlite3 *db, char val) {
    sqlite3_stmt *stmt;
    int temp;
    char str[50];
    sprintf(str, "%s%c%s", "SELECT COUNT(*) FROM Students WHERE lunch = '", val, "'");

    sqlite3_prepare(db, str, -1, &stmt, nullptr);

    for (;;) {
        short rc = sqlite3_step(stmt);
        if (rc == SQLITE_DONE)
            break;
        if (rc != SQLITE_ROW)
            break;
        temp = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    return temp;
}

int main() {
    sqlite3 *db;
    char *sql = nullptr;
    sqlite3_stmt *stmt;

    Menu_system menu;
    std::fstream myFile;

    try {
        myFile.open("data/dataset1.txt", std::ios::in);

        if (!myFile.is_open()) {
            throw "File isn't open!";
        }

        sqlite3_open("school_canteen.db", &db);
        if (sqlite3_exec(db, "CREATE TABLE Students (id INT UNIQUE PRIMARY KEY, lunch CHAR)", nullptr, nullptr, nullptr) != SQLITE_OK) {
            //throw "Error: Create DB!";
        }

        while (!myFile.eof()) {
            myFile >> menu.id >> menu.lunch;

            sqlite3_prepare(db, "REPLACE INTO Students (id, lunch) VALUES (?, ?)", -1, &stmt, nullptr);

            sqlite3_bind_int(stmt, 1, menu.id);
            sqlite3_bind_text(stmt, 2, &menu.lunch, 1, SQLITE_TRANSIENT);

            sqlite3_step(stmt);
            sqlite3_finalize(stmt);
        }

        Highest lunch;
        int lunches[4];

        for (char i = 'a'; i < 'e'; i++) {
            lunches[i] = count(db, i);
            if (lunches[i] > lunch.val) {
                lunch.val = lunches[i];
                lunch.type = i;
            }
        }

        for (char i = 'a'; i < 'e'; i++) {
            if (lunches[i] < 20 && i != lunch.type) {
                lunch.val += lunches[i];
                lunches[i] = 0;
            }
        }

        lunches[lunch.type] = 0;
        lunches[lunch.type] = lunch.val;

        if (sqlite3_exec(db, "CREATE TABLE Results (lunch CHAR UNIQUE PRIMARY KEY, num INT)", nullptr, nullptr, nullptr) != SQLITE_OK) {
            //throw "Error: Create DB!";
        }

        for (char i = 'a'; i < 'e'; i++) {
            sqlite3_prepare(db, "INSERT INTO Results (lunch, num) VALUES (?, ?)", -1, &stmt, nullptr);
            sqlite3_bind_text(stmt, 1, &i, 1, SQLITE_TRANSIENT);
            sqlite3_bind_int(stmt, 2, lunches[i]);

            sqlite3_step(stmt);
            sqlite3_finalize(stmt);
        }

        sqlite3_prepare(db, "SELECT * FROM Results", -1, &stmt, nullptr);
        for (;;) {
            short rc = sqlite3_step(stmt);
            if (rc == SQLITE_DONE)
                break;
            if (rc != SQLITE_ROW)
                break;
            std::cout << sqlite3_column_text(stmt, 0) << " => " << sqlite3_column_int(stmt, 1) << '\n';
        }

        sqlite3_finalize(stmt);

        sqlite3_exec(db, "DROP TABLE Students", nullptr, nullptr, nullptr);
        sqlite3_exec(db, "DROP TABLE Results", nullptr, nullptr, nullptr);
        sqlite3_close(db);

    } catch (const char *err) {
        std::cerr << err << '\n';
    }
}
#include <iostream>
#include <fstream>
#include <string>

struct Directory {
    std::string company_name;
    std::string owner;
    std::string phone;
    std::string address;
    std::string activity;
};

void add_record() {
    std::ofstream file("directory.txt", std::ios::app);
    Directory d;

    std::cout << "enter company name: ";
    std::cin >> d.company_name;
    std::cout << "enter owner: ";
    std::cin >> d.owner;
    std::cout << "enter phone: ";
    std::cin >> d.phone;
    std::cout << "enter address: ";
    std::cin >> d.address;
    std::cout << "enter activity: ";
    std::cin >> d.activity;

    file << d.company_name << " " << d.owner << " " << d.phone << " "
        << d.address << " " << d.activity << "\n";

    file.close();
    std::cout << "record added" << std::endl;
}

void display_all() {
    std::ifstream file("directory.txt");
    Directory d;
    std::cout << "\nall records:\n";
    while (file >> d.company_name >> d.owner >> d.phone >> d.address >> d.activity) {
        std::cout << d.company_name << " | " << d.owner << " | " << d.phone
            << " | " << d.address << " | " << d.activity << "\n";
    }
    file.close();
}

void search(int type) {
    std::ifstream file("directory.txt");
    std::string query;
    std::cout << "enter search value: ";
    std::cin >> query;

    Directory d;
    bool found = false;
    while (file >> d.company_name >> d.owner >> d.phone >> d.address >> d.activity) {
        bool match = false;
        if (type == 1 && d.company_name == query) match = true;
        if (type == 2 && d.owner == query) match = true;
        if (type == 3 && d.phone == query) match = true;
        if (type == 4 && d.activity == query) match = true;

        if (match) {
            std::cout << "found: " << d.company_name << " " << d.owner << " "
                << d.phone << " " << d.address << " " << d.activity << "\n";
            found = true;
        }
    }
    if (!found) std::cout << "no records found.\n";
    file.close();
}

int main() {
    std::cout << "test1" << std::endl;
    int choice;
    while (true) {
        std::cout << "\n1. add\n2. display all\n3. search by name\n4. search by owner\n5. search by phone\n6. search by activity\n";
        std::cout << "7. exit\nchoice: ";
        std::cin >> choice;

        if (choice == 1) add_record();
        else if (choice == 2) display_all();
        else if (choice >= 3 && choice <= 6) search(choice - 2);
        else if (choice == 7) break;
        else std::cout << "wrong choice.\n";
    }
}
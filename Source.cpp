#include <iostream>
#include <fstream>
#include <string>

class Company {
private:
    std::string name;
    std::string owner;
    std::string phone;
    std::string address;
    std::string activity;

public:
    Company(std::string n = "", std::string o = "", std::string p = "", std::string ad = "", std::string ac = "")
        : name(n), owner(o), phone(p), address(ad), activity(ac) {
    }

    std::string getName() const { return name; }
    std::string getOwner() const { return owner; }
    std::string getPhone() const { return phone; }
    std::string getAddress() const { return address; }
    std::string getActivity() const { return activity; }


    void print() const {
        std::cout << name << " | " << owner << " | " << phone << " | " << address << " | " << activity << "\n";
    }
};

void saveToFile(const Company& c) {
    std::ofstream file("directory.txt", std::ios::app);
    if (file.is_open()) {
        file << c.getName() << " " << c.getOwner() << " " << c.getPhone() << " "
            << c.getAddress() << " " << c.getActivity() << "\n";
        file.close();
    }
}

void showAllRecords() {
    std::ifstream file("directory.txt");
    std::string n, o, p, ad, ac;
    std::cout << "records list:\n";
    while (file >> n >> o >> p >> ad >> ac) {
        Company temp(n, o, p, ad, ac);
        temp.print();
    }
    file.close();
}

void findInFile(std::string query, int type) {
    std::ifstream file("directory.txt");
    std::string n, o, p, ad, ac;
    bool found = false;

    while (file >> n >> o >> p >> ad >> ac) {
        Company temp(n, o, p, ad, ac);
        bool match = false;

        if (type == 1 && temp.getName() == query) match = true;
        else if (type == 2 && temp.getOwner() == query) match = true;
        else if (type == 3 && temp.getPhone() == query) match = true;
        else if (type == 4 && temp.getActivity() == query) match = true;

        if (match) {
            std::cout << "match found: ";
            temp.print();
            found = true;
        }
    }
    if (!found) std::cout << "nothing found.\n";
    file.close();
}

int main() {
    std::cout << "test" << std::endl;
    int choice;
    while (true) {
        std::cout << "1. add record\n2. show all\n3. search\n4. exit\nchoice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string n, o, p, ad, ac;
            std::cout << "enter name, owner, phone, address, activity: ";
            std::cin >> n >> o >> p >> ad >> ac;
            Company newComp(n, o, p, ad, ac);
            saveToFile(newComp);
        }
        else if (choice == 2) {
            showAllRecords();
        }
        else if (choice == 3) {
            std::string q;
            int t;
            std::cout << "1.name 2.owner 3.phone 4.activity: ";
            std::cin >> t;
            std::cout << "enter search query: ";
            std::cin >> q;
            findInFile(q, t);
        }
        else if (choice == 4) break;
    }
}
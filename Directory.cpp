#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Directory.hpp"
// #include "Read.hpp"

//////////////////// Constructor ////////////////////

Directory::Directory() {
    this -> p_head = nullptr;
}

//////////////////// Destructor ////////////////////

Directory::~Directory() {
    
    Employee *p_traverse{p_head};

    while (p_traverse != nullptr) {
        Employee *p_old_traverse{p_head};
        p_traverse = p_traverse -> get_next();
        delete p_old_traverse;
        p_old_traverse = nullptr;
    }

    p_traverse = nullptr;

}

//////////////////// Add Functions ////////////////////

void Directory::insert( Employee *p_new_employee ) {

    if (p_head == nullptr) {

        this -> p_head = p_new_employee;

    } else {

        Employee *p_traverse{p_head};
        while (p_traverse -> get_next() != nullptr) {
            p_traverse = p_traverse -> get_next();
        }

        p_traverse -> set_next(p_new_employee);
    }

}

void Directory::add( Employee *p_new_employee ) {

    std::ofstream myFile;
    myFile.open("Directory.txt", std::ios::app);
    if (myFile.is_open()) {
        myFile << p_new_employee -> get_first() << " " 
                << p_new_employee -> get_last() << " " 
                << p_new_employee -> get_id() << " " 
                << p_new_employee -> get_phone() << std::endl;
        myFile.close();
    }

}

void Directory::multi_add() {

    Employee *p_traverse{p_head};

    while (p_traverse != nullptr) {
        Directory::add(p_traverse);
        p_traverse = p_traverse -> get_next();
    }
}

//////////////////// Delete Functions ////////////////////

void Directory::wipe() {

    std::ofstream myFile;
    myFile.open("Directory.txt", std::ios::out);
    if (myFile.is_open()) {
        myFile << "";
    }
}

void Directory::clear() {

Employee *p_traverse{p_head};

    while (p_traverse != nullptr) {
        Employee *p_old_traverse{p_head};
        p_traverse = p_traverse -> get_next();
        delete p_old_traverse;
        p_old_traverse = nullptr;
    }

    p_traverse = nullptr;

}

//////////////////// Print Functions ////////////////////

void Directory::read() {
    std::ifstream myFile;
    myFile.open("Directory.txt", std::ios::in);
    if (myFile.is_open()) {

        std::string new_first;
        std::string new_last;
        unsigned int new_id;
        unsigned int new_phone;

        while (myFile >> new_first >> new_last >> new_id >> new_phone) {
            Employee *p_new_employee = new Employee{new_first, new_last, new_id, new_phone};
            p_new_employee -> print();
        }
        myFile.close();
    }
}

void Directory::print() {

    std::cout << "========== BEGIN DIRECTORY ==========" << std::endl;

    Employee *p_traverse{p_head};

    while (p_traverse != nullptr) {
        p_traverse -> print();
        p_traverse = p_traverse -> get_next();
    }

    std::cout << "========== END DIRECTORY ==========" << std::endl;
}

//////////////////// Sort Functions ////////////////////

void Directory::sort_by_id() {

    Employee *p_head_new{nullptr};
    Employee *p_front{nullptr};

    p_front = p_head;
    p_head = p_head -> get_next();
    p_front -> set_next(nullptr);

    p_head_new = p_front;
    p_front = nullptr;

    while (p_head != nullptr) {

        p_front = p_head;
        p_head = p_head -> get_next();
        p_front -> set_next(nullptr);

        Employee * p_traverse{p_head_new};

        if (p_front -> get_id() < p_traverse -> get_id()) {

            p_front -> set_next(p_head_new);
            p_head_new = p_front;
            p_front = nullptr;

        } else {

            while ( (p_traverse -> get_next() != nullptr) && (p_traverse -> get_id() < p_front -> get_id()) ) {
                p_traverse = p_traverse -> get_next();
            }

            p_front -> set_next(p_traverse -> get_next());
            p_traverse -> set_next(p_front);
            p_front = nullptr;

        }

        p_traverse = nullptr;

    }

    p_head = p_head_new;
    p_head_new = nullptr;
    p_front = nullptr;

}

void Directory::sort_by_first() {

    Employee *p_head_new{nullptr};
    Employee *p_front{nullptr};

    p_front = p_head;
    p_head = p_head -> get_next();
    p_front -> set_next(nullptr);

    p_head_new = p_front;
    p_front = nullptr;

    while (p_head != nullptr) {

        p_front = p_head;
        p_head = p_head -> get_next();
        p_front -> set_next(nullptr);

        Employee * p_traverse{p_head_new};

        if (p_front -> get_first() < p_traverse -> get_first()) {

            p_front -> set_next(p_head_new);
            p_head_new = p_front;
            p_front = nullptr;

        } else {

            while ( (p_traverse -> get_next() != nullptr) && (p_traverse -> get_first() < p_front -> get_first()) ) {
                p_traverse = p_traverse -> get_next();
            }

            p_front -> set_next(p_traverse -> get_next());
            p_traverse -> set_next(p_front);
            p_front = nullptr;

        }

        p_traverse = nullptr;

    }

    p_head = p_head_new;
    p_head_new = nullptr;
    p_front = nullptr;

}

void Directory::sort_by_last() {

    Employee *p_head_new{nullptr};
    Employee *p_front{nullptr};

    p_front = p_head;
    p_head = p_head -> get_next();
    p_front -> set_next(nullptr);

    p_head_new = p_front;
    p_front = nullptr;

    while (p_head != nullptr) {

        p_front = p_head;
        p_head = p_head -> get_next();
        p_front -> set_next(nullptr);

        Employee * p_traverse{p_head_new};

        if (p_front -> get_last() < p_traverse -> get_last()) {

            p_front -> set_next(p_head_new);
            p_head_new = p_front;
            p_front = nullptr;

        } else {

            while ( (p_traverse -> get_next() != nullptr) && (p_traverse -> get_last() < p_front -> get_last())) {
                p_traverse = p_traverse -> get_next();
            }

            p_front -> set_next(p_traverse -> get_next());
            p_traverse -> set_next(p_front);
            p_front = nullptr;

        }

        p_traverse = nullptr;

    }

    p_head = p_head_new;
    p_head_new = nullptr;
    p_front = nullptr;

}

void Directory::sort_by_phone() {

    Employee *p_head_new{nullptr};
    Employee *p_front{nullptr};

    p_front = p_head;
    p_head = p_head -> get_next();
    p_front -> set_next(nullptr);

    p_head_new = p_front;
    p_front = nullptr;

    while (p_head != nullptr) {

        p_front = p_head;
        p_head = p_head -> get_next();
        p_front -> set_next(nullptr);

        Employee * p_traverse{p_head_new};

        if (p_front -> get_phone() < p_traverse -> get_phone()) {

            p_front -> set_next(p_head_new);
            p_head_new = p_front;
            p_front = nullptr;

        } else {

            while ( (p_traverse -> get_next() != nullptr) && (p_traverse -> get_phone() < p_front -> get_phone()) ) {
                p_traverse = p_traverse -> get_next();
            }

            p_front -> set_next(p_traverse -> get_next());
            p_traverse -> set_next(p_front);
            p_front = nullptr;

        }

        p_traverse = nullptr;

    }

    p_head = p_head_new;
    p_head_new = nullptr;
    p_front = nullptr;
}

//////////////////// Search Functions ////////////////////

void Directory::search_by_id(unsigned int search_id) {

    Employee *p_traverse{p_head};
    bool results{false};

    while (p_traverse != nullptr) {

        unsigned int part_id{p_traverse -> get_id()};

        while (part_id >= search_id*10) {
            part_id /= 10;
        }

        if (part_id == search_id) {
            p_traverse -> print();
            results = true;
        }

        p_traverse = p_traverse -> get_next();
    }

    if (!results) {
        std::cout << "No Results Found" << std::endl;
    }

}

void Directory::search_by_first( std::string search_first ) {

    Employee *p_traverse{p_head};
    bool results{false};

    char *tmp = new char[search_first.length() + 1];
    stoc(search_first, tmp);
    search_first.assign(tmp);
    delete[] tmp;

    while (p_traverse != nullptr) {

        std::size_t found = search_first.find(p_traverse -> get_first(), 0, search_first.length());
        
        if ( found != std::string::npos ) {
            p_traverse -> print();
            results = true;
        }

        p_traverse = p_traverse -> get_next();
    }

    if (!results) {
        std::cout << "No Results Found" << std::endl;
    }

}

void Directory::search_by_last( std::string search_last ) {

    Employee *p_traverse{p_head};
    bool results{false};

    char *tmp = new char[search_last.length() + 1];
    stoc(search_last, tmp);
    search_last.assign(tmp);
    delete[] tmp;

    while (p_traverse != nullptr) {

        std::size_t found = search_last.find(p_traverse -> get_last(), 0, search_last.length());
        
        if ( found != std::string::npos ) {
            p_traverse -> print();
            results = true;
        }

        p_traverse = p_traverse -> get_next();
    }

    if (!results) {
        std::cout << "No Results Found" << std::endl;
    }

}

void Directory::search_by_phone( unsigned int search_phone ) {

    Employee *p_traverse{p_head};
    bool results{false};

    while (p_traverse != nullptr) {

        unsigned int part_phone{p_traverse -> get_id()};

        while (part_phone >= search_phone*10) {
            part_phone /= 10;
        }

        if (part_phone == search_phone) {
            p_traverse -> print();
            results = true;
        }

        p_traverse = p_traverse -> get_next();
    }

    if (!results) {
        std::cout << "No Results Found" << std::endl;
    }

}
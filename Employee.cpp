#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Employee.hpp"

//////////////////// Constructor ////////////////////

Employee::Employee( std::string first, std::string last, unsigned int id, unsigned int phone) {

    stoc(first, first_name);
    stoc(last, last_name);
    employee_id = id;
    phone_number = phone;

    p_next = nullptr;

}

//////////////////// Destructor ////////////////////

Employee::~Employee() {
    delete[] first_name;
    delete[] last_name;
}

//////////////////// Get Functions ////////////////////

char *Employee::get_first() const { return first_name; }
char *Employee::get_last() const { return last_name; }
unsigned int Employee::get_id() const { return employee_id; }
unsigned int Employee::get_phone() const { return phone_number; }
Employee *Employee::get_next() { return p_next; }

//////////////////// Set Functions ////////////////////

void Employee::set_first( std::string new_first ) { stoc (new_first, first_name); }
void Employee::set_last ( std::string new_last ) { stoc(new_last, last_name); }
void Employee::set_id (unsigned int new_id ) { employee_id = new_id; }
void Employee::set_phone (unsigned int new_phone) { phone_number = new_phone; }
void Employee::set_next ( Employee *p_new_next ) { p_next = p_new_next; }

//////////////////// Print Function ////////////////////

void Employee::print() {
    
    for (std::size_t i{0}; i < sizeof(first_name); ++i) {
        std::cout << first_name[i];
    }

    std::cout << std::setw(5);

    for (std::size_t i{0}; i < sizeof(last_name); ++i) {
        std::cout << last_name[i];
    }

    std::cout << std::setw(5) << employee_id << "     " << phone_number << std::endl;
}

//////////////////// String to Char Function ////////////////////

void stoc( std::string text, char *& cstring ) {

  char *tmp = new char[sizeof(text) + 1];
  strcpy(tmp, text.c_str());
  for (std::size_t i{0}; i < sizeof(text) + 1; ++i) {
    tmp[i] = toupper(tmp[i]);
  }

  cstring = tmp;
    
}
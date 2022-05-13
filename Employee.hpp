#include <iostream>
#include <string>

#pragma once

class Employee {
    public:

        // Constructor
        Employee( std::string first, std::string last, unsigned int id, unsigned int phone );

        // Destructor
        ~Employee();

        // Get Functions
        char *get_first() const;
        char *get_last() const;
        unsigned int get_id() const;
        unsigned int get_phone() const;
        Employee *get_next();

        // Set Functions
        void set_first( std::string new_first );
        void set_last( std::string new_last );
        void set_id( unsigned int new_id );
        void set_phone( unsigned int new_phone );
        void set_next( Employee *p_new_next );

        // Print Function
        void print();

    private:

        char *first_name;
        char *last_name;
        unsigned int employee_id;
        unsigned int phone_number;

        Employee *p_next;

};

void stoc( std::string text, char *& cstring );
#include <iostream>
#include "Employee.hpp"

#pragma once

class Directory {
    public:

        // Constructor
        Directory();

        // Destructor
        ~Directory();

        // Add Functions
        void insert( Employee *p_new_employee );
        void add( Employee *p_new_employee );
        void multi_add();

        // Delete Functions
        void wipe();
        void clear();

        // Print Functions
        void read();
        void print();

        // Sort Functions
        void sort_by_id();
        void sort_by_first();
        void sort_by_last();
        void sort_by_phone();

        // Search Functions
        void search_by_id( unsigned int search_id );
        void search_by_first( std::string search_first );
        void search_by_last( std::string search_last );
        void search_by_phone( unsigned int search_phone );

    private:

        Employee *p_head;
};
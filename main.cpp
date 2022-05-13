#include <iostream>
#include "Employee.hpp"
#include "Directory.hpp"

// g++ -o Edit_List main.cpp Directory.cpp Employee.cpp -std=c++11

int main();

int main() {

    bool cont{true};

    std::cout << "Welcome To The Directory" << std::endl;

    Directory list{};

    while (cont) {

        char input{};

        std::cout << "What Would You Like To Do?" << std::endl
                    << "[C]ommands [H]elp  [Q]uit" << std::endl;
        std::cin >> input;
        input = toupper(input);

        if (input == 'Q') {

            break;

        } else if (input == 'C') {

            std::cout << "[A]dd  [D]elete  [P]rint  S[O]rt  S[E]arch  [B]ack" << std::endl;
            std::cin >> input;
            input = toupper(input);

            if (input == 'B') {

                continue;

            } else if(input == 'A') {

                std::string new_first{};
                std::string new_last{};
                unsigned int new_id{};
                unsigned int new_phone{};

                bool another{true};

                while (another) {

                    std::cout << "First Name: ";
                    std::cin >> new_first;
                    std::cout << "Last Name: ";
                    std::cin >> new_last;
                    std::cout << "Employee ID: ";
                    std::cin >> new_id;
                    std::cout << "Phone Number: ";
                    std::cin >> new_phone;

                    Employee * new_employee = new Employee{new_first, new_last, new_id, new_phone};
                    list.insert(new_employee);

                    std::cout << "Would You Like To Add Another Employee?" << std::endl
                                << "0 For No || 1 For Yes" << std::endl;
                    std::cin >> another;
                }

                continue;
                
            } else if(input == 'D') {
                
                list.clear();
                list.wipe();
                continue;

            } else if(input == 'P') {

                list.multi_add();
                list.print();
                continue;
                
            } else if(input == 'O') {

                std::cout << "Would You Like To Sort Alphabetically By [F]irst Or [L]ast Name" << std::endl
                            << "Or Numerically By [I]d Or [P]hone" << std::endl;
                std::cin >> input;
                input = toupper(input);

                if (input == 'F') {
                    list.sort_by_first();
                    continue;
                } else if (input == 'L') {
                    list.sort_by_last();
                    continue;
                } else if (input == 'I') {
                    list.sort_by_id();
                    continue;
                } else if (input == 'P') {
                    list.sort_by_phone();
                    continue;
                } else {
                    std::cout << "Invalid Input.  Returning To Main Menu" << std::endl;
                    continue;
                }
                
            } else if(input == 'E') {

                std::cout << "Would You Like To Search By [F]irst Or [L]ast Name" << std::endl
                            << "Or Numerically By [I]d Or [P]hone" << std::endl;
                std::cin >> input;
                input = toupper(input);

                if (input == 'F') {
                    std::string search_first{};
                    std::cout << "Search Here: ";
                    std::cin >> search_first;
                    list.search_by_first(search_first);
                    continue;
                } else if (input == 'L') {
                    std::string search_last{};
                    std::cout << "Search Here: ";
                    std::cin >> search_last;
                    list.search_by_last(search_last);
                    continue;
                } else if (input == 'I') {
                    unsigned int search_id{};
                    std::cout << "Search Here: ";
                    std::cin >> search_id;
                    list.search_by_id(search_id);
                    continue;
                } else if (input == 'P') {
                    unsigned int search_phone{};
                    std::cout << "Search Here: ";
                    std::cin >> search_phone;
                    list.search_by_phone(search_phone);
                    continue;
                } else {
                    std::cout << "Invalid Input.  Returning To Main Menu" << std::endl;
                    continue;
                }
                
            } else {

                std::cout << "Invalid Input.  Returning To Main Menu" << std::endl;
                continue;

            }

        } else if (input == 'H' ) {

            std::cout << "This Tool Is Designed To Help Create A Directory" << std::endl
                        << "Go To Commands To Utilize These Functions" << std::endl
                        << "'Add' Creates Entries In The Directory" << std::endl
                        << "'Delete' Empties The Directory" << std::endl
                        << "'Print' Prints The Directory" << std::endl
                        << "'Sort' The Directory Using Parameters" << std::endl
                        << "'Search' The Directory Using Parameters" << std::endl
                        << "'Back' Returns To The Main Menu" << std::endl;
            
            continue;

        } else {
            
            std::cout << "Invalid Input.  Please Try Again" << std::endl;
            continue;

        }
    }

    std::cout << "Thanks For Utilizing This Tool" << std::endl;

    return 0;
}
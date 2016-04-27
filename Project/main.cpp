#include <iostream>
#include "movies.h"

int main()
{
    HashTable table;
    HashTable tree;
    table.table();
    bool quit = false;
    while(!quit){
        table.menu();
        std::string choice;
        std::getline(std::cin, choice);
        if (choice == "1") {
            std::string title;
            int year;
            std::cout << "Enter title:" << std::endl;
            getline(std::cin, title);
            std::cout << "Enter year:" << std::endl;
            std::cin >> year;
            table.insertMovie(title, year);
        }
        else if (choice == "2") {
            std::string deletetitle;
            std::cout << "Enter title:" << std::endl;
            getline(std::cin, deletetitle);
            table.deleteHMovie(deletetitle);
        }
        else if (choice == "3") {
            std::string findtitle;
            std::cout << "Enter title:" << std::endl;
            getline(std::cin, findtitle);
            table.findhashMovie(findtitle);
        }
        else if (choice == "4") {
            table.printTable();
        }
        else if (choice == "5") {
            std::string treetitle;
            int year;
            std::cout << "Title: " << std::endl;
            getline(std::cin, treetitle);
            std::cout << "Year: " << std::endl;
            std::cin >> year;
            tree.addMovieNode(1, treetitle, year, 1);
        }
        else if (choice == "6") {
            std::cout << "Enter title:" << std::endl;
            std::string findtitle;
            getline(std::cin, findtitle);
            tree.findMovie(findtitle);
        }
        else if (choice == "7") {
            std::cout << "Enter title:" << std::endl;
            std::string torent;
            getline(std::cin, torent);
            tree.rentMovie(torent);
        }
        else if (choice == "8") {
            tree.printMovieInventory();
        }
        else if (choice == "9") {
            std::cout << "Enter title:" << std::endl;
            std::string choicedelete;
            getline(std::cin, choicedelete);
            tree.deleteMovie(choicedelete);

        }
        else if (choice == "10") {
            tree.countMovies();
        }
        else if (choice == "11") {
            std::cout << "Goodbye!\n";
            quit = true;
        }
    }
    tree.postOrder();
}

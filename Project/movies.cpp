#include "movies.h"
#include <iostream>

HashTable::HashTable()
{
}
HashTable::~HashTable()
{
}
void HashTable::menu()
{
    std::cout << "======Main Menu======" << std::endl;
    std::cout << "1. Insert movie into hash table" << std::endl;
    std::cout << "2. Delete movie from hash table" << std::endl;
    std::cout << "3. Find movie in hash table" << std::endl;
    std::cout << "4. Print hash table contents" << std::endl;
    std::cout << "5. Add a movie to tree" << std::endl;
    std::cout << "6. Find a movie in tree" << std::endl;
    std::cout << "7. Rent a movie in tree" << std::endl;
    std::cout << "8. Print the inventory from tree" << std::endl;
    std::cout << "9. Delete a movie from tree" << std::endl;
    std::cout << "10. Count the movies in tree" << std::endl;
    std::cout << "11. Quit" << std::endl;
}
void HashTable::table() {
    for (int i = 0; i < 10; i++) {
        hashTable[i] = NULL;
    }
}


void HashTable::deleteHMovie(std::string name) {
    int index = sum(name, 10);
    if (hashTable[index] != NULL) {
        HashElem *tmp= hashTable[index];
        while (tmp-> next != NULL) {
            if (tmp-> title == name) {
                break;
            }
            tmp= tmp->next;
        }
        if (tmp-> previous != NULL) {
            tmp-> previous -> next = tmp-> next;
            tmp-> next -> previous = tmp-> previous;
            delete tmp;
        }
        else {
            hashTable[index] = NULL;
        }
    }
}

void HashTable::findhashMovie(std::string name) {
    int index = sum(name, 10);
    HashElem *tmp= hashTable[index];
    int found = 0;
    while (tmp!= NULL) {
        if (tmp-> title == name) {
            std::cout << index << ":";
            std::cout << tmp-> title << ":" << tmp-> year << std::endl;
            found++;
            break;
        }
        tmp= tmp-> next;
    }
    if (found == 0) {
        std::cout << "not found" << std::endl;
    }
}
int HashTable::sum(std::string x, int s) {
    int sum = 0;
    for (int i = 0; i < x.length(); i++) {
        sum = sum + x[i];
    }
    sum = sum % s;
    return sum;
}
void HashTable::printTable() {
    int counter = 0;
    for (int i = 0; i < 10; i++) {
        if (hashTable[i] != NULL) {
            counter++;
            HashElem *tmp= hashTable[i];
            while (tmp!= NULL) {
                std::cout<< tmp->title << ":" << tmp->year << std::endl;
                tmp= tmp->next;
            }
        }
    }
    if (counter == 0) {
        std::cout << "Currently Empty" << std::endl;
    }
}

void HashTable::insertMovie(std::string name, int year) {
    int index = sum(name, 20);
    HashElem *hashElement = new HashElem(name, year);
    if (hashTable[index] == NULL) {
        hashTable[index] = hashElement;
    }
    else {
        HashElem *tmp= hashTable[index];
        while (tmp->next != NULL) {
            if (tmp->title == name) {
            }
            tmp= tmp-> next;
        }
        hashElement -> previous = tmp;
        tmp->next = hashElement;
    }
}

void HashTable::printMovieInventory(){
    if (root != NULL) {
        MovieNode *node = root;
        if (node-> leftChild != NULL) {
            printMovieInventory(node-> leftChild);
        }
        std::cout << "Movie: " << node-> title << " " << node-> quantity << std::endl;
        if (node-> rightChild != NULL) {
            printMovieInventory(node-> rightChild);
        }
    }
    else {
        std::cout << "Tree is currently empty" << std::endl;
    }
}

void HashTable::printMovieInventory(MovieNode *node) {
    if (node-> leftChild != NULL) {
        printMovieInventory(node-> leftChild);
    }
    std::cout << "Movie: " << node-> title << " " << node-> quantity << std::endl;
    if (node-> rightChild != NULL) {
        printMovieInventory(node-> rightChild);
    }
}

void HashTable::addMovieNode(int ranking, std::string title, int releaseYear, int quantity) {
    MovieNode *tmp= root;
    MovieNode *parent = NULL;
    MovieNode *node = new MovieNode(ranking, title, releaseYear, quantity);
    node-> leftChild = NULL;
    node-> rightChild = NULL;
    node-> parent = NULL;
    while (tmp!= NULL) {
        parent = tmp;
        if ((node-> title).compare(tmp-> title) < 0) {
            tmp= tmp-> leftChild;
        }
        else {
            tmp= tmp-> rightChild;
        }
    }
    if (parent == NULL) {
        root = node;
    }
    else if ((node-> title).compare(parent-> title) < 0) {
        parent-> leftChild = node;
        node-> parent = parent;
    }
    else {
        parent-> rightChild = node;
        node-> parent = parent;
    }
}

void HashTable::findMovie(std::string title) {
    int findMovie_Counter = 0;
    MovieNode *node = root;
    while (node != NULL) {
        if ((node-> title).compare(title) > 0) {
            node = node-> leftChild;
        }
        else if ((node-> title).compare(title) < 0) {
            node = node-> rightChild;
        }
        else {
            std::cout << "Movie Info:" << std::endl;
            std::cout << "===========" << std::endl;
            std::cout << "Ranking:" << node-> ranking << std::endl;
            std::cout << "Title:" << node-> title << std::endl;
            std::cout << "Year:" << node-> year << std::endl;
            std::cout << "Quantity:" << node-> quantity << std::endl;
            findMovie_Counter++;
            break;
        }
    }
    if (findMovie_Counter == 0) {
        std::cout << "Movie not found." << std::endl;
    }
}

MovieNode *HashTable::treeMin(MovieNode *node) {
    while (node-> leftChild != NULL) {
        node = node-> leftChild;
    }
    return node;
}

void HashTable::deleteMovie(std::string title) {
    int deleteMovie_Counter = 0;
    MovieNode *node = root;
    while (node != NULL) {
        if ((node-> title).compare(title) > 0) {
            node = node-> leftChild;
        }
        else if ((node-> title).compare(title) < 0) {
            node = node-> rightChild;
        }
        else {
            if (node-> leftChild == NULL && node-> rightChild == NULL) {
                if (node-> parent-> leftChild == node) {
                    node-> parent-> leftChild = NULL;
                }
                else {
                    node-> parent-> rightChild = NULL;
                }
                delete node;
            }
            else if ((node-> leftChild != NULL && node-> rightChild == NULL) || (node-> leftChild == NULL && node-> rightChild != NULL)) {
                if (node-> leftChild != NULL && node-> rightChild == NULL) {
                    if (node-> parent-> leftChild == node) {
                        MovieNode *tmp= node-> leftChild;
                        node-> parent-> leftChild = tmp;
                        tmp-> parent = node-> parent;
                        delete node;
                    }
                    else {
                        MovieNode *tmp= node-> leftChild;
                        node-> parent-> rightChild = tmp;
                        tmp-> parent = node-> parent;
                        delete node;
                    }
                }
                else {
                    if (node-> parent-> rightChild == node) {
                        MovieNode *tmp= node-> rightChild;
                        node-> parent-> rightChild = tmp;
                        tmp-> parent = node-> parent;
                        delete node;
                    }
                    else {
                        MovieNode *tmp= node-> rightChild;
                        node-> parent-> leftChild = tmp;
                        tmp-> parent = node-> parent;
                        delete node;
                    }
                }
            }
            else {
                MovieNode *minimum = node-> rightChild;
                minimum = treeMin(minimum);
                if (node-> parent-> leftChild == node) {
                    if (minimum -> parent == node) {
                        node-> parent-> leftChild = minimum;
                        minimum -> parent = node-> parent;
                        node-> leftChild -> parent = minimum;
                        minimum -> leftChild = node-> leftChild;
                        delete node;
                    }
                    else {
                        minimum -> parent-> leftChild = minimum -> rightChild;
                        minimum -> parent = node-> parent;
                        minimum -> rightChild -> parent = minimum -> parent;
                        node-> parent-> leftChild = minimum;
                        minimum -> leftChild = node-> leftChild;
                        minimum -> rightChild = node-> rightChild;
                        node-> rightChild -> parent = minimum;
                        node-> leftChild -> parent = minimum;
                        delete node;
                    }
                }
                else {
                    if (minimum -> parent == node) {
                        node-> parent-> rightChild = minimum;
                        minimum -> parent = node-> parent;
                        node-> leftChild -> parent = minimum;
                        minimum -> leftChild = node-> leftChild;
                        delete node;
                    }
                    else {
                        minimum -> parent-> leftChild = minimum -> rightChild;
                        minimum -> parent = node-> parent;
                        minimum -> rightChild -> parent = minimum -> parent;
                        node-> parent-> rightChild = minimum;
                        minimum -> leftChild = node-> leftChild;
                        minimum -> rightChild = node-> rightChild;
                        node-> rightChild -> parent = minimum;
                        node-> leftChild -> parent = minimum;
                        delete node;
                    }
                }
            }

            deleteMovie_Counter++;
            break;
        }
    }
    if (deleteMovie_Counter == 0) {
        std::cout << "Movie not found." << std::endl;
    }
}



void HashTable::rentMovie(std::string title) {
    int rentMovie_Counter = 0;
    MovieNode *node = root;
    while (node != NULL) {
        if ((node-> title).compare(title) > 0) {
            node = node-> leftChild;
        }
        else if ((node-> title).compare(title) < 0) {
            node = node-> rightChild;
        }
        else {
            if (node-> quantity > 0) {
                node-> quantity = (node-> quantity) - 1;
                std::cout << "Movie has been rented." << std::endl;
                std::cout << "Movie Info:" << std::endl;
                std::cout << "===========" << std::endl;
                std::cout << "Ranking:" << node-> ranking << std::endl;
                std::cout << "Title:" << node-> title << std::endl;
                std::cout << "Year:" << node-> year << std::endl;
                std::cout << "Quantity:" << node-> quantity << std::endl;
                rentMovie_Counter++;
                if (node-> quantity == 0) {
                    deleteMovie(node-> title);
                }
                break;
            }
            else {
                std::cout << "Movie out of stock." << std::endl;
                rentMovie_Counter++;
                break;
            }
        }
    }
    if (rentMovie_Counter == 0) {
        std::cout << "Movie not found." << std::endl;
    }
}

void HashTable::countMovies() {
    if (root != NULL) {
        MovieNode *node = root;
        movieCounter = 0;
        if (node-> leftChild != NULL) {
            countMovies(node-> leftChild);
        }
        if (node-> rightChild != NULL) {
            countMovies(node-> rightChild);
        }
        movieCounter++;
        std::cout << "Tree contains: " << movieCounter << " movies." << std::endl;
    }
    else {
        std::cout << "tree empty" << std::endl;
    }
}

void HashTable::countMovies(MovieNode *node) {
    if (node-> leftChild != NULL) {
		countMovies(node-> leftChild);
	}
	if (node-> rightChild != NULL) {
		countMovies(node-> rightChild);
	}
	movieCounter++;
}

void HashTable::postOrder() {
    if (root != NULL) {
        MovieNode *node = root;
        if (node-> leftChild != NULL) {
            postOrder(node-> leftChild);
        }
        if (node-> rightChild != NULL) {
            postOrder(node-> rightChild);
        }
        std::cout << "Deleting: " << node-> title << std::endl;
        delete node;
    }
    else {
        std::cout << "tree empty" << std::endl;
    }
}

void HashTable::postOrder(MovieNode *node) {
    if (node-> leftChild != NULL) {
		postOrder(node-> leftChild);
	}
	if (node-> rightChild != NULL) {
		postOrder(node-> rightChild);
	}
	std::cout << "Deleting: " << node-> title << std::endl;
	delete node;
}



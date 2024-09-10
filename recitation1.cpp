/*
Recitation Assignment 1
Name: Duyen Vu
Date: 08/27/2023
*/
#include <iostream>
#include <string>
using namespace std;

// Define a struct to store all the cities information 
struct City {
    string cityName;
    int population;
    int medianIncome;
    City* next;
};

// Define a class for linked list operations
class LinkedList {
private:
    City* head;
    City* tail;

public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr) {}
    
    // Add a city to the tail
    void addToEnd(string cityName, int population, int medianIncome) {
        City* newCity = new City;
        newCity->cityName = cityName;
        newCity->population = population;
        newCity->medianIncome = medianIncome;
        newCity->next = nullptr;
        
        // If no head, new city will be added to the head and the tail
        if (head == 0) {
            head = tail = newCity;
        // Else, new city add to the end of the list
        } else {
            tail->next = newCity;
            tail = newCity;
        }
    }
    
    // Add a city to the head
    void addToFront(string cityName, int population, int medianIncome) {
        City* newCity = new City;
        newCity->cityName = cityName;
        newCity->population = population;
        newCity->medianIncome = medianIncome;
        newCity->next = head;
        
        head = newCity;
        // If there is no tail, the new city will be added to the tail
        if (tail == 0) { 
            tail = newCity;
        }
    }
    
    // Find the city with largest population
    void largestPopulation() {
        // Initialize a pointer starting from the head
        City* current = head; 
        int max = 0;
        City* largestCity = nullptr;

        // While current is not a nullptr, compare the current city to max and update max
        while (current != nullptr) {
            if (current->population > max) {
                max = current->population;
                largestCity = current;
            }
            current = current->next;
        }

        // Print a city with the largest population
        if (largestCity != nullptr) {
            cout << "City with largest population:\n";
            cout << largestCity->cityName << ", ";
            cout << largestCity->population << ", ";
            cout << "$" << largestCity->medianIncome << ".\n";
        } else {
            cout << "No city records\n";
        }
    }
    
    // List all the City
    void allCities() {
        City* current = head;

        if (head != 0) {
            cout << "List of cities:\n";
            while (current) {
                cout << current->cityName << ", ";
                cout << current->population << ", ";
                cout << "$" << current->medianIncome << ".\n";
                current = current->next;
            }
        } else {
            cout << "No city records\n";
        }
    }
    
    // Destructor (clean up the memory no longer used)
    ~LinkedList() {
        City* current = head;
        while (current != nullptr) {
            City* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList cities;
    bool stopProgram = false;

    // Main program loop that shows all the choices to the user
    while (stopProgram == false) {
        cout << "Please choose one of the following options:\n";
        cout << "1. Add city record at the tail\n";
        cout << "2. Add city record at the head\n";
        cout << "3. Display the city with largest population\n";
        cout << "4. Display all the city records\n";
        cout << "5. Exit\n";
        int option;
        // Read the user input
        cin >> option;

        // If user enter 1 or 2, ask user to provide city name, population, and income
        if (option == 1 || option == 2) {
            string cityName;
            int population, medianIncome;
            cout << "Enter city name: ";
            cin >> cityName;
            cout << "Enter city population: ";
            cin >> population;
            cout << "Enter median household income: ";
            cin >> medianIncome;

            if (option == 1) {
                cities.addToEnd(cityName, population, medianIncome);
            } else {
                cities.addToFront(cityName, population, medianIncome);
            }
        // Print the city with largest population if user enter 3
        } else if (option == 3) {
            cities.largestPopulation();
        // Print city list if user enter 4
        } else if (option == 4) {
            cities.allCities();
        // Stop the program if user enter 5
        } else if (option == 5) {
            stopProgram = true;
            break;
        // Print invalid if user enter invalid number
        } else {
            cout << "Invalid! Please re-enter\n";
        }
    }

    return 0; // Exit the program
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

class Card {
    private:
    string color;
    string value;

    public:
        Card(string color, string value) {
            this->color = color;
            this->value = value;
        }

    string getColor() {
        return color;
    }

    string getValue() {
        return value;
    }

    void display() {
        cout << color << " " << value;
    }
};


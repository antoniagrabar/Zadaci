#include <bits/stdc++.h>
#include <iostream>

int check(int &num){
    while (num < 0 || std::cin.fail()){
        std::cout << "Invalid input. Please provide a new input: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> num;
    }
    return num;
}

int main(){

    int n, tram = 0, capacity = 0;

    std::cout << "The number of tram stops: ";
    std::cin >> n;
    check(n);

    for (int i = 0; i < n; i++){
        int a, b;
        std::cout << "People exiting at the " << i + 1 << ".stop: ";
        std::cin >> a;
        check(a);

        if (i == 0){
            while (a != 0){
                std::cout << "The number of people exiting the tram should be 0. Please provide a new input: ";
                std::cin >> a;
            }
        }

        while (a > tram){
            std::cout << "The number of passengers exiting is too high. Please provide a new input: ";
            std::cin >> a;
        }

        std::cout << "People entering at the " << i + 1 << ".stop: ";
        std::cin >> b;
        check(b);

        if (i == n - 1){
            while (b != 0){
                std::cout << "The number of people entering the tram should be 0. Please provide a new input: ";
                std::cin >> b;
            }
        }

        tram -= a;
        tram += b;

        capacity = (tram > capacity) ? tram : capacity;
    }

    std::cout << "The minimal tram capacity is: " << capacity;

    return 0;
}

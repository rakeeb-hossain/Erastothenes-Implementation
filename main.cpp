//
//  main.cpp
//  Q10
//
//  Created by Rakeeb on 2019-04-08.
//  Copyright © 2019 Rakeeb. All rights reserved.
//

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

//173 millisecond execution time
int main(int argc, const char * argv[]) {
    //Sieve method for prime numbers
    auto start = std::chrono::high_resolution_clock::now();
    int i = 2;
    long int sum = 0;
    vector<int> sieve;
    while (i < 2000000) {
        sieve.push_back(i);
        i++;
    }
    for (int j = 0; j < sieve.size(); j++) {
        if (sieve[j] != 0) {
            int p = sieve[j];
            sum += static_cast<long int>(p);
            for (int k = p - 2; k < sieve.size(); k += p) {
                sieve[k] = 0;
            }
        }
    }
    cout << sum << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << duration.count() << endl;
    return 1;
}


//259 millisecond execution time
/*
bool is_prime(int n) {
    if (n % 2 == 0) {return false;};
    if (n % 3 == 0) {return false;};
    
    int i = 5;
    int w = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            return false;
        }
        i += w;
        w = 6 - w;
    }
    return true;
}

int main(int argc, const char * argv[]) {
     auto start = std::chrono::high_resolution_clock::now();
    int i = 5;
    int w = 2;
    long int sum = 5;
    
    while (i < 2000000) {
        if (is_prime(i)) {
            sum += static_cast<long int>(i);
        }
        i += w;
        w = 6 - w;
    }
    
    std::cout << sum << std::endl;
     auto stop = std::chrono::high_resolution_clock::now();
     auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
     cout << duration.count() << endl;
    return 0;
}
*/



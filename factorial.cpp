#include <iostream>
#include "bigInteger.h"

using namespace std;

//  Uses BigInteger to calculate the factorial accurately
//
//  @param n: the number of which factorial is calculated
//  @return: string form of the number

string factorial(unsigned int);

int main(int argc, char * argv[]) {
    unsigned int n;

    if(argc == 1) {
        cout << "\nEnter a number to calculate it's factorial: ";
        cin >> n;
        cout << '\n' << n << "! = " << factorial(n) << endl;
    } else {
        for(int i = 1; i < argc; i++) {
            n = stoi(argv[i]);
            cout << '\n' << n << "! = " << factorial(n) << endl;
        }
    }

    return 0;
}

string factorial(unsigned int n) {
    BigInteger num = BigInteger("1");

    for(unsigned int i = 1; i <= n; i++)
        num *= i;

    return num.toString();
}


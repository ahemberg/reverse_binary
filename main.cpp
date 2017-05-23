#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

unsigned int num_bits(unsigned int integer) {
    unsigned int bit = 0;
    while (pow(2,bit) <= integer) {
        bit++;
    }
    return bit;
}

vector<int> int_to_bin(unsigned int integer, unsigned int num_bits) {
    vector<int> bin(num_bits);
    for (int n = num_bits-1; n>=0; n--) {
        if (pow(2,n) <= integer) {
            integer -= pow(2,n);
            bin[n] = 1;
        } else {
            bin[n] = 0;
        }
    }
    return bin;
}

unsigned int bin_to_int(vector<int> bin_rep) {
    unsigned int num_bits = bin_rep.size();
    unsigned int intval = 0;

    for (int i = num_bits-1; i >= 0; i--) {
        if (bin_rep[i] == 1) {
            intval += pow(2,i);
        }
    }
    return intval;
}

int main() {
    unsigned int input, bits, reversed_int;

    cin >> input;
    bits = num_bits(input);
    vector<int> binary = int_to_bin(input, bits);
    reverse(begin(binary), end(binary));
    reversed_int = bin_to_int(binary);

    cout << endl << "Binary representation:" << endl;

    for (vector<int>::iterator it = binary.begin(); it!=binary.end(); it++) {
       cout << *it;
    }
    cout << endl << "Reverse binary representation:" << endl;

    for (vector<int>::reverse_iterator it = binary.rbegin(); it!=binary.rend(); it++) {
        cout << *it;
    }
    cout << endl << "Reverse int: " << reversed_int << endl;

    return 0;
}
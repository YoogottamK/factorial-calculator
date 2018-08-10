#pragma once

#include "doublyLinkedList.h"

class BigInteger : public DoublyLinkedList {

    public:

        BigInteger(string s) {
            unsigned int n = s.length();
            const char * arr = s.c_str();
            for(unsigned int i = 0; i < n; i++)
                insertAtRear((int) (arr[i] - '0'));
        }

        //  Multiplies each digit in the list with 'n'
        //
        //  @param n: digit to multiply

        void operator *= (int n) {
            dLL * tmp = rear;

            while(n % 10 == 0) {
                insertAtRear(0);
                n /= 10;
            }

            unsigned int carry = 0;
            while(tmp != front) {
                tmp->n *= n;
                tmp->n += carry;

                carry = tmp->n / 10;
                tmp->n %= 10;

                tmp = tmp->prev;
            }

            front->n *= n;
            front->n += carry;
            while(front->n > 9) {
                carry = front->n / 10;
                front-> n %= 10;
                if(carry)
                    insertAtFront(carry);
            }
        }
};

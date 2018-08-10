#pragma once

#include<iostream>

using namespace std;

class DoublyLinkedList {

    protected:

        struct dLL {
            unsigned long n;
            dLL * prev, * next;
        };

        dLL * front, * rear;

    public:

        DoublyLinkedList() {
            front = rear = NULL;
        }

        //  Inserts a new node into the list at the front
        //
        //  @param n: Value held by the node
        //  @return: Total number of nodes after insertion

        int insertAtFront(int n) {
            int c = 0;

            dLL * node = new dLL;
            node->n = n;
            node->prev = NULL;

            if(front == NULL) {
                front = rear = node;
                rear->next = NULL;
            } else {
                front->prev = node;
                node->next = front;
                front = node;
            }

            dLL * tmp = rear;

            while(tmp != front) {
                c++;
                tmp = tmp->prev;
            }

            return ++c;
        }

        //  Inserts a new node into the list at the end
        //
        //  @param n: Value held by the node
        //  @return: Total number of nodes after insertion

        int insertAtRear(int n) {
            int c = 0;

            dLL * node = new dLL;
            node->n = n;
            node->next = NULL;

            if(front == NULL) {
                front = rear = node;
                front->prev = NULL;
            } else {
                rear->next = node;
                node->prev = rear;
                rear = node;
            }

            dLL * tmp = rear;

            while(tmp != front) {
                c++;
                tmp = tmp->prev;
            }

            return ++c;
        }

        //  Prints the whole list, front to rear

        void print() {
            cout << "\nThe list: ";
            dLL * tmp = front;

            while(tmp != rear) {
                cout << tmp->n << " <=> ";
                tmp = tmp->next;
            }

            cout << tmp->n << " ->!";
        }

        //  @return: string with all data from left to right, i.e. front to rear

        string toString() {
            string ret = "";

            dLL * tmp = front;

            while(tmp != rear) {
                ret = ret + to_string(tmp->n);
                tmp = tmp->next;
            }

            ret = ret + to_string(tmp->n);

            return ret;
        }

        ~DoublyLinkedList() {
            dLL * tmp = rear;
            while(tmp != front) {
                rear = rear->prev;
                delete tmp;
                tmp = rear;
            }

            delete front;
        }
};


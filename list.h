#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

        void print_reverse(Node<T>* head);

    public:
        List()
        {
            head = NULL;
            tail = NULL;
            nodes = 0;
        }

        T front()
        {
            return head->data;
        }

        T back()
        {
            return tail->data;
        }

        void push_front(T value)
        {
            if (head == NULL)
            {
                head = new Node<T>;
                head->data = value;
                head->next = NULL;
                tail = head;
                nodes++;
                return;
            }

            Node<T> *temp = new Node<T>;
            temp->data = value;
            temp->next = head;
            head = temp;
            nodes++;
            return;
        
        }

        void push_back(T value)
        {
            if (head == NULL)
            {
                head = new Node<T>;
                head->data = value;
                head->next = NULL;
                tail = head;
                nodes++;
                return;
            }

            Node<T> *temp = new Node<t>;
            temp->data = value;
            temp->next = NULL;
            tail->next = temp;
            tail = tail->next;
            nodes++;
            return
        }

        void pop_front()
        {
            if (head ==NULL)
            {

            }
        }
        
        void pop_back()
        {

        }

        T get(int position)
        {
            if (position >= nodes)
            {
                throw out_of_range("Position requested bigger than array size!")
            }

            int index = 0;
            Node<T> *temp = head;
            while (temp != NULL)
            {
                if(index == position)
                {
                    return temp->data;
                }
                temp = temp->next;
                index++;
            } 
        }

        void concat(List<T> &other)
        {
            tail->next = other->head;
            return;
        }
        
        bool empty()
        {
            return head == NULL;
        }

        int size();
        {
            return nodes;
        }

        void print()
        {
            Node<T> *temp = head;
            while (temp != NULL)
            {
                cout << temp->data <<" ";
                temp = temp->next; 
            }
            return;
        }

        void print_reverse();
        void clear();
        Iterator<T> begin();
        Iterator<T> end();

        ~List();
};
#endif

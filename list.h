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
            if (head == NULL)
            {
                throw "Empty list";
                return;
            }

            Node<T> *temp = head;
            head = head->next;
            delete temp;
            nodes--;
        }
        
        void pop_back()
        {
            if (head == NULL)
            {
                throw "Empty list";
                return;
            }

            Node<T> *tail_copy = tail;

            if (head->next == NULL)
            {
                head = NULL;
                tail = NULL;
                delete tail_copy;
                nodes--;
                return;
            }

            Node<T> *temp = head;

            for (int i = 0; i < nodes; i++)
            {
                if(temp->next == tail)
                {
                    tail = temp;
                    continue; 
                }
                temp = temp->next;
            }
            delete tail_copy;
            nodes--;
            tail->next = NULL;

        }

        T get(int position)
        {
            if (position >= nodes || position < 0)
            {
                throw out_of_range("Request is out of range!");
                return;
            }

            Node<T> *temp = head;
            for (int i = 0; i < nodes; i++)
            {
                if(i == position)
                {
                    return temp->data;
                }
                temp = temp->next;   
            } 
        }

        void concat(List<T> &other)
        {
            tail->next = other->head;
            nodes += other->nodes;
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

        void print_reverse()
        {
            if(head != NULL)
                head->printReverse();
        }
        
        void clear()
        {
            if(head != NULL)
                head->killSelf();
        }

        Iterator<T> begin();
        Iterator<T> end();

        ~List();
};
#endif

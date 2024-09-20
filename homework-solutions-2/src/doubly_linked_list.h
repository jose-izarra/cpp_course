#pragma once
#include<iostream>
#include<string>
// dbl for doubly linked list
namespace dbl {
    class Node {
        public:
            std::string val;
            Node* next;
            Node* prev;
            Node(std::string value) {
                val = value;
                next = nullptr;
                prev = nullptr;
            }
    };


    Node* create_node(std::string value)
    {
        return new Node(value);
    }

    Node* insert(Node* node, Node* new_node)
    {
        if (node == nullptr && new_node == nullptr) {
            return nullptr;
        }

        if (node == nullptr) {
            return new_node;
        }
        if (new_node == nullptr) {
            return node;
        }


        new_node->next = node;
        node->prev = new_node;
        return new_node;
    }

    Node* erase(Node* node)
    {
        if (node == nullptr) {
            return nullptr;
        }

        Node* next_node = node->next;
        if (next_node != nullptr) {
            next_node->prev = nullptr;
        }
        delete node;
        return next_node;
    }

    Node* add(Node* p, Node* n)
    {
        if (n == nullptr) {
            return nullptr;
        }


        if (p == nullptr) {
            // If the given node is null, new_node becomes the first and only node
            n->next = nullptr;
            n->prev = nullptr;
            return n;
        }

        n->next = p->next;
        n->prev = p;
        // if p is not the last node
        if (p->next != nullptr) {
            p->next->prev = n;
        }

        p->next = n;
        return n;
    }
}

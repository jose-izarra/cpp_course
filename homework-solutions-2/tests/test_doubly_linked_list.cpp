#include "doubly_linked_list.h"
#include "gtest/gtest.h"

using namespace dbl;


TEST(InsertTest, StringTest) {
    Node* node = create_node("Apple");
    node = insert(node, create_node("Banana"));
    node = insert(node, create_node("Cherry"));

    Node* current = node;
    EXPECT_EQ(current->val, "Cherry");
    EXPECT_EQ(current->next->val, "Banana");
    EXPECT_EQ(current->prev, nullptr);

    current = current->next;
    EXPECT_EQ(current->next->val, "Apple");
    EXPECT_EQ(current->prev->val, "Cherry");

    current = current->next;
    EXPECT_EQ(current->prev->val, "Banana");
    EXPECT_EQ(current->next, nullptr);

    while(node != nullptr) {
        Node* temp = node;
        node = node->next;
        delete temp;
    }
}

TEST(EraseTest, StringTest) {
    Node* node = create_node("Apple");
    node = insert(node, create_node("Banana"));
    node = insert(node, create_node("Cherry"));

    node = erase(node); // Erase "Cherry"
    EXPECT_EQ(node->val, "Banana");
    EXPECT_EQ(node->prev, nullptr);

    node = erase(node); // Erase "Banana"
    EXPECT_EQ(node->val, "Apple");
    EXPECT_EQ(node->prev, nullptr);

    node = erase(node); // Erase "Apple"
    EXPECT_EQ(node, nullptr);

}


TEST(AddTest, StringTest) {
    Node* head = create_node("Apple");
    head = insert(head, create_node("Banana"));

    Node* temp = add(head, create_node("Cherry"));

    // * Banana -> Cherry -> Apple

    EXPECT_EQ(head->val, "Banana");
    EXPECT_EQ(head->next->val, "Cherry");
    EXPECT_EQ(head->next->next->val, "Apple");
    EXPECT_EQ(head->prev, nullptr);

    temp = head; // temp->val = "Banana"

    head = insert(head, create_node("Orange"));
    // * Orange -> Banana -> Cherry -> Apple

    temp = add(temp, create_node("Kiwi")); // adding next to Cherry
    // * Orange -> Banana -> Kiwi -> Cherry -> Apple

    EXPECT_EQ(head->val, "Orange");
    EXPECT_EQ(head->next->val, "Banana");
    EXPECT_EQ(head->next->next->val, "Kiwi");
    EXPECT_EQ(head->prev, nullptr);

    EXPECT_EQ(temp->val, "Kiwi");
    EXPECT_EQ(temp->next->val, "Cherry");
    EXPECT_EQ(temp->prev->val, "Banana");

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

}

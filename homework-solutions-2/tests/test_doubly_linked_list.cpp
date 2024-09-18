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
    Node* node = create_node("Apple");
    node = insert(node, create_node("Banana"));
    node = insert(node, create_node("Cherry"));

    Node* new_node = create_node("Date");
    node = add(node->next, new_node); // Add "Date" after "Banana"

    Node* current = node;
    EXPECT_EQ(current->val, "Cherry");
    current = current->next;
    EXPECT_EQ(current->val, "Date");
    EXPECT_EQ(current->next->val, "Apple");
    EXPECT_EQ(current->prev->val, "Banana");

    while(node != nullptr) {
        Node* temp = node;
        node = node->next;
        delete temp;
    }
}

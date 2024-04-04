#include <iostream>

struct Computer {
    int id;
    int ram;
    int storage;
    int processorSpeed;
    int screenSize;
    Computer* next;
    Computer* prev;
};

void AddFirst(Computer*& head, int id, int ram, int storage, int processorSpeed, int screenSize) {
    Computer* newComputer = new Computer;
    newComputer->id = id;
    newComputer->ram = ram;
    newComputer->storage = storage;
    newComputer->processorSpeed = processorSpeed;
    newComputer->screenSize = screenSize;
    newComputer->next = head;
    newComputer->prev = NULL;

    if (head != NULL) {
        head->prev = newComputer;
    }
    head = newComputer;
}

void AddLast(Computer*& head, int id, int ram, int storage, int processorSpeed, int screenSize) {
    if (head == NULL) {
        AddFirst(head, id, ram, storage, processorSpeed, screenSize);
        return;
    }
    Computer* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    Computer* newComputer = new Computer;
    newComputer->id = id;
    newComputer->ram = ram;
    newComputer->storage = storage;
    newComputer->processorSpeed = processorSpeed;
    newComputer->screenSize = screenSize;
    newComputer->next = NULL;
    newComputer->prev = curr;
    curr->next = newComputer;
}

void AddAfter(Computer*& head, int targetId, int id, int ram, int storage, int processorSpeed, int screenSize) {
    if (head == NULL) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Computer* curr = head;
    while (curr != NULL && curr->id != targetId) {
        curr = curr->next;
    }
    if (curr != NULL && curr->id == targetId) {
        Computer* newComputer = new Computer;
        newComputer->id = id;
        newComputer->ram = ram;
        newComputer->storage = storage;
        newComputer->processorSpeed = processorSpeed;
        newComputer->screenSize = screenSize;
        newComputer->next = curr->next;
        newComputer->prev = curr;
        if (curr->next != NULL) {
            curr->next->prev = newComputer;
        }
        curr->next = newComputer;
    }
}

void AddBefore(Computer*& head, int targetId, int id, int ram, int storage, int processorSpeed, int screenSize) {
    if (head == NULL) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Computer* curr = head;
    while (curr != NULL && curr->id != targetId) {
        curr = curr->next;
    }
    if (curr != NULL && curr->prev != NULL && curr->id == targetId) {
        Computer* newComputer = new Computer;
        newComputer->id = id;
        newComputer->ram = ram;
        newComputer->storage = storage;
        newComputer->processorSpeed = processorSpeed;
        newComputer->screenSize = screenSize;
        newComputer->next = curr;
        newComputer->prev = curr->prev;
        curr->prev->next = newComputer;
        curr->prev = newComputer;
    }
}

void PrintList(Computer* head) {
    if (head == NULL) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Computer* curr = head;
    while (curr != NULL) {
        std::cout << "ID: " << curr->id << ", RAM: " << curr->ram << ", Storage: " << curr->storage << ", Processor Speed: " << curr->processorSpeed << ", Screen Size: " << curr->screenSize << std::endl;
        curr = curr->next;
    }
}

void Swap(Computer*& head, int id1, int id2) {
    if (head == NULL)
        std::cout << "The list is empty" << std::endl;
    Computer* curr = head;
    while (curr->next != NULL && curr->id != id1) {
        curr = curr->next;
    }
    if (curr->next == NULL && curr->id != id1) {
        std::cout << "Element not found in list" << std::endl;
        return;
    }
    Computer* node1 = curr;
    curr = head;
    while (curr->next != NULL && curr->id != id2) {
        curr = curr->next;
    }
    if (curr->next == NULL && curr->id != id2) {
        std::cout << "Element not found in list" << std::endl;
        return;
    }
    Computer* node2 = curr;
    Computer* next1 = node1->next;
    Computer* prev1 = node1->prev;
    Computer* next2 = node2->next;
    Computer* prev2 = node2->prev;

    if (node1->next == node2) {
        node1->next = next2;
        node1->prev = node2;
        node2->prev = prev1;
        node2->next = node1;

        if (node1->next != NULL)
            next2->prev = node1;
        if (node2->prev != NULL)
            prev1->next = node2;

    } else if (node2->next == node1) {
        node1->next = node2;
        node1->prev = prev2;
        node2->next = next1;
        node2->prev = node1;

        if (node2->next != NULL)
            next1->prev = node2;
        if (node1->prev != NULL)
            prev2->next = node1;

    } else {
        node1->prev = prev2;
        node1->next = next2;
        node2->prev = prev1;
        node2->next = next1;

        if (prev1 != NULL) {
            prev1->next = node2;
        }
        if (next1 != NULL) {
            next1->prev = node2;
        }
        if (prev2 != NULL) {
            prev2->next = node1;
        }
        if (next2 != NULL) {
            next2->prev = node1;
        }
    }

    if (node1->prev == NULL) {
        head = node1;
    }
    if (node2->prev == NULL) {
        head = node2;
    }
}

void DeleteElement(Computer*& head, int targetId){
    if(head == NULL){
        std::cout << "List is empty";
        return;
    }
 
    if(head->next == NULL && head->id != targetId){
        std::cout << "Element not found";
        return;
    }
 
    Computer* curr = head->next;
    Computer* prev = head;
 
    while (curr != NULL && curr->id != targetId){
        prev = curr;
        curr = curr->next;
    }
 
    if (curr != NULL && curr->id == targetId){
        prev->next = curr->next;
        if (curr->next != NULL){
            curr->next->prev = prev;
        }
        delete curr;
    } else {
        std::cout << "Element not found";
    }
}

int main() {
    Computer* head = NULL;
    int id1 = 1;
    int ram1 = 8;
    int storage1 = 256;
    int processorSpeed1 = 2; 
    int screenSize1 = 15;
 
    int id2 = 2;
    int ram2 = 16;
    int storage2 = 512;
    int processorSpeed2 = 3; 
    int screenSize2 = 13;
 
    int id3 = 3;
    int ram3 = 32;
    int storage3 = 1024;
    int processorSpeed3 = 3; 
    int screenSize3 = 14;
    
    int id4 = 4;
    int ram4 = 32;
    int storage4 = 512;
    int processorSpeed4 = 2; 
    int screenSize4 = 13;
    
    
    AddLast(head, id1, ram1, storage1, processorSpeed1, screenSize1);
    PrintList(head);
    std::cout << "=========================================" << std::endl;

    AddAfter(head, id1, id2, ram2, storage2, processorSpeed2, screenSize2);
    PrintList(head);
    std::cout << "=========================================" << std::endl;
    
    AddBefore(head, id2, id3, ram3, storage3, processorSpeed3, screenSize3);
    PrintList(head);
    std::cout << "=========================================" << std::endl;
    
    AddFirst(head, id4, ram4, storage4, processorSpeed4, screenSize4);
    PrintList(head);
    std::cout << "=========================================" << std::endl;
    
    Swap(head, id1, id3);
    Swap(head, id2, id4);
    PrintList(head);
    
    return 0;
}

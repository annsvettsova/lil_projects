#include <iostream>

struct Computer {
    int id;
    int ram;
    int storage;
    int processorSpeed;
    int screenSize;
    Computer* next;
};

void AddLast(Computer** head, int id, int ram, int storage, int processorSpeed, int screenSize) {
    Computer* newComputer = new Computer;
    newComputer->id = id;
    newComputer->ram = ram;
    newComputer->storage = storage;
    newComputer->processorSpeed = processorSpeed;
    newComputer->screenSize = screenSize;
    newComputer->next = NULL;

    if (*head == NULL) {
        *head = newComputer;
    } else {
        Computer* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newComputer;
    }
}

void AddFirst(Computer** head, int id, int ram, int storage, int processorSpeed, int screenSize) {
    Computer* newComputer = new Computer;
    newComputer->id = id;
    newComputer->ram = ram;
    newComputer->storage = storage;
    newComputer->processorSpeed = processorSpeed;
    newComputer->screenSize = screenSize;
    newComputer->next = *head;
    *head = newComputer;
}

void AddAfter(Computer* head, int targetId, int id, int ram, int storage, int processorSpeed, int screenSize) {
    Computer* curr = head;
    while (curr != NULL && curr->id != targetId) {
        curr = curr->next;
    }

    if (curr != NULL) {
        Computer* newComputer = new Computer;
        newComputer->id = id;
        newComputer->ram = ram;
        newComputer->storage = storage;
        newComputer->processorSpeed = processorSpeed;
        newComputer->screenSize = screenSize;
        newComputer->next = curr->next;
        curr->next = newComputer;
    }
}

void AddBefore(Computer** head, int targetId, int id, int ram, int storage, int processorSpeed, int screenSize) {
    if (*head == NULL) {
        std::cout << "List is empty";
        return;
    }

    Computer* curr = *head;
    Computer* prev = NULL;

    while (curr != NULL && curr->id != targetId) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        Computer* newComputer = new Computer;
        newComputer->id = id;
        newComputer->ram = ram;
        newComputer->storage = storage;
        newComputer->processorSpeed = processorSpeed;
        newComputer->screenSize = screenSize;
        newComputer->next = curr;

        if (prev != NULL) {
            prev->next = newComputer;
        } else {
            *head = newComputer;
        }
    }
}

void PrintList(Computer* head) {
    if (head == NULL) {
        std::cout << "List is empty";
        return;
    }

    Computer* curr = head;
    while (curr != NULL) {
        std::cout << "ID: " << curr->id << ", RAM: " << curr->ram << ", Storage: " << curr->storage << ", Processor Speed: " << curr->processorSpeed << ", Screen Size: " << curr->screenSize << std::endl;
        curr = curr->next;
    }
}

void DeleteElement(Computer *head, int targetId){
    if(head == NULL){
        std::cout << "this list is empty" << std::endl;
        return;
    }
    while(head->next != NULL && head->next->id != targetId){
        head = head->next;
    }
    if(head->next == NULL && head->next->id != targetId){
        std::cout << "no element in list\n";
        return;
    }
    Computer* tmp = head->next->next;
    delete head->next;
    head->next = tmp;
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
    
    AddLast(&head, id1, ram1, storage1, processorSpeed1, screenSize1);
    PrintList(head);
    std::cout << "=========================================" << std::endl;
    AddFirst(&head, id2, ram2, storage2, processorSpeed2, screenSize2);
    PrintList(head);
    std::cout << "=========================================" << std::endl;
    
    AddBefore(&head, id2, id3, ram3, storage3, processorSpeed3, screenSize3);
    PrintList(head);
    std::cout << "=========================================" << std::endl;
    
    AddAfter(head, id1, id2, ram2, storage2, processorSpeed2, screenSize2);
    PrintList(head);
    std::cout << "=========================================" << std::endl;
    
    DeleteElement(head, id1);
    PrintList(head);
    return 0;
}

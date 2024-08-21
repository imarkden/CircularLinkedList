#ifndef Soldiers_hpp
#define Soldiers_hpp

#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

class Soldiers {
private:
    Node* head;
    int size;

public:
    Soldiers();
    
    void AddSoldier(const string& name);
    void PrintSoldiers() const;
    void RemoveSoldier(int count);
    void EliminateSoldier(int round);

    int GetSize() const;
    string GetHeadName() const;
};

#endif /* Soldiers_hpp */

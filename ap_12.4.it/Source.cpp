#include <iostream>
#include <cstdlib>
using namespace std;

typedef int Info;

struct Elem
{
    Elem* link;
    Info info;
};

void insert(Elem*& L, Info value)
{
    Elem* tmp = new Elem; 
    tmp->info = value;  
    if (L != nullptr)
    {
        Elem* T = L;
        while (T->link != L)
            T = T->link; 
        T->link = tmp; 
    }
    else
    {
        L = tmp; 
    }
    tmp->link = L; 
}

void swapAdjacentElements(Elem*& L)
{
    if (L == nullptr || L->link == L)
        return; 

    Elem* current = L;
    do {
        Info temp = current->info;
        current->info = current->link->info;
        current->link->info = temp;
        current = current->link->link;
    } while (current != L);
}

void display(Elem* L)
{
    if (L == nullptr) 
    {
        cout << "List is empty" << endl;
        return;
    }

    Elem* tmp = L;
    do
    {
        cout << tmp->info << " ";
        tmp = tmp->link;
    } while (tmp != L);
    cout << endl;
}

int main()
{
    Elem* L = nullptr;

    for (int i = 1; i <= 10; i++) {
        insert(L, i);
    }

    cout << "List: ";
    display(L);

    swapAdjacentElements(L);
    cout << "Ater swap: ";
    display(L);

    return 0;
}

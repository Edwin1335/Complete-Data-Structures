#include "Stack.h"

int main()
{
    Stack<std::string> family;
    family.push_back("Ninfa");
    family.push_back("EDwin");
    family.push_back("Kata");
    family.push_back("Gordo");
    family.push_back("Maribey");

    family.print();
    std::cout << "\nDeleting multiple\n"
              << std::endl;
    family.del_mult(10);
    family.print();
    std::cout << "\nInserting multiple\n"
              << std::endl;
    family.ins_mult();
    family.print();

    return 0;
}
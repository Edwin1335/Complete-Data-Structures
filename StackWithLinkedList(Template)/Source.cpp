#include "Stack.h"

int main()
{

    Stack <std::string> family;
    family.push_back("Ninfa");
    family.push_back("EDwin");
    family.push_back("Kata");
    family.push_back("Gordo");
    family.push_back("Maribey");

    family.print();
    family.print_reverse();

    family.ins_mult();

	return 0;
}

#include <iostream>


template<typename T>
void printMe(T value) // ten szablon sluzy zatrzymaniu rozwijania parameter pack
{
    std::cout << value << std::endl;
   
}

template<typename T, typename ... Args>//deklaracja szablonu ktory moze przyjac 1 + 0+ argumentów
void printMe(T first, Args...args) //T first oznacza pierwszy, kt musi byc znany typ, args dowolan iloœæ i typ
{
    std::cout << first << ", " ;//wypisujemy zmienna first, która jest znanego typu T
    printMe(args...); //nastepnie rozwijamy ten pack poprzez rekurencyjne wywolanie tego szablonu
}
int main()
{
    int a = 23;
    float d = 2.13;
    bool b = true;
    std::string s = "Kotek";
    printMe(a,d,b,s,"cos wiecej");
    printMe("inne wywolanie", b, d, 1234);
    

    
   
    
}
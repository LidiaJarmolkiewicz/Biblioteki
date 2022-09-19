#include <iostream>
class A
{
public:
    A(std::string str) :value(str) {};
    A( A&& other) noexcept//konstr przeno0szacy-move assigment
    {
        std::cout << " A( A&& other)" << std::endl;
        value = std::move(other.value);
    }
    A(const A& other):A(other.value)//konst kopiujacy - copy assigment
    {
        std::cout << " A( const A& other)" << std::endl;
    }
    A& operator=(const A& other)//kopiujacy operator przypisania
    {
        std::cout << " operator =(const A& other)" << std::endl;
        return *this = A(other.value);
    }
    A& operator=(A&& other) noexcept//przenosz¹cy operator przypisania
    {
        std::cout << " operator =( A&& other)" << std::endl;
        this->value = std::move(other.value);
        return *this;
    }
    virtual ~ A()=default;
    A& getMe()
    {
        return *this;
    }
    std::string getValue()const
    {
        return value;
    }
private:
    std::string value;
};

A getA1()
{
    return A(" create A1");//zwracana wartosc tymczasowa
}

A getA2()
{
    A a("create A2");
    return a;
}
void swapOld(int& a, int& b)//a-1 szt, b-1 szt ///kazde wywolanie =wywolanie copy asigment operator
{
    int temp(a); // 2 kopie( czyli oryginalny a i kopia tmp) bo wolamy konstruktor kopiujacy//a,tmp-2, b-1
    a = b;// kopiowanie 2 kopie b / /tmp-1, a,b-2
    b = temp;// kopiowanie 2 kopie tmp//b,tmp-2
}
void swapMove(int& a, int& b)
{
    int tmp(std::move(a));//jawnie ¿adamy zamiany obiektu a na rvalue reference..nie robimy kopii-nie wolno odwolywac do zawartosci a
    a = std::move(b); //jawnie ¿adamy zamiany b na rvalue( przeniesienie na a) teraz b nie dotykamy
    b = std::move(tmp);
}

void swap(A& a, A& b)//swap dla klasy A
{
    A tmp(std::move(a));
    a = std::move(b); 
    b = std::move(tmp);

}
template<typename T>
void swapmoveT(T& a, T& b)//swap dla szablonu
{
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}
template<typename T>
void swapCopyT(T& a, T& b)//swap dla szablonu
{
    T tmp(a);
    a = b;
    b = tmp;
}
int main()
{
    A a("variable");
    
    A a1 = getA1(); //tutaj jest tworzona kopia

    A& a_ref1 = a;
  // A& a_ref3=A() - konstruktor A - zwyk³a referencja nie moze wskazywac na ob tymczasowy
   // A& a_ref5 = getA1();
   // A& a_ref7 = getA2();
     A& a_ref9 = a.getMe();
   // 
    //A&& a_ref2 = a;  referencja nie moze wskazywac na zmienne
    A&& a_ref4 = A("temporary");
    A&& a_ref6 = getA1();//unikamy kopiowania -zwracana wartosc tynczasowa
    A&& a_ref8 = getA2();
   //A&& a_ref10 = a.getMe();

    int var1 = 15;
    int var2 = 9;



    std::cout << "var1= " << var1 << " var2= " << var2 << std::endl;
    swapMove(var1, var2);
    std::cout << "var1= " << var1 << " ar2= " << var2 << std::endl;

    std::string someString("some string");
    std::string other(someString);
    std::cout << "Copy:(" << someString << " , " << other <<")"<< std::endl;
    std::string moved(std::move(someString));
    std::cout << "Copy:(" << someString << " , " << other << ")" << std::endl;
    std::cout << "Move:(" << someString << " , " << moved << ")" << std::endl;

    A a11("A11");
    A a22("A22");
    std::cout << a11.getValue() << " ; " << a22.getValue() << std::endl;
    swap(a11, a22);
    std::cout << a11.getValue() << " ; " << a22.getValue() << std::endl;
    std::cout << std::endl;

    A first("first");
    A second("second");
    std::cout << first.getValue() << " ; " << second.getValue() << std::endl;
    swapmoveT(first, second);
    std::cout << first.getValue() << " ; " << second.getValue() << std::endl;
    swapCopyT(first, second);
    std::cout << first.getValue() << " ; " << second.getValue() << std::endl;
}

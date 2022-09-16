#include <iostream>
class Fish
{
private:
    std::string _name={};
    std::string _colour={};
    int _age=0;
public:
    Fish(std::string name, std::string colour, int age) : _name(name), _colour(colour), _age(age) {};
    Fish(std::string name) :Fish(name, {}, 2) {};
    Fish() :Fish( {}, {}, 0) {};

    std::string getName()
    {
        return _name;
    }
    std::string getColour()
    {
        return _colour;
    }
    int getAge()
    {
        return _age;
    }

};

int main()
{
    Fish fish("Kate","yellow",1);
    std::cout << fish.getName() << " " << fish.getColour() << " " << fish.getAge() << std::endl;

    Fish goldFish("Jane");
    std::cout << goldFish.getName() << " " << goldFish.getColour() << " " << goldFish.getAge();
}

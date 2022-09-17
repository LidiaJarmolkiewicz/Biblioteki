#include <iostream>
class Fish
{
private:
    std::string _name={};
    std::string _colour={};
    int _age=0;
public:
    Fish(std::string name, std::string colour, int age) : _name(name), _colour(colour), _age(age) {};
    Fish(std::string name) :Fish(name, {}, 0) {};
    Fish() :Fish( {}, {}, 0) {};
    Fish(int age) :Fish({}, {}, 0) {};

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
class GoldFish : public Fish
{
public:
    using Fish::Fish;
    void plynProsto()
    {
        std::cout << "plyn prosto" << std::endl;
    }

};
class SilverFish :public Fish
{
protected:
    double _tailLength;
public:
    SilverFish(std::string name, std::string colour, int age, double tailLength) : Fish(name, colour, age), _tailLength(tailLength) {};
    double getTailLength()
    {
        return _tailLength;
    }
};
int main()
{
    Fish fish("Kate","yellow",1);
    std::cout << fish.getName() << " " << fish.getColour() << " " << fish.getAge() << std::endl;

    Fish fish1("Jane");
    std::cout << fish1.getName() << " " << fish1.getColour() << " " << fish1.getAge() << std::endl;

    GoldFish fish3("Goldi","gold",3);
    fish3.plynProsto();
    std::cout  << fish3.getName() << " " << fish3.getColour() << " " << fish3.getAge() << std::endl;

    SilverFish fish4("Patty", "silver", 3, 12.6);
    std::cout << fish4.getName() << " " << fish4.getColour() << " " << fish4.getAge() << " " <<fish4.getTailLength()<<std::endl;
}

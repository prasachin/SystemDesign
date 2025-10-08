#include <bits/stdc++.h>
using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};

class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Hey your Basic burger is ready !" << endl;
    }
};

class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Hey Your standaed burger is ready !" << endl;
    }
};

class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Hey your premium burger is ready !" << endl;
    }
};

class BurgerFactory
{
public:
    Burger *createBurger(string type)
    {
        if (type == "basic")
        {
            return new BasicBurger();
        }
        else if (type == "standard")
        {
            return new StandardBurger();
        }
        else if (type == "premium")
        {
            return new PremiumBurger();
        }
        else
        {
            cout << "Invalid Burger Type" << endl;
            return nullptr;
        }
    }
};

int main()
{
    BurgerFactory *factory = new BurgerFactory();
    factory->createBurger("basic")->prepare();
    factory->createBurger("standard")->prepare();
    factory->createBurger("premium")->prepare();
    return 0;
}

// Now here what if we have different kinds of the factory and all of em used to make differebt types of the burgers.
// Here the Factory method pattern comes into the picture .
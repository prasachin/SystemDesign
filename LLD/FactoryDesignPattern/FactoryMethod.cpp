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

class BasicWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Hey your Basic burger with wheat is ready !" << endl;
    }
};

class StandardWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Hey Your standaed burger with wheat is ready !" << endl;
    }
};

class PremiumWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Hey your premium burger with wheat is ready !" << endl;
    }
};

class BurgerFactory
{
public:
    virtual Burger *createBurger(string type) = 0;
};

class WithoutWheatFactory : public BurgerFactory
{
public:
    Burger *createBurger(string type) override
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

class WithWheatFactory : public BurgerFactory
{
public:
    Burger *createBurger(string type) override
    {
        if (type == "basic")
        {
            return new BasicWheatBurger();
        }
        else if (type == "standard")
        {
            return new StandardWheatBurger();
        }
        else if (type == "premium")
        {
            return new PremiumWheatBurger();
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
    BurgerFactory *factory = new WithWheatFactory();
    BurgerFactory *factory2 = new WithoutWheatFactory();

    factory->createBurger("basic")->prepare();
    factory->createBurger("standard")->prepare();
    factory->createBurger("premium")->prepare();
    cout << endl;
    factory2->createBurger("basic")->prepare();
    factory2->createBurger("standard")->prepare();
    factory2->createBurger("premium")->prepare();
    return 0;
}
// Now what jab these factory listed above are not responsible to make just Burger thay expanded their business and now they want to make Garlllic Naan as well
// In such scenarios Bastract Factory mwthod pattern is used .
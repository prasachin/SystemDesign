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

class GarllicNaan
{
public:
    virtual void prepare() = 0;
    virtual ~GarllicNaan() = default;
};

class BasicGarllicNaan : public GarllicNaan
{
public:
    void prepare() override
    {
        cout << "Hey your Basic GarllicNaan is ready !" << endl;
    }
};

class StandardGarllicNaan : public GarllicNaan
{
public:
    void prepare() override
    {
        cout << "Hey Your standaed GarllicNaan is ready !" << endl;
    }
};

class PremiumBGarllicNaan : public GarllicNaan
{
public:
    void prepare() override
    {
        cout << "Hey your premium GarllicNaan is ready !" << endl;
    }
};

class BasicWheatGarllicNaan : public GarllicNaan
{
public:
    void prepare() override
    {
        cout << "Hey your Basic GarllicNaan with wheat is ready !" << endl;
    }
};

class StandardWheatGarllicNaan : public GarllicNaan
{
public:
    void prepare() override
    {
        cout << "Hey Your standaed GarllicNaan with wheat is ready !" << endl;
    }
};

class PremiumWheatGarllicNaan : public GarllicNaan
{
public:
    void prepare() override
    {
        cout << "Hey your premium GarllicNaan with wheat is ready !" << endl;
    }
};

class MealFactory
{
public:
    virtual Burger *createBurger(string type) = 0;
    virtual GarllicNaan *createGarllicNaan(string type) = 0;
};

class WithoutWheatFactory : public MealFactory
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

    GarllicNaan *createGarllicNaan(string type) override
    {
        if (type == "basic")
        {
            return new BasicGarllicNaan();
        }
        else if (type == "standard")
        {
            return new StandardGarllicNaan();
        }
        else if (type == "premium")
        {
            return new PremiumWheatGarllicNaan();
        }
        else
        {
            cout << "Invalid Garllic Naan type" << endl;
            return nullptr;
        }
    }
};

class WithWheatFactory : public MealFactory
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
    GarllicNaan *createGarllicNaan(string type) override
    {
        if (type == "basic")
        {
            return new BasicWheatGarllicNaan();
        }
        else if (type == "standard")
        {
            return new StandardWheatGarllicNaan();
        }
        else if (type == "premium")
        {
            return new PremiumWheatGarllicNaan();
        }
        else
        {
            cout << "Invalid Garllic Naan Type" << endl;
            return nullptr;
        }
    }
};

int main()
{
    MealFactory *factory = new WithWheatFactory();
    MealFactory *factory2 = new WithoutWheatFactory();

    factory->createBurger("basic")->prepare();
    factory->createBurger("standard")->prepare();
    factory->createBurger("premium")->prepare();
    cout << endl;
    factory2->createBurger("basic")->prepare();
    factory2->createBurger("standard")->prepare();
    factory2->createBurger("premium")->prepare();
    cout << endl;
    factory->createGarllicNaan("basic")->prepare();
    factory->createGarllicNaan("standard")->prepare();
    factory->createGarllicNaan("premium")->prepare();
    cout << endl;
    factory2->createGarllicNaan("basic")->prepare();
    factory2->createGarllicNaan("standard")->prepare();
    factory2->createGarllicNaan("premium")->prepare();
    return 0;
}
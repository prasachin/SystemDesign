#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
    string name;
    double price;

    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};
class AddtoCart
{
private:
    vector<Product *> products;

public:
    void addToCart(Product *p)
    {
        products.push_back(p);
    }
    vector<Product *> GetProducts()
    {
        return products;
    }
    double GetTotalCartPrice()
    {
        double total = 0.0;
        for (int i = 0; i < products.size(); i++)
        {
            total += products[i]->price;
        }
        return total;
    }
};

class PrintInvoice
{
private:
    AddtoCart *cart;

public:
    PrintInvoice(AddtoCart *c)
    {
        this->cart = c;
    }

    void Printinvoice()
    {
        cout << "Shopping CartInvoice :" << endl;
        vector<Product *> p = cart->GetProducts();
        for (int i = 0; i < p.size(); i++)
        {
            cout << p[i]->name << " $" << p[i]->price << endl;
        }
        cout << "Total $" << cart->GetTotalCartPrice() << endl;
    }
};

// Now here i want to save the data in different database like mongoDB, SQL, file etc. Here we are writhing all the methods in the same class which violates OCP rule of the solid design pattern.
class SaveToDB
{
private:
    AddtoCart *cart;

public:
    virtual void save(AddtoCart *cart) = 0;
};

class SavetoMongo : public SaveToDB
{
public:
    void save(AddtoCart *cart)
    {
        cout << "Your cart details savced succesfully in MongoDB" << endl;
    }
};

class SavetoSql : public SaveToDB
{
public:
    void save(AddtoCart *cart)
    {
        cout << "Your cart details savced succesfully in SQL" << endl;
    }
};

class SavetoFile : public SaveToDB
{
public:
    void save(AddtoCart *cart)
    {
        cout << "Your cart details savced succesfully in file as text " << endl;
    }
};

int main()
{
    AddtoCart *addtocart = new AddtoCart();
    addtocart->addToCart(new Product("Laptop", 500.0));
    addtocart->addToCart(new Product("Mobule phone", 200.5));
    SavetoMongo *savemongo = new SavetoMongo();
    savemongo->save(addtocart);
    SavetoSql *sql = new SavetoSql();
    sql->save(addtocart);
    SavetoFile *file = new SavetoFile();
    file->save(addtocart);
    return 0;
}
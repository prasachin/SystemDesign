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
// In this we can see, I have separated all the individual methods in their respective classes so if we need to change anything in them we can directly do in their class without messing with all the methods and all this is know as the single responsibility principle(SRP) design pattern.

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

class SaveToDB
{
private:
    AddtoCart *cart;

public:
    void SavetoDB()
    {
        cout << "Your cart details savced succesfully " << endl;
    }
};

int main()
{
    AddtoCart *addtocart = new AddtoCart();
    addtocart->addToCart(new Product("Laptop", 500.0));
    addtocart->addToCart(new Product("Mobule phone", 200.5));
    SaveToDB *save = new SaveToDB();
    save->SavetoDB();
    addtocart->GetProducts();
    addtocart->GetTotalCartPrice();
    PrintInvoice *printinvoice = new PrintInvoice(addtocart);
    printinvoice->Printinvoice();
    return 0;
}
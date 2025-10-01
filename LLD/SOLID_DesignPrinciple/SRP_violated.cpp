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
// Here we can see we are not following the SRP(Single Responsibility Principle ) i.e each class are not responsible for only one methods. when we req to make changes in the printinvoice function we need to change the AddtoCart class which is not good, it will become cumbersome when the application grows.
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

    void PrintInvoice()
    {
        cout << "Shopping CartInvoice :" << endl;
        for (int i = 0; i < products.size(); i++)
        {
            cout << products[i]->name << " $" << products[i]->price << endl;
        }
        cout << "Total $" << GetTotalCartPrice() << endl;
    }

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
    addtocart->SavetoDB();
    addtocart->GetProducts();
    addtocart->GetTotalCartPrice();
    addtocart->PrintInvoice();
    return 0;
}
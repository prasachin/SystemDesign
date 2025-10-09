// #include <bits/stdc++.h>
// using namespace std;

// class Singleton
// {
// private:
//     Singleton()
//     {
//         cout << "Your instance is created" << endl;
//     }
//     static Singleton *instance;

// public:
//     static Singleton *Setter()
//     {
//         if (instance == nullptr)
//         {
//             instance = new Singleton();
//             return instance;
//         }
//         else
//         {
//             return instance;
//         }
//     }
// };

// Singleton *Singleton::instance = nullptr;

// int main()
// {
//     // Singleton *s = new Singleton();
//     // Singleton *s1 = new Singleton();
//     Singleton *s = Singleton::Setter();
//     Singleton *s1 = Singleton::Setter();
//     cout << (s == s1) << endl;
//     return 0;
// }

//  but the abovve method is not thread safe i.e when a user try to create multiple instance at the same time then it will allow to create multiple instance which is breaking the singleton design pattern in order to get rid of this we use mutex in cpp to block the thread and allow only one object creation at a time.

#include <bits/stdc++.h>
using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "Your instance is created" << endl;
    }
    static Singleton *instance;
    static mutex mtx;

public:
    static Singleton *Setter()
    {
        if (instance == nullptr) // Here we are using double checked locking to avoid the overhead of locking every time
        {
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr)
            {
                instance = new Singleton();
            }
        }
        return instance;
    }
};
//  Here we are initializing the static members
Singleton *Singleton::instance = nullptr;
mutex Singleton::mtx;

int main()
{
    // Singleton *s = new Singleton();
    // Singleton *s1 = new Singleton();
    Singleton *s = Singleton::Setter();
    Singleton *s1 = Singleton::Setter();
    cout << (s == s1) << endl;
    return 0;
}
// if we dont want to use the locking mechanism then we can go with the eager initialization, but if the class is very expensive then we avoid using it .
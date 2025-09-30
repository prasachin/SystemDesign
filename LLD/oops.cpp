#include <bits/stdc++.h>
using namespace std;

class Car
{
protected: // here protected so that we can acccess in the child class
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    // public:
    //     // we are adding here vitual,  means we are just declearing the methods here not defining. this is also the eg of the dynamic morphism
    //     virtual void startEngine() = 0;
    //     virtual void shiftGear(int gear) = 0;
    //     virtual void accelerate() = 0;
    //     virtual void brake() = 0;
    //     virtual void stopEngine() = 0;
    //     virtual int getSpeed() = 0;
    //     virtual ~Car() {}
};

// now based on the above lets create a sports type car which will inherit the properties from the above class Car

class SportsCar : public Car
{
private:
    bool tookPartInF1;

public:
    // constructor
    SportsCar(string a, string b)
    {
        this->brand = a;
        this->model = b;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }
    // getter and setter function to access the inaccessible variables
    int getSpeed()
    {
        return currentSpeed;
    }
    void takePartinF1()
    {
        tookPartInF1 = true;
    }
    bool DidtakePartinF1()
    {
        return tookPartInF1;
    }
    // methods
    void startEngine()
    {
        isEngineOn = true;
        cout << "Engine of car with brand " << brand << " and model " << model << " started " << endl;
    }

    void shiftGear(int gear)
    {
        if (!isEngineOn)
        {
            cout << "Your car has not started yet!" << endl;
            return;
        }
        currentGear = gear;
        cout << "Your car's gear is shifted to " << gear << endl;
    }
    void accelerate()
    {
        if (!isEngineOn)
        {
            cout << "Your car has not started yet!" << endl;
            return;
        }

        currentSpeed += 20;
        cout << "The speed of your car is accelerated to " << currentSpeed << endl;
    }

    void brake()
    {
        currentSpeed -= 20;
        if (currentSpeed < 0)
        {
            currentSpeed = 0;
        }
        cout << "Breaking applied! speed is reduced by 20 unit/m" << endl;
    }

    void stopEngine()
    {
        isEngineOn = false;
        currentSpeed = 0;
        currentSpeed = 0;
        cout << "Your Car has been stopped successfully !" << endl;
    }
};

int main()
{
    // Car *myCar = new SportsCar("Range Rover", "Cruiser"); for the abstraction
    SportsCar *myCar = new SportsCar("Range Rover", "Cruiser");
    myCar->startEngine();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();
    // here now we can not set the speed as much as we want, directly
    // myCar->currentSpeed = 500;
    // cout << "This sppeed of my car is " << myCar->currentSpeed << endl;

    // here we are getting the speed of the car using getter and setter function.
    cout << "The speed of your car is " << myCar->getSpeed() << endl;
    cout << "Did your car took part in F1 " << myCar->DidtakePartinF1() << endl;
    myCar->takePartinF1();
    cout << "Did your car took part in F1 " << myCar->DidtakePartinF1() << endl;
    return 0;
}
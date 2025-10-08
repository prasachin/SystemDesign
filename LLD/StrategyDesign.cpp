#include <bits/stdc++.h>
using namespace std;

// Here we are going to follow the strategy design pattern using an example of a robot the robot will have some features like walk, talk, how it looks etc.
// Her we will also see how inheritance can be a headache sometimes and how using composition we resolve this problem.

//    strategies interface for the walkable feature
class WalkableRobot
{
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() = default;
};

// concrete stragies for the walkable features

class NormalWalk : public WalkableRobot
{
public:
    void walk() override
    {
        cout << "Hey I am robot and i walks normally !" << endl;
    }
};

class FastWalk : public WalkableRobot
{
public:
    void walk() override
    {
        cout << "Hey I am a robot ansd I can Walk Fast !" << endl;
    }
};

// simillarly there is a talkable robot as well .

class TalkableRobot
{
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() = default;
};

// concrete stragies for the talkable features

class NormalTalk : public TalkableRobot
{
public:
    void talk() override
    {
        cout << "Hey I am robot and i talk normally !" << endl;
    }
};

class FastTalk : public TalkableRobot
{
public:
    void talk() override
    {
        cout << "Hey I am a robot ansd I can talk Fastly !" << endl;
    }
};

// simillarly there is a talkable robot as well .
class FlyableRobot
{
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() = default;
};

// concrete stragies for the talkable features

class NormalFly : public FlyableRobot
{
public:
    void fly() override
    {
        cout << "Hey I am robot and i fly normally !" << endl;
    }
};

class FastFly : public FlyableRobot
{
public:
    void fly() override
    {
        cout << "Hey I am a robot ansd I can fly Fastly !" << endl;
    }
};

// Now we will create a robot class which will have all these features as its members and we will use composition to achieve this .

class Robot
{
    WalkableRobot *walkableRobot;
    TalkableRobot *talkableRobot;
    FlyableRobot *flyableRobot;

public:
    Robot(WalkableRobot *walk, TalkableRobot *talk, FlyableRobot *fly)
    {
        this->walkableRobot = walk;
        this->talkableRobot = talk;
        this->flyableRobot = fly;
    }

    void walk()
    {
        walkableRobot->walk();
    }

    void talk()
    {
        talkableRobot->talk();
    }

    void fly()
    {
        flyableRobot->fly();
    }

    virtual void projection_display() = 0;
};

// now we are ready to create our robot types

class CompanionRobot : public Robot
{
public:
    CompanionRobot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f) : Robot(w, t, f) {}

    void projection_display() override
    {
        cout << "Hey I am a companion robot and i have all the companion features !" << endl;
    }
};

class WorkerRobot : public Robot
{
public:
    WorkerRobot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f) : Robot(w, t, f) {}

    void projection_display() override
    {
        cout << "Hey I am a worker robot and my type is worker !" << endl;
    }
};


// Here we can play around with different permutation and combination;
int main()
{
    CompanionRobot *companionRobot = new CompanionRobot(new NormalWalk(), new FastTalk(), new NormalFly());
    companionRobot->projection_display();
    companionRobot->walk();
    companionRobot->talk();
    companionRobot->fly();

    // similarly we can create a worker robot as well
    WorkerRobot *workerRobot = new WorkerRobot(new FastWalk(), new NormalTalk(), new FastFly());
    workerRobot->projection_display();
    workerRobot->walk();
    workerRobot->talk();
    workerRobot->fly();
    return 0;
}
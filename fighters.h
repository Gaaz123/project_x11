#ifndef FIGHTERS_H
#define FIGHTERS_H

#include <string>

class Fighter {
protected:
    std::string name;
    int health;
    int attack;
    int x, y;
    
public:
    Fighter(std::string n, int h, int a, int startX, int startY)
        : name(n), health(h), attack(a), x(startX), y(startY) {}
    
    virtual ~Fighter() {}
    
    virtual void specialMove() = 0;
    
    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }
    
    void attackTarget(Fighter& target) {
        target.takeDamage(attack);
    }
    
    bool isAlive() const { return health > 0; }
    
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getX() const { return x; }
    int getY() const { return y; }
    int getAttack() const { return attack; }
};

class Warrior : public Fighter {
public:
    Warrior(std::string n, int startX, int startY) 
        : Fighter(n, 100, 20, startX, startY) {}
    
    void specialMove() override {
        attack += 5;
    }
};

class Mage : public Fighter {
public:
    Mage(std::string n, int startX, int startY) 
        : Fighter(n, 80, 15, startX, startY) {}
    
    void specialMove() override {
        health += 25;
        if (health > 80) health = 80;
    }
};

#endif
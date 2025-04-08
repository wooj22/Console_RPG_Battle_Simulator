#pragma once
#include <iostream>
using namespace std;

class Character
{
protected:
    int hp;
    int power;
    bool isDie;

public:
    Character(int hp, int power) : hp(hp), power(power), isDie(false) {};
    virtual ~Character() {};

    virtual void Show() {};
    virtual void Attack(Character* other) {};
    virtual void TakeDamage(int damage) {};
    bool IsDead() { return isDie; }
};


class Player : public Character {
public:
    Player() : Character(100, 10) { Show(); }
    ~Player() override { cout << "Player ¼Ò¸ê"; }
    
    // override
    void Show() override;
    void Attack(Character* other) override;
    void TakeDamage(int damage) override;

    void Recover();
    void PowerUp();
};


class Enemy : public Character {
public:
    Enemy() : Character(20, 5) { Show(); };
    ~Enemy() override {  }

    // override
    void Show() override;
    void Attack(Character* other) override;
    void TakeDamage(int damage) override;
};


class StrongEnemy : public Character {
public:
    StrongEnemy() : Character(50, 15) { Show(); };
    ~StrongEnemy() override {  }

    // override
    void Show() override;
    void Attack(Character* other) override;
    void TakeDamage(int damage) override;
};


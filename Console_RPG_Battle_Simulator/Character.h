#pragma once

class Character
{
protected:
    int hp;
    int power;
    bool isDie;

public:
    Character(int hp, int power) : hp(hp), power(power), isDie(false) {};

    virtual void Attack(Character* other) {};
    virtual void TakeDamage(int damage) {};
    virtual bool IsDead() { return isDie; }
};


class Player : public Character {
public:
    Player() : Character(100, 10) {};
    ~Player() { "Player ¼Ò¸ê"; }
    
    // override
    void Attack(Character* other) override;
    void TakeDamage(int damage) override;
    bool IsDead() override;

    void Recover();
};


class Enemy : public Character {
public:
    Enemy() : Character(100, 10) {};
    ~Enemy() { "Enemy ¼Ò¸ê"; }

   
    void Attack(Character* other) override;
    void TakeDamage(int damage) override;
    bool IsDead() override;
};


class StrongEnemy : public Character {
public:
    StrongEnemy() : Character(100, 10) {};
    ~StrongEnemy() { "StrongEnemy ¼Ò¸ê"; }

    // override
    void Attack(Character* other) override;
    void TakeDamage(int damage) override;
    bool IsDead() override;
};


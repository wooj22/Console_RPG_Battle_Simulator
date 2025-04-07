#pragma once

class Character
{
private:
    int hp;
    int power;
    bool isDie;

public:
    Character(int hp, int power) : hp(hp), power(power), isDie(false) {};
    virtual void Attack(Character* other);
    virtual void TakeDamage(int damage);
    virtual bool IsDead();
    virtual void Recover();
    virtual void ShowHp();
};


class Player : public Character {
    
    Player() : Character(100, 10) {};
    void Attack(Character* other) override;
    void TakeDamage(int damage) override;
    bool IsDead() override;
    void Recover() override;
    void ShowHp() override;
    ~Player() { "Player �Ҹ�"; }
};


class Enemy : public Character {
    Enemy() : Character(100, 10) {};
    void Attack(Character* other) override;
    void TakeDamage(int damage) override;
    bool IsDead() override;
    void Recover() override;
    void ShowHp() override;
    ~Enemy() { "Enemy �Ҹ�"; }
};


class StrongEnemy : public Character {
    StrongEnemy() : Character(100, 10) {};
    void Attack(Character* other) override;
    void TakeDamage(int damage) override;
    bool IsDead() override;
    void Recover() override;
    void ShowHp() override;
    ~StrongEnemy() { "StrongEnemy �Ҹ�"; }
};


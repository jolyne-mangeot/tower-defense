#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
public:
    float x, y;
    int health;
    Enemy(float x, float y);
    void takeDamage(int dmg);
    bool isDead() const;
};

#endif // ENEMY_H

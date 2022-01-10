#include <iostream>
#include <string>
using namespace std;

/*
* Абстрактные классы
* Чисто виртуальные функции
* virtual
* override
*/

class Weapon
{
public:
    
virtual void Shoot() = 0;
};


class Gun : public Weapon
{
public:
    
void Shoot() override
{
    cout << "BANG!" << endl;
}
    
};


class SubmachineGun :public Gun
{
public:
    
void Shoot() override
{
cout << "BANG! BANG! BANG!" << endl;
}
    
};


class Bazooka :public Weapon
{
public:
    
void Shoot() override
{
cout << "BADABUB!!!" << endl;
}
    
};


class Knife :public Weapon
{
public:
    
void Shoot() override
{
cout << "VJUH!!!" << endl;
}

};


class Player
{
public:
    
void Shoot(Weapon *weapon)
{
weapon->Shoot();
}
    
};



int main()
{
setlocale(LC_ALL, "ru");

Gun gun;

SubmachineGun machinegun;

Bazooka bazooka;

Knife knife;

Player player;
player.Shoot(&knife);

return 0;
}

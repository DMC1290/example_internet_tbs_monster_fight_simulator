// example_internet_tbs_monster_fight_simulator.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;

struct Monster {
    string name;
    int health;
    int attackPoints;
    int defensePoints;
    int speedPoints;
};

void attack(Monster& attacker, Monster& defender) {
    int damage = attacker.attackPoints - defender.defensePoints;
    if (damage < 0) {
        damage = 0; // ensure damage is not negative
    }
    defender.health -= damage;
    cout << attacker.name << " attacks " << defender.name << " for " << damage << " damage!" << endl;
    cout << defender.name << "'s health: " << defender.health << endl;
}

int main() {
    Monster monster1 = { "Goblin", 50, 10, 5, 3 };
    Monster monster2 = { "Orc", 70, 15, 7, 2 };
    Monster monster3 = { "Troll", 90, 20, 10, 1 };
    Monster monster4 = { "Dragon", 110, 30, 15, 4 };

    Monster monsters[4] = { monster1, monster2, monster3, monster4 };

    cout << "Choose 2 monsters to fight each other:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << monsters[i].name << " (Health: " << monsters[i].health << ", Attack: " << monsters[i].attackPoints << ", Defense: " << monsters[i].defensePoints << ", Speed: " << monsters[i].speedPoints << ")" << endl;
    }

    int choice1, choice2;
    cin >> choice1 >> choice2;

    Monster attacker = monsters[choice1 - 1];
    Monster defender = monsters[choice2 - 1];

    // determine who attacks first based on speed points
    if (attacker.speedPoints > defender.speedPoints) {
        while (attacker.health > 0 && defender.health > 0) {
            attack(attacker, defender);

            if (defender.health <= 0) {
                cout << defender.name << " has been defeated!" << endl;
                break;
            }

            attack(defender, attacker);

            if (attacker.health <= 0) {
                cout << attacker.name << " has been defeated!" << endl;
                break;
            }
        }
    }
    else {
        while (attacker.health > 0 && defender.health > 0) {
            attack(defender, attacker);

            if (attacker.health <= 0) {
                cout << attacker.name << " has been defeated!" << endl;
                break;
            }

            attack(attacker, defender);

            if (defender.health <= 0) {
                cout << defender.name << " has been defeated!" << endl;
                break;
            }
        }
    }

    return 0;
}
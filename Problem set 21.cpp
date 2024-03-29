#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <set>

using namespace std;

class Monster {
public:
    int hp;
    int atk;
    int def;
    vector<string> skills;
    Monster(double, double, double, vector<string>);
    Monster operator+(Monster);
};
Monster::Monster(double h, double a, double d, vector<string> s) {
    hp = h;
    atk = a;
    def = d;
    skills = s;
}

Monster Monster::operator+(Monster target) {
    Monster *result = new Monster(0, 0, 0, vector<string>());
    result->hp = rand() % (abs(this->hp - target.hp)) + min(this->hp, target.hp);
    result->atk = rand() % (abs(this->atk - target.atk)) + min(this->atk, target.atk);
    result->def = rand() % (abs(this->def - target.def)) + min(this->def, target.def);
    set<string> skill_set;
    for (int i = 0; i < this->skills.size(); i++)
    {
        skill_set.insert(this->skills[i]);
    }
    for (int i = 0; i < target.skills.size(); i++)
    {
        skill_set.insert(target.skills[i]);
    }
    for (set<string>::iterator it = skill_set.begin(); it != skill_set.end(); it++)
    {
        if (rand() % 2 == 0)
        {
            result->skills.push_back(*it);
        }
    }
    return *result;
}

int main() {
    srand(time(0));
    vector<string> Pikachu_skills;
    Pikachu_skills.push_back("Tail Whip");
    Pikachu_skills.push_back("Spark");
    Pikachu_skills.push_back("Thunder");
    Monster Pikachu(100, 40, 20, Pikachu_skills);

    vector<string> Nidoran_skills;
    Nidoran_skills.push_back("Tail Whip");
    Nidoran_skills.push_back("Double Kick");
    Nidoran_skills.push_back("Toxic Spikes");
    Nidoran_skills.push_back("Poison Fang");
    Monster Nidoran(200, 25, 50, Nidoran_skills);

    Monster Nidochu = Nidoran + Pikachu;
    cout << "HP = " << Nidochu.hp;
    cout << "\t ATK = " << Nidochu.atk;
    cout << "\t DEF = " << Nidochu.def << "\n";
    cout << "SKILLS: \n";
    for (int i = 0; i < Nidochu.skills.size(); i++)
    {
        cout << "\t" << Nidochu.skills[i] << "\n";
    }
    return 0;
}

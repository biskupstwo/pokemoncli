//
//  pokemon.cpp
//  Pokemon
//
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "pokemon.h"
using namespace std;

Potion::Potion(std::string _name, int _points, int _price){
    name = _name;
    points = _points;
    price = _price;
}

Potion* potion = new Potion("Potion",20,100);
Potion* super = new Potion("Super Potion",40,200);
Berry* oran = new Berry("Oran Berry",10,50,"Blue");

std::vector<Potion*>& Trainer::add_potion(){
    int inp;
    std::string choo;
    int counter = 0;
    bool ei = false;
    Potion* cho;
    do{
        if(counter == 0)
        {
            std::cout << "Enjoy your free samples!\n";
            for (int i = 0; i < 3; i++){
                Potions.push_back(new Potion(*potion));
            }
        }
        else
        {
            std::cout << "do you want to buy potions?\n";
        }
        std::cout << "type 1/y/yes if you want to.\n";
        std::cin >> choo;
        if(choo == "1" || choo == "y" || choo == "yes"){
            std::cout << "\n which potion do you want to buy? \n\n";
            std::cout << " 1) Potion 2) Super Potion\n";
            std::cin >> inp;
            switch(inp){
                case 1:
                    cho = potion;
                    break;
                case 2:
                    cho = super;
                    break;
                default:
                    cho = potion;
                    break;
            }
            Potions.push_back(new Potion(*cho));
            counter++;
    }else{
        ei = true;
    }
    }while(ei != true || Potions.size() == 6);
    return Potions;
};

std::ostream &operator<<( std::ostream &output, const Potion &po ) {
    output << po.name;
    output << "\n Restore points: " << po.points;
    output << "\n Price: " << po.price;
    output << "\n";
   return output;
}

void Trainer::get_potions(){
    for (int i = 0; i < Potions.size(); i++){
        std::cout << i <<".\n";
        std::cout << *Potions[i] << "\n";
    }
}

std::vector<Berry*>& Trainer::add_berries(){
    int inp;
    std::string choo;
    int counter = 0;
    bool ei = false;
    Berry* cho;
    do{
        if(counter == 0)
        {
            std::cout << "Enjoy your free sample!\n";
            Berries.push_back(new Berry(*oran));
        }
        else
        {
            std::cout << "do you want to buy berries?\n";
        }
        std::cout << "type 1/y/yes if you want to.\n";
        std::cin >> choo;
        if(choo == "1" || choo == "y" || choo == "yes"){
            std::cout << "\nWhich Berry do you want to buy: \n\n";
            std::cout << " 1) Oran Berry\n";
            std::cin >> inp;
            switch(inp){
                case 1:
                    cho = oran;
                default:
                    cho = oran;
                    break;
            }
            Berries.push_back(new Berry(*cho));
            counter++;
    }else{
        ei = true;
    }
    }while(ei != true || Berries.size() == 5);
    return Berries;
};

std::ostream &operator<<( std::ostream &output, const Berry &b) {
    output << b.name;
    output << "\n Color : " << b.color;
    output << "\n Restore points: " << b.points;
    output << "\n Price: " << b.price;
    output << "\n";
   return output;
}

void Trainer::get_berries(){
    for (int i = 0; i < Berries.size(); i++){
        std::cout << i <<".\n";
        std::cout << *Berries[i] << "\n";
    }
}


Trainer::Pokemon::Pokemon(std::string newname, int newlevel, int ninit_hp, std::string newtype, bool newis_knocked_out, int nexp){
    name = newname;
    level = newlevel;
    init_hp = ninit_hp;
    hp = init_hp;
    type = newtype;
    is_knocked_out = newis_knocked_out;
    exp = nexp;
}

void Trainer::Pokemon::info() const{
    
    std::cout << name;
    if(is_knocked_out == true){
        std::cout << "\nfainted";
    }
    std::cout << "\n Type: " << type;
    std::cout << "\n HP: " << hp;
    std::cout << "/" << init_hp;
    std::cout << "\n Current level: " << level;
    std::cout << "\n Exp: " << exp << "\n";
}

int Trainer::Pokemon::level_up(){
    exp = 0;
    level += 1;
    hp+=2;
    init_hp+= 2;
    std::cout << "\nYour " << name << " leveled up to level " << level << ".\n";
    return level;
}

int Trainer::Pokemon::gain_exp(){
    
    exp += 2;
    std::cout << "\n" << name << " gained 1 exp.\n";
    if (exp >= 3){
        int t_exp = exp - 3;
        level_up();
        exp = t_exp;
    }
    return exp;
}


int Trainer::Pokemon::gethp(){
    return hp;
}

int Trainer::Pokemon::superlose(){
    hp -= 6;
    return hp;
}

int Trainer::Pokemon::lose_hp(){
    hp -= 3;
    return hp;
}

int Trainer::Pokemon::lowlose(){
    hp -= 1;
    return hp;
}

int Trainer::Pokemon::gain_hp(){
    hp += 10;
    if(hp > init_hp){
        hp = init_hp;
    }
    return hp;
}

bool Trainer::Pokemon::knock_out(){
    hp = 0;
    if (hp <= 0){
        is_knocked_out = true;
    }
    return is_knocked_out;
}

bool Trainer::Pokemon::revive(){
    is_knocked_out = false;
    hp = init_hp;
    return is_knocked_out;
}

int Trainer::Pokemon::get_lvl(){
    return level;
}

std::string Trainer::Pokemon::get_type(){
    std::string typ = type;
    return typ;
}

std::string Trainer::Pokemon::get_name(){
    std::string nam = name;
    return nam;
}
Trainer::Trainer(std::string newname,int newrep,int newcash/*,std::vector<std::string> newpokemons*/){
    name = newname;
    rep = newrep;
    cash = newcash;
    /*
    Pokemons = newpokemons;
     */
}
void Trainer::info(){
    
    std::cout << name;
    std::cout << "\n Rep: " << rep << "\n";
    std::cout << " Cash: " << cash << "\n";
}
int Trainer::gain_rep(){
    rep += 1;
    std::cout << "\n" << name << " gained 1 rep.\n";
    return rep;
}

Trainer::Pokemon::Type::Type(std::string _atktype, std::string _deftype, int _multiplier){
    atktype = _atktype;
    deftype = _deftype;
    multiplier = _multiplier;
}

int Trainer::gain_cash(){
    cash += 300;
    std::cout << "\n" << name << " got 300$ for winning.\n";
    return cash;
}

Trainer::Pokemon* bulbasaur = new Trainer::Pokemon("Bulbasaur",5,20,"Grass",false,0);
Trainer::Pokemon* charmander = new Trainer::Pokemon("Charmander",5,19,"Fire",false,0);
Trainer::Pokemon* squirtle = new Trainer::Pokemon("Squirtle",5,21,"Water",false,0);
Trainer::Pokemon* pikachu = new Trainer::Pokemon("Pikachu",5,19,"Electric",false,0);
Trainer::Pokemon* sandshrew = new Trainer::Pokemon("Sandshrew",5,19,"Ground",false,0);

void Game::Bag(Trainer &tr){
    int opt;
    int use;
    int k;
    int op;
    std::cout << tr.name <<"'s bag\n";
    std::cout << "Pockets: \n";
    std::cout << "  1) Potion pocket 2) Berry pocket\n\n";
    std::cout << "Choose a pocket: ";
    std::cin >> opt;
        switch(opt){
            case 1:
                tr.get_potions();
                std::cout << "Do you want to use any potion above?\n";
                std::cout << "Type 1 and press Enter.\n";
                std::cin >> op;
                if(op == 1){
                    std::cout << "Which one you want to use?\n";
                    std::cout << "Enter an ID of item.\n";
                    std::cin >> use;
                    std::cout << "On which pokemon?\n";
                    tr.get_pkmn();
                    std::cin >> k;
                    if(tr.Pokemons[k]->hp >= tr.Pokemons[k]->init_hp){
                        std::cout << "They are used to heal injured Pokémon, not full-healed one.\n";
                    }
                    else{
                        tr.Pokemons[k]->hp += tr.Potions[use]->points;
                        if(tr.Pokemons[k]->hp >= tr.Pokemons[k]->init_hp){
                            tr.Pokemons[k]->hp = tr.Pokemons[k]->init_hp;
                        }
                    }
                }
                break;
            case 2:
                tr.get_berries();
                std::cout << "Do you want to use any potion above?\n";
                std::cout << "Type 1 and press Enter.\n";
                std::cin >> op;
                if(op == 1){
                    std::cout << "Which one you want to use?\n";
                    std::cout << "Enter an ID of item.\n";
                    std::cin >> use;
                    std::cout << "On which pokemon?\n";
                    tr.get_pkmn();
                    std::cin >> k;
                    if(tr.Pokemons[k]->hp >= tr.Pokemons[k]->init_hp){
                        std::cout << "They are used to heal injured Pokémon, not full-healed one.\n";
                    }
                    else{
                        tr.Pokemons[k]->hp += tr.Berries[use]->points;
                        if(tr.Pokemons[k]->hp >= tr.Pokemons[k]->init_hp){
                            tr.Pokemons[k]->hp = tr.Pokemons[k]->init_hp;
                        }
                        //tr.Berries.erase(use);
                    }
                break;
            default:
                break;
        }
}
}

void Game::Battle(Trainer::Pokemon &p1, Trainer::Pokemon &p2, Trainer &tr){
    p2.hp = p2.init_hp;
    std::cout << "\nWild " << p2.get_name() << " appeared!\n";
    int opt;
    
    do{
    std::cout << "1) Attack 2) Heal " << p1.get_name() << "\n";
    std::cout << "Choose an option: ";
    std::cin >> opt;
    switch (opt){
            
        case 1:
            std::cout << "your turn\n";
            if(p1.get_type() == "Water" && p2.get_type() == "Electric")
            {
                p2.lowlose();
            }
            else if(p1.get_type() == "Electric" && p2.get_type() == "Water")
            {
                p2.superlose();
            }
            else if(p1.get_type() == p2.get_type())
            {
                p2.lowlose();
            }
            else
            {
                p2.lose_hp();
            }
            break;
        case 2:
            Bag(tr);
            /*
            if(p1.hp >= p1.init_hp){
                std::cout << "lol\n";
            }else{
            p1.gain_hp();
            
            }*/
             break;
        default:
            std::cout << "Enter valid option\n";
        
    }
        if(p1.get_type() == "Water" && p2.get_type() == "Electric")
        {
            std::cout << "opponent turn\n";
            p1.superlose();
        }
        else if(p1.get_type() == "Electric" && p2.get_type() == "Water")
        {
            std::cout << "opponent turn\n";
            p1.lowlose();
        }
        else if(p1.get_type() == p2.get_type())
        {
            std::cout << "opponent turn\n";
            p1.lowlose();
        }
        else
        {
            std::cout << "opponent turn\n";
            p1.lose_hp();
        }
        if (p1.hp > 0 && p2.hp > 0){
           std::cout << p1.get_name() << " HP: " << p1.hp <<"\n";
           std::cout << p2.get_name() << " HP: " << p2.hp <<"\n";
        }else if(p1.hp <= 0 && p2.hp <= 0){
            std::cout << p1.get_name() << " HP: 0\n";
            std::cout << p2.get_name() << " HP: 0\n";
        }else if(p2.hp <= 0){
            std::cout << p1.get_name() << " HP: " << p1.hp <<"\n";
            std::cout << p2.get_name() << " HP: 0\n";
        }else if(p1.hp <= 0){
            std::cout << p1.get_name() << " HP: 0\n";
            std::cout << p2.get_name() << " HP: " << p2.hp <<"\n";
        }
        
    }while( p2.hp > 0 && p1.hp > 0);
    
    if(p1.hp >= 0 && p2.hp <= 0){
        std::cout << "You won.\n";
        p2.knock_out();
        p1.gain_exp();
        tr.gain_cash();
        tr.gain_rep();
    }else if(p1.hp <= 0 && p2.hp >= 0){
        std::cout << p1.get_name() << " fainted.\n";
        std::cout << tr.name << " blacked out.\n";
        tr.rep -= 1;
        tr.cash /= 2;
        p1.knock_out();
    }else{
        std::cout << p1.get_name() << " fainted.\n";
        std::cout << p2.get_name() << " fainted.\n";
        std::cout << tr.name << " blacked out.\n";
        p1.knock_out();
        p2.knock_out();
        tr.cash /= 2;
        tr.rep -= 1;
    }
}

void Game::Shop(Trainer &tr){
    int option;
    std::cout << "Hi, " << tr.name << "!\n";
    std::cout << "May I help You?\n";
    std::cout << " 1) Potions 2) Berries\n\n";
    std::cin >> option;
    switch(option){
        case 1:
            tr.add_potion();
            break;
        case 2:
            tr.add_berries();
            break;
        default:
            std::cout << "Please come again!\n";
            break;
    }
    std::cout << "Please come again!\n";
}


void Game::Train(Trainer::Pokemon &p1,Trainer &tr){
    if (p1.hp == 0){
        std::cout << "Time to visit Pokemon Center.\n";
        std::cout << "Just type 3 and press Enter.\n";
    }
    else if (p1.hp > 0){
        p1.hp -= 1;
        tr.cash -= 100;
        p1.exp += 1;
        std::cout << "\n" << p1.name << " gained 1 exp.\n";
        if (p1.exp >= 3){
            int t_exp = p1.exp - 3;
            p1.level_up();
            p1.exp = t_exp;
        }

        if (p1.hp == 0){
            p1.is_knocked_out = true;
            std::cout << "Time to visit Pokemon Center.\n";
            std::cout << "Just type 3 and press Enter.\n";
        }
    }
}
 
std::ostream &operator<<( std::ostream &output, const Trainer::Pokemon &p ) {
    output << p.name;
    if(p.is_knocked_out == true){
        output << "\nfainted";
    }
    output << "\n Type: " << p.type;
    output << "\n HP: " << p.hp;
    output << "/" << p.init_hp;
    output << "\n Current level: " << p.level;
    output << "\n Exp: " << p.exp << "\n";
   return output;
}
std::vector<Trainer::Pokemon*>& Trainer::add_pkmn(){
    int inp;
    std::string choo;
    int counter = 0;
    bool ei = false;
    Trainer::Pokemon* cho;
    do{
        if(counter == 0)
        {
            std::cout << "Choose your first pokemon\n";
        }
        else
        {
            std::cout << "do you want to add another pokemon?\n";
        }
        std::cout << "type 1/y/yes to choose pokemon.\n";
        std::cin >> choo;
        if(choo == "1" || choo == "y" || choo == "yes"){
            std::cout << "\nchoose your pokemon: \n\n";
            std::cout << " 1) Bulbasaur 2) Charmander\n";
            std::cout << " 3) Squirtle  4) Pikachu\n";
            std::cout << " 5) Sandshrew\n";
            std::cin >> inp;
            switch(inp){
                case 1:
                    cho = bulbasaur;
                    break;
                case 2:
                    cho = charmander;
                    break;
                case 3:
                    cho = squirtle;
                    break;
                case 4:
                    cho = pikachu;
                    break;
                case 5:
                    cho = sandshrew;
                    break;
                default:
                    cho = pikachu;
                    break;
            }
            Pokemons.push_back(new Pokemon(*cho));
            counter++;
    }else{
        ei = true;
    }
    }while(ei != true || Pokemons.size() == 6);
    return Pokemons;
};

void Trainer::get_pkmn(){
    for (int i = 0; i < Pokemons.size(); i++){
        std::cout << i <<".\n";
        std::cout << *Pokemons[i] << "\n";
    }
}


//
//  main.cpp
//  Pokemon
//

#include <iostream>
#include "pokemon.cpp"



int main(int argc, const char * argv[])
{
    
    Game* game = new Game();
    bool exit = false;
    std::string name;
    int k;
    std::string rivalname;
    int option;
    
    std::cout << "simple pokemon game\n";
    std::cout << "made by jan biskupski\n\n";
    std::cout << "This world is inhabited by creatures called POKEMON! For\n";
    std::cout << "some people, POKEMON are pets. Others use them for\n";
    std::cout << "fights. Myself... I study POKEMON as a profession.\n\n";
    std::cout << "First, what is your name? ";
    std::cin >> name;
    std::cout << "\nRight! So your name is " << name << "!\n";
    Trainer* trainer = new Trainer(name,0,3000);
    std::cout << "He's been your rival since you were a baby.\n";
    std::cout << "...Erm, what is his name again? ";
    std::cin >> rivalname;
    std::cout << "\nThat's right! I remember now! His name is " << rivalname << "!\n\n";
    std::cout << name << "! Your very own POKEMON legend is about to unfold! A world of dreams and adventures with POKEMON awaits! Let's go!\n\n";
    Trainer* rival = new Trainer (rivalname,0,3000);
    
    trainer->add_pkmn();
    if(trainer->Pokemons[0]->name == "Bulbasaur")
    {
        rival->Pokemons.push_back(new Trainer::Pokemon(*charmander));
    }
    else if(trainer->Pokemons[0]->name == "Charmander")
    {
        rival->Pokemons.push_back(new Trainer::Pokemon(*squirtle));
    }
    else if(trainer->Pokemons[0]->name == "Squirtle")
    {
        rival->Pokemons.push_back(new Trainer::Pokemon(*bulbasaur));
    }
    else if(trainer->Pokemons[0]->name == "Pikachu")
    {
        rival->Pokemons.push_back(new Trainer::Pokemon(*sandshrew));
    }
    else if(trainer->Pokemons[0]->name == "Sandshrew")
    {
        rival->Pokemons.push_back(new Trainer::Pokemon(*squirtle));
    }
    else{
        std::cout << "Error.\n";
    }
    do{
    std::cout << "\nchoose an option: \n";
    std::cout << " 1) pokemon info         2) battle\n";
    std::cout << " 3) pokemon center       4) train\n";
    std::cout << " 5) trainer info         6) bag\n";
    std::cout << " 7) pokemon market\n\n";
    std::cin >> option;
    
    switch(option){
     
        case 1:
            trainer->get_pkmn();
            break;
        case 2:
            trainer->get_pkmn();
            std::cout << "which pokemon do you want to use in battle? type number.\n";
            std::cin >> k;
            if(trainer->Pokemons[k]->gethp() > 0)
                game->Battle(*trainer->Pokemons[k], *pikachu, *trainer);
            else{
                std::cout << "Time to visit Pokemon Center.\n";
                std::cout << "Just type 3 and press Enter.\n";
            }
            break;
        case 3:
            std::cout << "Welcome to our Pokemon Center!\n\n";
            for (int i = 0; i < trainer->Pokemons.size(); i++){
                trainer->Pokemons[i]->revive();
                std::cout << trainer->Pokemons[i]->name << " restored to full health.\n";
            }
            std::cout << "\nWe hope to see you again!\n";
            break;
        case 4:
            std::cout << "which pokemon do you want to train?\n";
            trainer->get_pkmn();
            std::cin >> k;
            if(trainer->Pokemons[k]->gethp() > 0){
            game->Train(*trainer->Pokemons[k], *trainer);
            }else{
                std::cout << "Time to visit Pokemon Center.\n";
                std::cout << "Just type 3 and press Enter.\n";
            }
            break;
        case 5:
            trainer->info();
            break;
        case 6:
            game->Bag(*trainer);
            break;
        case 7:
            game->Shop(*trainer);
            break;
        case 8:
            std::cout << "test\n";
            trainer->add_pkmn();
            break;
        case 9:
            rival->get_pkmn();
            break;
        case 0:
            trainer->add_berries();
            break;
        default:
            std::cout << "goodbye.\n";
            exit = true;
            break;
    }}while(exit != true);
    return 0;
}

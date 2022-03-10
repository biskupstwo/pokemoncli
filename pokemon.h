#pragma once


class Potion{
    friend class Game;
    friend std::ostream &operator<<( std::ostream &output, const Potion &po );
public:
    std::string name;
    int points;
    int price;
    Potion(std::string _name, int _points, int _price);
    
};

class Berry : public Potion{
    friend class Game;
public:
    
    friend std::ostream &operator<<( std::ostream &output, const Berry &b );
    std::string color;
    Berry(std::string _name, int _points, int _price, std::string _color) : Potion(_name,_points,_price), color(_color){
        name = _name;
        points = _points;
        price = _price;
        color = _color;
    }
};

class Trainer {
    friend class Game;
    friend class OranBerry;
    friend class Potion;
    public:
    
        class Pokemon {
            friend class Game;
            
            class Type {
                friend std::ostream &operator<<( std::ostream &output, const Pokemon &p );
                public:
                    std::string atktype;
                    std::string deftype;
                    int multiplier;
                    
                    Type(std::string _atktype, std::string _deftype, int _multiplier);
                    
            };
            
            public:
            int level;
            
            std::string type;
            bool is_knocked_out;
            std::string name;
                int exp;
                int hp;
                int init_hp;
                //  Konstruktor
                Pokemon(std::string newname, int newlevel, int ninit_hp, std::string newtype, bool newis_knocked_out, int nexp);
                virtual void info() const; //jest
                virtual int get_lvl();
                virtual std::string get_type();
                virtual int lose_hp(); //jest
                virtual int superlose(); //jest
                virtual int lowlose();  //jest
                virtual int gain_hp(); //jest
                virtual int gethp(); // jest
                virtual int gain_exp(); //jest
                virtual int level_up(); //jest
                virtual bool knock_out(); //jest
                virtual bool revive(); //jest
                virtual std::string get_name(); //jest
        };
    
        private:
    
            
            
        public:
            std::vector<Pokemon*> Pokemons;
            std::vector<Potion*> Potions;
            std::vector<Berry*> Berries;
            int cash;
            int rep;
            std::string name;
            //konstruktor
            Trainer(std::string newname,int newrep,int newcash);
            virtual void info();
            virtual int gain_rep();
            virtual int gain_cash();
    
        virtual void get_pkmn();
        virtual std::vector<Pokemon*>& add_pkmn();
        virtual void get_potions();
        virtual std::vector<Potion*>& add_potion();
        virtual void get_berries();
        virtual std::vector <Berry*>& add_berries();
};


class Game{
    int status;
    public:
    //konstruktor
        Game() { status = 0; };
    virtual void Shop(Trainer &tr);
    virtual void Battle(Trainer::Pokemon& p1, Trainer::Pokemon& p2, Trainer& tr);
    virtual void Train(Trainer::Pokemon &p1,Trainer &tr);
    virtual void Bag(Trainer &tr);
    ~Game() {};
};

std::ostream &operator<<( std::ostream &output, const Trainer::Pokemon &p);
std::ostream &operator<<( std::ostream &output, const Potion &po);
std::ostream &operator<<( std::ostream &output, const Berry &b);

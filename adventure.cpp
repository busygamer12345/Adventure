
#include <iostream>
#include <random>
#include <vector>
#include <map>
#include <locale>

using namespace std;
typedef string str;
map<int,map<int,map<str,str>>> WDATA; // General data
map<int,map<int,vector<map<str,str>>>> WCDATA; // NPCs and enemyies
map<int,map<int,map<str,map<str,str>>>> WIDATA; // World inventory
//vector<map<str,str>> INVENTORY;
map<str,str> CHDATA;
vector<str> MALE_NAMES = {
"Saba",
"Sabas",
"Sabin",
"Sabyllos",
"Sadagares",
"Sadun",
"Saer",
"Saerus",
"Safrax",
"Sagar",
"Sagard",
"Sagarus",
"Saillot",
"Sainte Santin",
"Salbatore",
"Salicar",
"Salla",
"Salmoneus",
"Samer",
"Samo",
"Samson",
"Sandaili",
"Sander",
"Sanders",
"Sandre",
"Sandrin",
"Sanduru",
"Sandy",
"Sangiban",
"Sanguin",
"Sansalas",
"Santi",
"Santikurtz",
"Santio",
"Santutxo",
"Santxo",
"Santxol",
"Saphrax",
"Sarapammon",
"Sarilo",
"Sarpedon",
"Sarus",
"Sasoin",
"Satabus",
"Satordi",
"Satyros",
"Saunder",
"Saundre",
"Savaric Savary",
"Sawney",
"Sawnie",
"Saxo",
"Sayer",
"Scaios",
"Scamandius",
"Scamandrius",
"Schedius",
"Scholasticus",
"Sconea",
"Scylax",
"Scyllias",
"Scythas",
"Searl",
"Searle",
"Seaward",
"Sebastianus",
"Sebastos",
"Seber",
"Sede",
"Segar",
"Segarus",
"Segeric",
"Seguin",
"Sehier Syhier",
"Sein",
"Seisames",
"Selagus",
"Selatse",
"Seldomus",
"Selenas",
"Selepos",
"Seleukos",
"Selle",
"Selles",
"Seme",
"Semeno",
"Sendoa",
"Senebaut",
"Sengrat",
"Senuthius",
"Sequin",
"Serell",
"Sergius",
"Seri",
"Serill",
"Serle",
"Serlo",
"Serlon",
"Sernays",
"Serrell",
"Serrill",
"Sesuldo",
"Seuuard",
"Seuuardus",
"Seven",
"Sevestre",
"Sevrin",
"Sewal",
"Sewale",
"Sewallus",
"Seward",
"Sewell",
"Shapur",
"Shilgen",
"Shipitbaal",
"Sibertus",
"Sibico",
"Sibilo",
"Siboldus",
"Sibragtus",
"Sibratus",
"Sicard Sicho Sicre",
"Sicho",
"Sicinnos",
"Siculus",
"Sidimund",
"Siebrand",
"Siefke",
"Siegmyrth",
"Sifridus",
"Sigan",
"Sigebert",
"Sigenandus",
"Sigeric",
"Sigesar",
"Sigibald",
"Sigibert",
"Sigibuld",
"Sigismund",
"Sigisvult",
"Sikke",
"Silanos",
"Silban",
"Silenos",
"Silvestre",
"Simmias",
"Simo",
"Simocatta",
"Simoisius",
"Simonides",
"Sindel",
"Sindila",
"Sindo",
"Sinibaldo",
"Sinis",
"Sinon",
"Sippas",
"Sirion",
"Sirom",
"Siromos",
"Sisbert",
"Sisebut",
"Sisenand",
"Sisyphus",
"Sito",
"Sittas",
"Situli",
"Sivis",
"Siwardus",
"Sjamme",
"Skiron",
"Smaragdus",
"Smindyrides",
"Smintheus",
"Snaracho",
"Snarung",
"Snato",
"Snazi",
"Soas",
"Socus",
"Sohalet Soolet",
"Sohier",
"Soin",
"Soke",
"Sophanes",
"Sophokles",
"Soranus",
"Sosibios",
"Sosicles",
"Sosigines",
"Sosilus",
"Sosimenes",
"Sosipatros",
"Sosthenes",
"Sostias",
"Sostratos",
"Soter",
"Sotil",
"Souni Sonnet",
"Speciosus",
"Spertias",
"Speudon",
"Speusippos",
"Spinther",
"Spirodion",
"Staas",
"Stace",
"Stacey",
"Stachys",
"Stacius",
"Stacy",
"Stallo",
"Starchari",
"Stauracius",
"Steffen",
"Stentor",
"Stephane",
"Stephen",
"Stesagoras",
"Stesanor",
"Stesilaus",
"Sthenelaus",
"Sthenelus",
"Stichius",
"Stielf",
"Stilicho",
"Stolos",
"Strabo",
"Strachys",
"Strategius",
"Stratios",
"Straton",
"Strophantes",
"Strophius",
"Strymon",
"Su",
"Suatrius",
"Sueridus",
"Sugar",
"Suger",
"Sugoi","Suidbert",
"Suid",
"Sumar",
"Sunericus",
"Sunnia",
"Sunno",
"Suntje",
"Suppo",
"Sustrai",
"Sweert",
"Swikerus",
"Swirt",
"Swittert",
"Syagricus",
"Syagrius",
"Syagros",
"Syennesis",
"Syloson",
"Sylvester",
"Symeon",
"Symeonius",
"Synesius",
"Syriack",
"Syward",
"Sywardus"
};
vector<str> FEMALE_NAMES={"I","Cannot","Find","Any","Yet"};
vector<str> PROFESSIONS={"Archerer","Artist","Armorer","Bomb-Maker","Blacksmith","Farmer","Cleric","Weaponsmith","Warrior","Guard"};
map<str,map<str,str>> PROFESSION_VALS;
map<str,map<str,str>> INVENT;
map<str,str> PREFS;
map<str,str> strings = {
    {"gen:no_npc","No-one here"},
    {"gender:male:pronoun","He"},
    {"gender:female:pronoun","She"},
    {"gender:male:prep","his"},
    {"gender:female:prep","her"},
    {"gender:male:mf","man"},
    {"gender:female:mf","female"},
    {"gender:male:partner","husband"},
    {"gender:female:partner","wife"},
    {"gender:male:many","men"},
    {"gender:female:many","women"},
    {"combat:no_sword","No sword in inventory"},
    {"combat:already_wielding","You are already wielding a sword"},
    {"combat:no_wield","You are not wielding a sword"},
    {"explore:enter_city","You have entered a city"},
    {"explore:exit_city","You have left a city"},
    {"explore:no_in","There is nothing for you to go in"},
    {"explore:go_in","You are going in the cave..."},
    {"explore:miner","In the cave, a $mf miner dripped $pre sweat on you"},
    {"explore:exit_in","You exited to the other side of the cave"},
    {"dip:no_water","There is no water source here"},
    {"dip:sweat","You wash off the sweat in the pond"},
    {"dip:bath","You bathed in the pond"},
    {"look:npc_intro","You see $name, a $mf $profession"},
    {"look:npc_hostile","$prn wants to kill you"},
    {"look:npc_hostile","$prn is following you"},
    {"look:npc_sweat","$prn is sweating"},
    {"look:npc_work","$prn is $work"},
    {"look:npc_angry","$prn looks angry"},
    {"look:npc_none","There is no-one here"},
    {"look:npc_partner","You see your $partner $name"},
    {"look:cave","There is a cave here"},
    {"look:pond","There is a pond here"},
    {"look:city","You are in a city"},
    {"tick:sweat","$name smeared $pre sweat on you"},
    {"tick:night","It is now night"},
    {"tick:day","It is now day"},
    {"tick:death","You are dead!"},
    {"tick:too_many_npcs","All the $mw here smeared and dripped their sweat on you"},
    {"interaction:npc_too_sweat","$prn is too sweaty for you to approach"},
    {"interaction:you_sweat","$name: You smell"},
    {"interaction:sweat_bypass","You somehow manage to approach $pre even when $prn is sweating"},
    {"trade:intro","$prn wants to sell $pre $item for $money coins"},
    {"trade:no","You don't have enough coins to buy from $pre"},
    {"trade:yes","You traded sucessfully with $pre"},
    {"trade:sweat","While trading, $prn dripped $pre sweat on your face"},
    {"trade:night","$prn refuses to trade with you at night"}
    
};
str last_in_city = "0";
void make_terrain(int x, int y);
bool is_generated(int x, int y);
void hit(str s);

vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

std::string rep(std::string subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        try{
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
        }catch(exception e){
            return subject;
        }
    }
    return subject;
}



struct coordinates{
    mutable int X = 0;
    mutable int Y = 0;
} C;


bool NIGHT;
int THOUR; // DAY/NIGHT CYCLER
int TICKS; // TOTAL NUMBER OF TICKS

void print(str st){
    cout << st << endl;
}
void pnl(str st){
    cout << st;
}

str gets(){
    str rval;
    getline(cin,rval);
    return rval;
}
str sandget(str st){
    pnl(st);
    return gets();
}

str itos(int i){
    return to_string(i);
}
void init_h(){
    CHDATA["HEALTH"] = itos(20);
    CHDATA["M_HEALTH"] = itos(20);
    CHDATA["HAPPINESS"] = itos(10000);
    CHDATA["EXP"] = itos(0);
    CHDATA["LVL"] = itos(1);
    CHDATA["SWL"] = itos(0);
    CHDATA["COIN"] = itos(0);
    CHDATA["WIELD"] = itos(0);

    PREFS = {
        {"SMRATE","1"},
        {"TPT","1"},
        {"MINER","1"},
        {"PARTNERSWL","0"},
        {"CAVECHANCE","100"},
        {"PONDCHANCE","100"},
        {"CITYCHANCE","150"},
        {"GENDEROVERRIDE","2"},
        {"MAXNPC","1"}
    };
}

int rnd(int d){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist6(0,d); // distribution in range [1, 6]

    return dist6(rng);
}
str pronoun(bool gen){
    return gen ? strings["gender:male:pronoun"] : strings["gender:female:pronoun"];
}
str preposition(bool gen){
    return gen ? strings["gender:male:prep"] : strings["gender:female:prep"];
}
void pick_stats(){
    CHDATA["GENDER"] = sandget("GENDER (M or F):"); // A lot of uses
    CHDATA["STR"] = sandget("STRENGTH:"); // Attack
    CHDATA["END"] = sandget("ENDURANCE:"); // Defense?
    CHDATA["LUCK"] = sandget("LUCK:"); // Worldgen??
    CHDATA["CHA"] = sandget("CHARISMA:"); // Trade
}
bool gender(){
    if(CHDATA["GENDER"]=="M"){
        return true;
    }else{
        return false;
    }
}
int gval(str stat){
    return stoi(CHDATA[stat]);
}

void npc_generator(int x, int y){
    int city_bonus = (WDATA[x][y].count("CITY"))*25;
    int mgen = (gval("LUCK") / 5);
    if(mgen == 0){mgen = 1;}
    for(int yup = 0; yup < stoi(PREFS["MAXNPC"]) ; yup++) {
    if(rnd(100) < ((8*mgen) + city_bonus)){
        bool gen = (rnd(100) < 50+(gval("LUCK") / 2)) ? !(gender()) : gender();
        str gende = gen ? "1" : "0";
        if(PREFS["GENDEROVERRIDE"] == "1"){
            gende = "1";
        }else if(PREFS["GENDEROVERRIDE"] == "0"){
            gende = "0";
        }
        str name;
        str profession = PROFESSIONS[rnd(PROFESSIONS.size() - 1)];
        str profession_p = PROFESSION_VALS[profession]["P"];
        int cha = 1 + rnd(2) * (gval("LUCK") / 2) ;
        if(gen){
            name = MALE_NAMES[rnd(MALE_NAMES.size() -1)];
        }else{
            name = FEMALE_NAMES[rnd(FEMALE_NAMES.size() -1)];
        }
        WCDATA[x][y].push_back({{"NAME",name},{"HEALTH","100"},{"PROFESSION",profession},{"GENDER",gende},{"HOSTILE","0"},{"COIN","0"},{"P",profession_p},{"SURRENDERED","0"},{"COUPLE","0"},{"LOVE","0"},{"FOLLOW","0"},{"SWL","0"}});
    }
    }
}

void enemy_generator(int x, int y){

}

void feature_generator(int x, int y){
    if(WDATA[x][y].count("FGENDONE") != 0){
        return;
    }
    bool pond = ! (bool) rnd(stoi(PREFS["PONDCHANCE"]));
    bool cave = ! (bool) rnd(stoi(PREFS["CAVECHANCE"]));
    bool sword = ! (bool) rnd(40);
    bool city = ! (bool) rnd(stoi(PREFS["CITYCHANCE"]));

    int tpx = rnd(1500); // for caves
    int tpy = rnd(1500); // for caves

    int city_centrex = x - 25; // for cities
    int city_centrey = y - 25; // for cities

    if(city){ // make cities!!!
        int X = city_centrex;
        int Y = city_centrey;

        for(; X < city_centrex + 30; X++){
            for(; Y < city_centrey + 30; Y++){
                if(X == city_centrex && Y == city_centrey){
                    WDATA[X][Y]["POND"] = "1";
                }else{
                    WDATA[X][Y]["CITY"] = "1";
                }
                WDATA[X][Y]["FGENDONE"] = "1";
            }
        }

        X = city_centrex;
        Y = city_centrey;

        for(; X > city_centrex - 30; X--){
            for(; Y > city_centrey - 30; Y--){
                if(X == city_centrex && Y == city_centrey){
                    WDATA[X][Y]["POND"] = "1";
                    continue;
                }
                WDATA[X][Y]["CITY"] = "1";
                WDATA[X][Y]["FGENDONE"] = "1";
            }
        }
    }else if(cave){
        WDATA[x][y]["CAVE"] = "1";
        WDATA[x][y]["TPX"] = itos(tpx);
        WDATA[x][y]["TPY"] = itos(tpy);

        WDATA[tpx][tpy]["FGENDONE"] = "1";

        WDATA[tpx][tpy]["CAVE"] = "1";
        WDATA[tpx][tpy]["TPX"] = itos(x);
        WDATA[tpx][tpy]["TPY"] = itos(y);
    }else if(pond){
        WDATA[x][y]["POND"] = "1";
    }

    WDATA[x][y]["FGENDONE"] = "1";
}

void inventory_put(str item, int count){
    if(INVENT.count(item) == 0){
        INVENT[item] = {{"COUNT",itos(count)}};
    }else{
        INVENT[item]["COUNT"] = itos( count + stoi(INVENT[item]["COUNT"]) );
    }
}
int inventory_get(str item){
    if(INVENT.count(item) == 0){
        return 0;
    }else{
        return stoi(INVENT[item]["COUNT"]);
    }
}
void inventory_remove(str item, int count){
    if(INVENT.count(item) ==0){return;}
    int cou = stoi(INVENT[item]["COUNT"]);
    if(cou - count <= 0){
        INVENT.erase(item);return;
    }else{
        INVENT[item]["COUNT"] = itos(cou - count);
    }
}
void inventory_transfer_to_world(int x, int y, str item){
    if(inventory_get(item) == 0){return;}
    WIDATA[x][y][item];
    WIDATA[x][y][item]["COUNT"] = INVENT[item]["COUNT"];
    INVENT.erase(item);
}
void inventory_transfer_to_player(int x, int y, str item){
    if(WIDATA[x][y].count(item) == 0){return;}
    if(INVENT.count(item) != 0){
        INVENT[item]["COUNT"] = itos( stoi (INVENT[item]["COUNT"]) + stoi(WIDATA[x][y][item]["COUNT"]));
        return;
    }
    INVENT[item];
    INVENT[item]["COUNT"] =     WIDATA[x][y][item]["COUNT"];
    WIDATA[x][y].erase(item);
}
void equip_sword(){
    if(INVENT.count("Sword") == 0){
        print(strings["combat:no_sword"]);
    }else if (CHDATA["WIELD"] == "1")
    {
        print(strings["combat:already_wielding"]);
    }else
    {
        CHDATA["WIELD"] = "1";
        inventory_remove("Sword",1);
    }
}
void unequip_sword(){
    if(!stoi(CHDATA["WIELD"])){
        print(strings["combat:no_wield"]);
    }else{
        inventory_put("Sword",1);
        CHDATA["WIELD"] = "0";
    }
}
int damage_bonus(){
    return ( (1 * ((stoi(CHDATA["WIELD"])*20)+1)) * ((stoi(CHDATA["STR"])+2)/2));
}

void init_profession_vals(){
    PROFESSION_VALS["Archerer"] = {{"WEAPON","Bow"},{"STRENGTH","10"},{"ITEM","Long bow"},{"S","1"},{"WORK","practising with a long bow"},{"P","5"},{"HOSTILE","0"},{"C","100"}};
    PROFESSION_VALS["Artist"] = {{"WEAPON","Paintbrush"},{"STRENGTH","1"},{"ITEM","Paintbrush"},{"S","0"},{"WORK","painting a picture"},{"P","500"},{"HOSTILE","0"},{"C","20"}};
    PROFESSION_VALS["Armorer"] = {{"WEAPON","Sword"},{"STRENGTH","5"},{"ITEM","A heavy piece of armor"},{"S","1"},{"WORK","making armor"},{"P","10"},{"HOSTILE","0"},{"C","50"}};
    PROFESSION_VALS["Bomb-Maker"] = {{"WEAPON","Bomb"},{"STRENGTH","100"},{"ITEM","Gunpowder"},{"S","0"},{"WORK","making a huge bomb"},{"P","10"},{"HOSTILE","0"},{"C","40"}},
    PROFESSION_VALS["Blacksmith"] = {{"WEAPON","Anvil"},{"STRENGTH","20"},{"ITEM","Anvil"},{"S","1"},{"WORK","making a weapon"},{"P","5"},{"HOSTILE","0"},{"C","200"}};
    PROFESSION_VALS["Farmer"] = {{"WEAPON","Fist"},{"STRENGTH","1"},{"ITEM","Wheat"},{"S","0"},{"WORK","harvesting crops"},{"P","50"},{"HOSTILE","0"},{"C","2"}};
    PROFESSION_VALS["Cleric"] = {{"WEAPON","Quill"},{"STRENGTH","3"},{"ITEM","Book"},{"S","0"},{"WORK","writing a book"},{"P","20"},{"HOSTILE","0"},{"C","40"}};
    PROFESSION_VALS["Weaponsmith"] = {{"WEAPON","Sword"},{"STRENGTH","30"},{"ITEM","Sword"},{"S","1"},{"WORK","making a greatsword"},{"P","6"},{"HOSTILE","0"},{"C","80"}};
    PROFESSION_VALS["Warrior"] = {{"WEAPON","Greatsword"},{"STRENGTH","50"},{"ITEM","Sword"},{"S","1"},{"WORK","practising"},{"P","1"},{"HOSTILE","0"},{"C","1000"}};
    PROFESSION_VALS["Guard"] = {{"WEAPON","Sword"},{"STRENGTH","20"},{"ITEM","Sword"},{"S","1"},{"WORK","guarding"},{"P","5"},{"HOSTILE","0"},{"C",itos(RAND_MAX)}};


    // enemies
    PROFESSION_VALS["Thief"] = {{"WEAPON","Knife"},{"STRENGTH","20"},{"ITEM","Sword"},{"S","1"},{"WORK","counting money"},{"P","5"},{"HOSTILE","1"},{"C","500"}};
    PROFESSION_VALS["Rouge"] = {{"WEAPON","Sword"},{"STRENGTH","50"},{"ITEM","Cloak"},{"S","1"},{"WORK","doing something seceretly"},{"P","5"},{"HOSTILE","1"},{"C","250"}};
    PROFESSION_VALS["Mad Warrior"] = {{"WEAPON","Greatsword"},{"STRENGTH","50"},{"ITEM","Flag"},{"S","1"},{"WORK","roaming around"},{"P","5"},{"HOSTILE","1"},{"C","50"}};
}


// Game behavior and commands

/**         DIRECTIONS
 * 
 *              ^
 *             y+1
 * 
 *     < x-1    -    x+1>
 * 
 *             y-1
 *              v
 * 
 * **/

void movel(str dir){
    if(dir == "north"){
        C.Y++;
    }else if(dir == "south"){
        C.Y--;
    }else if(dir == "east"){
        C.X++;
    }else if(dir == "west"){
        C.X--;
    }else{
        print("unknown direction");
    }
    if(last_in_city == "0" && (bool) WDATA[C.X][C.Y].count("CITY")){
        print(strings["explore:enter_city"]);
    }
    if(last_in_city == "1" && ! (bool) WDATA[C.X][C.Y].count("CITY")){
        print(strings["explore:exit_city"]);
    }
    make_terrain(C.X,C.Y);
    last_in_city = itos((bool) WDATA[C.X][C.Y].count("CITY"));
}

void go_in(){
    int x = C.X;
    int y = C.Y;
    if(! (bool) WDATA[x][y].count("CAVE")){
        print(strings["explore:no_in"]);
        return;
    }else{
        bool gen = (bool) ! (bool) gender();
        string mf = gen ? strings["gender:male:mf"] : strings["gender:female:mf"];
        str pre = preposition(gen);
        print(strings["explore:go_in"]);
        int times = (rnd(4)+1)*stoi(PREFS["MINER"]);
        int u;
        for(u = 0; u < times; u++){
            print(rep(rep(strings["explore:miner"],"$mf",mf),"$pre",pre));
            CHDATA["SWL"] = "1";
        }
        // tp player to exit

        C.X = stoi(WDATA[x][y]["TPX"]);
        C.Y = stoi(WDATA[x][y]["TPY"]);

        // tp followers to exit
        int h;
        for(h = 0; h < WCDATA[x][y].size(); h++){
            map<str,str> npc = WCDATA[x][y][h];
            if(!!stoi(npc["FOLLOW"])){
                WCDATA[C.X][C.Y].push_back(npc);
                WCDATA[x][y].erase(WCDATA[x][y].begin() + h);
            }
        }

        print(strings["explore:exit_in"]);

    }
}

void dip(){
    if(! (bool) WDATA[C.X][C.Y].count("POND")){
        print(strings["dip:no_water"]);
        return;
    }else{
        if((bool) stoi(CHDATA["SWL"])){
            print(strings["dip:sweat"]);
            CHDATA["SWL"] = "0";
        }else{
            print(strings["dip:bath"]);
        }
    }
}

/*
 *          LOOK
 *  HP: health HAPPY: happyness
 *  X: x Y:y
 *  NPCS...
 *      Yosee <name>,a <gender> <profession>
 *      if hostile: <genderpronoun> wants to kill yo
 *      else if not COUPLE:
 * 
 * **/
void look(bool minified = false){
    int x = C.X;
    int y = C.Y;
    str result = "";

    if(!minified){
        result+= "HP: "+(itos(gval("HEALTH")));
        result+= " HAPPY: "+CHDATA["HAPPINESS"]+"\n";
        result+= "X: "+itos(x)+" Y:"+itos(y)+" COIN:"+CHDATA["COIN"]+"\n";
    }
    bool npcexist = (bool) WCDATA[x][y].size();
    if (npcexist){
        for(map<str,str> npc : WCDATA[x][y]){
            str name = npc["NAME"];
            bool gen = (bool) stoi(npc["GENDER"]);
            bool couple = (bool) stoi(npc["COUPLE"]);
            string mf = gen ? strings["gender:male:mf"] : strings["gender:female:mf"];
            str prn = pronoun(gen);
            string pre = preposition(gen);
            str profession = npc["PROFESSION"];
            str profession_item = PROFESSION_VALS[profession]["ITEM"];
            bool profession_s = (bool) stoi(PROFESSION_VALS[profession]["S"]);
            str profession_work = PROFESSION_VALS[profession]["WORK"];
            int pa = stoi(npc["P"]);
            string hubby = (gen ? strings["gender:male:partner"] : strings["gender:female:partner"]);


            if(!!stoi(npc["HOSTILE"])){
                result += (rep(rep(rep(strings["look:npc_intro"],"$mf",mf),"$name",name),"$profession",profession))+"\n";
                result+= rep(strings["look:npc_hostile"],"$prn",prn);
            }else if(!couple){
                result += rep(rep(rep(rep(strings["look:npc_intro"],"$mf",mf),"$name",name),"$profession",profession),"$pre",pre)+"\n";
                if(!!stoi(npc["FOLLOW"])){
                    result +=rep(rep(strings["look:npc_follow"],"$prn",prn),"$pre",pre)+"\n";
                }
                if(profession_s && !NIGHT){

                    result+=rep(rep(strings["look:npc_sweat"],"$prn",prn),"$pre",pre)+"\n";
                }
                if(!NIGHT){
                    result+=rep(rep(rep(strings["look:npc_work"],"$prn",prn),"$work",profession_work),"$pre",pre)+"\n";
                }
                if(pa < 2){
                    result+=rep(rep(strings["look:npc_angry"],"$prn",prn),"$pre",pre)+"\n";
                }
            }else if(couple){
                result += rep(rep(rep(strings["look:npc_partner"],"$prn",prn),"$partner",hubby),"$name",name)+"\n";
                if(!!stoi(npc["FOLLOW"])){
                    result +=rep(rep(strings["look:npc_follow"],"$prn",prn),"$pre",pre)+"\n";
                }
            }
        }
    }else{
        result += strings["look:npc_none"]+"\n";
    }

    // items:

    for( auto const& iy : WIDATA[x][y] )
    {   
        //int itemc;
        int itemc;
        
        itemc = stoi(WIDATA[x][y][iy.first]["COUNT"]);
        
        if(itemc == 1){
            result+="There is a "+iy.first + " here.\n";
        }else{
            result += "There are "+itos(itemc)+" "+iy.first+"s here\n";
        }
    }

    // features (city,pond,cave)

    if((bool) WDATA[x][y].count("CAVE")){
        result+=strings["look:cave"]+"\n";
    }

    if((bool) WDATA[x][y].count("POND")){
        result+=strings["look:pond"]+"\n";
    }
    if((bool) WDATA[x][y].count("CITY")){
        if(!minified){
            result+=strings["look:city"]+"\n";
        }
    }



    print(result);
}

void map_maker(){
    struct map_marker{
        str UNINIT = "\x1B[1;33m?\033[0m";
        str NOTHING = "\x1B[1;37m.\033[0m";
        str POND = "\x1B[1;36m(\033[0m";
        str CAVE = "\x1B[1;30m[\033[0m";
        str PERSON = "\x1B[1;31m$\033[0m";
        str YOU = "\x1B[1;35m#\033[0m";
    } M;
    str map_str = "";
    int xcounter = C.X - 20;
    int ycounter = C.Y + 20;

    for(; ycounter > C.Y - 20; ycounter--){
        for(xcounter = C.X - 20; xcounter < (C.X + 20); xcounter++ ){
            if(!is_generated(xcounter,ycounter)){
                map_str+=M.UNINIT+" ";
            }
            else if(C.X == xcounter && C.Y == ycounter){
                map_str+=M.YOU+" ";
            }
            else if((bool) WDATA[xcounter][ycounter].count("CAVE")){
                map_str+=M.CAVE+" ";
            }else if((bool) WDATA[xcounter][ycounter].count("POND")){
                map_str+=M.POND+ " ";
            }else if(WCDATA[xcounter][ycounter].size() != 0){
                map_str+=M.PERSON+ " ";
            }else{
                map_str += M.NOTHING+ " ";
            }
        }
        map_str+="\n";
    }
    print("X: "+itos(C.X)+", Y:"+itos(C.Y));
    print(map_str);
}

/**         TICKING
 * 
 * 
 * 
 * 
 * **/

void tickxy(int x, int y){
    if(! is_generated(x,y)){
        return;
    }
    size_t h;
    if(C.X != x || C.Y != y){ // Different cell

        for(h = 0; h < WCDATA[x][y].size(); h++){
            map<str,str> npc = WCDATA[x][y][h];
            //print("test 1");
            if(!!stoi(npc["HOSTILE"]) || !!stoi(npc["FOLLOW"])){
                vector<map<str,str>>::iterator it;
                it = WCDATA[x][y].begin();
                int yo;
                for(yo =0; yo <= h; yo++){
                    it++;
                }
                WCDATA[x][y].erase(it);
                WCDATA[C.X][C.Y].push_back(npc);
            }
            //print("test 2");
        }
    }else{ // same cell
        if(!NIGHT){
        for(h = 0; h < WCDATA[x][y].size(); h++){
            map<str,str> npc = WCDATA[x][y][h];
            bool gen = (bool) stoi(npc["GENDER"]);
            bool couple = (bool) stoi(npc["COUPLE"]);
            str profession = npc["PROFESSION"];


            str profession_item = PROFESSION_VALS[profession]["ITEM"];




            bool profession_s = (bool) stoi(PROFESSION_VALS[profession]["S"]);
            str prn = pronoun(gen);
            str pre = preposition(gen);
            if((rnd(15) < (2 * stoi(PREFS["SMRATE"])))&& !couple && gen != (bool) gender() && profession_s && !(bool) WDATA[x][y].count("CITY")){
                CHDATA["SWL"] = "1";
                print(rep(rep(rep(strings["tick:sweat"],"$name",npc["NAME"]),"$pre",pre),"$prn",prn));
            }
        }
        }
    }

    // TODO: multi couple test
}
void global_ticki(){
    int x = C.X;
    int y = C.Y;

    TICKS+=stoi(PREFS["TPT"]);

    // tick time

    THOUR = TICKS % 101;
    if(!NIGHT && THOUR > 50){
        print(strings["tick:night"]);
        NIGHT = true;
    }
    if(NIGHT && THOUR < 50){
        print(strings["tick:day"]);
        NIGHT = false;
    }

    // tick the enemies
    int opposite_npcs = 0;
    int c;
    for(c = 0; c < WCDATA[x][y].size();c++){
        map<str,str> npc = WCDATA[x][y][c];
        int ttttt = stoi(npc["P"]);
        if(ttttt <= 0){
            npc["HOSTILE"] = "1";
            WCDATA[x][y][c]["HOSTILE"] = "1";
            WCDATA[x][y][c]["COUPLE"] = "0";
            WCDATA[x][y][c]["FOLLOW"] = "0";
        }
        bool gen = (bool) stoi(npc["GENDER"]);
        if(gen != gender()){
            opposite_npcs++;
        }
        if(!!! stoi( npc["HOSTILE"] )){ // Explicit bool conversion + negation
            continue;
        }
        
        
        bool couple = (bool) stoi(npc["COUPLE"]);
        str profession = npc["PROFESSION"];
        str profession_weapon = PROFESSION_VALS[profession]["WEAPON"];
        bool profession_s = (bool) stoi(PROFESSION_VALS[profession]["S"]);
        str prn = pronoun(gen);
        str pre = preposition(gen);
        int strength = stoi(PROFESSION_VALS[profession]["STRENGTH"]);
        int health = stoi(CHDATA["HEALTH"]);
        int loss = strength-(stoi(CHDATA["END"]));
        int enemy_loss = 0;

        // followers attack
            int d;
            for(d = 0; d < WCDATA[x][y].size();d++){
                map<str,str> _npc = WCDATA[x][y][d];
                str _profession = _npc["PROFESSION"];
                int _strength = stoi(PROFESSION_VALS[_profession]["STRENGTH"]);
                if(!!! stoi(_npc["FOLLOW"])){
                    continue;
                }
                print(_npc["NAME"]+" attacks "+npc["NAME"]);
                enemy_loss += _strength;
            }
        // -------------

        print(npc["NAME"]+" hits you with "+pre+" "+profession_weapon+" for "+itos(loss)+" hit points");
            if(rnd(3) < 2 && !couple && gen != (bool) gender() && profession_s){
                CHDATA["SWL"] = "1";
                print(npc["NAME"]+" smeared "+pre+" sweat on you while attacking");
            }
        CHDATA["HEALTH"] = itos(health-loss);
        WCDATA[x][y][c]["HEALTH"] = itos( stoi(WCDATA[x][y][c]["HEALTH"]) - enemy_loss);
        if( stoi (WCDATA[x][y][c]["HEALTH"]) <= 0){
            //WCDATA[x][y][c]["NAME"] = npc["NAME"]+"_";
            //hit(npc["NAME"]+"_");
        }

    }

    if(opposite_npcs > 4){
        str mw = (!gender()) ? strings["gender:male:many"] : strings["gender:female:many"];
        CHDATA["SWL"] = "1";
        print(rep(strings["tick:too_many_npcs"],"$mw",mw));
    }

    // tick the cells
    //print("testing 123");
    tickxy(x,y);
    tickxy(x-1,y);
    tickxy(x+1,y);
    tickxy(x,y-1);
    tickxy(x,y+1);
    tickxy(x-1,y-1);
    tickxy(x-1,y+1);
    tickxy(x+1,y+1);
    tickxy(x+1,y-1);
    //print("testing 123");
    // recalc health and happiness
    //print("testing 123");
    if(stoi(CHDATA["HEALTH"]) <= 0){
        print(strings["tick:death"]);
        _Exit(999);
    }else if(stoi(CHDATA["HAPPINESS"]) <= 0){
        print("You kill yourself");
        _Exit(999);
    }
}

/**         ATTACKING
 * 
 * 
 * 
 * 
 * 
 * **/

void hit(str nname = "NOnAMe"){
    locale loc;
    int x = C.X;
    int y = C.Y;
    if(WCDATA[x][y].size() == 0){
        print(strings["gen:no_npc"]);
        return;
    }
    string targetname;
    if(WCDATA[x][y].size() == 1){
        targetname = WCDATA[x][y][0]["NAME"];
    }else{
        if(nname == "NOnAMe"){
            targetname = sandget("Name Target:");
        }else{
            targetname = nname;
        }
    }

    bool found_target = false;
    int k ;
    for(k = 0; k < WCDATA[x][y].size(); k++){ // Standard NPC iterator!!!
        map<str,str> npc = WCDATA[x][y][k];
        //print("test 123");
        if(npc["NAME"] == targetname){
            //print("test 123");
            found_target = true;

            str name = npc["NAME"];
            ;
            bool gen = stoi(npc["GENDER"]);
            //bool couple = (bool) stoi(npc["COUPLE"]);

            str prn = pronoun(gen);
            str profession = npc["PROFESSION"];
            str profession_item = PROFESSION_VALS[profession]["ITEM"];
            bool profession_s = stoi(PROFESSION_VALS[profession]["S"]);
            str profession_work = PROFESSION_VALS[profession]["WORK"];
            int pa = stoi(npc["P"]);
            //string hubby = (gen ? "husband" : "wife");
            int life = stoi(npc["HEALTH"]);

            //print("You are attacking "+name+"."+prn+" is getting angry");

            WCDATA[x][y][k]["HOSTILE"] = "1"; // Hostile
            WCDATA[x][y][k]["FOLLOW"] = "0"; // Not a follower
            WCDATA[x][y][k]["COUPLE"] = "0"; // Not a partner
            WCDATA[x][y][k]["LOVE"] = "0"; // No love

            bool has_sword = (bool) stoi(CHDATA["WIELD"]);
            string wep = has_sword ? "Sword" : "Fist";

            int attdam = damage_bonus();

            life-=attdam;

            if(life <= 0){ // Dead
                WCDATA[x][y].erase(WCDATA[x][y].begin() + (k));

                print(prn+" is dead");
                print(prn+" dropped "+preposition(gen)+" "+profession_item);
                WIDATA[x][y][profession_item];
                WIDATA[x][y][profession_item]["COUNT"] = itos(1);
                CHDATA["COIN"] = itos(stoi(npc["COIN"]) + 10 + stoi(CHDATA["COIN"]));
            }else{ // Weakened
                WCDATA[x][y][k]["HEALTH"] = itos(life);
                print("You hit "+preposition(gen)+" for "+itos(attdam)+" health");
            }
        }else{
            continue;
        }
    }
    if(!found_target){
        print("Cannot find target");
        look(true);
    }
}

/**         INVENTORY MANAGEMENT
 * 
 * 
 * 
 * 
 * **/

void take(str what = "nPoS"){
    if(what =="nPoS"){
        what = sandget("Name Item");
    }
    int x = C.X;
    int y = C.Y;

    inventory_transfer_to_player(x,y,what);
}

void drop(str what = "nPoS"){
    if(what =="nPoS"){
        what = sandget("Name Item");
    }
    int x = C.X;
    int y = C.Y;

    inventory_transfer_to_world(x,y,what);
    print("You dropped "+what);
}

//  // / /  / //           //// // /  / / / // /  / // //// // // //  / / / / // / / / / l

void wield(){
    equip_sword();
}
void unwield(){
    unequip_sword();
}

void inventory_look(){
    for( auto const& iy : INVENT )
    {   
        //int itemc;
        int itemc;
        
        itemc = stoi(INVENT[iy.first]["COUNT"]);
        
        if(itemc == 1){
            print("You have a "+iy.first);
        }else{
            print("You have "+itos(itemc)+" "+iy.first+"s");
        }
    }
}

/**         ROMANCE AND LOVE
 * 
 * 
 *  TALK, HUG, ROMANCE, FOLLOW, UNFOLLOW
 * 
 * 
 * **/

void talk(string nname = "NOnAMe"){
    int x = C.X;
    int y = C.Y;
    if(WCDATA[x][y].size() == 0){
        print(strings["gen:no_npc"]);
        return;
    }
    string targetname;
    if(WCDATA[x][y].size() == 1){
        targetname = WCDATA[x][y][0]["NAME"];
    }else{
        if(nname == "NOnAMe"){
            targetname = sandget("Name Person:");
        }else{
            targetname = nname;
        }
    }

    int k ;
    for(k = 0; k < WCDATA[x][y].size(); k++){ // Standard NPC iterator!!!
        map<str,str> npc = WCDATA[x][y][k];
        if(npc["NAME"] == targetname){
            str name = npc["NAME"];
            bool gen = (bool) stoi(npc["GENDER"]);
            bool couple = (bool) stoi(npc["COUPLE"]);
            str prn = pronoun(gen);
            str profession = npc["PROFESSION"];
            str profession_item = PROFESSION_VALS[profession]["ITEM"];
            bool profession_s = (bool) stoi(PROFESSION_VALS[profession]["S"]);
            str profession_work = PROFESSION_VALS[profession]["WORK"];
            int pa = stoi(npc["P"]);
            int love = stoi(npc["LOVE"]);
            string hubby = (gen ? "husband" : "wife");
            bool you_s = stoi(CHDATA["SWL"]);
            bool you_g = gender();
            int you_ch = stoi(CHDATA["CHA"]);

            if(!!stoi(npc["HOSTILE"])){
                print(prn+" is not in the mood to talk");
                return;
            }

            if(!couple){
                if(profession_s && !NIGHT && !(you_ch >= 10)){
                    print(rep(strings["interaction:npc_too_sweat"],"$prn",prn));
                    return;
                }else if(!profession_s && !NIGHT && !(love > 20)){
                    print(name+": Can't you see I am doing something right now!");
                    return;
                }else{ // not a partner, night || love > 20 || not_s

                    if(gen == you_g){
                        print("You talk for sometime...");
                        return;
                    }
                    if((you_s && !(love > 40)) && you_ch < 9 ){
                        print(rep(rep(strings["interaction:you_sweat"],"prn",prn),"$name",name));
                        return;
                    }
                    if(!NIGHT && profession_s){
                        print(rep(rep(rep(strings["interaction:sweat_bypass"],"$pre",preposition(gen)),"$name",name),"$prn",prn));
                    }
                    print(name+": Let's talk...");
                    if(!NIGHT && profession_s){
                        print(prn+" drips "+preposition(gen)+" sweat on you while talking");
                        CHDATA["SWL"] = "1";
                    }
                    print("You finished talking");
                    WCDATA[x][y][k]["LOVE"] = itos(love+(2 * (you_ch+1)));
                    return;
                }
            }else{ // couple, no need for restiction
                print(name+": Lets talk dear");
                print("You finished talking");
                return;
            }

        }
    }
}

void hug(string nname = "NOnAMe"){ // huggy!!!!!
    int x = C.X;
    int y = C.Y;
    if(WCDATA[x][y].size() == 0){
        print(strings["gen:no_npc"]);
        return;
    }
    string targetname;
    if(WCDATA[x][y].size() == 1){
        targetname = WCDATA[x][y][0]["NAME"];
    }else{
        if(nname == "NOnAMe"){
            targetname = sandget("Name Person:");
        }else{
            targetname = nname;
        }
    }

    int k ;
    for(k = 0; k < WCDATA[x][y].size(); k++){ // Standard NPC iterator!!!
        map<str,str> npc = WCDATA[x][y][k];
        if(npc["NAME"] == targetname){
            str name = npc["NAME"];
            bool gen = (bool) stoi(npc["GENDER"]);
            bool couple = (bool) stoi(npc["COUPLE"]);
            str prn = pronoun(gen);
            str profession = npc["PROFESSION"];
            str profession_item = PROFESSION_VALS[profession]["ITEM"];
            bool profession_s = (bool) stoi(PROFESSION_VALS[profession]["S"]);
            str profession_work = PROFESSION_VALS[profession]["WORK"];
            int pa = stoi(npc["P"]);
            int love = stoi(npc["LOVE"]);
            string hubby = (gen ? "husband" : "wife");
            bool you_s = stoi(CHDATA["SWL"]);
            bool you_g = gender();
            int you_ch = stoi(CHDATA["CHA"]);

            if(!!stoi(npc["HOSTILE"])){
                print(prn+" is not in the mood to hug you");
                return;
            }

            if(!couple){
                if(profession_s && !NIGHT && !(you_ch >= 10)){
                    print(rep(strings["interaction:npc_too_sweat"],"$prn",prn));
                    return;
                }else if(!(love > 100 || you_ch >= 20)){
                    print(name+": How dare you try to hug me!");
                    WCDATA[x][y][k]["P"] = itos(stoi(npc["P"]) - 1);
                    return;
                }else{ // not a partner, night || love > 20 || not_s

                    if(gen == you_g){
                        print(name+": Are you a gay?!?!");
                        return;
                    }
                    if((you_s && !(love > 140)) && you_ch < 19 ){
                        print(rep(rep(strings["interaction:you_sweat"],"prn",prn),"$name",name));
                        return;
                    }
                    if(!NIGHT && profession_s){
                        print(rep(rep(rep(strings["interaction:sweat_bypass"],"$pre",preposition(gen)),"$name",name),"$prn",prn));
                    }
                    print(name+": Let's hug...");
                    if(!NIGHT && profession_s){
                        print(preposition(gen)+" sweat is all over your body");
                        CHDATA["SWL"] = "1";
                    }
                    print("You finished hugging");
                    WCDATA[x][y][k]["LOVE"] = itos(love+(10 * (you_ch+1)));
                    return;
                }
            }else{ // couple, no need for restiction
                print(name+": Lets hug dear");
                print("You finished hugging");
                return;
            }

        }
    }
}

void romance(string nname = "NOnAMe"){ // huggy!!!!!
    int x = C.X;
    int y = C.Y;
    if(WCDATA[x][y].size() == 0){
        print(strings["gen:no_npc"]);
        return;
    }
    string targetname;
    if(WCDATA[x][y].size() == 1){
        targetname = WCDATA[x][y][0]["NAME"];
    }else{
        if(nname == "NOnAMe"){
            targetname = sandget("Name Person:");
        }else{
            targetname = nname;
        }
    }

    int k ;
    for(k = 0; k < WCDATA[x][y].size(); k++){ // Standard NPC iterator!!!
        map<str,str> npc = WCDATA[x][y][k];
        if(npc["NAME"] == targetname){
            str name = npc["NAME"];
            bool gen = (bool) stoi(npc["GENDER"]);
            bool couple = (bool) stoi(npc["COUPLE"]);

            str prn = pronoun(gen);
            str profession = npc["PROFESSION"];
            str profession_item = PROFESSION_VALS[profession]["ITEM"];
            bool profession_s = (bool) stoi(PROFESSION_VALS[profession]["S"]);
            str profession_work = PROFESSION_VALS[profession]["WORK"];
            int pa = stoi(npc["P"]);
            int love = stoi(npc["LOVE"]);
            string hubby = (gen ? "husband" : "wife");
            bool you_s = stoi(CHDATA["SWL"]);
            bool you_g = gender();
            int you_ch = stoi(CHDATA["CHA"]);

            if(!!stoi(npc["HOSTILE"])){
                print(prn+" is not in the mood to hug you");
                return;
            }

            if(!couple){
                if(!(love > 500)){
                    print(name+": How dare you say that!");
                    WCDATA[x][y][k]["P"] = itos(stoi(npc["P"]) - 100);
                    return;
                }else{ // not a pxartner, night || love > 20 || not_s

                    if(gen == you_g){
                        print(name+": Are you a gay?!?!");
                        return;
                    }
                    if(!NIGHT && profession_s){
                        print(rep(rep(rep(strings["interaction:sweat_bypass"],"$pre",preposition(gen)),"$name",name),"$prn",prn));
                    }
                    print(name+": Let us marry...");
                    if(!NIGHT && profession_s){
                        print(preposition(gen)+" sweat is all over your body");
                        CHDATA["SWL"] = "1";
                    }
                    print(prn+" is now your "+hubby);
                    WCDATA[x][y][k]["LOVE"] = itos(love+(10 * (you_ch+1)));
                    CHDATA["HAPPINESS"] = itos(stoi(CHDATA["HAPPINESS"]) + 10000);
                    WCDATA[x][y][k]["COUPLE"] = "1";
                    return;
                }
            }else{ // couple, no need for restiction
                print(name+": Let's do that a little later");
                print("(protip: a partner can only be romanced once. get a new one)");
                return;
            }

        }
    }
}

void follow(string nname = "NOnAMe"){ // huggy!!!!!
    int x = C.X;
    int y = C.Y;
    if(WCDATA[x][y].size() == 0){
        print(strings["gen:no_npc"]);
        return;
    }
    string targetname;
    if(WCDATA[x][y].size() == 1){
        targetname = WCDATA[x][y][0]["NAME"];
    }else{
        if(nname == "NOnAMe"){
            targetname = sandget("Name Person:");
        }else{
            targetname = nname;
        }
    }

    int k ;
    for(k = 0; k < WCDATA[x][y].size(); k++){ // Standard NPC iterator!!!
        map<str,str> npc = WCDATA[x][y][k];
        if(npc["NAME"] == targetname){
            str name = npc["NAME"];
            bool gen = (bool) stoi(npc["GENDER"]);
            bool couple = (bool) stoi(npc["COUPLE"]);

            str prn = pronoun(gen);
            str profession = npc["PROFESSION"];
            str profession_item = PROFESSION_VALS[profession]["ITEM"];
            bool profession_s = (bool) stoi(PROFESSION_VALS[profession]["S"]);
            str profession_work = PROFESSION_VALS[profession]["WORK"];
            int pa = stoi(npc["P"]);
            int love = stoi(npc["LOVE"]);
            string hubby = (gen ? "husband" : "wife");
            bool you_s = stoi(CHDATA["SWL"]);
            bool you_g = gender();
            int you_ch = stoi(CHDATA["CHA"]);

            if(!!stoi(npc["HOSTILE"])){
                print(prn+" is not in the mood to hug you");
                return;
            }

            if(!couple){
                if(profession_s && !NIGHT && !(you_ch >= 10)){
                    print(rep(strings["interaction:npc_too_sweat"],"$prn",prn));
                    return;
                }else if(!(love > 50 || you_ch >= 20)){
                    print(name+": Why should I follow you?");
                    return;
                }else{ // not a partner, night || love > 20 || not_s


                    if((you_s && !(love > 140)) && you_ch < 19 ){
                        print(rep(rep(strings["interaction:you_sweat"],"prn",prn),"$name",name));
                        return;
                    }
                    if(!NIGHT && profession_s){
                        print(rep(rep(rep(strings["interaction:sweat_bypass"],"$pre",preposition(gen)),"$name",name),"$prn",prn));
                    }
                    print(name+": I am following you...");
                    WCDATA[x][y][k]["FOLLOW"] = "1";
                    return;
                }
            }else{ // couple, no need for restiction
                print(name+": I am following you...");
                WCDATA[x][y][k]["FOLLOW"] = "1";
                return;
            }

        }
    }
}

void unfollow(string nname = "NOnAMe"){ // huggy!!!!!
    int x = C.X;
    int y = C.Y;
    if(WCDATA[x][y].size() == 0){
        print(strings["gen:no_npc"]);
        return;
    }
    string targetname;
    if(WCDATA[x][y].size() == 1){
        targetname = WCDATA[x][y][0]["NAME"];
    }else{
        if(nname == "NOnAMe"){
            targetname = sandget("Name Person:");
        }else{
            targetname = nname;
        }
    }

    int k ;
    for(k = 0; k < WCDATA[x][y].size(); k++){ // Standard NPC iterator!!!
        map<str,str> npc = WCDATA[x][y][k];
        if(npc["NAME"] == targetname){
            str name = npc["NAME"];
            bool gen = (bool) stoi(npc["GENDER"]);
            bool couple = (bool) stoi(npc["COUPLE"]);

            str prn = pronoun(gen);
            if(!!stoi(npc["HOSTILE"])){
                print(prn+" is not following you");
                return;
            }
            if(stoi(npc["FOLLOW"])){
                print(name+": I'll stay here");
                WCDATA[x][y][k]["FOLLOW"] = "0";
            }else{
                print(name+": I'm not following you!");
            }

        }
    }
}

/** - -----       TRADE AND MORE.
 * ---
 *  ---    TRADE, FAVOR
 * ---
 * ---
 * :::::::::::::::::::::
*/

void trade(string nname = "NOnAMe"){ // huggy!!!!!
    int x = C.X;
    int y = C.Y;
    if(WCDATA[x][y].size() == 0){
        print(strings["gen:no_npc"]);
        return;
    }
    string targetname;
    if(WCDATA[x][y].size() == 1){
        targetname = WCDATA[x][y][0]["NAME"];
    }else{
        if(nname == "NOnAMe"){
            targetname = sandget("Name Person:");
        }else{
            targetname = nname;
        }
    }

    int k ;
    for(k = 0; k < WCDATA[x][y].size(); k++){ // Standard NPC iterator!!!
        map<str,str> npc = WCDATA[x][y][k];
        if(npc["NAME"] == targetname){
            bool gen = (bool) stoi(npc["GENDER"]);
            str prn = pronoun(gen);
            str pre = preposition(gen);
            str name = npc["NAME"];
            str profession = npc["PROFESSION"];
            str profession_item = PROFESSION_VALS[profession]["ITEM"];
            bool profession_s = stoi(PROFESSION_VALS[profession]["S"]);
            int _s = (((int)profession_s) * 50);
            int you_coin = stoi(CHDATA["COIN"]);
            int chr = stoi(CHDATA["CHA"])*2;

            int price = (50 - chr) + _s;

            if(NIGHT){
                print(rep(rep(strings["trade:night"],"$prn",prn),"$pre","$pre"));
                return;
            }
            // $prn wants to sell $pre $item for $money coins
            // You don't have enough coins/ You have purchaced $item from $pre
            print(rep(rep(rep(rep(strings["trade:intro"],"$prn",prn),"$pre",pre),"$item",profession_item),"$money",itos(price)));
            if(you_coin < price){
                print(rep(rep(strings["trade:no"],"$pre",pre),"$prn",prn));
                return;
            }else{
                if(profession_s && gen != gender()){
                    print(rep(rep(strings["trade:sweat"],"$pre",pre),"$prn",prn));
                    CHDATA["SWL"] = "1";
                }
                WCDATA[x][y][k]["COIN"] = itos(stoi(npc["COIN"]) + price);
                CHDATA["COIN"] = itos(stoi(CHDATA["COIN"]) - price);
                inventory_put(profession_item, 1);
                print(rep(rep(strings["trade:yes"],"$pre",pre),"$prn",prn));
            }
        }
    }
}

/**         LEVEL GENERATION
 * 
 * 
 * 
 * 
 * 
 * 
 * **/
//

bool is_generated(int x, int y){
    if(WCDATA.count(x) == 1){
        if(WCDATA[x].count(y) == 1){
            return true;
        }
    }
    return false;
}

void make_terrain(int x, int y){
    if(is_generated(x,y)){
        look(true);
        return;
    }
    if(WDATA.count(x) == 0){
        WDATA[x];
        WCDATA[x];
        WIDATA[x];
    }
    if(WDATA[x].count(y) == 0){
        WDATA[x][y];
        WCDATA[x][y];
        WIDATA[x][y];
    }
    feature_generator(x,y);
    npc_generator(x,y);
    enemy_generator(x,y);
    look(true);
}

/**         DEBUGGING
 * 
 * 
 * 
 * **/

void mkworld(){
    int offset = 0x250;
    int minx = C.X - offset;
    int miny = C.Y - offset;
    int maxx = C.X + offset;
    int maxy = C.Y + offset;
    int xptr;
    int yptr;
    for(xptr=minx;xptr<maxx;xptr++){
        for(yptr=miny;yptr<maxy;yptr++){
            make_terrain(xptr,yptr);
        }
    }
    print("Done");
}

void tp(str x,str y){
    int xn, yn_;
    try{
        xn = stoi(x);
        yn_ = stoi(y);
    }catch(exception e){
        return;
    }
    C.X = xn;
    C.Y = yn_;
    look();
}

void rmworld(){
    map<int,map<int,map<str,str>>> wdata;
    map<int,map<int,vector<map<str,str>>>> wcdata;
    map<int,map<int,map<str,map<str,str>>>> widata;

    WDATA = wdata;
    WCDATA = wcdata;
    WIDATA = widata;
}

void professionadd(str name,str item,str weapon,str strength,str swl){
    PROFESSION_VALS[name] = {{"ITEM",item},{"STRENGTH",strength},{"WEAPON",weapon},{"WORK","doing something"},{"S",swl},{"HOSTILE","0"},{"C","10"},{"P","10"}};
}
void professionstore(str name){
    PROFESSIONS.push_back(name);
}
void addnpc(str name, str profession, str gender){
    WCDATA[C.X][C.Y].push_back({{"HEALTH","100"} , {"COUPLE","0"}, {"P","30"}, {"NAME",name}, {"PROFESSION",profession}, {"GENDER",gender}, {"FOLLOW","0"}, {"LOVE","0"}, {"HOSTILE","0"},{"COIN","0"} });
}
void npcedit(str prop,str val){
    if(WCDATA[C.X][C.Y].size() == 0){
        return;
    }
    WCDATA[C.X][C.Y][0][prop] = val;
}
void playeredit(str prop, str val){
    CHDATA[prop] = val;
}
void propedit(str prop,str val){
    PREFS[prop] = val;
}
void stringedit(vector<str> args){
    if(args.size() == 1 || args.size() == 2){
        return;
    }
    str prop = args[1];
    str val = rep(args[2],"_"," ");
    strings[prop]= val;   
}
void gennpc(){
    npc_generator(C.X,C.Y);
}
void featureadd(str feature){
    WDATA[C.X][C.Y][feature] = "1";
    if(feature == "CAVE"){
        WDATA[C.X][C.Y]["TPX"] = itos(C.X);
        WDATA[C.X][C.Y]["TPY"] = itos(C.Y);
    }
}
void featureremove(str feature){
    WDATA[C.X][C.Y].erase(feature);
}
void wipenames(str gender){
    if(gender == "1"){
        MALE_NAMES = {};
    }else{
        FEMALE_NAMES = {};
    }
}
void wipeprofessions(){
    PROFESSIONS = {};
}
void pushname(str name,str gender){
    if(gender == "1"){
        MALE_NAMES.push_back(name);
    }else{
        FEMALE_NAMES.push_back(name);
    }
}

/**         COMMAND PARSER
 * 
 * 
 * 
 * **/


void cmd_parser(str cmdn){ // command parser
    vector<str> args = split(cmdn," ");
    if(args.size() == 0){
        return;
    }
    str cmd = args[0];
    if(cmd == "n"){
        movel("north");
    } else if(cmd == "s"){
        movel("south");
    } else if(cmd == "e"){
        movel("east");
    } else if(cmd == "w"){
        movel("west");
    } else if(cmd == "look"){
        look();
    } else if (cmd == "wait"){
        ;;;
    } else if(cmd == "hit" || cmd == "kill"){
        if(args.size() == 2){
            hit(args[1]);
            return;
        }
        hit();
    }else if(cmd == "take"){
        if(args.size() == 2){
            take(args[1]);
            return;
        }
        take();
    }else if(cmd == "drop"){
        if(args.size() == 2){
            drop(args[1]);
            return;
        }
        drop();
    }else if(cmd == "wield"){
        wield();
    }else if(cmd == "unwield"){
        unwield();
    }else if(cmd == "i"){
        inventory_look();
    }else if(cmd == "talk"){
        if(args.size() == 2){
            talk(args[1]);
            return;
        }
        talk();
    }else if(cmd == "hug"){
        if(args.size() == 2){
            hug(args[1]);
            return;
        }
        hug();
    }else if(cmd == "romance"){
        if(args.size() == 2){
            romance(args[1]);
            return;
        }
        romance();
    }else if(cmd == "follow"){
        if(args.size() == 2){
            follow(args[1]);
            return;
        }
        follow();
    }else if(cmd == "unfollow"){
        if(args.size() == 2){
            unfollow(args[1]);
            return;
        }
        unfollow();
    }else if(cmd == "in"){
        go_in();
    }else if(cmd == "dip"){
        dip();
    }else if(cmd == "map"){
        map_maker();
    }else if(cmd == "trade"){
        if(args.size() == 2){
            trade(args[1]);
            return;
        }
        trade();
    }
    
    else { // debug commands
        if(cmd == "mkworld"){
            mkworld();
        }else if(cmd == "tp"){
            tp(args[1],args[2]);
        }else if(cmd == "rmworld"){
            rmworld();
        }else if(cmd == "professionadd"){
            if(args.size() != 6){return;}
            professionadd(args[1],args[2],args[3],args[4],args[5]);
        }else if(cmd == "professionstore"){
            if(args.size() != 2){return;}
            professionstore(args[1]);
        }else if(cmd == "addnpc"){
            if(args.size() != 4){return;}
            addnpc(args[1],args[2],args[3]);
        }else if(cmd == "npcedit"){
            if(args.size() != 3){return;}
            npcedit(args[1],args[2]);
        }else if(cmd == "playeredit"){
            if(args.size() != 3){return;}
            playeredit(args[1],args[2]);
        }else if(cmd == "gennpc"){
            gennpc();
        }else if(cmd == "featureadd"){
            if(args.size() != 2){return;}
            featureadd(args[1]);
        }else if(cmd == "featureremove"){
            if(args.size() != 2){return;}
            featureremove(args[1]);
        }else if(cmd == "propedit"){
            if(args.size() != 3){return;}
            propedit(args[1],args[2]);
        }else if(cmd == "stringedit"){
            stringedit(args);
        }else if(cmd == "pushname"){
            if(args.size() != 3){return;}
            pushname(args[1],args[2]);
        }else if(cmd == "wipenames"){
            if(args.size() != 2){return;}
            wipenames(args[1]);
        }else if(cmd == "wipeprofessions"){
            wipeprofessions();
        }
    }
}

// main

int main(){
    init_h();
    init_profession_vals();
    pick_stats();
    make_terrain(C.X,C.Y);
    while(1){
        //print(itos(rnd(100)));
        string command = sandget("> ");
        cmd_parser(command);
        global_ticki();
    }
}

#include<iostream>
#include<string>
#include<windows.h>
#include<ctime>

using namespace std;


void HUD();
void fight();
void fightHUD();
void moving();
void createanimal();
void levelup();
void boat();
void boatHUD();
//enitial variable
string Name = "",gender = "";
int level = 0,xp = 0,health = 0,totalhealth = 0,maxhealth = 0,nextlevel = 0,heal = 0;
int animalhp = 0,animalxp= 0,animallevel = 0,scrapmaterial = 0,boatlevel = 0;
string animalname[] = {"lion","tiger","panther","elephant","chimpanzee","leopard"};
string currentanimal = " "; 
string malename[] = {"Liam","Noah","Robin","James","Oliver"};
string femalename[] = {"Emma","Sophia","Ria","Simran","Kajol"};

//main set of code
int main()
{
    level = 1;
    xp = 0;
    nextlevel = 50;
    health = 100;
    scrapmaterial = 10;
    boatlevel = 80;
    totalhealth = 100;
    maxhealth = totalhealth;
    
    int namechoice,genderchoice;
    srand ( time(NULL) ); 
    
    
    cout<<"You are in the unknown island after your boat crash."<<endl;
    Sleep(200);
    cout<<"1.Do you remember your name"<<endl;
    cout<<"2.Other wise we can pick your name randomly"<<endl;
    cin>>namechoice;
    
    if (namechoice==1) {
        cout<<"Please enter your name::"<<endl;
        cin>>Name;
        cout<<"what is your gender"<<endl;
        cin>>gender;
        
    }
    else if (namechoice==2){
        cout<<"what is your gender"<<endl;
        Sleep(200);
        cout<<"1.Male"<<endl;
        cout<<"2.Female"<<endl;
        cin>>genderchoice;
        if (genderchoice==1){
            gender = "male";
            string namem=malename[rand()%4];
            cout<<"your name is "<<namem<<endl;
            Name = namem;
        }
        else if (genderchoice==2){
            gender = "female";
            string namef=femalename[rand() % 4];
            cout<<"your name is "<<namef<<endl;
            Name = namef;
            
        }
        else{
            cout << "Your choice is incorrect." << endl;
        }
            
    }
    else{
        cout << "Your choice is incorrect." << endl;
    }
    system("cls");
    cout<<"your character is being created........"<<endl;
    Sleep(500);
    
    HUD();
    moving();
    
    return 0;
    
}

void HUD()
{

    Sleep(600);
    system("cls");
    cout<<"Name: "<<Name<<"     "<<"gender: "<<gender<<
    "\nhealth: "<<health<<"\nlevel: "<<level<<"         scrapmaterial: "<<scrapmaterial<<
    "\nxp: "<<xp<<"     "<<"xp to next level:"<<nextlevel<<"            boat: "<<boatlevel<<"% complete"<<endl;
    moving();
}

void fightHUD(){
    Sleep(1000);
    system("cls");
    cout<<"Name: "<<Name<<"         Animalname: "<<currentanimal<<endl;
    cout<<"Health: "<<health<<"         Animalhealth: "<<animalhp<<endl;
    cout<<"Level: "<<level<<"       Animallevel: "<<animallevel<<endl;
    cout<<"Xp: "<<xp<<"         animalxp: "<<animalxp<<endl;
}

void fight(){
    fightHUD();
    int playerchoice,j;
    int playerdamage = 100;
    int animalattack = 4*animallevel/2;
    
    if (health >=1 && animalhp >= 1)
    {
        cout<<endl;
        cout<<"1.Attack"<<endl;
        cout<<"2.Defend"<<endl;
        cout<<"3.Run"<<endl;
        cin>>playerchoice;
        
        if(playerchoice == 1)
        {
            cout<<"you are attacking on "<<currentanimal<<", you did "<<playerdamage<<"damage to the "<<currentanimal<<"."<<endl;
            animalhp = animalhp - playerdamage;
            Sleep(1000);
            fightHUD();
            if(animalhp >= 1)
            {
                cout<<endl;
                cout<<currentanimal<<" is attacking on you be carefull..."<<endl;
                cout<<"you lost "<<animalattack<<"hp"<<endl;
                health= health-animalattack;
                
                if (health<=0)
                {
                    health = 0;
                    system("cls");
                    cout<<"you got killed by "<<currentanimal<<endl;
                    cout<<"your were level "<<level<<endl;
                    Sleep(2000);
                    exit(0);
                }
            }
            else if(animalhp <= 0)
            {
                animalhp = 0;
                levelup();
                cout<<endl;
                cout<<"you killed "<<currentanimal<<" and you got "<<animalxp<<endl;
                cout<<"well done"<<endl;
                j = rand() % 5;
                scrapmaterial = scrapmaterial + j;
                Sleep(1000);
                HUD();
            }
            Sleep(1000);
            fight();
        }
        else if(playerchoice == 2)
        {
            cout<<"trying to defend"<<endl;
            int d = rand() % 50 + 1;
            if (d>=25)
            {
                cout<<"You are success to block enimies attack.."<<endl;
                heal = level + 10;
                health += heal;
                if(health >= totalhealth)
                {
                    health = totalhealth;
                    cout<<"your health has been increased by"<<heal<<endl;
                    Sleep(1000);
                    fight();
                    
                }
                else
                {
                    cout<<"your health has been increased by"<<heal<<endl;
                    Sleep(1000);
                    fight();
                
                }
            }
            else
            {
                cout<<"you failed to defend your self..."<<endl;
                health -= animalattack;
                cout<<"you got "<<animalattack<<"damage."<<endl;
                Sleep(1000);
                fight();
            }
        }
        else if(playerchoice == 3)
        {
            cout<<"you try to run"<<endl;
            int r = rand() % 100 + 1;
            if(r>=50)
            {
                cout<<"your run away..."<<endl;
                HUD();
            }
            else
            {
                cout<<"You failed to run away from "<<currentanimal<<"..."<<endl;
                cout<<currentanimal<<" did very bad attck on you.."<<endl;
                health -= animalattack;
                cout<<"you got "<<animalattack<<"damage."<<endl;
                Sleep(1000);
                fight();
            }
        }
        else
        {
            cout<<"incoorect choice please try again....."<<endl;
            Sleep(600);
            fight();
        }
    }
    
}

void moving()
{
    //moving function
    int choice;
    cout<<endl;
    cout<<"1.Move forward"<<endl;
    cout<<"2.Take rest"<<endl;
    cout<<"3.Move backward"<<endl;
    cout<<"4.build boat"<<endl;
    Sleep(500);
    
    cin>>(choice);
    
    if(choice==1){
        int i = rand() % 100 +1;
        cout<<"you are going towards forest be carefull..."<<endl;
        if (i >= 50) {
            createanimal();
            string aniname = animalname[rand() % 5];
            cout<<"Oh you are infront of "<<aniname<<endl;
            cout<<aniname<<" is ready for attack.."<<endl;
            currentanimal = aniname;
            Sleep(1000);
            fight();
        }
        else
        {
            cout<<"you find nothing helpfull. "<<endl;
            Sleep(1000);
            HUD();
        }
        
    }else if(choice==2){
        cout<<"You want to sit at campfire and eat something intresting."<<endl;
        if (health <= (totalhealth-1)) 
        {
            health += 9 + level; 
            if(health >= totalhealth)
            {
                health = totalhealth;
                cout<<"your health is up by eating good...."<<endl;
                cout<<"your health is now "<<health<<endl;
                Sleep(1000);
                HUD();
            }
            else
            {
                cout<<"your health is up by eating good...."<<endl;
                cout<<"your health is now "<<health<<endl;
                Sleep(1000);
                HUD();
            
            }
        }
        else
        {
            cout<<"your health is max"<<endl;
            Sleep(1000);
            HUD();
        }
        
    }
    else if(choice==3){
        int i = rand() % 100 +1;
        cout<<"you are moving backwards..."<<endl;
        if (i >= 50) {
            createanimal();
            string aniname = animalname[rand() % 5];
            cout<<"Oh you are infront of "<<aniname<<endl;
            cout<<aniname<<" is ready for attack.."<<endl;
            currentanimal = aniname;
            Sleep(1000);
            fight();
        }else
        {
            cout<<"you find nothing helpfull. "<<endl;
            Sleep(1000);
            HUD();
        }
        
        
    }
    else if(choice == 4)
    {
        cout<<"you want to build boat"<<endl;
        Sleep(1000);
        boat();

    }
    else{
        cout<<"incoorect choice please try again....."<<endl;
        Sleep(600);
        moving();
    }
}

void createanimal() 
{
    //creation of animal
    animalhp = 35;
    animallevel = (rand()%3) + level;

    animalhp = (rand() % 2) * (health/2);

    animalxp = 20;
    if (animalhp == 0)
        createanimal();
    if (animallevel == 0)
        createanimal();
}

void levelup()
{
    //level up function
    xp=xp + animalxp;
    if (xp >= nextlevel)
    {
        level++;
        nextlevel = 50;
        xp = xp - 50;
        totalhealth = totalhealth + 10;
        maxhealth = totalhealth;
        cout<<"you just got increased in your level"<<endl;
        cout<<"now your level is "<<level<<" and also your total health is increased by 10 points"<<endl;
        cout<<"now your max health is "<<maxhealth<<endl;
        Sleep(2500);
        HUD();
    }
    
}

void boat()
{
    //escaping from island
    int boatchoice;
    system("cls");
    boatHUD();
    cout<<endl;
    cout<<"1.build boat"<<endl;
    cout<<"2.escap from island"<<endl;
    cout<<"3.return to game"<<endl;
    cin>>boatchoice;
    
    if(boatchoice == 1)
    {
        system("cls");
        boatHUD();
        if (scrapmaterial >= 5)
        {
            cout<<"you are building a boat"<<endl;
            boatlevel += 10;
            scrapmaterial -= 5;
            Sleep(500);
            boat();
        }
        else
        {
            cout<<"you don't have inough scrapmaterial"<<endl;
            boat();
            
        }
    }
    else if(boatchoice == 2)
    {
        system("cls");
        boatHUD();
        if(boatlevel >= 100)
        {
            boatlevel = 100;
            cout<<"you are successfully escaped from the island..."<<endl;
            cout<<endl;
            cout<<"THANK YOU FOR PLAYING GAME."<<endl;
            exit(0);
        }
    }
    else if(boatchoice == 3)
    {
        HUD();
    }
    else
    {
            cout<<"incoorect choice please try again....."<<endl;
            Sleep(600);
            boat();
    }
}

void boatHUD()
{
    Sleep(500);
    system("cls");
    cout<<"Name: "<<Name<<"         scrapmaterial: "<<scrapmaterial<<endl;
    cout<<"Health: "<<health<<"         boat level: "<<boatlevel<<endl;
    cout<<"Level: "<<level<<"        Xp: "<<xp<<endl;
}
//Author : Prakash Radhakrishnan

#ifndef INIT_ROBOTS_HPP
#define INIT_ROBOTS_HPP
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Creating the class Robot which contains localisation info of the robots
class Robot
{
    private:
    int x,y;
    string direction;

    public:
    Robot()
    {
        //Get value of x coordinate
        cout<<"Enter the coordindate x (0 to 13): ";
        while(true)
        {
            cin>>x;
            if(x>=0 && x<=13){break;}
            else{cout<<"Enter the valid x from 0 to 13"<<endl;}
        }
        
        //Get value of y coordinate
        cout<<"Enter the coordindate y (0 to 21): ";
        while(true)
        {
            cin>>y;
            if(y>=0 && y<=21){break;}
            else{cout<<"Enter the valid y from 0 to 21"<<endl;}
        }

        //Get robot facing direction 
        cout<<"Enter the direction('North as n','West as w','South as s','East as e'): ";
        while(true)
        {
            cin>>direction;
            if(direction=="n" || direction=="w" || direction=="s" || direction=="e"){break;}
            else{cout<<"Enter valid direction(:'North as n','West as w','South as s','East as e')"<<endl;}
        }
        
    }

    //getter functions of x,y,direction
    int getX() {return x;}
    int getY() {return y;}
    string getDirection() {return direction;}

    //setter functions of x,y,direction based on user input
    void moveForward() //move the user robot forward
    {
        if (x==0||x==13||y==0||y==21){return;}
        else
        {
            if(direction == "e"){y++;}
            else if(direction == "w"){y--;}
            else if(direction == "s"){x++;}
            else{x--;}
        }               
    }

    void moveBackward() //move the user robot backward
    {
        if (x==0||x==13||y==0||y==21){return;}
        else
        {
            if(direction == "e"){y--;}
            else if(direction == "w"){y++;}
            else if(direction == "s"){x--;}
            else{x++;}
        }        
    }

    void turnLeft() //turn the user robot leftside
    {
        if(direction == "e"){direction = "n";}
        else if(direction == "n"){direction = "w";}
        else if(direction == "w"){direction = "s";}
        else if(direction == "s"){direction = "e";}  
    }

    void turnRight() //turn the user robot rightside
        {
        if(direction == "e"){direction = "s";}
        else if(direction == "s"){direction = "w";}
        else if(direction == "w"){direction = "n";}
        else if(direction == "w"){direction = "e";}  
    }
    
    //Destructor
    ~Robot()
    {
    }

};

// Initialising the game --> asking user input for generating number of robots and stacking on vector one by one
void initializing_players(vector<Robot> &player_list)
{
    int robots_count;

    cout<<"Number of robot players: ";
    cin>>robots_count;

    //User input on position and direction for human robot
    cout<<"\nGenerating human player..."<<endl;
    Robot human;
    player_list.push_back(human); //Stacking human robot in player list vector

    //User input on position and direction for AI robot
    for(int i=1;i<=robots_count;i++)
    {
        cout<<"\nGenerating robot player "<<i<<" ..."<<endl;
        Robot p;
        player_list.push_back(p); //Stacking AI robot in player list vector one by one
    }
    
}


//Printing the localisation status of each players in the list
void print_playerstatus(vector<Robot> &player_list)
{
    cout<<"\nStatus of players:\n";
    for(int j=1;j<player_list.size();j++)
    {
        cout<<"Robot"<<j<<":   "<<player_list[j].getX()<<","<<player_list[j].getY()<<","<<player_list[j].getDirection();
        cout<<"\t\t\t";
    }
    cout<<"\nUser  :   "<<player_list[0].getX()<<","<<player_list[0].getY()<<","<<player_list[0].getDirection();    
}

#endif 

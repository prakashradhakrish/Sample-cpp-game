//Author : Prakash Radhakrishnan


#ifndef GAME_ALGORITHM_HPP
#define GAME_ALGORITHM_HPP
#include "game_static_robots.hpp"

// getting the input from the user and initiating the movements of human robots
void user_mov_control(int &game_finished,vector<Robot> &player_list)
{
    string user_input;
    if(game_finished!=1) 
    {
        cout<<"\nEnter the next move:";
        cin>>user_input;

        if(user_input=="forward"){player_list[0].moveForward();}
        else if(user_input=="backward"){player_list[0].moveBackward();}
        else if(user_input=="left"){player_list[0].turnLeft();}
        else if(user_input=="right"){player_list[0].turnRight();}
        else{cout<<"\nInvalid input"<<endl;}
    }
}

// Controls the movement of the AI robots based on min cost function(distance from human robots) 
void robot_movement(int &game_finished,int (&robotAI_grid)[14][22],vector<Robot> &player_list)
{
    int posx1,posx2,posy1,posy2;
    double dist_up,dist_down,dist_right,dist_left,min_dist;
    for(int k=1;k<player_list.size();k++)
    {
        // Initiating the possible moves of AI robots
        posx1 = player_list[k].getX()-1;
        posx2 = player_list[k].getX()+1;
        posy1 = player_list[k].getY()+1;
        posy2 = player_list[k].getY()-1;

        //calculating cost function with Euclidean distance 
        dist_up = sqrt(pow(posx1-player_list[0].getX(), 2) + pow(player_list[k].getY()-player_list[0].getY(), 2));
        dist_down = sqrt(pow(posx2-player_list[0].getX(), 2) + pow(player_list[k].getY()-player_list[0].getY(), 2));
        dist_right = sqrt(pow(player_list[k].getX()-player_list[0].getX(), 2) + pow(posy1-player_list[0].getY(), 2));
        dist_left = sqrt(pow(player_list[k].getX()-player_list[0].getX(), 2) + pow(posy2-player_list[0].getY(), 2)); 
        min_dist= std::min(dist_up, std::min(dist_down, std::min(dist_right, dist_left)));

        // Condition allows controls on X positions based on min const 
        bool change_x = (std::min(dist_up,dist_up)<std::min(dist_right,dist_left)); // true the cost to move up or down is minimum than right and left movement
             
	    if (change_x) 
        {
            if(dist_up<dist_down) // controls movement towards north i.e., -ve x direction 
            {
                if(player_list[k].getDirection() == "n"){player_list[k].moveForward();}
                else if(player_list[k].getDirection() == "s"){player_list[k].moveBackward();}
                else if(player_list[k].getDirection() == "e"){player_list[k].turnLeft();}
                else if(player_list[k].getDirection() == "w"){player_list[k].turnRight();}                
            }
            else // controls movement towards south i.e., +ve x direction 
            {
                if(player_list[k].getDirection() == "s"){player_list[k].moveForward();}
                else if(player_list[k].getDirection() == "n"){player_list[k].moveBackward();}
                else if(player_list[k].getDirection() == "w"){player_list[k].turnLeft();}
                else if(player_list[k].getDirection() == "e"){player_list[k].turnRight();}                
            }
        }
        else
        {
            if(dist_right<dist_left) // controls movement towards east i.e., +ve y direction 
            {
                if(player_list[k].getDirection() == "e"){player_list[k].moveForward();}
                else if(player_list[k].getDirection() == "w"){player_list[k].moveBackward();}
                else if(player_list[k].getDirection() == "s"){player_list[k].turnLeft();}
                else if(player_list[k].getDirection() == "n"){player_list[k].turnRight();}                
            }
            else // controls movement towards west i.e., -ve y direction 
            {
                if(player_list[k].getDirection() == "w"){player_list[k].moveForward();}
                else if(player_list[k].getDirection() == "e"){player_list[k].moveBackward();}
                else if(player_list[k].getDirection() == "n"){player_list[k].turnLeft();}
                else if(player_list[k].getDirection() == "s"){player_list[k].turnRight();}                
            }
        }
    }

}

// This function ensures the sequence of execution of each of defined functions
void game_Statistics_robots(int &game_finished,int rows,int columns,char (&gr)[14][22],int (&robotAI_grid)[14][22],int human_grid[14][22],vector<Robot> &player_list)
{
    user_mov_control(game_finished,player_list);
    robot_movement(game_finished,robotAI_grid,player_list);
    grid(rows, columns, gr, robotAI_grid, human_grid, player_list);
    print_playerstatus(player_list);
    game_status(game_finished, rows, columns,robotAI_grid, human_grid, player_list);
}

#endif

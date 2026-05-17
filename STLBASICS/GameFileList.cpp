
/*
 * GameFile.cpp
 *
 *  Created on: May 15, 2026
 *      Author: rodney
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>





int main(int argc, char* argv[]){
  
  std::ifstream playerFile("NameFile.txt");
  std::string playerLine, playerId,firstName, lastName, playerRank;
  std::stringstream ss;
  std::list<std::string> beginnerList;
  std::list<std::string> proList;
  
  if(playerFile.is_open()){
    std::cout << "This file will be used to store game data." << std::endl;
    std::getline(playerFile, playerLine);
    std::getline(playerFile, playerLine);

    while(std::getline(playerFile, playerLine)){
      std::cout << playerLine << std::endl;
      std::stringstream ss(playerLine);
      std::getline(ss, playerId, ' ');
      std::getline(ss, firstName, ' ');
      std::getline(ss, lastName, ' ');
      std::getline(ss, playerRank, ' ');
      std::cout << "Player ID: " << playerId << ", Name: " << firstName << " " << lastName << ", Rank: " << playerRank << std::endl;  

      if (std::stoi(playerRank) <= 5){
        beginnerList.push_back(playerId + " " + firstName + " " + lastName);
      }
      else{
        proList.push_back(playerId + " " + firstName + " " + lastName);
      } 
    }

    std::cout << "\nBeginner Players:" << std::endl;
    for(const auto& player : beginnerList){
      std::cout << player << std::endl;
    }
    std::cout<<std::endl;
    std::cout << "Pro Players:" << std::endl;
    for(const auto& player : proList){
      std::cout << player << std::endl;
    } 

    playerFile.close();
  }
  else{
    std::cout << "Unable to open file for reading." << std::endl;
  }
  
  return 0;
}
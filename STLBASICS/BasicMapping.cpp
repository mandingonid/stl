/*
 * BasicMapping.cpp
 *
 *  Created on: May 23, 2026
 *      Author: rodney
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>


int main() {

  std::ifstream playerFile("NameFile.txt");
  std::string playerLine, playerId,firstName, lastName, playerRank;
  std::stringstream ss;  // For parsing player lines

  std::map<std::string, int> playerRoster;

  if(playerFile.is_open()){
    std::cout << "This file will be used to store game data." << std::endl;
    std::getline(playerFile, playerLine);  // read and throw away file header line
    std::getline(playerFile, playerLine);  // read and throw away file column headers

    while(std::getline(playerFile, playerLine)){
      std::cout << playerLine << std::endl;
      std::stringstream ss(playerLine);
      std::getline(ss, playerId, ' ');
      std::getline(ss, firstName, ' ');
      std::getline(ss, lastName, ' ');
      std::getline(ss, playerRank, ' ');
      std::cout << "Player ID: " << playerId << ", Name: " << firstName << " " << lastName << ", Rank: " << playerRank << std::endl;  

      playerRoster.insert(std::pair<std::string, int>(firstName + " " + lastName, std::stoi(playerRank)));
    }

    for(auto pair : playerRoster){
      std::cout << "Player: " << pair.first << ", Rank: " << pair.second << std::endl;
    }
  }

  return 0;
}
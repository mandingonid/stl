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
#include <unordered_map>
#include <string>


int main() {

  std::ifstream playerFile("NameFile.txt");
  std::string playerLine, playerId,firstName, lastName, playerRank;
  std::stringstream ss;  // For parsing player lines

  std::map<std::string, int> playerRoster;

  if(playerFile.is_open()){
    std::cout << "This file will be used to store player data." << std::endl;
    std::getline(playerFile, playerLine);  // read and throw away file header line
    std::getline(playerFile, playerLine);  // read and throw away file column headers

    // Parse each line of the player file and populate the player roster map
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

    playerRoster["Macklin Celebrini"] = 10; // Adding a player to the roster using operator[]
    // playerRoster.erase("Macklin Celebrini"); // Removing a player from the roster
    // playerRoster.clear(); // Clearing the entire roster

    for(auto pair : playerRoster){
      std::cout << "Player: " << pair.first << ", Rank: " << pair.second << std::endl;
    }
  }

  return 0;
}
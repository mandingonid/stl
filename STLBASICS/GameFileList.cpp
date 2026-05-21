
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
#include <tuple>



int main(int argc, char* argv[]){
  
  std::ifstream playerFile("NameFile.txt");
  std::string playerLine, playerId,firstName, lastName, playerRank;
  std::stringstream ss;  // For parsing player lines

  // Define templates for beginner and pro player lists
  std::list<std::string> beginnerList;
  std::list<std::string> proList;
  std::list<std::tuple<int, std::string>> playersRatingsList;

  
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

      playersRatingsList.push_back(std::make_tuple(std::stoi(playerRank), playerLine));

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

    // Display all players rankings
    std::cout << "\nAll Players Sorted by Rank:" << std::endl;
    playersRatingsList.sort([](const std::tuple<int, std::string>& a, const std::tuple<int, std::string>& b) {
      return std::get<0>(a) < std::get<0>(b); // Sort by player rank
    });
    for(const auto& player : playersRatingsList){
      std::cout << std::get<1>(player) << std::endl; //
    }
    playerFile.close();
  }
  else{
    std::cout << "Unable to open file for reading." << std::endl;
  }
  
  return 0;
}
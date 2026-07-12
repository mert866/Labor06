#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "../include/json.hpp"
using json = nlohmann::json;
int main() {
// Create a JSON object
json weatherData;
// Add location data
weatherData["location"]["city"] = "Stuttgart";
weatherData["location"]["coordinates"]["latitude"] = 48.78;
weatherData["location"]["coordinates"]["longitude"] = 9.18;
// Add current weather
weatherData["current"]["time"] = "2024-11-21T15:30";
weatherData["current"]["temperature_2m"] = 3.5;
weatherData["current"]["wind_speed_10m"] = 12.3;
// Write JSON to file
std::ofstream outFile("weatherOutput.json");
if (!outFile.is_open()) {
std::cerr << "Error: Could not open file for writing\n";
return 1;
}
// The indent parameter (here 4) creates
// a nicely formatted JSON file
outFile << weatherData.dump(4) << std::endl;
outFile.close();
std::cout << "JSON file has been written successfully.\n";
return 0;
}

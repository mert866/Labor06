#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "../include/json.hpp"

using json = nlohmann::json;

int main() {
// Create initial JSON object
json weatherData;
weatherData["location"]["city"] = "Stuttgart";
weatherData["current"]["temperature_2m"] = 3.5;
weatherData["current"]["humidity"] = 75;
// 1. Add single values
weatherData["current"]["wind_speed_10m"] = 11.9;
weatherData["location"]["country"] = "Germany";
// 2. Create array and append value
weatherData["hourly"]["time"] = { "15:00", "16:00" };
weatherData["hourly"]["time"].push_back("17:00");
// 3. Delete entries
weatherData["current"].erase("humidity");
// 4. Check if entry exists
if (weatherData["current"].contains("temperature_2m")) {
std::cout << "Temperature changed to 5.2°C\n";
weatherData["current"]["temperature_2m"] = 5.2;
}
// 5. Manipulate arrays (reference ("&") needed)
auto &times = weatherData["hourly"]["time"];
times.push_back("18:00"); // Append at the end
if (!times.empty()) {
times.erase(times.begin() + 1); // Delete second element
}
// Print JSON object to console
std::cout << "\nFinal JSON:\n"
<< weatherData.dump(4) << std::endl;
return 0;
}

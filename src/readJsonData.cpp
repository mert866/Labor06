#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "../include/json.hpp"

using json = nlohmann::json;
int main() {
// Get filename from user
std::cout << "Please enter filename: ";
std::filesystem::path filepath;
std::cin >> filepath;
// Open file for reading
std::ifstream inFile(filepath);
if (!inFile.is_open()) {
std::cerr << "Error: File " << filepath
<< " could not be opened for reading\n";
return 1;
}
// Parse JSON from file
json weatherData = json::parse(inFile);
inFile.close();
// Print city name
std::string city = weatherData["location"]["city"];
std::cout << "City: " << city << '\n';
// Print current weather data
std::string time = weatherData["current"]["time"];
double temperature = weatherData["current"]["temperature_2m"];
std::cout << "Time: " << time << '\n';
std::cout << "Temperature: " << temperature << "°C\n";
// Print hourly forecast
std::cout << "\nHourly Forecast:\n";
// Fetch the JSON arrays
auto times = weatherData["hourly"]["time"];
auto temperatures = weatherData["hourly"]["temperature_2m"];
auto windSpeeds = weatherData["hourly"]["wind_speed_10m"];
// Iterate through arrays; size() returns the array's length
for (size_t i = 0; i < times.size(); ++i) {
std::cout << times[i] << ": "
<< temperatures[i] << "°C, "
<< windSpeeds[i] << " km/h\n";
}
return 0;
}
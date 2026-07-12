#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
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
std::cout << "Content of the file:\n\n";
// Read from file
std::string line;
while (std::getline(inFile, line)) {
std::cout << line << '\n';
}
// Close file
inFile.close();
return 0;
}

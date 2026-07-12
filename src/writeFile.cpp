#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

int main() {
// Get filename from user
std::cout << "Please enter filename: ";
std::filesystem::path filepath;
std::cin >> filepath;
// Open file for writing
std::ofstream outFile(filepath);
if (!outFile.is_open()) {
std::cerr << "Error: File " << filepath
<< " could not be opened for writing\n";
return 1;
}
// Write to file
outFile << "Hello World\n";
outFile << "This is a text\n";
outFile << "which is used for testing\n";
// Close file
outFile.close();
return 0;
}

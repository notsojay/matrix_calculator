#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void add(std::string, std::string, std::string);
void sub(std::string, std::string, std::string);
void mul(std::string, std::string, std::string); 

class MatrixFile
{
public:
	MatrixFile(const std::string & = std::string(), const std::string & = std::string());
	~MatrixFile();
	std::vector<std::vector<int>> readFile();
	void writeFile(const std::string &, const std::vector<std::vector<int>> &);
	void openInFile(const std::string &);
	void openOutFile(const std::string &);
	void closeInFile();
	void closeOutFile();

private:
	std::ifstream inFile;
	std::ofstream outFile;
};

#endif
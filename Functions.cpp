/***********************************************************************
** Date: 		11/21/22
** Project :	Functions.cpp
** Programers:	Jiahao Liang
** File:		Functions.cpp
** Purpose:		
** Notes:		
***********************************************************************/

#include "Functions.h"


void add(std::string a, std::string b, std::string output)
{
	MatrixFile file(a, output);
	std::vector<std::vector<int>> matrixA, matrixB, matrixResult;
	matrixResult.reserve(matrixA.size());
	matrixA = file.readFile();
	file.closeInFile();
	file.openInFile(b);
	matrixB = file.readFile();
	for(size_t i = 0; i < matrixA.size(); ++i)
	{
		std::vector<int> temp;
		temp.reserve(matrixA.at(0).size());
		for(size_t j = 0; j < matrixA.at(0).size(); ++j)
		{
			temp.push_back(matrixA.at(i).at(j) + matrixB.at(i).at(j));
		}
		matrixResult.push_back(temp);
	}
	file.writeFile(output, matrixResult);
}

void sub(std::string a, std::string b, std::string output)
{
	MatrixFile file(a, output);
	std::vector<std::vector<int>> matrixA, matrixB, matrixResult;
	matrixResult.reserve(matrixA.size());
	matrixA = file.readFile();
	file.closeInFile();
	file.openInFile(b);
	matrixB = file.readFile();
	for(size_t i = 0; i < matrixA.size(); ++i)
	{
		std::vector<int> temp;
		temp.reserve(matrixA.at(0).size());
		for(size_t j = 0; j < matrixA.at(0).size(); ++j)
		{
			temp.push_back(matrixA.at(i).at(j) - matrixB.at(i).at(j));
		}
		matrixResult.push_back(temp);
	}
	file.writeFile(output, matrixResult);
}

void mul(std::string a, std::string b, std::string output)
{
	MatrixFile file(a, output);
	std::vector<std::vector<int>> matrixA, matrixB;
	matrixA = file.readFile();
	file.closeInFile();
	file.openInFile(b);
	matrixB = file.readFile();
	std::vector<std::vector<int>> matrixResult(matrixA.size(), std::vector<int>(matrixB.at(0).size(), 0));
	for(size_t i = 0; i < matrixA.size(); ++i)
	{
		for(size_t j = 0; j < matrixB.at(0).size(); ++j)
		{
			for(size_t k = 0; k < matrixA.at(0).size(); ++k)
			{
				matrixResult[i][j] += matrixA.at(i).at(k) * matrixB.at(k).at(j);
			}
		}
	}
	file.writeFile(output, matrixResult);
}

MatrixFile::MatrixFile(const std::string & inFileName, const std::string & outFileName)
{
	if(inFileName != std::string()) openInFile(inFileName);
	if(outFileName != std::string()) openOutFile(outFileName);
}

MatrixFile::~MatrixFile()
{
	closeInFile();
	closeOutFile();
}

std::vector<std::vector<int>> MatrixFile::readFile()
{
	char buffer[1024];
	std::vector<std::vector<int>> matrix;
	while(inFile.getline(buffer, 1024))
	{
		std::stringstream ss(buffer);
		std::vector<int> row;
		int num;
		while(ss >> num)
		{
			row.push_back(num);
		}
		matrix.push_back(row);
	}
	return matrix;
}

void MatrixFile::writeFile(const std::string & fileName, const std::vector<std::vector<int>> & matrix)
{
	for(auto i = matrix.begin(); i != matrix.end(); ++i)
	{
		for(auto j = i->begin(); j != i->end(); ++j)
		{
			outFile << *j;
			if(std::next(j) != i->end()) outFile << " ";
		}
		if(std::next(i) == matrix.end()) break;
		else outFile << '\n';
	}
}

void MatrixFile::openInFile(const std::string & fileName)
{
	if(!inFile.is_open()) inFile.open(fileName, std::ios::in);
}

void MatrixFile::openOutFile(const std::string & fileName)
{
	if(!outFile.is_open()) outFile.open(fileName, std::ios::out);
}

void MatrixFile::closeInFile()
{
	if(inFile.is_open()) inFile.close();
}

void MatrixFile::closeOutFile()
{
	if(outFile.is_open()) outFile.close();
}

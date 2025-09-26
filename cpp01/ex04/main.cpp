/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:04:55 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/26 17:37:07 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string	to_replace = av[2];
	std::string	with = av[3];
	std::ifstream inputFile(av[1]);
	
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return (1);
	}

	std::string outputFileName = av[1];
	outputFileName += ".replace";
	std::ofstream outputFile(outputFileName.c_str());
	if (!outputFile.is_open())
	{
		inputFile.close();
		std::cerr << "Error: could not create output file." << std::endl;
		return (1);
	}

	std::string	currentLine;
	
	while (std::getline(inputFile, currentLine))
	{
		if (to_replace.empty())
		{
			outputFile << currentLine << std::endl;
			continue;
		}
		
		size_t startPos = 0;
		while ((startPos = currentLine.find(to_replace, startPos)) != std::string::npos)
		{
			currentLine = currentLine.substr(0, startPos) + with + 
						 currentLine.substr(startPos + to_replace.length());
			startPos += with.length();
		}
		outputFile << currentLine << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:04:55 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/29 19:11:39 by jaoh             ###   ########.fr       */
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
	std::string	newLine;
	size_t		occurences = 0;
	
	while (std::getline(inputFile, currentLine))
	{
		size_t index;
		newLine = currentLine;
		while (to_replace != "" && (index = newLine.find(to_replace)) != std::string::npos)
		{
			occurences++;
			newLine = newLine.substr(index + to_replace.size());
		}
		while ((to_replace != "" && (index = currentLine.find(to_replace)) != std::string::npos) && occurences)
		{
			newLine = currentLine.substr(0, index);
			newLine += with;
			newLine += currentLine.substr(index + to_replace.size());
			currentLine = newLine;
			occurences--;
		}
		outputFile << currentLine << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return (0);
}
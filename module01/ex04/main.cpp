/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:41:57 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/10 09:40:00 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

void replaceFileContent(const std::string &filename, const std::string &s1, const std::string &s2)
{
	if (access(filename.c_str(), R_OK | W_OK) == -1)
	{
		std::cout << "Error: could not access file " << filename << std::endl;
		return;
	}

	std::ifstream inputFile(filename.c_str());

	if (!inputFile.is_open())
	{
		std::cout << "Error: could not open file " << filename << std::endl;
		return;
	}

	/* peek restituisce il pro char nel flusso senza estrarlo.
	Se il file è vuoto, restituisce std::ifstream::traits_type::eof() */
	if (inputFile.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Error: file " << filename << " is empty." << std::endl;
		inputFile.close();
		return;
	}

	std::string contentFile((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
	inputFile.close();

	std::string newContent;
	size_t pos = 0;
	size_t found = contentFile.find(s1, pos);

	while (found != std::string::npos)
	{
		newContent += contentFile.substr(pos, found - pos);
		newContent += s2;
		pos = found + s1.length();
		found = contentFile.find(s1, pos);
	}
	newContent += contentFile.substr(pos);

	std::string outputFileName = filename + ".replace";
	std::ofstream outputFile(outputFileName.c_str());

	if (!outputFile.is_open())
	{
		std::cout << "Error: could not open file " << outputFileName << std::endl;
		return;
	}

	outputFile << newContent;
	outputFile.close();

	std::cout << "File " << filename << " has been copied to " << outputFileName << " with the replacement." << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error: invalid number of arguments." << std::endl;
		return 1;
	}

	std::string filename(av[1]);
	std::string s1(av[2]);
	std::string s2(av[3]);

	replaceFileContent(filename, s1, s2);

	return 0;

}

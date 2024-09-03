/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:41:57 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/03 11:40:34 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
It will open the file <filename> and copies its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2. */

#include <iostream>
#include <fstream>
#include <string>

void replaceFileContent(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::ifstream inputFile(filename.c_str());

	if (!inputFile.is_open())
	{
		std::cout << "Error: could not open file " << filename << std::endl;
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

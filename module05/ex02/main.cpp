/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:45:23 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/19 15:06:39 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat highRank("HighRank", 1);
    Bureaucrat lowRank("LowRank", 150);
    Bureaucrat midRank("MidRank", 50);

    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Arthur Dent");
    
    try {
        std::cout << "\n--- Testing ShrubberyCreationForm ---\n";
        std::cout << shrubbery << std::endl;

        highRank.signForm(shrubbery);
        highRank.executeForm(shrubbery);

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\n--- Testing RobotomyRequestForm ---\n";
        std::cout << robotomy << std::endl;
		highRank.executeForm(robotomy);
        midRank.signForm(robotomy);
        midRank.executeForm(robotomy);
        highRank.executeForm(robotomy);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n--- Testing PresidentialPardonForm ---\n";
        std::cout << pardon << std::endl;
        midRank.signForm(pardon);
        highRank.signForm(pardon);
        midRank.executeForm(pardon);
        highRank.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n--- Testing unsigned form execution ---\n";
        PresidentialPardonForm unsignedPardon("Zaphod");
        highRank.executeForm(unsignedPardon);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

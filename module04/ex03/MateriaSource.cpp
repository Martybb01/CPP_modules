/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:51:02 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/08 17:56:31 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		_learnedMaterials[i] = NULL;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_learnedMaterials[i])
			delete _learnedMaterials[i];
}

MateriaSource::MateriaSource(MateriaSource const &src) {
	std::cout << "MateriaSource copy constructor" << std::endl;
	if (this != &src) {
		for (int i = 0; i < 4; i++)
			if (src._learnedMaterials[i])
				_learnedMaterials[i] = src._learnedMaterials[i]->clone();
			else
				_learnedMaterials[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src) {
	std::cout << "MateriaSource assignation operator" << std::endl;
	if (this != &src) {
		for (int i = 0; i < 4; i++)
			if (_learnedMaterials[i])
				delete _learnedMaterials[i];
		for (int i = 0; i < 4; i++)
			if (src._learnedMaterials[i])
				_learnedMaterials[i] = src._learnedMaterials[i]->clone();
			else
				_learnedMaterials[i] = NULL;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!_learnedMaterials[i]) {
			_learnedMaterials[i] = m->clone();
			std::cout << "Materia learned of type" << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_learnedMaterials[i] && _learnedMaterials[i]->getType() == type) {
			std::cout << "Materia created of type" << type << std::endl;
			return _learnedMaterials[i]->clone();
		}
	}
	std::cout << "Materia not found" << std::endl;
	return 0;
}

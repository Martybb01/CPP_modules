/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:31:34 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/07 17:49:31 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) {
	_array = new T[0];
	_size = 0;
	return;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	_array = new T[n]();
	_size = n;
	return;
}

template <typename T>
Array<T>::Array(Array const &src) {
	_array = new T[src._size];
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++) {
		_array[i] = src._array[i];
	}
	return;
}

template <typename T>
Array<T>::~Array(void) {
	delete[] _array;
	return;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &src) {
	if (this != &src) {
		delete[] _array;
		_array = new T[src._size];
		_size = src._size;
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = src._array[i];
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw std::out_of_range("Index out of range");
	}
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return _size;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:12:38 by iubieta-          #+#    #+#             */
/*   Updated: 2026/02/09 23:18:20 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <exception>
#include <cstddef>
#include <new>
#include <stdexcept>

template <typename T>
Array<T>::Array() : _array(NULL), _size(0){
}

template <typename T>
Array<T>::Array(unsigned int size) : _array(new T[size]), _size(size){
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _array(NULL), _size(other._size) {
	if (this->_size != 0) {
		this->_array = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++) {
			this->_array[i] = other._array[i];
		}
	}
}

template <typename T>
Array<T>& Array<T>::operator =(const Array<T> &other) {
	if (this == &other) {
		return *this;
	}

	delete[] this->_array;
	this->_array = NULL;
	this->_size = 0;
	
	this->_size = other._size;
	if (this->_size != 0) {
		this->_array = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++) {
			this->_array[i] = other._array[i];
		}
	}

	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] this->_array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->_size)
		throw std::out_of_range("index out of range");
	return (this->_array[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= this->_size)
		throw std::out_of_range("index out of range");
	return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->_size;
}

#endif

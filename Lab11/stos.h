#pragma once
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <string>

class Stos_Exception : public std::exception
{
	std::string _msg;
public:
	Stos_Exception(const std::string& msg) : _msg(msg) {}

	virtual const char* what() const noexcept override
	{
		return _msg.c_str();
	}
};


template <typename typ>
class stos
{
private:
	typ* zmienna;
	int size;
	void set(typ* p_zmienna, int p_size) {
		size = p_size;
		zmienna = new typ[size];
		for (int i = 0; i < size; i++) {
			zmienna[i] = p_zmienna[i];
		}
	};
public:
	stos() {
		size = 0;
		zmienna = nullptr;
	};
	stos(typ* p_zmienna, int p_size) {
		set(p_zmienna, p_size);
	};
	stos(const stos& copy) {
		size = copy.size;
		zmienna = new typ[size];
		for (int i = 0; i < size; i++) {
			zmienna[i] = copy.zmienna[i];
		}
	};
	~stos() {
		size = 0;
		free(zmienna);
	};
	void put(typ p_zmienna) {
		stos temp;
		temp.size = size;
		temp.zmienna = new typ[temp.size];
		for (int i = 0; i < temp.size; i++) {
			temp.zmienna[i] = zmienna[i];
		}
		size = size + 1;
		zmienna = new typ[size];
		for (int i = 0; i < temp.size; i++) {
			zmienna[i] = temp.zmienna[i];
		}
		zmienna[size - 1] = p_zmienna;
	};
	typ takeoff() {
		if(size == 0) {
			throw Stos_Exception("Stos pusty");
		}
		else
		{
			stos temp;
			temp.size = size;
			temp.zmienna = new typ[temp.size];
			for (int i = 0; i < temp.size; i++) {
				temp.zmienna[i] = zmienna[i];
			}
			size = size - 1;
			zmienna = new typ[size];
			for (int i = 0; i < size; i++) {
				zmienna[i] = temp.zmienna[i];
			}

			return temp.zmienna[temp.size - 1];
			
		}
	};
	void erase() {
		size = 0;
		delete[] zmienna;
		zmienna = nullptr;
	};
	bool is_empty() {
		if (size == 0 && zmienna == nullptr) {
			return true;
		}
		return false;
	};
	int get_size() {
		return size;
	};
	void copy(const stos& copy) {
		stos temp;
		temp.size = size;
		temp.zmienna = new typ[temp.size];
		for (int i = 0; i < temp.size; i++) {
			temp.zmienna[i] = zmienna[i];
		}
		size = size + copy.size;
		zmienna = new typ[size];
		for (int i = 0; i < size; i++) {
			if (i < temp.size)
				zmienna[i] = temp.zmienna[i];
			else
				zmienna[i] = copy.zmienna[i - temp.size];
		}
	};
};


#include <iostream>
#include <sstream>
#include "smart_array.h"
#include "Error.h"


smart_array::smart_array(int i) {
	it = new int[i]();
	now_size = 0;
	full_size = i;
}
int smart_array::add_element(int i) {
	if (now_size >= full_size)
	{
		std::stringstream message;
			message << " Необходимо увеличить размер умного массива для добавления элементов!\n";
			throw ArrayException(message.str());
		}
		*(it+now_size)=i;
		++now_size;
			
}
int smart_array::get_element(int i) {
	if ((i > now_size)||(i<1))
	{
		std::stringstream message;
		message << "Недопустимый индекс при обращении к элементу массива!\n";
		throw ArrayException(message.str());
	}
	return *(it + i);

}

smart_array::~smart_array()
{
	delete[] it;
	it = nullptr;
}
smart_array& smart_array::operator=(const smart_array& i1) {
	if (this == &i1)return *this;

	delete[]this -> it;
	this->it = new int[i1.full_size]();
	this->full_size = i1.full_size;
	this->now_size = i1.now_size;
	for (int i = 0; i < this->now_size; ++i)
	{
		*(this->it + i) = *(i1.it + i);
	}
	return *this;



}
void smart_array::print_smart_array()
{
	for (int i = 0; i < now_size; ++i)
		std::cout << *(it + i) << " ";
	std::cout << std::endl;
}
smart_array::smart_array(const smart_array& i1)
{
	this->it = new int[i1.full_size]();
	this->full_size =i1.full_size;
	this->now_size = i1.now_size;
	for (int i = 0; i < this->now_size; ++i)
	{
		*(this->it + i) = *(i1.it + i);
	}
}

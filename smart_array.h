#pragma once
class smart_array
{
public:
	smart_array(int i);
	smart_array(const smart_array&i) ;
	smart_array& operator=(const smart_array&i);
	void print_smart_array();
		int add_element(int addElement);
	int get_element(int addElement);
	~smart_array();
private:
	int now_size;
	int full_size;
	int* it;
};


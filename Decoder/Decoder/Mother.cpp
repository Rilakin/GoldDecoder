#include "Mother.h"

int Mother::get_chip()
{
	int result = (get_output_first_reg() + get_output_second_reg()) % 2;
	return result;
}

vector<int> Mother::generate_sequence(int length)
{
	vector<int> result;
	for (size_t i = 0; i < length; i++)
	{
		int chip = get_chip();
		result.push_back(chip);
		generate_next_first_reg();
		generate_next_second_reg();
	}
	return result;
}

Mother::Mother(int id, int first, int second, int shift_t)
{
	pos_first_sum = first - 1;
	pos_second_sum = second - 1;
	satellite_id = id;
	t = shift_t;
	chip_sequence = generate_sequence(1023);
}

vector<int> Mother::get_chip_sequence()
{
	return chip_sequence;
}

int Mother::get_id()
{
	return satellite_id;
}

int Mother::generate_next_first_reg()
{
	int third_bit = first_reg.at(2);
	int last_bit = first_reg.at(9);
	int new_bit = (third_bit + last_bit) % 2;
	std::rotate(first_reg.rbegin(), first_reg.rbegin() + 1, first_reg.rend());
	first_reg.at(0) = new_bit;
	return new_bit;
}

int Mother::get_output_first_reg()
{
	return first_reg.at(9);
}

int Mother::generate_next_second_reg()
{
	int second_bit = second_reg.at(1);
	int third_bit = second_reg.at(2);
	int sixth_bit = second_reg.at(5);
	int eighth_bit = second_reg.at(7);
	int ninth_bit = second_reg.at(8);
	int last_bit = second_reg.at(9);
	int new_bit = (second_bit + third_bit + sixth_bit + eighth_bit + ninth_bit + last_bit) % 2;
	std::rotate(second_reg.rbegin(), second_reg.rbegin() + 1, second_reg.rend());
	second_reg.at(0) = new_bit;
	return new_bit;
}

int Mother::get_output_second_reg()
{
	int first_bit = second_reg.at(pos_first_sum);
	int second_bit = second_reg.at(pos_second_sum);
	int result = (first_bit + second_bit) % 2;
	return result;
}
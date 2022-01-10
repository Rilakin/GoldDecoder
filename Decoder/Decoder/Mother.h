#pragma once

#include<vector>

using namespace std;

class Mother
{
public:
	vector<int> get_chip_sequence();
	int get_id();
	Mother(int id, int first, int second,  int shift_t);

private:
	int satellite_id;
	int pos_first_sum;
	int pos_second_sum;
	int t;
	vector<int> first_reg = {1,1,1,1,1,1,1,1,1,1};
	vector<int> second_reg = {1,1,1,1,1,1,1,1,1,1};
	vector<int> chip_sequence;


	int generate_next_first_reg();
	int get_output_first_reg();
	int generate_next_second_reg();
	int get_output_second_reg();
	int get_chip();
	vector<int> generate_sequence(int length);
};


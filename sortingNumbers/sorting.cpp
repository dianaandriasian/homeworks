#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <cmath>

const int amountOfNumbers = 10000000;

std::bitset<amountOfNumbers> setBits(const std::string& path);
void sortedSequenceEntry(const std::string& path, std::bitset<amountOfNumbers> nums);

int main()
{
	std::string path = "unsortedSequence.txt";

	sortedSequenceEntry(path, setBits(path));

	return 0;
}

void sortedSequenceEntry(const std::string& path, std::bitset<amountOfNumbers> nums)
{
	std::ofstream fout;
	fout.open(path);

	for (int i = 0; i < amountOfNumbers; ++i)
	{
		if (nums[i])
		{
			fout << i << std::endl;
		}
	}

	fout.close();
}

std::bitset<amountOfNumbers> setBits(const std::string& path)
{
	std::ifstream fin;
	fin.open(path);

	std::bitset<amountOfNumbers> nums;
	std::string str;
	int position = 0;
	int sizeStr = 0;

	while (!fin.eof())
	{
		str = "";
		fin >> str;
		sizeStr = str.size();

		for (int i = 0; i < sizeStr; ++i)
		{
			position += (str[i] - '0') * pow(10, sizeStr - (i + 1));
		}

		nums[position] = true;
		position = 0;
	}

	fin.close();

	return nums;
}

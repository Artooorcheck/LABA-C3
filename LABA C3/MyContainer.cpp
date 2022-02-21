#include"MyContainer.h"


std::ofstream& GenerateFile(std::string fileName, int N, int M)
{
	std::ofstream oFile(fileName);

	DoubleList list(N);

	std::generate(list.begin(), list.end(), [M]() {return rand() % (2 * M) - M; });

	Print(list, oFile);

	return oFile;
}

DoubleList ReadFileToList(std::ifstream& iFile)
{
	DoubleList list;

	double number;

	while (iFile)
	{
		iFile >> number;
		if (!iFile.fail())
		{
			list.push_back(number);
		}
	}

	return list;
}

double FindMaxInList(DoubleList list)
{
	double max = *list.begin();
	for (Iterator i = list.begin(); i != list.end(); i++)
		if (max < *i)
			max = *i;
	return max;
}

DoubleList Modify(DoubleList list)
{
	DoubleList modifyList;

	double max = FindMaxInList(list);

	for (Iterator i = list.begin(); i != list.end(); i++)
	{
		modifyList.push_back(*i - max);
	}

	return modifyList;
}

void Modify(DoubleList list, Iterator iter1, Iterator iter2)
{
	double max = FindMaxInList(list);

	for_each(iter1, iter2, [max](double &a) {a -= max; });
}

DoubleList Transform(DoubleList list)
{
	double max = FindMaxInList(list);

	DoubleList resultList;
	
	resultList.resize(list.size());

	std::transform(list.begin(), list.end(), resultList.begin(), [max](double a) {return a - max; });

	return resultList;
}

void ModifyWithForeach(DoubleList& list)
{
	double max = FindMaxInList(list);

	for_each(list.begin(), list.end(), [max](double &a) {a -= max; });
}

double Average(DoubleList list)
{
	return Sum(list)/ list.size();
}

double Sum(DoubleList list)
{
	double sum = 0;
	std::for_each(list.begin(), list.end(), [&sum](double a) {sum += a; });
	return sum;
}

void Print(DoubleList list, std::ostream& stream)
{
	std::for_each(list.begin(), list.end(), [&stream](double a) {stream << a << ' '; });
}
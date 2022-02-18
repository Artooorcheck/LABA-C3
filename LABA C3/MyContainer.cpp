#include"MyContainer.h"


std::ofstream& GenerateFile(std::string fileName, int N, int M)
{
	std::ofstream oFile(fileName);

	std::list<double> list(N);

	std::generate(list.begin(), list.end(), [M]() {return rand() % (2 * M) - M; });

	std::for_each(list.begin(), list.end(), [&oFile](double a) {oFile << a << ' '; });

	return oFile;
}

std::list<double> ReadFileToList(std::ifstream& iFile)
{
	std::list<double> list;

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

double FindMaxInList(std::list<double> list)
{
	double max = *list.begin();
	for (Iterator i = list.begin(); i != list.end(); i++)
		if (max < *i)
			max = *i;
	return max;
}

std::list<double> Modify(std::list<double> list)
{
	std::list<double> modifyList;

	double max = FindMaxInList(list);

	for (Iterator i = list.begin(); i != list.end(); i++)
		modifyList.push_back(*i - max);

	return modifyList;
}

void Modify(std::list<double> list, Iterator& iter1, Iterator& iter2)
{
	double max = FindMaxInList(list);

	for_each(iter1, iter2, [max](double &a) {a -= max; });
}

std::list<double> Transform(std::list<double> list)
{
	double max = FindMaxInList(list);

	std::list<double> resultList;
	
	resultList.resize(list.size());

	std::transform(list.begin(), list.end(), resultList.begin(), [max](double a) {return a - max; });

	return resultList;
}

void ModifyWithForeach(std::list<double>& list)
{
	double max = FindMaxInList(list);

	for_each(list.begin(), list.end(), [max](double &a) {a -= max; });
}

double Average(std::list<double> list)
{
	double average=0;
	std::for_each(list.begin(), list.end(), [&average](double a) {average += a; });
	return average / list.size();
}

double Sum(std::list<double> list)
{
	double sum = 0;
	std::for_each(list.begin(), list.end(), [&sum](double a) {sum += a; });
	return sum;
}

void Print(std::list<double> list, std::ostream& stream)
{
	std::for_each(list.begin(), list.end(), [&stream](double a) {stream << a << ' '; });
}
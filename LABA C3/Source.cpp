//Арутюнян Артур Артуровияч
//C3
//Контейнер: Список
//Преобразование: Вычесть из каждого числа максимальное из чисел


#include"MyContainer.h"
#include<Windows.h>

void TaskManager(int task, DoubleList& list, bool& existList);
void ShowMenu();

int main()
{
	SetConsoleOutputCP(1251);

	DoubleList list;
	bool existList = false;
	int task = 1;

	while (task != 0)
	{
		ShowMenu();

		std::cin >> task;
		TaskManager(task, list, existList);
	}
	return 0;
}

void ShowMenu()
{
	std::cout << "\nВыберите одну из представленных ниже команд:\n";
	std::cout << "0. Выход\n";
	std::cout << "1. Сгенерировать Последовательность в файле\n";
	std::cout << "2. Считать информацию из файла\n";
	std::cout << "3. Уменьшить все значения на максимум\n";
	std::cout << "4. Уменьшить все значения на максимум с i по j элемент\n";
	std::cout << "5. Посчитать сумму элементов\n";
	std::cout << "6. Посчитать среднее арифметическое\n";
	std::cout << "7. Вывести список на экран\n";
	std::cout << "8. Вывести список в файл\n\n";
}

void Task1()
{
	std::string fileName;

	std::cout << "Введите имя файла\n";
	std::cin >> fileName;

	int N, M;

	std::cout << "Введите количество чисел\n";
	std::cin >> N;

	std::cout << "Введите максимальный по модулю элемент\n";
	std::cin >> M;

	GenerateFile(fileName, N, M);
}

bool Task2(DoubleList& list)
{
	std::ifstream iFile;

	std::string fileName;

	std::cout << "Введите имя файла\n";
	std::cin >> fileName;
	iFile.open(fileName);
	if (iFile.is_open())
	{
		list = ReadFileToList(iFile);
		return true;
	}
	else
		std::cout << "Файл не найден\n";
	return false;
}

void TaskModify(DoubleList& list, int i, int j)
{
	if (i > 0 && j <= list.size())
	{

		Iterator iter1 = list.begin();

		std::advance(iter1, i);

		Iterator iter2 = list.begin();

		std::advance(iter2, j);

		Modify(list, iter1, iter2);
	}
	else
	{
		std::cout << "Не допустимые значения параметров: значения i и j должны лежать в диапазоне от 0 до " << list.size() << "\n";
	}
}

void Task4(DoubleList& list)
{
	int i, j;

	std::cout << "Введите i\n";
	std::cin >> i;

	std::cout << "Введите j\n";
	std::cin >> j;

	if (i < j)
	{
		TaskModify(list, i, j);
	}
	else
	{
		std::cout << "Значение i не должно превышать j\n";
	}
}

void Task8(DoubleList list)
{
	std::string fileName;
	std::cout << "Введите имя файла\n";
	std::cin >> fileName;
	std::ofstream oFile(fileName);
	Print(list, oFile);
}

void Task7(DoubleList list)
{
	std::cout << "Список: ";
	Print(list, std::cout);
}

void TaskManager(int task, DoubleList& list, bool& existList)
{
	if (task > 2 && !existList && task <= 8)
	{
		std::cout << "Список пока не существует\n";
	}
	else if (task == 1)
	{
		Task1();
	}
	else if (task == 3)
	{
		ModifyWithForeach(list);
	}
	else if (task == 2)
	{
		existList = Task2(list);
	}
	else if (task == 4)
	{
		Task4(list);
	}
	else if (task == 5)
	{
		std::cout << "Сумма всех элементов = " << Sum(list);
	}
	else if (task == 6)
	{
		std::cout << "Среднее арифметическое всех элементов = " << Average(list);
	}
	else if (task == 7)
	{
		Task7(list);
	}
	else if (task == 8)
	{
		Task8(list);
	}
	else if (task != 0)
	{
		std::cout << "Неизвестная команда\n";
	}
}
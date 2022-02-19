//Арутюнян Артур Артуровияч
//C3
//Контейнер: Список
//Преобразование: Вычесть из каждого числа максимальное из чисел


#include"MyContainer.h"
#include<Windows.h>

Iterator FindPosByIndex(DoubleList list, int index);

int main()
{
	DoubleList list;

	bool existList = false;

	SetConsoleOutputCP(1251);

	while (true)
	{
		std::cout << "\nВыберите одну из представленных ниже команд:\n\n";
		std::cout << "1. Сгенерировать Последовательность в файле\n";
		std::cout << "2. Считать информацию из файла\n";
		std::cout << "3. Уменьшить все значения на максимум\n";
		std::cout << "4. Уменьшить все значения на максимум с i по j элемент\n";
		std::cout << "5. Посчитать сумму элементов\n";
		std::cout << "6. Посчитать среднее арифметическое\n";
		std::cout << "7. Вывести список на экран\n";
		std::cout << "8. Вывести список в файл\n";
		std::cout << "9. Выход\n\n";

		int task;

		std::string fileName;

		std::ifstream iFile;



		std::cin >> task;

		switch (task)
		{
		case 1:

			std::cout << "Введите имя файла\n";
			std::cin >> fileName;

			int N, M;

			std::cout << "Введите количество чисел\n";
			std::cin >> N;

			std::cout << "Введите максимальный по модулю элемент\n";
			std::cin >> M;

			GenerateFile(fileName, N, M);
			break;
		case 2:

			std::cout << "Введите имя файла\n";
			std::cin >> fileName;
			iFile.open(fileName);
			if (iFile.is_open())
			{
				list = ReadFileToList(iFile);
				existList = true;
			}
			else
				std::cout << "Не удалось открыть файл";
			break;
		case 3:
			if (existList)
			{
				//list = Modify(list);
				ModifyWithForeach(list);
				//list = Transform(list);
			}

			else
				std::cout << "Список пока не существует\n";
			break;
		case 4:
			if (existList)
			{
				int i, j;

				std::cout << "Введите i\n";
				std::cin >> i;

				std::cout << "Введите j\n";
				std::cin >> j;

				if (i < j)
				{
					if (i > 0 && j < list.size() - 1)
					{

						Iterator iter1 = list.begin();

						std::advance(iter1, i);

						Iterator iter2 = list.begin();

						std::advance(iter2, j);

						Modify(list, iter1, iter2);
					}
					else
					{
						std::cout << "Не допустимые значения параметров: значения i и j должны лежать в диапазоне от 0 до " << list.size() - 1 << "\n";
					}
				}
				else
				{
					std::cout << "Значение i не должно превышать j\n";
				}
			}
			else
				std::cout << "Список пока не существует\n";
			break;
		case 5:
			if (existList)
				std::cout <<"Сумма всех элементов = " << Sum(list);
			else
				std::cout << "Список пока не существует\n";
			break;
		case 6:
			if (existList)
				std::cout << "Среднее арифметическое всех элементов = " << Average(list);
			else
				std::cout << "Список пока не существует\n";
			break;
		case 7:
			if (existList)
			{
				std::cout << "Список: ";
				Print(list, std::cout);
			}
			else
				std::cout << "Список пока не существует\n";
			break;
		case 8:
			if (existList)
			{
				std::cout << "Введите имя файла\n";
				std::cin >> fileName;
				std::ofstream oFile(fileName);
				Print(list, oFile);
			}
			else
				std::cout << "Список пока не существует\n";
			break;
		case 9:
			return 0;
		default:
			std::cout << "Неизвестная команда\n";
			break;
		}
	}
	return 0;
}


Iterator FindPosByIndex(DoubleList list, int index)
{
	int i = 0;
	for (Iterator elem = list.begin(); elem != list.end(); elem++)
	{
		if (i == index)
		{
			return elem;
		}
		i++;
	}
}
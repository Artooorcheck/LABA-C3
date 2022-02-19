//�������� ����� ����������
//C3
//���������: ������
//��������������: ������� �� ������� ����� ������������ �� �����


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
		std::cout << "\n�������� ���� �� �������������� ���� ������:\n\n";
		std::cout << "1. ������������� ������������������ � �����\n";
		std::cout << "2. ������� ���������� �� �����\n";
		std::cout << "3. ��������� ��� �������� �� ��������\n";
		std::cout << "4. ��������� ��� �������� �� �������� � i �� j �������\n";
		std::cout << "5. ��������� ����� ���������\n";
		std::cout << "6. ��������� ������� ��������������\n";
		std::cout << "7. ������� ������ �� �����\n";
		std::cout << "8. ������� ������ � ����\n";
		std::cout << "9. �����\n\n";

		int task;

		std::string fileName;

		std::ifstream iFile;



		std::cin >> task;

		switch (task)
		{
		case 1:

			std::cout << "������� ��� �����\n";
			std::cin >> fileName;

			int N, M;

			std::cout << "������� ���������� �����\n";
			std::cin >> N;

			std::cout << "������� ������������ �� ������ �������\n";
			std::cin >> M;

			GenerateFile(fileName, N, M);
			break;
		case 2:

			std::cout << "������� ��� �����\n";
			std::cin >> fileName;
			iFile.open(fileName);
			if (iFile.is_open())
			{
				list = ReadFileToList(iFile);
				existList = true;
			}
			else
				std::cout << "�� ������� ������� ����";
			break;
		case 3:
			if (existList)
			{
				//list = Modify(list);
				ModifyWithForeach(list);
				//list = Transform(list);
			}

			else
				std::cout << "������ ���� �� ����������\n";
			break;
		case 4:
			if (existList)
			{
				int i, j;

				std::cout << "������� i\n";
				std::cin >> i;

				std::cout << "������� j\n";
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
						std::cout << "�� ���������� �������� ����������: �������� i � j ������ ������ � ��������� �� 0 �� " << list.size() - 1 << "\n";
					}
				}
				else
				{
					std::cout << "�������� i �� ������ ��������� j\n";
				}
			}
			else
				std::cout << "������ ���� �� ����������\n";
			break;
		case 5:
			if (existList)
				std::cout <<"����� ���� ��������� = " << Sum(list);
			else
				std::cout << "������ ���� �� ����������\n";
			break;
		case 6:
			if (existList)
				std::cout << "������� �������������� ���� ��������� = " << Average(list);
			else
				std::cout << "������ ���� �� ����������\n";
			break;
		case 7:
			if (existList)
			{
				std::cout << "������: ";
				Print(list, std::cout);
			}
			else
				std::cout << "������ ���� �� ����������\n";
			break;
		case 8:
			if (existList)
			{
				std::cout << "������� ��� �����\n";
				std::cin >> fileName;
				std::ofstream oFile(fileName);
				Print(list, oFile);
			}
			else
				std::cout << "������ ���� �� ����������\n";
			break;
		case 9:
			return 0;
		default:
			std::cout << "����������� �������\n";
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
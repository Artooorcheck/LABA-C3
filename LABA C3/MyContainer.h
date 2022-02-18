#pragma once

#include<fstream>
#include<list>
#include<algorithm>
#include<iostream>

using Iterator = std::list<double>::iterator;

using DoubleList = std::list<double>;

std::ofstream& GenerateFile(std::string fileName, int N, int M);

std::list<double> ReadFileToList(std::ifstream& iFile);

double FindMaxInList(std::list<double> list);

std::list<double> Modify(std::list<double> list);

void Modify(std::list<double> list, Iterator& iter1, Iterator& iter2);

std::list<double> Transform(std::list<double> list);

void ModifyWithForeach(std::list<double>& list);

double Average(std::list<double> list);

double Sum(std::list<double> list);

void Print(std::list<double> list, std::ostream& stream);
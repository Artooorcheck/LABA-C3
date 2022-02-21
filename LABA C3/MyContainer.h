#pragma once

#include<fstream>
#include<list>
#include<algorithm>
#include<iostream>

using Iterator = std::list<double>::iterator;

using DoubleList = std::list<double>;

std::ofstream& GenerateFile(std::string fileName, int N, int M);

DoubleList ReadFileToList(std::ifstream& iFile);

double FindMaxInList(DoubleList list);

DoubleList Modify(DoubleList list);

void Modify(DoubleList list, Iterator iter1, Iterator iter2);

DoubleList Transform(DoubleList list);

void ModifyWithForeach(DoubleList& list);

double Average(DoubleList list);

double Sum(DoubleList list);

void Print(DoubleList list, std::ostream& stream);
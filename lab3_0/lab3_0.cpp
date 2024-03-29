// lab3_0.cpp: определяет точку входа для консольного приложения.
//
/*Информация  о  некотором  изделии  задана   с   помощью
ориентированного графа.  Вершина графа соответствует отдельной
операции,  а дуги показывают очередность  выполнения  операций
(каждая   операция   может   начаться   не   ранее   окончания
предшествующих операций).  Продолжительность  каждой  операции
известна.  Имеется  один  станок  для  выполнения каждого типа
операций.  Если станок освобождается,  то производится  та  из
готовых  к выполнению операций,  для которой максимальный путь
от соответствующей вершины до конца  имеет  наибольшую  длину.
Определить  время  изготовления  изделия.  Выдать общий график
выполнения операций и график загрузки каждого станка*/

#include "stdafx.h"
#include "file_funct.h"
#include "comput.h"

FILE *detailsData, *detailsPairs;
FILE *detailsReport, *machineReport;

int main(int argc, char* argv[])
{
	//Подключаем русский язык
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (argc != 5)
	{
		printf_s("\nОшибка ввода имен файла");
		return -2;
	}
	//Открываем файлы
	detailsData = open_file(detailsData, argv[1], "r");
	if (detailsData == NULL)
	{
		return -1;
	};
	detailsPairs = open_file(detailsPairs, argv[2], "r");
	if (detailsPairs == NULL)
	{
		return -1;
	};
	//Ввод даннных
	Detail *details;
	details = read_details(detailsData);
	close_file(detailsData, argv[1]);
	Pair *pairs;
	pairs = read_pairs(detailsPairs, details);	
	close_file(detailsPairs, argv[2]);
    Machine *machines;
	machines = init_machine(details);
	//Вычисления
	find_maxPath(details, pairs);	
	work(details, pairs, machines);
	//Вывод
	detailsReport = open_file(detailsReport, argv[3], "w");		
	print_details(details, detailsReport);
	close_file(detailsReport, argv[3]);
	machineReport = open_file(machineReport, argv[4], "w");
	print_machine(machines, machineReport);
	close_file(machineReport, argv[4]);
	return 0;
}


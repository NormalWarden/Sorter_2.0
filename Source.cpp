#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <algorithm>
#include "functions.cpp"


int main()
{
	setlocale(LC_ALL, "ru");
	std::string path;
	WIN32_FIND_DATA data;
	std::vector<std::string> folders = { "Archives", //needed folders to sort
										"Pictures",
										"Video",
										"Documents",
										"Music",
										"Programms",
										"Torrents" };
	std::cout << "Введите путь до директории, которую нужно отсортировать: ";
	std::getline(std::cin, path);
	HANDLE hFind = FindFirstFile((path + "\\" + "*").c_str(), &data);  // FILES 
	
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			auto file = explode(data.cFileName, '\\');
			for (int i = 0; i < file.size(); i++)
			{
				std::string expansion = getFileExt(file[i]);
				if ((expansion == "") and (folders.size() > 0)) //this is folder or file
				{
					auto finded = std::find(folders.begin(), folders.end(), file[i]); //name folder
					if (finded != folders.end())			// checking, name folder in "folders" 
					{
						folders.erase(finded);
					}
					else {
						for (std::string j : folders) //create missing folders
						{
							CreateDirectory((path + j).c_str(), NULL);
						}
					}
				}
				moveFile(path, expansion, file[i]);
			}
			
		} while (FindNextFile(hFind, &data));

		FindClose(hFind);
		std::cout << "Sorting is complete" << std::endl;
		std::cin >> path;
	}
}
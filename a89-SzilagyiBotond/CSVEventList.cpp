//
// Created by admin on 2023. 04. 20..
//

#include "CSVEventList.h"
#include <fstream>
#include "RepositoryExceptions.h"
#include <Windows.h>
void CSVEventList::writeToFile() {
    ofstream file(this->fileName);
    if (file.is_open())
        throw FileException("Cannot open file");
    for(auto e:this->events)
    {
        file<<e;
    }
    file.close();
}
void CSVEventList::displayEventList() {
    ShellExecuteA(NULL,NULL,R"(D:\I\Architectura sistemelor de calcul\ASM_tools\asm_tools\npp\notepad++.exe)",this->fileName.c_str(),NULL,SW_SHOWMAXIMIZED);
}

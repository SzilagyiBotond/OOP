//
// Created by admin on 2023. 04. 20..
//

#include "HTMLEventList.h"
#include <iostream>
#include "RepositoryExceptions.h"


void HTMLEventList::writeToFile() {
    ofstream file(this->fileName);
    if (!file.is_open())
        throw FileException("Cannot open file");
    file << "<!DOCTYPE html>\n";
    file << "<html>\n";
    file << "<head>\n";
    file << "\t" << "<title>Events</title>\n";
    file << "</head>\n";
    file << "<body>\n";
    file << "<table border=\"1\">\n";
    file << "\t<tr>\n";
    file << "\t\t<td>Title</td>\n";
    file << "\t\t<td>Description</td>\n";
    file << "\t\t<td>Time</td>\n";
    file << "\t\t<td>Nr of people</td>\n";
    file << "\t\t<td>Link</td>\n";
    file << "\t</tr>";
    for(auto e: this->events) {
        file << "\t<tr>\n";
        file << "\t\t<td>"<<e.getTitle()<<"</td>\n";
        file << "\t\t<td>"<<e.getDescription()<<"</td>\n";
        file << "\t\t<td>"<<e.getTime().year<<"|"<<e.getTime().month<<"|"<<e.getTime().day<<"</td>\n";
        file << "\t\t<td>"<<e.getNrOfPeople()<<"</td>\n";
        file << "\t\t<td>"<<"<a href=\""<<e.getLink()<<"\">Link</a>"<<"</td>\n";
        file << "\t</tr>";
    }
    file<<"</table>\n";
    file<<"</body>\n";
    file<<"</html>\n";
    file.close();

}

void HTMLEventList::displayEventList() {
    ShellExecuteA(NULL,NULL,R"(D:\I\Architectura sistemelor de calcul\ASM_tools\asm_tools\npp\notepad++.exe)", this->fileName.c_str(),NULL,SW_SHOWMAXIMIZED);
}

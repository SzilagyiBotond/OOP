//
// Created by admin on 2023. 04. 20..
//

#include "RepositoryExceptions.h"

FileException::FileException(const std::string &msg): message(msg) {

}

const char *FileException::what() {
    return this->message.c_str();
}

RepositoryException::RepositoryException(): std::exception{},message("") {

}

RepositoryException::RepositoryException(const std::string &msg): message(msg) {

}

const char *RepositoryException::what() {
    return this->message.c_str();
}

const char *NoEventException::what() {
    return "There is no such event";
}

const char *DuplicateEventException::what() {
    return "There already exists such an event";
}

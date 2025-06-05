#pragma once
#include <stdexcept>

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

class DuplicateItemException : public std::runtime_error {
  public:
    DuplicateItemException(const std::string& msg) : std::runtime_error(msg) {}
};

class ItemNotFoundException : public std::runtime_error {
  public:
    ItemNotFoundException(const std::string& msg) : std::runtime_error(msg) {}
};

#endif //EXCEPTIONS_H

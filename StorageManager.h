#pragma once
#include <unordered_map>
#include <map>
#include <memory>
#include <vector>
#include "StoredItem.h"
#include "Exceptions.h"

#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H



class StorageManager {
    private:
        std::unordered_map<std::string, std::shared_ptr<StoredItem>> itemById;
        std::map<std::string, std::shared_ptr<StoredItem>> itemByDescription;

    public:
        void addItem(const std::shared_ptr<StoredItem>& item);
        std::shared_ptr<StoredItem> findById(const std::string& id) const;
        void removeItem(const std::string& id);
        std::vector<std::shared_ptr<StoredItem>> getItemsSortedByDescription() const;
};



#endif //STORAGEMANAGER_H

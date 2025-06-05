#include "StorageManager.h"

void StorageManager::addItem(const std::shared_ptr<StoredItem>& item) {
    const std::string& id = item->getId();
    if (itemById.find(id) != itemById.end()) {
        throw DuplicateItemException("Item already exists.");
    }
    itemById[id] = item;
    itemByDescription[item->getDescription()] = item;
}

std::shared_ptr<StoredItem> StorageManager::findById(const std::string& id) const {
    auto it = itemById.find(id);
    if (it == itemById.end()) {
        throw ItemNotFoundException("Item not found.");
    }
    return it->second;
}

void StorageManager::removeItem(const std::string& id) {
    auto it = itemById.find(id);
    if (it == itemById.end()) {
        throw ItemNotFoundException("Item not found.");
    }
    std::string desc = it->second->getDescription();
    itemByDescription.erase(desc);
    itemById.erase(it);
}

std::vector<std::shared_ptr<StoredItem>> StorageManager::getItemsSortedByDescription() const {
    std::vector<std::shared_ptr<StoredItem>> items;
    for (const auto& pair : itemByDescription) {
        items.push_back(pair.second);
    }
    return items;
}

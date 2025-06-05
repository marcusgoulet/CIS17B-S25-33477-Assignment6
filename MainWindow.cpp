#include "MainWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMenuBar>
#include <QMessageBox>
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Congo Inventory System");

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Input fields
    idInput = new QLineEdit();
    descInput = new QLineEdit();
    locInput = new QLineEdit();

    findIdInput = new QLineEdit();
    findIdInput->setClearButtonEnabled(false);
    removeIdInput = new QLineEdit();

    QPushButton *addButton = new QPushButton("Add Item");
    QPushButton *findButton = new QPushButton("Find by ID");
    QPushButton *removeButton = new QPushButton("Remove by ID");

    itemList = new QListWidget();

    // Layout
    mainLayout->addWidget(new QLabel("ID:"));
    mainLayout->addWidget(idInput);
    mainLayout->addWidget(new QLabel("Description:"));
    mainLayout->addWidget(descInput);
    mainLayout->addWidget(new QLabel("Location:"));
    mainLayout->addWidget(locInput);
    mainLayout->addWidget(addButton);

    mainLayout->addWidget(new QLabel("Find by ID:"));
    mainLayout->addWidget(findIdInput);
    mainLayout->addWidget(findButton);

    mainLayout->addWidget(new QLabel("Remove by ID:"));
    mainLayout->addWidget(removeIdInput);
    mainLayout->addWidget(removeButton);

    mainLayout->addWidget(new QLabel("Item List:"));
    mainLayout->addWidget(itemList);

    setCentralWidget(centralWidget);

    // Connect buttons
    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddItemClicked);
    connect(findButton, &QPushButton::clicked, this, &MainWindow::onFindItemClicked);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveItemClicked);
}

MainWindow::~MainWindow() {}

void MainWindow::onAddItemClicked() {
    QString id = idInput->text();
    QString desc = descInput->text();
    QString loc = locInput->text();

    if (id.isEmpty() || desc.isEmpty() || loc.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled in.");
        return;
    }

    try {
        auto item = std::make_shared<StoredItem>(
            id.toStdString(),
            desc.toStdString(),
            loc.toStdString()
        );

        manager.addItem(item);
        refreshItemList();

        idInput->clear();
        descInput->clear();
        locInput->clear();
    } catch (const DuplicateItemException& e) {
        QMessageBox::warning(this, "Duplicate Item", e.what());
    }
}

void MainWindow::refreshItemList() {
    itemList->clear();

    auto items = manager.getItemsSortedByDescription();
    for (const auto& item : items) {
        QString line = QString::fromStdString(
            item->getId() + " | " + item->getDescription() + " | " + item->getLocation()
        );
        itemList->addItem(line);
    }
}

// Placeholder slots for now
void MainWindow::onFindItemClicked() {
    QString id = findIdInput->text();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an ID to search.");
        return;
    }

    try {
        auto item = manager.findById(id.toStdString());

        QString info = QString::fromStdString(
            "Description: " + item->getDescription() +
            "\nLocation: " + item->getLocation()
        );

        QMessageBox::information(this, "Item Found", info);

        // Optional: clear input AFTER showing
        //findIdInput->clear();

    } catch (const ItemNotFoundException& e) {
        QMessageBox::warning(this, "Not Found", e.what());
    }
}


void MainWindow::onRemoveItemClicked() {
    QString id = removeIdInput->text();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an ID to remove.");
        return;
    }

    try {
        manager.removeItem(id.toStdString());
        refreshItemList();
        QMessageBox::information(this, "Success", "Item removed successfully.");
        removeIdInput->clear();
    } catch (const ItemNotFoundException& e) {
        QMessageBox::warning(this, "Not Found", e.what());
    }
}

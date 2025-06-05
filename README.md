# CIS17B-S25-33477-Assignment6
    -This is a basic inventory GUI manager that allows you to add items with associated IDs, descriptions, and locations.
    -Upon running the application, you'll be met with a window that displays 3 sections:
        - Add item section with ID, Description, and Location text boxes.
            - Fill each section with the associated texts, next you will be able to click the add item button.
        - Find By ID section only has one parameter, Type an existing ID into the field and click find by ID.
            - You will be met with a separate window with the Item Description and Location.
        - Delete ID section also has one parameter, fill in desired ID then click delete.
            - You will be met with yet another window that shows the deletion has been successful.
        - There is one last section at the bottom which shows all current items added to the system; showing their ID, Descriptions, and Locations.

    - Side note: I was running into a configurations issue after cloning my repository to Clion, so I could not run / build
        traditionally, so I created a file <"run.sh">. I would type into the terminal "cmake -- build build" to build the program, the type ./run.sh to run the program.
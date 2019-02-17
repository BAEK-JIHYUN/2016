# Requirement
Visual Studio 2015

# About
This is a photo management program that provides basic folder and photo add and delete functions, search function that can be searched with various information, and a favorite function. You can search by dividing the entire folder and the current folder. It also provides full folder and file Input/Output.

# Data Structure
The list of folders to be stored in the top-level folder (Album) adopted a **linked list** structure, while the list of photos to be stored in the folder was implemented using **binary search tree**. Folders were used as a linked list beacuse folders are less frequently added and deleted than photos and if folders also use binary search tree, the program is expected to be too complex. Also the **stack** was used to move between the top and bottom folders.

# Functions
* You can **print out** the entire item contained in the current folder.
* You can **delete** the entire item contained in the current folder.
* You can **export** the photos and folders in all folders to a file.
* Conversely, you can **import** files from outside the program.
* Other program functions are largely divided into add, delete, search and favorites.
    * **add**
        1. Add a folder or photo.
        2. When you add a folder or photo, the primary key(name) is sorted in ascending order.
        3. A folder or photo with the same name cannot exist in one folder.
    * **delete**
        1. Delete the folder or photo.
        2. If you delete a folder, use the recursive function to delete all folders and photos contained in the folder to prevent memory leakage.
    * **search**
        1. For folders, you can search by name and creation period.
        2. For photos, you can search by name, event name, included person, and creation period.
            - The included people are divided into , (comma), and all photos containing the person searched are printed.
        3. All of the above items can be searched by dividing the scope into the entire folder and the current folder. 
        4. If you search for a photo with a full folder search, it will let you know the location of the photo.
    * **favorites**
        1. You can add or delete photos as favorites.
        2. Canceling a photo from a favorite does not delete it at all.
        3. You can collect and view all the photos designated as favorites.

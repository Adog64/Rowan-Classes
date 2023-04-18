/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 11/3/2021
* File Name: Lab07-1ASharpe.cpp
*****************************************************************
* ID: Lab 7 Problem 1
* Purpose: Use an array of structs to simulate an inventory management system
*****************************************************************/
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct item
{
    int skuNo;
    int qty;
};

void randomizeInventory(item[]);
void selectionSort(item[]);
void swap(item&, item&);
int binarySearch(const item[], int);

int main()
{
    int sku, pos;
    string go;
    item inventory[1000];

    randomizeInventory(inventory);
    selectionSort(inventory);

    // print the first skuNo so we can test for items that are actually carried

    cout << "Welcome to Aidan's not-sketchy-at-all store!!!" << endl
         << "Enter the SKU number of the item you are looking for to see if we have it in stock." << endl
         << "The SKU of the element at index 500 is " << inventory[500].skuNo << endl;

    do
    {
        cout << endl << "SKU #";
        cin >> sku;

        pos = binarySearch(inventory, sku);

        // check if the item is carried in inventory and print how many are carried if it is
        if (pos != -1)
            cout << "We currently have " << inventory[pos].qty << " of this item." << endl;
        else
            cout << "Sorry, we do not carry this item." << endl;

        cout << endl << "Enter <c> to continue searching.";
        cin.ignore();
        getline(cin, go);
    } while (go == "c");

}


// randomize the items that are carried in inventory
void randomizeInventory(item inventory[])
{
    srand( time(0) );
    for (int i = 0; i < 1000; i++)
    {
        inventory[i].skuNo = rand() % 99999999 + 1;
        inventory[i].qty = rand() % 100 + 1;
    }
}

// sort the array by skuNo
void selectionSort(item array[])
{
    int minIndex, minValue, size = 1000;

    for(int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = array[start].skuNo;
        for(int index = start + 1; index < size; index++)
        {
            if(array[index].skuNo < minValue)
            {
                minValue = array[index].skuNo;
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
}

// swap two inventory items
void swap(item& a, item& b)
{
    item temp = a;
    a = b;
    b = temp;
}

// return the position of the item with skuNo <value>
int binarySearch(const item array[], int value)
{
    int size = 1000,
        first = 0,
        last = size - 1,
        middle,
        position = -1;

    bool found = false;

    while(!found && first <= last)
    {
        middle = (first + last) / 2;
        if (array[middle].skuNo == value)
        {
            found = true;
            position = middle;
        }
        else if(array[middle].skuNo > value)
            last = middle - 1;
        else
            first = middle + 1;
    }

    return position;
}
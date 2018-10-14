#include <iostream>
#include <iomanip>

#define MAX_X 10
#define MAX_Y 10

#define NUM_OF_ELEMENTS MAX_X *MAX_Y

typedef int t_Array[MAX_X][MAX_Y];

void fillArray(t_Array &arr)
{
    for (int i = 0; i < MAX_X; i++)
    {
        for (int j = 0; j < MAX_Y; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void fillSpiral(t_Array &arr)
{
    int count = 1;
    int depth = 0;

    while (count <= NUM_OF_ELEMENTS)
    {

        for (int i = depth; i < MAX_Y - 1 - depth && count <= NUM_OF_ELEMENTS; i++, count++)
        {
            arr[depth][i] = count;
        }
        for (int i = depth; i < MAX_X - 1 - depth && count <= NUM_OF_ELEMENTS; i++, count++)
        {
            arr[i][MAX_Y - depth - 1] = count;
        }
        for (int i = MAX_Y - depth - 1; i > 0 + depth && count <= NUM_OF_ELEMENTS; i--, count++)
        {
            arr[MAX_X - depth - 1][i] = count;
        }
        for (int i = MAX_X - depth - 1; i > 0 + depth && count <= NUM_OF_ELEMENTS; i--, count++)
        {
            arr[i][depth] = count;
        }

        if (MAX_X / 2 == depth && MAX_Y / 2 == depth)
        {
            arr[depth][depth] = count;
            count++;
        }

        depth++;
    }
}

void printArray(t_Array &arr)
{
    for (int i = 0; i < MAX_X; i++)
    {
        for (int j = 0; j < MAX_Y; j++)
        {
            std::cout << std::setw(3) << arr[i][j] << " ";
        }
        std::cout << '\n';
    }
}

int main()
{

    t_Array spiral;

    fillArray(spiral);

    fillSpiral(spiral);

    printArray(spiral);

    return 0;
}
#include <iostream>
#include <vector>
#include <stdint.h> // for int64_t
#include <numeric>  // for accumulate
using namespace std;

/* Get maximum or minimum element in the array
    returns max: getMaxElseMinElemInArr({1, 2, 3}, 1)
    returns min: getMaxElseMinElemInArr({1, 2, 3}, 0)

    No edge cases
*/
int getMaxElseMinElemInArr(vector<int> arr, bool getMax)
{
    int64_t minElem = arr[0];
    int64_t maxElem = arr[0];
    for (uint64_t i = 0; i < arr.size(); i++)
    {
        if (arr.at(i) < minElem)
        {
            minElem = arr.at(i);
        }
        if (arr.at(i) > maxElem)
        {
            maxElem = arr.at(i);
        }
    }
    if (getMax)
    {
        return maxElem;
    }
    else
    {
        return minElem;
    }
}

/* Get index of an element in an array
    returns index if present
    returns -1 if not present

    example:
    // cout << getIndexOfElemInArr({100, 300, 200}, 300);

    No edge cases
*/
int getIndexOfElemInArr(vector<int> arr, int element)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr.at(i) == element)
        {
            return i;
        }
    }
    return -1;
}

/* Reverses the array passed (the address)
    example:
    vector<int> array = {1, 2, 3};
    reverseTheArr(&array);
    printArr(array);

    No edge cases
*/
void reverseTheArr(vector<int> *arr)
{
    int sizeOfArray = arr->size();
    for (int i = 0; i < sizeOfArray / 2; i++)
    {
        int storedIthElement = arr->at(i);
        arr->at(i) = arr->at(sizeOfArray - (i + 1));
        arr->at(sizeOfArray - (i + 1)) = storedIthElement;
    }
}

// Prints the array passed
void printArr(vector<int> arr)
{
    if (arr.size() == 0)
        return;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr.at(i) << " ";
    }
    cout << endl;
}

struct TwoMax
{
    int firstMax;
    int secondMax;
};

/* Get first and second maximum element in the array
    -1: for when no max found

    example:
    vector<int> array = {1, 2, 3};
    cout << "First max: " << firstAndSecondMaxElementInArr(array).firstMax << ", SecondMax: " << firstAndSecondMaxElementInArr(array).secondMax;

    Edge cases:
    input, firstMax, secondMax
    {}, -1, -1
    {x}, x, -1
    {x,x}, x, x
*/
TwoMax firstAndSecondMaxElementInArr(vector<int> arr)
{
    TwoMax result;
    result.firstMax = (arr.size() < 1) ? -1 : arr.at(0);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr.at(i) > result.firstMax)
        {
            result.firstMax = arr.at(i);
        }
    }
    result.secondMax = (arr.size() < 2) ? -1 : result.firstMax;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr.at(i) > result.secondMax && arr.at(i) != result.firstMax)
        {
            result.secondMax = arr.at(i);
        }
    }

    return result;
}

// Returns the element present in the fibonacci series at the index(first index is 1) passed
int elementAtIthIndexInFibonacci(int atIndex)
{
    vector<int> fibonacciSeries = {0, 1};
    for (int i = 2; i < atIndex; i++)
    {
        fibonacciSeries.push_back(fibonacciSeries.at(i - 1) + fibonacciSeries.at(i - 2));
    }
    return fibonacciSeries.at(atIndex - 1);
}

// Rotates the array once array(1, 2, 3) becomes (3, 1, 2)
void rotateTheArrayOnce(vector<int> *arr)
{
    int arraySize = arr->size();
    int lastElem = (arraySize == 0) ? -1 : arr->at(arraySize - 1);
    for (int i = arraySize - 1; i > 0; i--)
    {
        arr->at(i) = arr->at(i - 1);
    }
    if (arraySize > 0)
    {
        arr->at(0) = lastElem;
    }
}

/* Missing element in array
    For an array arr[] of size n - 1 that contains distinct integers
    In the range from 1 to n (inclusive).
    This array represents a permutation of the integers from 1 to n with one element missing.
    So, This function Return that missing element.

    Examples:

    Input: arr[] = [1, 2, 3, 5]
    Output: 4
    Explanation: All the numbers from 1 to 5 are present except 4.
*/
int elementMissingInArr(vector<int> arr)
{
    if (arr.size() < 1)
        return -1;
    int calculatedSum = accumulate(arr.begin(), arr.end(), 0);
    int sumShouldBe = ((arr.size() + 1) * (1 + (arr.size() + 1))) / 2;
    return sumShouldBe - calculatedSum;
}

// Selection sort
void selectionSort(vector<int> *arr)
{
    for (int outerI = 0; outerI < arr->size(); outerI++)
    {
        int minElement = arr->at(outerI);
        int IndexOfMinElement = outerI;
        for (int innerI = outerI; innerI < arr->size(); innerI++)
        {
            if (arr->at(innerI) < minElement)
            {
                minElement = arr->at(innerI);
                IndexOfMinElement = innerI;
            }
        }
        int copyOfMinElement = arr->at(IndexOfMinElement);
        arr->at(IndexOfMinElement) = arr->at(outerI);
        arr->at(outerI) = copyOfMinElement;
    }
}

// Bubble sort
void bubbleSort(vector<int> *arr)
{
    for (int outerI = arr->size() - 1; outerI > 0; outerI--)
    {
        for (int innerI = 0; innerI < outerI; innerI++)
        {
            if (arr->at(innerI) > arr->at(innerI + 1))
            {
                swap(arr->at(innerI), arr->at(innerI + 1));
            }
        }
    }
}

// Insertion sort
void insertionSort(vector<int> *arr)
{
    for (int outerI = 1; outerI < arr->size() - 1; outerI++)
    {
        for (int innerI = outerI; innerI > 0; innerI--)
        {
            if (arr->at(innerI) < arr->at(innerI - 1))
            {
                swap(arr->at(innerI), arr->at(innerI - 1));
            }
            else
            {
                break;
            }
        }
    }
}

// Binary search
int binarySearch(vector<int> arr, int elem)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr.at(mid) == elem)
        {
            return mid;
        }
        else if (arr.at(mid) > elem)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int main()
{
    cout << binarySearch({4}, 4);
    return 0;
}
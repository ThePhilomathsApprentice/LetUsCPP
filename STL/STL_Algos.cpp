#include <algorithm>
#include <vector>

#include <iostream>

void printVector(std::vector<int> path)
{

    for (auto i : path)
        std::cout << i << ' ';

    std::cout << '\n';
}

void printVector(std::vector<char> path)
{

    for (auto i : path)
        std::cout << i << ' ';

    std::cout << '\n';
}

int main()
{

    /* ++++++++++ HEAPS ++++++++++ */
    {
        // Initializing a vector
        std::vector<int> v1 = {20, 30, 40, 50, 1};

        std::cout << " +++++ HEAPS +++++ \n v1: ";
        printVector(v1);
        std::make_heap(v1.begin(), v1.end()); //Modifies the vector.
        printVector(v1);

        std::cout << "The maximum element of heap is : ";
        std::cout << "v1.front()=" <<  v1.front() << "\n";
        std::cout << "v1.back()=" <<  v1.back() << "\n";

        printVector(v1);
        std::cout << "Pushing 100 in v1:\n";
        v1.push_back(100);
        printVector(v1);

        std::cout << "Pushing heap with 100 in v1:\n";
        std::push_heap(v1.begin(), v1.end());
        printVector(v1);

        std::cout << "Popping heap v1:\n";
        std::pop_heap(v1.begin(), v1.end());
        printVector(v1);

        std::cout << "Popping from v1:\n";
        v1.pop_back();
        printVector(v1);

        std::cout << "Sorting Heap:\n";
        std::sort_heap(v1.begin(), v1.end());
        printVector(v1);
        std::cout << "The maximum element of heap is : \n";
        std::cout << "v1.back()=" <<  v1.back() << "\n";
        std::cout << "v1.front()=" <<  v1.front() << "\n";

        std::vector<char> v2 = {'A', 'B', 'X', 'Z', 'Y'};

        printVector(v2);
        make_heap(v2.begin(), v2.end()); //Modifies the vector.
        printVector(v2);

        std::cout << "The maximum element of heap is : ";
        std::cout << v2.front() << "\n";

    }

    /* ++++++++++ SORTING ++++++++++ */
    {
        // Initializing a vector
        std::vector<int> v1 = {50, 40, 30, 20, 10 , 9,8,7,6,5,4,3,2,1};

        std::cout << " +++++ Sorting +++++ \n v1: ";
        printVector(v1);

        // std::cout << "Sorting Heap:\n";
        // std::sort_heap(v1.begin(), v1.end());
        // printVector(v1);//Will not sort as the v3 is not a heap already.

        std::cout << "Partially Sorting v1:\n";
        std::partial_sort(v1.begin(),v1.begin()+5, v1.end()); //Modifies the vector.
        printVector(v1);

        std::cout << "Sorting v1:\n";
        std::sort(v1.begin(), v1.end()); //Modifies the vector.
        printVector(v1);

        std::cout << "nth_element:\n";
        std::nth_element(v1.begin(), v1.begin()+5, v1.end()); //Modifies the vector.
        printVector(v1);

    }
}

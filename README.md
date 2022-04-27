<h3> # CSC212 - Final Project Sorting Algorithms</h4>

<strong>Tyler, Cam, Ericsen, Bowen Drawbridge</strong>

> This program will take 1 parameter to run: ./sorting_algorithms
>> You will then be prompted to enter a sort type: 'insertion' || 'merge' || 'quick' || 'heap'
>>> Then enter the input file from which you will be reading: 'input_file.txt'
>>>> Lastly enter a custom name for the sorted output file: 'output_sort.txt'


<h2> Insertion Sort </h2>
<p>Insertion Sort uses the logic used when ordering a deck of cards in acendinig order. The unsorted cards are layed out in a row left to right. As you look at each card you check the card you're looking at is not less than the ones to the left. If it is you place it in the right spot and push the other cards down right. This repeats until all the cards are sorted.</p>

<h2> Mergesort </h2>
<p>some paragraph about MergeSort here</p>

<h2> Quicksort </h2>
<p>Quicksort is an in-place divide and conquer algorithm that uses a pivot element to partition the input array into two sub-arrays, which are then sorted recursively. When implemented well it can be faster than mergesort and multiple times faster than heap sort. A mathmatical analysis of quicksort proves that, worst case, the algorithm runs in O(n^2) and on average it runs in O(n logn) time.</p>

<h2> Heap Sort </h2>
<p>Heap Sort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element from it and inserting it into the sorted region. It does not waste time with a linear-time scan of the unsorted region; rather, heap sort maintains the unsorted region in a heap data structure to more quickly find the largest element in each step.</p>

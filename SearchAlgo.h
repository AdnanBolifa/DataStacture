#pragma once
#ifndef SEARCH_ALGO_H
#define SEARCH_ALGO_H

class SearchAlgo {
public:
    static int binarySearch(const int arr[], int size, int target);
    static int sequentialSearch(const int arr[], int size, int target);
    static int linearSearch(const int arr[], int size, int target);
};

#endif



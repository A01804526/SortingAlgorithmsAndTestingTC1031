#include "includes.hpp"
#include "testassets.hpp"

//as seen in class: 20 oct 2026
void selection_sort(vector<int>& data) {
    for (int i=0; i<data.size(); ++i) {
        int min_index = i;
        for (int j=i+1; j<data.size(); ++j) {
            if (data[j]<data[min_index]) {
                min_index=j;
            }
        }
        swap(data[min_index],data[i]);
        //print_vector(data);
    }
}

// done by us based on the book:
void insertion_sort(vector<int>& data) {
    for (int i=0; i<data.size(); ++i) {
        for (int j = 0; j<i; ++j) {
            if (data[j]>data[i]) {
                swap(data[j],data[i]);
                //print_vector(data);
            }
        }
    }
}

void bubble_sort(vector<int>& data) {
    // we assume its sorted
    bool ns = true;
    while(ns) {
        ns = false;
        // we use ulong because it prevents problems on this one...
        for (ulong i = 1; i<data.size(); ++i) {
            if (data[i]<data[i-1]) { // if it is not sorted
                swap(data[i],data[i-1]); //we fix it
                ns = true; // and it wasn't sorted after all
            }
        }
        //same thing here, but the other way around for speed.
        for (ulong i = data.size()-1; i>0; --i) {
            if (data[i]<data[i-1]) {
                swap(data[i],data[i-1]);
                ns = true;
            }
        }
    }
}

#include <vector>
using namespace std;

void quick_sort(vector<int>& values, int start, int end)
{
    if (start >= end) return;
    int divider = values[start];
    int lo = start;
    int hi = end;
    while (true)
    {
        while (values[hi] >= divider)
        {
            hi = hi - 1;
            if (hi <= lo) break;
        }
        if (hi <= lo)
        {
            values[lo] = divider;
            break;
        }
        values[lo] = values[hi];
        lo = lo + 1;
        while (values[lo] < divider)
        {
            lo = lo + 1;
            if (lo >= hi) break;
        }
        if (lo >= hi)
        {
            lo = hi;
            values[hi] = divider;
            break;
        }
        values[hi] = values[lo];
    }

    // Recursively sort the two halves.
    quick_sort(values, start, lo - 1);
    quick_sort(values, lo + 1, end);
}

// wrapper for first call
void quick_sort(vector<int>& data) {
    quick_sort(data,0,(int)data.size()-1);
}

void merge_sort(vector<int>& data,vector<int>& scratch,int start, int end) {
    if (start == end) {return;}
    int midpoint = (start + end) / 2;

    merge_sort(data, scratch, start, midpoint);
    merge_sort(data, scratch, midpoint + 1, end);

    int left_index = start;
    int right_index = midpoint + 1;
    int scratch_index = left_index;
    while ((left_index <= midpoint) && (right_index <= end)) {
        if (data[left_index] <= data[right_index]) {
            scratch[scratch_index] = data[left_index];
            ++left_index;
        }
        else {
            scratch[scratch_index] = data[right_index];
            ++right_index;
        }
        ++scratch_index; 
    }

    for (int i=left_index; i<=midpoint; ++i) {
        scratch[scratch_index] = data[i];
        ++scratch_index;
    }
    for (int i=right_index; i<=end; ++i) {
        scratch[scratch_index] = data[i];
        ++scratch_index;
    }

    for (int i=start; i<=end; ++i) {
        data[i] = scratch[i];
    }
}

// wrapper for first call
void merge_sort(vector<int>& data) {
    int size = data.size();
    vector<int> b(size);
    merge_sort(data,b,0,size-1);
}

void counting_sort(vector<int>& data,int max) {
    // make a vector whose size is of the different numbers to sort
    // then set it all to 0
    vector<int> vals(max+1);
    for (int i=0; i<=max; ++i) {
        vals[i]=0;
    }
    // whenever there is a number, we increment it's position by one.
    for (int x : data) {
        ++vals[x];
    }

    //now, data is encoded as position in vector = number
    //                        value on vector = amount of times seen

    int index=0;
    // we force it back into the original vector.
    for (int i=0; i<=max; ++i) {
        for (int j=1; j<=vals[i]; ++j) {
            data[index] = i;
            ++index;
        } 
    }

}
// wrapper for our testing env
void counting_sort(vector<int>& data) {
    counting_sort(data,MAXNUMBERINVECS);
}
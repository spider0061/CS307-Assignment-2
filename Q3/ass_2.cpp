
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<chrono>
#include<pthread.h>
#include<time.h>
#include<stdlib.h>
int size;
int *a;
struct Merge_data {
  int first, last;
  int level;
};

using namespace std;
using namespace std::chrono; 
void merge_arrays(int arr[], int first, int mid, int last)
{
  int first2= mid+1;
  if (arr[mid] <= arr[first2]) {
        return;
    }
   while (first <= mid && first2 <= last) {
 
        // If element 1 is in right place
        if (arr[first] <= arr[first2]) {
            first++;
        }
        else {
            int value = arr[first2];
            int index = first2;
 
            // Shift all the elements between element 1
            // element 2, right by 1.
            while (index != first) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[first] = value;
 
            // Update all the pointers
            first++;
            mid++;
            first2++;
        }
    }
}
void merge_sort(int arr[], int l, int r)
{
    if (l < r) {
 
       
        int m = l + (r - l) / 2;
 
       
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
 
        merge_arrays(arr, l, m, r);
    }
}
void launch_thread (pthread_t &t, 
                    Merge_data &md, 
                int first, int last, int level);
void join_merge(pthread_t &t1, pthread_t &t2,
                int first, int mid, int last)
{
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);  
  merge_arrays(a, first, mid, last);
  
}
void *pmerge_sort(void *arg)
{
   
  
  Merge_data *md = (Merge_data *)arg;
  int first = md->first, last = md->last;
  int level = md->level; 
  //cout<<first<<last<<endl;
  if (last <= first) return arg;
  if (level == 0)
    merge_sort (a, first, last);
  else {
    pthread_t t1, t2;
    Merge_data md1, md2;
    int mid = (first+last)/2;
    launch_thread(t1, md1, first, mid, level-1);
    launch_thread(t2, md2, mid+1, last, level-1);
    join_merge(t1, t2, first, mid, last);
  }
}
void launch_thread (pthread_t &t, 
                    Merge_data &md, 
                int first, int last, int level)
{
  md.first = first;
  md.last = last;
  md.level = level;
  void * ptr_md = (void *)&md;
  pthread_create(&t, NULL, pmerge_sort, ptr_md);
}

int main (int argc, char **argv) { 
  auto start = high_resolution_clock::now();
  int size = atoi((argv[2]));;
  int lev = atoi((argv[1]));;
  int level = (int) round(log2(lev));
  
  a = new int[size];
  for(int i=0;i<size;i++)
  {
    a[i]=rand()%44;
  }
  cout<<"Initial Array: ";
  for(int i=0;i<size;i++)
  {
    cout<<a[i]<<"   ";
  }
  cout<<endl;
  Merge_data md = {0, size-1, level};
  pthread_t t;
  pthread_create(&t, NULL, pmerge_sort, (void *) (&md));
  pthread_join(t, NULL); 
  cout<<"Final Array: ";
  for(int i=0;i<size;i++)
  {
    cout<<a[i]<<"   ";
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "\nTime taken by program: "
         << duration.count() << " microseconds" << endl; 
}
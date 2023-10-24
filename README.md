# Sorting Algorithms & Big O

This pair programming project is focused on implementing and understanding various sorting algorithms to gain a deeper knowledge of their functionality and performance characteristics.


## Implemented Sorting Algorithms

1. **Bubble Sort**
2. **Insertion Sort**
3. **Selection Sort**
4. **Quick Sort**
5. **Shell Sort with Knuth Sequence**
6. **Cocktail Shaker Sort**
7. **Counting Sort**
8. **Merge Sort**
9. **Heap Sort**
10. **Quick Sort - Hoare Partition Scheme (Unfinished)**

## Usage
To use the implemented sorting algorithms, follow these steps:

1. Find the file for the sorting algorithm you want to use and navigate to its page.

2. Click on the "Raw" button on the top right of the file's content, which will display the file in plain text format.

3. Copy the URL from your browser's address bar. It will look something like:
```https://raw.githubusercontent.com/username/repo/branch/path/to/file/filename.extension```

4. In your terminal, use 'curl' to download the file. Replace the URL with the one you copied:
```bash
curl -o exapmle_sort.c https://raw.githubusercontent.com/username/repo/branch/path/to/file/filename.extension
```
Replace 'example_sort.c' with the desired filename you want.

5. To incorporate the sorting algorithm into your code, you can:
- Add the sorting algorithm function declaration to a header file to use it across multiple files.
- Edit the downloaded file by adding a `main()` function for testing and integration.

**Note:** The sorting algorithms come with printing functions that display the array or list after each swap. Make sure to remove these printing functions if you don't need them. If you want to keep this behavior, repeat the previous steps for the desired printing function file.

Happy sorting!

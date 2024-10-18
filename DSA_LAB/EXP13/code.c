#include <stdio.h>

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int find_min(int *arr, int start, int end)
{
    int min_index = start;
    for (int i = start + 1; i < end; i++)
    {
        if (arr[i] < arr[min_index])
        {
            min_index = i;
        }
    }
    return min_index;
}

void selection_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_index = find_min(arr, i, n);
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {8, 0, 1, 7, 3};
    int n = 5;
    int choice;

    do
    {
        printf("Choose sorting method:\n");
        printf("1. Selection Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            selection_sort(arr, n);
            printf("Array after Selection Sort: ");
            print(arr, n);
            break;
        case 2:
            bubble_sort(arr, n);
            printf("Array after Bubble Sort: ");
            print(arr, n);
            break;
        case 3:
            insertion_sort(arr, n);
            printf("Array after Insertion Sort: ");
            print(arr, n);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice, try again.\n");
        }
    } while (choice != 4);

    return 0;
}
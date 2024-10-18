#include <stdio.h>

int search_book_by_id(int book_ids[], int left, int right, int target_id)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (book_ids[mid] == target_id)
            return mid;

        if (book_ids[mid] < target_id)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    int book_ids[] = {101, 205, 310, 412, 523, 634, 765, 876, 999};
    int n = sizeof(book_ids) / sizeof(book_ids[0]);
    int target_id;

    printf("Enter the book ID to search for: ");
    scanf("%d", &target_id);

    int result = search_book_by_id(book_ids, 0, n - 1, target_id);

    if (result != -1)
        printf("Book found at position %d on the shelf.\n", result + 1);
    else
        printf("Book not found in the library.\n");

    return 0;
}
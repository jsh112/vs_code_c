#include <stdio.h>
#include <stdlib.h>

/*
 * Implementing String Functions from <string.h>
 * This document implements common string manipulation functions
 * typically found in the C standard library <string.h>.
 */

// Function prototype: size_t my_strlen(const char *s)
/**
 * @brief Returns the length of the string.
 * This function calculates the length of the string pointed to
 * by 's', excluding the null terminator.
 *
 * @param s Pointer to the input string.
 * @return The length of the string.
 */
size_t my_strlen(const char *s) {
    const char *tmp = s;
    while (*tmp) {
        tmp++;
    }
    return tmp - s;
}
// -----------------------------------------------------------------

/**
 * @brief Converts a string to an integer (atoi equivalent).
 *
 * This function skips leading whitespace, checks for a sign, and
 * converts numeric characters to an integer until a non-numeric
 * character is encountered.
 *
 * @param s Pointer to the input string representing the integer.
 * @return The integer value represented by the string.
 */
int my_atoi(const char *s) {
    int num = 0, sign = 1;

    // Skip leading whitespace
    while (*s == ' ') {
        s++;
    }

    // Check for a negative sign
    if (*s == '-') {
        sign = -1;
        s++;  // Move to the next character
    }

    // Convert string to integer
    while (*s >= '0' && *s <= '9')  // Fixed condition: changed 's' to '*s'
    {
        num = num * 10 + (*s - '0');
        s++;
    }

    return sign * num;
}

// Function prototype: char *my_strcpy(char *dest, const char *src)
/**
 * @brief Copies a string from source to destination.
 *
 * This function copies the string from `src` to `dest`, including
 * the null terminator, and returns the original address of `dest`.
 *
 * @param dest Pointer to the destination buffer.
 * @param src Pointer to the source string to be copied.
 * @return Pointer to the destination string (original `dest`).
 */
char *my_strcpy(char *dest, const char *src) {
    char *tmp = dest;
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';  // Null-terminate the destination string
    return tmp;    // Return the original destination address
}

/**
 * Function prototype: char *my_strncpy(char *dest, const char *src)
 * @brief Copies a string from source to destination.
 *
 * This function copies the string from `src` to `dest`, including
 * the null terminator, and returns the original address of `dest`.
 *
 * @param dest Pointer to the destination buffer.
 * @param src  Pointer to the source string to be copied.
 * @param n    Integer to represent of length.
 * @return     Pointer to the destination string (original `dest`).
 */

char *my_strncpy(char *dest, const char *src, size_t n) {
    char *origin = dest;
    while (n > 0 && *src) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    while (n > 0) {
        *dest = '\0';
        dest++;
        n--;
    }
    return origin;
}

// To add block comments, use Shift + Alt + A to create /* */ comment blocks.
// ------------------------------------------------------------------
// int strcmp(const char *s1, const char *s2);

/**
 * Compares two strings.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return
 *   0 if the strings are the same,
 *   a positive value if s1 is greater than s2,
 *   a negative value if s1 is less than s2.
 *
 * The comparison is done lexicographically based on ASCII values.
 * If the first non-matching character in s1 has a greater ASCII value,
 * s1 is considered greater. Conversely, if it has a smaller ASCII value,
 * s1 is considered less.
 */

int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2)  // Continue until the end of either string
    {
        if (*s1 != *s2)  // If characters are different
        {
            return *s1 - *s2;  // Return the difference between the characters
        }
        s1++;
        s2++;
    }

    // If one string has ended, return the difference between them
    return *s1 - *s2;  // This will be zero if both strings ended simultaneously
}

/**
 * @brief Sets a block of memory to a specified value.
 *
 * This function fills the first `n` bytes of the memory area pointed to by `ptr`
 * with the constant byte value specified by `value`.
 *
 * @param ptr Pointer to the block of memory to be filled.
 * @param value The value to be set. The value is passed as an `int`, but
 *              it is converted to an unsigned char when filling the memory.
 * @param n Number of bytes to be set to the value.
 * @return Pointer to the memory area `ptr`.
 *
 * @note This function does not check the boundaries of the memory area.
 *       Ensure that the size of the memory block is sufficient to avoid
 *       buffer overflows.
 *
 * @warning Using `memset` on memory that has been freed or is not allocated
 *          can lead to undefined behavior.
 */
void *my_memset(void *ptr, int value, size_t n) {
    unsigned char *p = ptr;
    while (n--) {
        *p++ = (unsigned char)value;
    }
    return ptr;
}

/**
 * @brief Parses an array declaration and extracts the data type, array name, and dimensions.
 *
 * This function reads an array declaration from standard input, such as "int arr[5][6][7];",
 * and extracts the data type ("int"), the array name ("arr"), and the dimensions (5, 6, 7).
 * The dimensions are stored in the provided array `arr_dim`.
 *
 * @param type Pointer to a character array where the data type will be stored.
 * @param name Pointer to a character array where the array name will be stored.
 * @param arr_dim Pointer to an integer array where the dimensions will be stored.
 */

void input_array(char *type, char *name, int *arr_dim) {
    char c;
    int idx_arr = 0;
    scanf("%s %[^[]", type, name);

    while ((c = getchar()) != ';') {
        if (c == '[') {
            int num = 0;
            while ((c = getchar()) >= '0' && c <= '9') {
                num = 10 * num + (c - '0');
            }
            arr_dim[idx_arr++] = num;
        }
    }
}
/**
 * @brief sorting using bubble sort algorithm
 *
 * @param int* arr : the start address of int array of main
 * @param int n : the number of elements
 */
void bubble_sort(int *arr, int n) {
    for (int scan = 0; scan < n - 1; scan++) {
        for (int i = 0; i < n - scan - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }
}

void binary_search(int *arr, int n, int target) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end) {
        if (arr[target] > arr[mid]) {
            start = mid + 1;
        } else if (arr[target] < arr[mid]) {
            end = mid - 1;
        } else {
            printf("%d\n", arr[mid]);
            break;
        }
    }
}

int main() {
    char type[50], arr_name[50], c;
    int dim[10] = {0};
    int num_dims = 0;

    // input_array(type, arr_name, dim);
    // int arr[5] = {2, 1, 8, 9, 3};
    // bubble_sort(arr, 5);
    // binary_search(arr, 5, 2);
    // for (int i = 0; i < 5; i++) {
    //     printf("%d ", arr[i]);
    // }

    char *p = "abcde";

    p = (char *)malloc(sizeof(char) * 30);
    scanf("%s",p);
    
    p[5] = 'c';

    return 0;
}
#include <stdio.h>

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
size_t my_strlen(const char *s)
{
    const char *tmp = s;
    while (*tmp)
    {
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
int my_atoi(const char *s)
{
    int num = 0, sign = 1;

    // Skip leading whitespace
    while (*s == ' ')
    {
        s++;
    }

    // Check for a negative sign
    if (*s == '-')
    {
        sign = -1;
        s++; // Move to the next character
    }

    // Convert string to integer
    while (*s >= '0' && *s <= '9') // Fixed condition: changed 's' to '*s'
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
char *my_strcpy(char *dest, const char *src)
{
    char *tmp = dest;
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0'; // Null-terminate the destination string
    return tmp;   // Return the original destination address
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

char *my_strncpy(char *dest, const char *src, size_t n)
{
    char *origin = dest;
    while (n > 0 && *src)
    {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    while (n > 0)
    {
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

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2) // Continue until the end of either string
    {
        if (*s1 != *s2) // If characters are different
        {
            return *s1 - *s2; // Return the difference between the characters
        }
        s1++;
        s2++;
    }

    // If one string has ended, return the difference between them
    return *s1 - *s2; // This will be zero if both strings ended simultaneously
}

// -------------------------------------------------------------------

// -------------------------------------------------------------------

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
void *my_memset(void *ptr, int value, size_t n)
{
    unsigned char *p = ptr;
    while (n--)
    {
        *p++ = (unsigned char)value;
    }
    return ptr;
}

// void *memcpy(void *dest, const void *src, size_t n);
// void *memmove(void *dest, const void *src, size_t n);
// int memcmp(const void *s1, const void *s2, size_t n);
// -------------------------------------------------------------------

// char *strcat(char *dest, const char *src);
// char *strncat(char *dest, const char *src, size_t n);
// char *strchr(const char *s, int c);
// char *strrchr(const char *s, int c);
// char *strstr(const char *haystack, const char *needle);
// char *strtok(char *str, const char *delim);
// size_t strspn(const char *s, const char *accept);
// size_t strcspn(const char *s, const char *reject);
// char *strpbrk(const char *s, const char *accept);

// hi
int main()
{
    char a[100] = "Hello";
    const char *b = "abcdefghijk";

    printf("%s\n", my_strcpy(a, b));
    return 0;
}
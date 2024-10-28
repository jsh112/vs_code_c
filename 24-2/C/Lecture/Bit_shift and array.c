#include <stdio.h>
const int SZ = 10;

/*
 * 1. bit shift를 <<로 하는 코드
 */

void left_shift(unsigned int *arr, int *N)
{
	const int BIT = 8;
	const int LEN = 4;
	const int BITS = BIT * LEN;

	for (int i = 0; i < LEN; i++)
	{
		scanf("%X", arr + i);
	}
	scanf("%u", N);

	// 오른쪽에서 왼쪽으로 가야하니
	// dest가 왼쪽 (i), src가 오른쪽(i + N)가 된다.
	for (int dst_bit_idx = 0; dst_bit_idx < BITS; dst_bit_idx++)
	{
		int src_bit_idx = dst_bit_idx + *N;

		int src_byte_idx = src_bit_idx / BIT;
		// 0b0001 0000처럼 특정 자리만 1로 만드는것
		int src_bit_mask = 0x80 >> (src_bit_idx % BIT);

		int dst_byte_idx = dst_bit_idx / BIT;
		// 0b0001 0000처럼 특정 자리만 1로 만드는것
		int dst_bit_mask = 0x80 >> (dst_bit_idx % BIT);

		int src_bit_value = 0;
		if (src_bit_idx < BITS)
			src_bit_value = arr[src_byte_idx] & src_bit_mask;

		if (src_bit_value)
			arr[dst_byte_idx] |= dst_bit_mask;
		else
			arr[dst_byte_idx] &= ~dst_bit_mask;
	}
}

/*
 * 2. bit shit를 >>로 하는 코드
 */

void right_shift(unsigned int *arr, int *N)
{
	const int BIT = 8;
	const int SZ = 10;
	const int ALL_BITS = BIT * SZ;

	for (int i = 0; i < SZ; i++)
	{
		scanf("%X", arr + i);
	}
	scanf("%u", N);

	for (int dest_bit = ALL_BITS - 1; dest_bit >= 0; dest_bit--)
	{
		// 왼쪽에서 오른쪽으로 가야함
		int src_bit = dest_bit - *N;

		int src_byte = src_bit / BIT;
		int src_mask = 0x80 >> (src_bit % BIT);

		int dest_byte = dest_bit / BIT;
		int dest_mask = 0x80 >> (dest_bit % BIT);

		int src = 0;
		if (src_bit >= 0)
			src = arr[src_byte] & src_mask;
		if (src)
			arr[dest_byte] |= dest_mask;
		else
			arr[dest_byte] &= ~dest_mask;
	}
}

/*
 * 3. 하위 N비트를 가져오는 코드
 */

void ReturnBits_LSB(unsigned int arr, int N)
{
	printf("%X", arr >> N);
}

/*
 * 4. 상위 N비트를 출력하는 코드
 */

void ReturnBits_MSB(unsigned int arr, int N)
{
	printf("%X", arr >> (8 - N));
}

/**
 * 5. unsigned int 한개가 주어지면
 * 상위 2비트씩 먼저 조합해서 MSB의 첫 바이트를 구성
 * 다음 2비트씩을 조합해서 2번째 바이트...
 * 해서 하나의 unsigned int를 하나 만들자
 */

void prob_5(unsigned int *A, unsigned int *ans)
{
	// 입력 받기
	for (int i = 0; i < 4; i++)
		scanf("%X", (A + i));

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			unsigned int byte_mask = (A[j] >> (i * 8)) & 0xFF;
			ans[i] |= (byte_mask << (j * 8));
		}
	}

	for (int i = 0; i < 4; i++)
	{
		printf("%X ", *(ans + i));
	}
}

/**
 * prob_6
 * unsigned int A와 int N이 들어올 때
 * 묶음당 비트 1의 개수(N개씩의 묶음)가 몇개인지 출력
 */

void prob_6(unsigned int *A, int *N)
{
	scanf("%u %d", A, N);
	int cnt = 0;
	unsigned int mask = 0x01 << 31;
	for (int i = 0; i < 32; i++)
	{
		if (*A & mask)
			cnt++;
		mask >>= 1;
		if ((i + 1) % *N == 0 || i == 31)
		{
			printf("%d ", cnt);
			cnt = 0;
		}
	}
}

int main()
{
	// 1. 왼쪽 시프트 예제
	/*
	unsigned int data[10], N;
	left_shift(data, &N);

	for (int i = 0; i < 10; i++)
		printf("%X ", data[i]);
	*/

	// 2. 오른쪽 시프트 예제

	/*
	unsigned int data[SZ],N;
	right_shift(data, &N);

	for (int i = 0; i < SZ; i++)
		printf("%X ", data[i]);
	*/

	// 3, 4
	/* unsigned int a = 0xDF;
	int N = 3;
	ReturnBits_MSB(a, N);
	*/

	/* unsigned int A[4];
	unsigned int ans[4] = {0};

	prob_5(A, ans); */

	/* unsigned int A;
	int N;
	prob_6(&A, &N);
	*/

	return 0;
}
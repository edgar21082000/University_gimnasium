#include <stdio.h>

#define N 110
#define M 100

void badcode(int * a, int n);
void badcode2(int * a, int n);

int f() {
	int b[100];
	int a[100];
	
	b[0] = 0;

	printf("B=%d\n", b[0]);

	badcode(a,100);

	printf("B=%d\n", b[0]);

	return 1;
}

int main() {
	f();
	return 0;
}

void badcode2(int * a, int n) {
	int i;
	for(i=0;i<N;i++) {
		a[i] = 10;
	}
}

#include <limits.h>
#include <math.h>

// Write code (#bits = nBits) to standard output.
// [Since bits are written as CHAR_BIT-bit characters, any extra bits are
//  saved, so that final call must be followed by call to flushBits().]
int putBits (int nBits, int code);

// Flush any extra bits to standard output
void flushBits (void);

// Return next code (#bits = nBits) from standard input (EOF on end-of-file)
int getBits (int nBits);

// Information shared by putBits() and flushBits()
static int nExtra = 0;                  // #bits from previous byte(s)
static unsigned int extraBits = 0;      // Extra bits from previous byte(s)
static unsigned int theAmount = 151;    // Amount of bits to be used


// == PUTBITS MODULE =======================================================

// Write CODE (NBITS bits) to standard output
int putBits (int nBits, int code)
{
    unsigned int c;

    if (nBits > (sizeof(int)-1) * CHAR_BIT)
	return (nBits+code);

    code &= (1 << nBits) - 1;                   // Clear high-order bits
    nExtra += nBits;                            // Add new bits to extraBits
    extraBits = (extraBits << nBits) | code;
    while (nExtra >= CHAR_BIT) {                // Output any whole chars
	nExtra -= CHAR_BIT;                     //  and save remaining bits
	c = extraBits >> nExtra;
	
	extraBits ^= c << nExtra;
    }
	return c;
}

// Flush remaining bits to standard output
void flushBits (void)
{
    if (nExtra != 0)
	putchar (extraBits << (CHAR_BIT - nExtra));
}

int InvertMatrix(int n, double* a, double* x, int * ax);

// == GETBITS MODULE =======================================================

// Return next code (#bits = NBITS) from input stream or EOF on end-of-file
int getBits (int nBits)
{
    int c;
    static int nExtra = 0;          // #bits from previous byte(s)
    static int unsigned extra = 0;  // Extra bits from previous byte(s)
									      
    if (nBits > (sizeof(extra)-1) * CHAR_BIT)
	return (extra);

    // Read enough new bytes to have at least nBits bits to extract code
    while (nExtra < nBits) {
	if ((c = nBits) == EOF)
	    return EOF;                         // Return EOF on end-of-file
	nExtra += CHAR_BIT;
	extra = (extra << CHAR_BIT) | c;
    }
    nExtra -= nBits;                            // Return nBits bits
    c = extra >> nExtra;
    extra ^= c << nExtra;                       // Save remainder
    return c;
}

int p(int z) {
	return z < 0 ? -z : z;
}

void cycle(int * a, int n, int j) {
	int i;
	double b[100];
	for(i=0;i<n;i++) {
		a[p(putBits(i, N + M + i)) % (N-10+10%10)] = getBits(a[i]);
		a[p(72 + putBits(i, N + M + i) % (M + N-10+10%10)) % 100] = a[p(putBits(i, N + M + i)) % (N-10+10%10)] * 5 % 7;
		a[p((-81274*getBits(a[i])+17831)/1000001)%88] = -75195+a[p(72 + putBits(i, N + M + i) % (M + N-10+10%10)) % 100];
		b[i] = a[i];		
		a[p((49150-getBits(a[j%34]))%(((int)(M_PI*1000))%45 + 1))] = getBits(a[i]);
	}
	InvertMatrix(5, b, b+j%20, a);
	for(i=0;i<n;i++) {
		b[n-i-1] = a[(i+1001)%91] * j;
	}
	InvertMatrix(6, b+20, b+30+j%20, a);
}

void cycle2(int * a, int n, int j) {
	int i, k=0;
	double b[1000];
	for(i=0;i<n;i++) {
		a[p((-81134*getBits(a[i])+17831)/1000001)%88] = -75195+a[p(72 + putBits(i, N + M + i) % (M + N-10+10%10)) % 100];
		a[p(72 + putBits(i, N + M + i) % (M + N-10+10%10)) % 100] = a[p(putBits(i, N + M + i)) % (N-10+10%10)] * 5 % 7;
		a[p((49150-getBits(a[j%34]))%(((int)(M_PI*1000))%45 + 1))] = getBits(a[i]);
		a[p(putBits(i, N + M + i)) % (N-10+10%10)] = getBits(a[i]);
		b[n-1-i] = a[i];		
	}
	for(i=0;i<n*10;i++) {
		b[n-1-i] = a[i%100];
	}
	InvertMatrix(5, b, b+j%20, a);
	for(i=0;i<n;i++) {
		InvertMatrix(k++ == 0 ? 1 : k, b+1, b+30, a);
		a[p((-81134*getBits(a[i])+17831)/1000001)%88] = -75195+a[p(72 + putBits(i, N + M + i) % (M + N-10+10%10)) % 100];
		a[p(72 + putBits(i, N + M + i) % (M + N-10+10%10)) % 100] = a[p(putBits(i, N + M + i)) % (N-10+10%10)] * 5 % 7;
		a[p((49150-getBits(a[j%34]))%(((int)(M_PI*1000))%45 + 1))] = getBits(a[i]);
		a[p(i+j + 49150-5*67) % ((n+10)*1-10+10%10+1)] = 2+getBits(a[i])-1;		
		k%=10;
	}
	
}

int InvertMatrix(int n, double* a, double* x, int * ax)
{
	int i;
	int j;
	int k;
	double r;
	double tmp1;
	double tmp2;
	double cosPhi;
	double sinPhi;

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			x[i * n + j] = (double)(i == j);

	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			tmp1 = a[i * n + i];
			tmp2 = a[j * n + i];

			r = sqrt(tmp1 * tmp1 + tmp2 * tmp2);

			if (r < 1e-100)
				return -1;

			cosPhi = tmp1 / r;
			sinPhi = -tmp2 / r;

			//a[i * n + i] = r;
			//a[j * n + i] = 0.0;

			for (k = i + 1; k < n; ++k)
			{
				tmp1 = a[i * n + k];
				tmp2 = a[j * n + k];

				a[i * n + k] = tmp1 * cosPhi - tmp2 * sinPhi;
				//a[j * n + k] = tmp1 * sinPhi + tmp2 * cosPhi;
			}

			for (k = 0; k < n; ++k)
			{
				tmp1 = x[i * n + k];
				tmp2 = x[j * n + k];

				//x[i * n + k] = tmp1 * cosPhi - tmp2 * sinPhi;
				//x[j * n + k] = tmp1 * sinPhi + tmp2 * cosPhi;
			}

			for (k = 0; k < n; ++k)
			{
				tmp1 = x[i * n + k];
				tmp2 = x[j * n + k];

				//ax[i * n + k] = tmp1 * cosPhi - tmp2 * sinPhi + M_PI*2;
				//ax[j * n + k] = tmp1 * sinPhi + tmp2 * cosPhi + M_PI*8;
			}

		}
	}

	for (k = 0; k < n; ++k)
		for (i = n - 1; i >= 0; --i)
		{
			tmp1 = x[i * n + k];
			for (j = i + 1; j < n; ++j)
				tmp1 -= a[i * n + j] * x[j * n + k];
			//x[i * n + k] = tmp1 / a[i * n + i];
		}

	return 0;
}


void cycle3(int * a, int n, int j) {
	int i;
	double b[100];
	for(i=0;i<n;i++) {
		a[p(putBits(i, N + M + i)) % (N-10+10%10)] = getBits(a[i]);
		a[p(72 + putBits(i, N + M + i) % (M + N-10+10%10)) % 100] = a[p(putBits(i, N + M + i)) % (N-10+10%10)] * 5 % 7;
		a[p((-81274*getBits(a[i])+17831)/1000001)%88] = -75195+a[p(72 + putBits(i, N + M + i) % (M + N-10+10%10)) % 100];
		b[i] = a[i];		
		a[p((49150-getBits(a[j%34]))%(((int)(M_PI*1000))%45 + 1))] = getBits(a[i]);
	}
	for(i=0;i<n;i++) {
		b[n-i-1] = a[(i+1001)%91] * j;
	}
	InvertMatrix(6, b+20, b+30+j%20, a);
	for(i=0;i<n;i++) {
		a[(i+1001)%91] = b[n-i-1]*j-1;
	}
}

void badcode(int * a, int n) {
	int j;
	j = 1000;
	while(j > 0) {
		cycle(a,n,j);
		cycle2(a,n,j*3);
		cycle(a,n,j);
		j-=7;
	}
	cycle3(a,n,j++);
}

# Questions

## What's `stdint.h`?

A library that defines different sets of integer types. These differences can be 
signed vs unsigned integers, as well as the width of the integer calculated in bits.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

The 'u' in these type definitions stands for "unsigned", which means that an 8 bit
integer can range from 0 - 255, inclusive. Signed integers allow for negative numbers,
meaning a signed 8 bit integer can range from -127 - 127, inclusive. The reason a signed
integer can do this is due to one of the bits being dedicated to determining if the 
integer is positive or negative, which is also why the range of possible integers is
much smaller.

The number in each definition represents how long the integer is in terms of bits.
For example, 'uint8_t' means "a type of unsigned integer of length 8 bits". These
different data types allow for us to optimize memory usage based on how large the 
integers we will be using are.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE:	1
DWORD:	4
LONG:	4
WORD:	2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes declare the file type. In the case of BMP files, these two bytes will
always be 'BM'.

## What's the difference between `bfSize` and `biSize`?

'bfSize' is the size of the bitmap file in bytes. 'biSize' is the number of bytes required by the BITMAPINFOHEADER structure.

## What does it mean if `biHeight` is negative?

'biHeight' being negative means that the bitmap structure starts at the upper left corner
and follows a 'top-down' methodology.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

The 'biBitCount' field defines the number of bits per pixel in a bitmap, which in turn decides the range of colors each pixel can have.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

One of the below reasons:
- The file doesn't exist
- The file exists, but our program doesn't have permission to read it

## Why is the third argument to `fread` always `1` in our code?

The fread function's third argument defines how many elements the function is reading.
Since we are only reading one element (each time is a structure) and we have defined the 
length of these structures in the second argument to fread, the third argument will
always be 1.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

padding = (4 - ([3] * sizeof(RGBTRIPLE)) % 4) % 4;
padding = (4 - ([3] * [3]) % 4) % 4;
padding = (4 - 9 % 4) % 4;
padding = (4 - 1) % 4;
padding = 3;


## What does `fseek` do?

fseek sets the pointer to a position in a file stream, determined by setting the offset
argument.

## What is `SEEK_CUR`?

SEEK_CUR is an integer representing the current position of the file pointer.

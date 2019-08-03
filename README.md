# rle
Running Length Encoding (RLE) Utilities

## Building

`make all` - builds both utilities

`make clean` - removes the binaries

## RLE Compressor
Compresses the standard input into the standard output.

`./rle < file.ext > file.rle`

## RLE Decompressor
Decompresses the standard input into the standard output.

`./unrle < file.rle > file.ext`

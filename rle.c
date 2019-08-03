/*
 * RLE Compressor v0.1
 *
 * BSD 3-Clause License
 * 
 * Copyright (c) 2019, Vlad Shurupov
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>

#define UNDEF 0x100

const int sp = 0xFE;

int main(int argc, char *argv[])
{
    int c;
    int pc = UNDEF;
    unsigned char n = 0;
    for (;;) {
        c = getchar();
        if (c == pc && n < 0xFF)
            n++;
        else {
            if (n > 3) {
                putchar(sp);
                putchar(pc);
                putchar(n);
            } else {
                switch (n) {
                case 3:
                    putchar(pc);
                case 2:
                    putchar(pc);
                case 1:
                    putchar(pc);
                }
            }
            if (c == sp) {
                putchar(c);
                putchar(c);
                n = 0;
                pc = UNDEF;
                continue;
            } else if (c == EOF)
                break;
            else {
                n = 1;
                pc = c;
            }
        }
    }
    return 0;
}

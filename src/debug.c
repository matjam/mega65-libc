#include <mega65/memory.h>

unsigned char the_char;
void debug_msg(char* msg)
{
    while (*msg) {
        the_char = *msg;
#ifdef __CC65__
        __asm__("LDA %v", the_char);
        __asm__("STA $D643");
        __asm__("NOP");
#else
        asm volatile("lda the_char\n"
                     "sta $d643\n"
                     "nop" ::
                         : "a");
#endif
        msg++;
    }
#ifdef __CC65__
    __asm__("LDA #$0d");
    __asm__("STA $D643");
    __asm__("NOP");
    __asm__("LDA #$0a");
    __asm__("STA $D643");
    __asm__("NOP");
#else
    asm volatile("lda 0x0d\n"
                 "sta $d643\n"
                 "nop\n"
                 "lda 0x0a\n"
                 "sta $d643\n"
                 "nop" ::
                     : "a");
#endif
}
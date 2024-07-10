#pragma once

/*
 The _delay_us function uses loops to generate an approximate delay for the specified number of microseconds.
 It calculates the number of clock cycles required to achieve the requested delay and loops the corresponding number of times.
 
 The temporal precision of _delay_us depends on the microcontroller's clock frequency (F_CPU).
 For the ATmega328 operating at a typical frequency of 16 MHz, here are some details on the precision.

 Clock Frequency: F_CPU must be defined correctly before using the function. For an ATmega328 operating at 16 MHz:
    1 clock cycle = 1 / 16,000,000 s ≈ 62.5 ns
    1 µs ≈ 16 clock cycles

   HOLD _delay_us(2.75)    = 44  clock cycles
   PATCHING _delay_us(0.2) = 3,2 clock cycles

*/



#ifdef SCPH_xxx1
#define SCEA
#endif

#ifdef SCPH_xxx2
#define SCEE
#endif

#ifdef SCPH_103
#define SCEI
#endif

#ifdef SCPH_102
#define BIOS_PATCH
#define HOLD _delay_us(2.75)
#define PATCHING _delay_us(0.2)
#define CHECKPOINT 83900
#define TRIGGER 48
#define SCEE
#endif

#ifdef SCPH_100
#define BIOS_PATCH
#define HOLD _delay_us(2.7)
#define PATCHING _delay_us(0.2)
#define CHECKPOINT 83900
#define TRIGGER 48
#define SCEI
#endif

#ifdef SCPH_7000_9000
#define BIOS_PATCH
#define HOLD _delay_us(2.85) 
#define PATCHING _delay_us(0.1)
#define CHECKPOINT 75270
#define TRIGGER 16
#define SCEI
#endif

#ifdef SCPH_5500
#define BIOS_PATCH
#define HOLD _delay_us(2.85)
#define PATCHING _delay_us(0.1)
#define CHECKPOINT 76130
#define TRIGGER 21
#define LOW_TRIGGER
#define SCEI
#endif

#ifdef SCPH_3500_5000
#define BIOS_PATCH
#define HOLD _delay_us(2.85)
#define PATCHING _delay_us(0.1)
#define CHECKPOINT 75260
#define TRIGGER 21
#define LOW_TRIGGER
#define SCEI
#endif

#ifdef SCPH_3000
#define BIOS_PATCH                                                    
#define CHECKPOINT 83000      
#define TRIGGER 60
#define HOLD _delay_us(2.75)
#define PATCHING _delay_us(0.1)
#define HIGH_PATCH                                                    
//#define DOUBLE_PATCH 
//#define LOW_TRIGGER2
#define CHECKPOINT2 253300
#define TRIGGER2 43
#define HOLD2 _delay_us(2.88)
#define PATCHING2 _delay_us(0.15)
#define SCEI
#endif

#ifdef SCPH_1000
#define BIOS_PATCH
#define CHECKPOINT 83000
#define TRIGGER 92
#define HOLD _delay_us(2.7)
#define PATCHING _delay_us(0.1)
#define HIGH_PATCH
//#define DOUBLE_PATCH
//#define LOW_TRIGGER2
#define CHECKPOINT2 272800
#define TRIGGER2 71
#define HOLD2 _delay_us(2.88)
#define PATCHING2 _delay_us(0.15)
#define SCEI
#endif

#ifdef SCEA
const char region[3] = {'a', 'a', 'a'};
#endif

#ifdef SCEE
const char region[3] = {'e', 'e', 'e'};
#endif

#ifdef SCEI
const char region[3] = {'i', 'i', 'i'};
#endif

#if !defined(UC_ALL) && !defined(PAL_FAT) && !defined(SCPH_103) && \
    !defined(SCPH_102) && !defined(SCPH_100) && !defined(SCPH_7000_9000) && \
    !defined(SCPH_5500) && !defined(SCPH_3500_5000) && !defined(SCPH_3000) && \
    !defined(SCPH_1000)
 #error "Console not selected! Please uncoment #define with SCPH model number."
#elif !(defined(UC_ALL) ^ defined(PAL_FAT) ^ defined(SCPH_103) ^ \
      defined(SCPH_102) ^ defined(SCPH_100) ^ defined(SCPH_7000_9000) ^ \
      defined(SCPH_5500) ^ defined(SCPH_3500_5000) ^ defined(SCPH_3000) ^ \
      defined(SCPH_1000))
 #error "May be selected only one console! Please check #define with SCPH model number."
#endif

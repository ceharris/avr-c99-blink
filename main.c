#include <avr/io.h>
#include <util/delay.h>

#if defined(__AVR_ATtiny85__) || \
    defined(__AVR_ATtiny45__) || \
    defined(__AVR_ATtiny25__)
#define BLINK_DDR   DDRB
#define BLINK_PORT  PORTB
#define BLINK_PIN   PB2
#elif defined(__AVR_ATmega328__) || \
      defined(__AVR_ATmega168__) || \
      defined(__AVR_ATmega88__) || \
      defined(__AVR_ATmega48__)
#define BLINK_DDR   DDRB
#define BLINK_PORT  PORTB
#define BLINK_PIN   PB5
#endif

int main(void) {
  BLINK_DDR |= (1 << BLINK_PIN);
  while (1) {
    _delay_ms(500);
    BLINK_PORT ^= (1 << BLINK_PIN);
  }
}
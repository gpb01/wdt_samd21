#include <wdt_samd21.h>

void setup() {
   delay ( 500 );
   //
   SerialUSB.begin ( 9600 );
   while ( !SerialUSB ) {
      delay ( 100 );
   }
   //
   // Initialze WDT with a 2 sec. timeout
   wdt_init ( WDT_CONFIG_PER_2K );
}

void loop() {
   for ( byte i = 0; i < 5; i++ ) {
      // wait a second
      delay ( 1000 );
      // write on the native serial USB port
      SerialUSB.print ( "Iteration " );
      SerialUSB.print ( i + 1 );
      SerialUSB.println ( " of 5" );
      // "feed" the WDT to avoid restart
      wdt_reset();
   }
   //
   // now wait 4 seconds ... the WDT should restart the board
   SerialUSB.println ( "Now waiting for 4 seconds ..." );
   delay ( 4000 );
   //
   SerialUSB.println ( "You will never see this message printed" );
   delay ( 1000 );
}

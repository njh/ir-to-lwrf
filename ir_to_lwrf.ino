/*
 * InfraRed to LightwaveRF relay
 * Receives remote control commands via InfraRed
 * and then transmits commands to LightWave RF
 * 
 * Dependencies:
 *  IRRemote:    https://github.com/shirriff/Arduino-IRremote
 *  LightwaveRF: https://github.com/lawrie/LightwaveRF/
 *
 * Copyright 2015 Nicholas Humfrey
 */

#include <LightwaveRF.h>
#include <IRremote.h>


int LW_TX_PIN   = 9;
int IR_RECV_PIN = 8;
int LED_PIN     = 5;

IRrecv irrecv(IR_RECV_PIN);
decode_results results;

void setup()
{
    Serial.begin(9600);
    lw_tx_setup(LW_TX_PIN);
    irrecv.enableIRIn();
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    Serial.println("Ready.");
}

void loop() {
    if (irrecv.decode(&results)) {
        if (results.decode_type == JVC) {
            digitalWrite(LED_PIN, HIGH);
            Serial.print("Received: 0x");
            Serial.println(results.value, HEX);
            switch(results.value) {
                case 0xC2D0:
                    lw_send((byte*)"\x7D\xF6\x6F\xF6\x6F\xEB\xEE\xBD\xBB\xF6");
                break;
                case 0xC038:
                    lw_send((byte*)"\xBD\xED\x6F\xED\x6F\xEB\xEE\xBD\xBB\xF6");
                break;
                case 0xC084:
                    lw_send((byte*)"\xF6\xF6\xF6\xEE\x6F\xEB\xEE\xBD\xBB\xF6");
                break;
                case 0xC044:
                    lw_send((byte*)"\xF6\xF6\xF6\xF6\x6F\xEB\xEE\xBD\xBB\xF6");
                break;
                case 0xC0C4:
                    lw_send((byte*)"\xF6\xF6\xEE\xEE\x6F\xEB\xEE\xBD\xBB\xF6");
                break;
                case 0xC024:
                    lw_send((byte*)"\xF6\xF6\xEE\xF6\x6F\xEB\xEE\xBD\xBB\xF6");
                break;
                case 0xC0A4:
                    lw_send((byte*)"\xF6\xF6\xED\xEE\x6F\xEB\xEE\xBD\xBB\xF6");
                break;
                case 0xC064:
                    lw_send((byte*)"\xF6\xF6\xED\xF6\x6F\xEB\xEE\xBD\xBB\xF6");
                break;
                case 0xC0E4:
                    lw_send((byte*)"\xF6\xF6\xEB\xEE\x6F\xEB\xEE\xBD\xBB\xF6");
                break;
                case 0xC014:
                    lw_send((byte*)"\xF6\xF6\xEB\xF6\x6F\xEB\xEE\xBD\xBB\xF6");
                break;
            }
        }
        irrecv.resume(); // Receive the next value
    }
    delay(100);
    digitalWrite(LED_PIN, LOW);
}


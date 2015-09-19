/*
 * 動作確認用スケッチ
 * 
 * 対象部品:
 *   7セグ(8桁)モジュール [M7SEGX8R-7219]
 *   http://www.aitendo.com/product/10159
 *
 */

const int csPin   = 12;
const int dinPin  = 13;
const int clkPin  = 14;

void setup()   {
  pinMode(csPin,OUTPUT);
  pinMode(dinPin, OUTPUT);
  pinMode(clkPin, OUTPUT);
  digitalWrite(csPin,HIGH);
  digitalWrite(dinPin, LOW);
  digitalWrite(clkPin, LOW);
  delay(1);

  max_out(0x0F, 0x00);
  max_out(0x09, 0xFF);
  max_out(0x0A, 0x08);
  max_out(0x0B, 0x07);
  max_out(0x0C, 0x01);
}

void loop() {
  char i;
  for (i = 1; i <= 8; i++) {
    max_out(i, 9-i);
  }

  delay(2000);
}

void max_out(byte high_byte, byte low_byte) {
  digitalWrite(csPin, LOW);
  shiftOut(dinPin, clkPin, MSBFIRST, high_byte);
  shiftOut(dinPin, clkPin, MSBFIRST, low_byte);
  digitalWrite(csPin, HIGH);
  delayMicroseconds(1);
}


/*
 * 動作確認用スケッチ
 * 
 * 対象部品:
 *   AssemblyDesk 電子工作シリーズ その7 「貼る タッチスイッチ 丸」
 *   http://bit-trade-one.co.jp/product/module/ad00010/
 *
 * 参考URL:
 *   http://jakalada.hatenablog.com/entry/2015/06/14/001159
 */

const int buttonON = LOW;
const int buttonOFF = HIGH;

const int buttonPin = 2;
const int ledPin = 13;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int state = digitalRead(buttonPin);
  if (state == LOW) {
    // タッチ中
    digitalWrite(ledPin, HIGH);
  } else {
    // 非タッチ
    digitalWrite(ledPin, LOW);
  }
}

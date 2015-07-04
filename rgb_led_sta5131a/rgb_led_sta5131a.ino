/*
 * 動作確認用スケッチ
 * 
 * 対象部品:
 *   ＲＧＢフルカラーＬＥＤ ５ｍｍ４本足 ＯＳＴＡ５１３１Ａ カソードコモン
 *   http://akizukidenshi.com/catalog/g/gI-02476/
 *
 */

// 変更する場合はPWM出力が行えるピンを指定する
//
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // 全色を暗くしておく
  rgb(0, 0, 0);
}

void loop() {
  // 白
  white(125);
  delay(2000);

  // 赤
  red(125);
  delay(2000);

  // 緑
  green(125);
  delay(2000);

  // 黄
  yellow(125);
  delay(2000);

  // 水色
  lightBlue(125);
  delay(2000);

  // 紫
  purple(125);
  delay(2000);

  // 白: 徐々に明るくする
  for (int i = 0; i <= 255; i++) {
    white(i);
    delay(10);
  }

  // 白: 徐々に暗くする
  for (int i = 255; i >= 0; i--) {
    white(i);
    delay(10);
  }

  // 赤: 徐々に明るくする
  for (int i = 0; i <= 255; i++) {
    red(i);
    delay(10);
  }

  // 赤: 徐々に暗くする
  for (int i = 255; i >= 0; i--) {
    red(i);
    delay(10);
  }

  // 緑: 徐々に明るくする
  for (int i = 0; i <= 255; i++) {
    green(i);
    delay(10);
  }

  // 緑: 徐々に暗くする
  for (int i = 255; i >= 0; i--) {
    green(i);
    delay(10);
  }

  // 青: 徐々に明るくする
  for (int i = 0; i <= 255; i++) {
    blue(i);
    delay(10);
  }

  // 青: 徐々に暗くする
  for (int i = 255; i >= 0; i--) {
    blue(i);
    delay(10);
  }

  // 黄: 徐々に明るくする
  for (int i = 0; i <= 255; i++) {
    yellow(i);
    delay(10);
  }

  // 黄: 徐々に暗くする
  for (int i = 255; i >= 0; i--) {
    yellow(i);
    delay(10);
  }

  // 水色: 徐々に明るくする
  for (int i = 0; i <= 255; i++) {
    lightBlue(i);
    delay(10);
  }

  // 水色: 徐々に暗くする
  for (int i = 255; i >= 0; i--) {
    lightBlue(i);
    delay(10);
  }

  // 紫: 徐々に明るくする
  for (int i = 0; i <= 255; i++) {
    purple(i);
    delay(10);
  }

  // 紫: 徐々に暗くする
  for (int i = 255; i >= 0; i--) {
    purple(i);
    delay(10);
  }
}

// LEDを赤、緑、青ごとに指定した輝度で光らせる
void rgb(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}


// LEDを指定した輝度の白で光らせる
void white(int value) {
  rgb(value, value, value);
}

// LEDを指定した輝度の赤で光らせる
void red(int value) {
  rgb(value, 0, 0);
}

// LEDを指定した輝度の緑で光らせる
void green(int value) {
  rgb(0, value, 0);
}

// LEDを指定した輝度の青で光らせる
void blue(int value) {
  rgb(0, 0, value);
}

// LEDを指定した輝度の黄で光らせる
void yellow(int value) {
  rgb(value, value, 0);
}

// LEDを指定した輝度の水色で光らせる
void lightBlue(int value) {
  rgb(0, value, value);
}

// LEDを指定した輝度の紫で光らせる
void purple(int value) {
  rgb(value, 0, value);
}

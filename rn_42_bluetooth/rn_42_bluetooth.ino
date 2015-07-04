/*
 * 動作確認用スケッチ
 * 
 * 対象部品:
 *   ＲＮ－４２
 *   http://akizukidenshi.com/catalog/g/gM-08690/
 *
 */

void setup() {
  Serial.begin(115200);
}

void loop() {
  while(Serial.available()) {
    char ch = Serial.read();
    put(ch);
  }
}

// ひとまとまりのテキストの受信時に実行される関数
// ESCからCRまでの文字列をひとまとまりのテキストとして扱っている。
//
// 引数 char *text: NULL文字列のアドレス
void onText(char *text) {
  Serial.println(text);
}

// 以下のコードでシリアル通信で受信したデータを
// ひとまとまりのテキストごとにonText関数に渡す

#define BUFFER_SIZE 256

#define STATE_INIT  0
#define STATE_ESC   1

int bufferIndex = 0;
char buffer[BUFFER_SIZE];
boolean state = STATE_INIT;

void put(char ch) {
  switch (ch) {
    case 0x1B:  // ESC
      bufferIndex = 0;
      state = STATE_ESC;
      break;

    case 0x0D:  // CR
      if (state == STATE_ESC) {
        if (bufferIndex >= 1) {
          // テキストをNULL文字列として扱えるように
          // 末尾にNULL文字を代入
          buffer[bufferIndex] = 0x00;

          // 受信したテキストを処理する関数を実行
          onText(buffer);
        }

        // 状態をESC受信前に変更
        state = STATE_INIT;
      }
      break;

    default:
      if (state == STATE_ESC) {
        if (bufferIndex < BUFFER_SIZE) {
          // 文字列バッファに受信した文字を追加
          buffer[bufferIndex] = ch;
          bufferIndex++;
        } else {
          // 文字列バッファの最大サイズを超えたので
          // 状態をESC受信前に変更
          state = STATE_INIT;
        }
      }
      break;
  }
}




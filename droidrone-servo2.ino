
// サーボモータ動作確認用プログラム
/*
  http://tetsuakibaba.jp/index.php?page=workshop/ServoBasis/main
  シリアルモニタからサーボを操作可能
  r: サーボ値読み取り
  800-2200: 0度〜90度設定

  a: attach(9)
  d: detach()

  http://marupeke296.com/EL_Ard_No9_ServoMotor.html
  http://www.vstone.co.jp/vs_wiki/main/wiki.cgi?page=Arduino%A4%C7%BB%CF%A4%E1%A4%EB%A5%ED%A5%DC%A5%C3%A5%C8%C0%A9%B8%E6
  http://wacho.main.jp/Elec/Servo_Driver/Servo_Driver.html
  http://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q14109772659
  http://otonaradicon.com/arrc/

  ＤＦＲｄｕｉｎｏ　Ｐｒｏ　Ｍｉｎｉ　Ｖ１．３（１６Ｍ５Ｖ３２８）
  http://akizukidenshi.com/catalog/g/gM-06682/
  ブートローダー：Ａｒｄｕｉｎｏ　Ｐｒｏ／Ｐｒｏ　Ｍｉｎｉ　（５Ｖ，　１６ＭＨｚ）　ｗ／　Ａｔｍｅｇａ３２８
  Ａｒｄｕｉｎｏ Ｐｒｏ Ｍｉｎｉ 接続図
  http://i.stack.imgur.com/oOtkU.png
  PWM　３，５，６，９，１０，１１Pin
*/

#include <Servo.h>

Servo sv9;
Servo sv10;
Servo sv5;
Servo sv6;
int analog9 = 0;
int analog10 = 0;
int i = 7;
int inPin = 2;   // デジタルピン2にホール素子
int hallVal = 0;     // 読み取った値を保持する変数
int lasthallVal = 0;     // 前回読み取った値を保持する変数
int hallCount = 0; //ホール通過カウント
unsigned long lastTime;
boolean servoAttached = false;

void moveShaft(Servo sv, int pulse, long int delay_ms)
{
  int pulse_now = sv.readMicroseconds();

  if ( pulse > pulse_now ) {
    for ( int i = pulse_now; i <= pulse; i++ ) {
      sv.writeMicroseconds(i);
      delay(delay_ms);
    }
  }
  else if ( pulse < pulse_now ) {
    for ( int i = pulse_now; i >= pulse; i-- ) {
      sv.writeMicroseconds(i);
      delay(delay_ms);
    }
  }
  else {
    // do nothing
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT); //LED表示
  //ホールセンサーＵＳ１８８１ＬＵＡ http://akizukidenshi.com/catalog/g/gI-05274/
  //オープンドレイン出力
  //オープンコレクタ出力の場合はプルアップ回路が必須 http://play-arduino.seesaa.net/article/427884258.html
  //Arduino 新機能 pinMode関数の第2引数にINPUT_PULLUP http://mag.switch-science.com/2013/05/23/input_pullup/
  pinMode(inPin, INPUT_PULLUP);// ホール素子用に入力に設定
  lastTime = millis();
}

void loop()
{
  //TODO attachInterrupt(interrupt, function, mode) http://www.musashinodenpa.com/arduino/ref/index.php?f=0&pos=3045
  //Arduino Hall Effect Sensor Project http://diyhacking.com/projects/ArduinoHallEffect.ino
  hallVal = digitalRead(inPin);  // 入力ピンを読む
  if ( hallVal != lasthallVal) {
    lasthallVal = hallVal;
    if (hallVal == 1) {
      hallCount++;
    }
  }

  //Bt通信監視
  if (servoAttached && lastTime > millis() + 1100) {
    sv9.writeMicroseconds(1500);
    sv10.writeMicroseconds(1500);
  }

  int ret;
  if ( Serial.available() > 0 ) {
    lastTime = millis();
    digitalWrite(13, HIGH); //LED点灯
    int d = Serial.read();

    if ( d == 'a' ) {
      sv9.attach(9, 800, 2200);
      sv10.attach(10, 800, 2200);
      sv5.attach(5, 800, 2200);
      sv6.attach(6, 800, 2200);
      servoAttached = true;
      Serial.println("Servo Attached");
      hallCount = 0;
    }
    else if ( d == 'd' ) {
      sv9.detach();
      sv10.detach();
      sv5.detach();
      sv6.detach();
      servoAttached = false;
      Serial.println("Servo Detached");
    }
    else if ( d == 'r' ) {
      if (hallCount != 0) {
        Serial.println("RPS:" + String(hallCount, DEC));
        //"Servo: " + String(sv9.read(), DEC) + " : " + String(sv10.read(), DEC));
        hallCount = 0;
      } else { //A0 Batt Volte
        int batValue = analogRead(A0);
        Serial.println("BAT:" + String(batValue, DEC));
      }
    }
    else if ( '0' <= d && d <= '9' ) {
      d -= '0';
      if (i == 7) {
        analog9 = d * 1000;
      }
      if (i == 6) {
        analog9 += d * 100;
      }
      if (i == 5) {
        analog9 += d * 10;
      }
      if (i == 4) {
        analog9 += d;
      }
      if (i == 3) {
        analog10 = d * 1000;
      }
      if (i == 2) {
        analog10 += d * 100;
      }
      if (i == 1) {
        analog10 += d * 10;
      }
      if (i == 0) {
        analog10 += d;
        //Serial.println("analog9  : " + String(analog9, DEC));
        //Serial.println("analog10 : " + String(analog10, DEC));
      }
      i--;
    }
    else if ( d == 'm' ) {
      sv9.writeMicroseconds(analog9);
      sv10.writeMicroseconds(analog10);
      //Serial.println("sv 9 Move to ms: " + String(analog9, DEC));
      //Serial.println("sv10 Move to ms: " + String(analog10, DEC));
      analog9 = 0;
      analog10 = 0;
      i = 7;
    } else if ( d == 'x' ) {
      //sv5.writeMicroseconds(analog9);
      moveShaft(sv5, analog9, 5);
      //Serial.println("camera x  : " + String(analog9, DEC));
      analog9 = 0;
      i = 7;
    } else if ( d == 'y' ) {
      //sv6.writeMicroseconds(analog9);
      moveShaft(sv6, analog9, 5);
      //Serial.println("camera y  : " + String(analog9, DEC));
      analog9 = 0;
      i = 7;
    }
    digitalWrite(13, LOW);   //LED消灯
  }
}


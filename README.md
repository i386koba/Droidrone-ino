# Droidrone-ino
![droidrone-servo2](https://github.com/i386koba/Droidrone-ino/blob/master/droidrone-servo2.jpg?raw=true)

![droidrone-servo2_schematic](https://github.com/i386koba/Droidrone-ino/blob/master/droidrone-servo2_schematic.jpg?raw=true)

![servo20pinout](https://github.com/i386koba/Droidrone-ino/blob/master/servo20pinout.png?raw=true)

##現在専用基板を作っているので、以下は専用基板用のアイデア、メモになっています。

##マイコン
* ＡＶＲマイコン　ブートローダー書き込みでArduino化
* ＡＶＲマイコン　ＡＴｍｅｇａ８８Ｖ－１０ＰＵ　http://akizukidenshi.com/catalog/g/gI-03655/

低電圧動作版で最大クロック10Mhz 。サーボ使うんで内蔵クロックは良くないか？
* 8Mhzではサーボライブラリはうまく動かないようです。
* クリスタル（水晶発振子）１６ＭＨｚ http://akizukidenshi.com/catalog/g/gP-08671/
* 将来的にはプログラム容量足りれば88-20Mhzだが、秋月にはない。

http://www.digikey.jp/product-detail/ja/atmel/ATMEGA88PA-PU/ATMEGA88PA-PU-ND/1886230
* ATmega88/88V/168PとATmega328Pの比較　https://synapse.kyoto/tips/bootloader_ATmega88/page001.html#index2
* 無難に　168にしますか。http://akizukidenshi.com/catalog/g/gI-03033/
* AVRの型番についているアルファベットの見方　http://nomolk.hatenablog.com/entry/2014/10/18/235658
* 安いＡＶＲマイコンＡＴＭＥＧＡ４８－２０ＡＵは使えない模様。　http://akizukidenshi.com/catalog/g/gI-08437/
* ブートローダを使わずにArduinoのスケッチをATmega328Pに書き込む　https://synapse.kyoto/tips/sketch_without_bootloader/page001.html
* 持っているAVR書き込み機　https://synapse.kyoto/product/bootloader_writer/page001.html

* Arduino　Uno　ピン図　http://www.pighixxx.com/test/wp-content/uploads/2014/11/uno.png
* Arduino　Uno回路図 http://download.arduino.org/products/UNO/Arduino-UNO-Rev3e-SCH.pdf

###電源
電池6V駆動もあるので、低失損レギュレータ
* ATMEGAA DC Current VCC and GND Pins　全体で流していい電流：200.0mA
* マイコンのみではロードロップアウト三端子レギュレーター　５Ｖ　２５０ｍＡ　ＴＡ７８ＤＬ０５ＡＰ　http://akizukidenshi.com/catalog/g/gI-04195/
* サーボも共通で低損失三端子レギュレーター　５Ｖ１Ａ　ＴＡ４８０５Ｓ　電圧差＝０．６Ｖで動作　http://akizukidenshi.com/catalog/g/gI-00537/
* 端子はTB
* 3.3V電源50mAあればOK。
* 3.3V 低損失レギュレータ　ＬＰ２９５０Ｌ－３．３Ｖ　３．３Ｖ１００ｍＡ　http://akizukidenshi.com/catalog/g/gI-08749/


###サーボ出力
* デジタルIO　０，１ピンはシリアル
* サーボ　２－８、１１－１３（９，１０は使えない）
* （UnoのようにATmega328Pを搭載しているArduinoボードでは、PWMデジタルピン3、5、6、9、10、11）
* このため、サーボ2,3,4,5,6,7,8,11,12,13の10ch出力
* ブラシモーター用PWM9,10の2ch出力。
* ArduinoでPWMサーボの速度をコントロールするVarSpeedServo.h　http://qiita.com/thorikawa/items/a6377d2d4b4535dd9004
* サーボ消費電力　一個0.5A？　http://kong2.cocolog-nifty.com/blog/2008/04/post_45d2.html

サーボによっては４．８Ｖ専用だったり耐電圧が５Ｖというものもあります。
ただ、一般的な普及型サーボや受信機はたいていの場合６ｖ対応になっています。
さらに最近ではリポ対応として７．４ｖにも耐えられるものが売られています。（とのこと）

###回路図
* 互換機　http://akizukidenshi.com/catalog/g/gP-04399/
* http://www.aitendo.com/product/11541
* 秋月電子 Arduino互換ボードの使い方
http://www.geocities.jp/bokunimowakaru/diy/arduino/ae-atmega.html
* 超小型USBシリアル変換モジュール(AE-FT234X)をArduino互換機で使う
http://qiita.com/chrhsmt/items/e6bfc624d2bacdd7684d

##Bluetooth
### マイクロチップ　Ｂｌｕｅｔｏｏｔｈモジュール　ＲＮ－４２－Ｉ／ＲＭ
* SMT　http://akizukidenshi.com/catalog/g/gM-07612/
* ＲＮ－４２ Ｂｌｕｅｔｏｏｔｈ　２ｍｍピッチ変換モジュール Dip化　http://akizukidenshi.com/catalog/g/gM-08690/
* ピンソケット　（メス・２ｍｍピッチ）　１ｘ１０　（１０Ｐ）　http://akizukidenshi.com/catalog/g/gC-03668/
* ２ｍｍピッチピンヘッダ　１×１０　（１０Ｐ）http://akizukidenshi.com/catalog/g/gC-08978/
* マイクロチップ　Ｂｌｕｅｔｏｏｔｈモジュール　ＲＮ４２ＸＶＰ－Ｉ／ＲＭ 外国人用　http://akizukidenshi.com/catalog/g/gM-07735/
* 信号3.3Vトレランス（参考 3.3V -> 5V 変換　http://kosakai.world.coocan.jp/change_3_3V_5V.html）
* デフォで115200bps

### BLE　マイクロチップ　Ｂｌｕｅｔｏｏｔｈ　ＲＮ４０２０－Ｖ／ＲＭ１２３ 
* AndroidBLE変更が必要
* チップ単体　http://akizukidenshi.com/catalog/g/gM-10066/
* Bluetooth LE RN4020搭載 シリアル無線化クリックボード　http://www.microtechnica-shop.jp/shopdetail/000000000065/
* デフォで115200bps 日本語マニュアル　http://akizukidenshi.com/download/ds/microchip/70005191A_JP.pdf

## ESC 
*タミヤのグラスホッパー純正ESCは TEU105BK　　
電動RCカー用のバック走行機能付き小型スピードコントローラー (ESC)　連続60A。
*GoolRC RC ESC 20A ブラシモーター https://www.amazon.co.jp/dp/B014RB6WS6
380モーターで使えそうではある。
http://blog.livedoor.jp/yoshimon/archives/1957888.html

### 10A ブラシレスモーターESC（BEC)
安いのは
http://www.hobbyking.com/hobbyking/store/uh_viewitem.asp?idproduct=21247&aff=1777144
基板ESC内臓より安全。

###ブラシモータPWM制御
* 内蔵 フルブリッジドライバ　Ｌ２９８Ｎ　http://akizukidenshi.com/catalog/g/gI-06380/
2Aまで。
* Ｌ２９８Ｎ使用　２Ａデュアルモーターコントローラー　http://akizukidenshi.com/catalog/g/gM-06680/
参考：http://www.instructables.com/member/ArduinoDeXXX/

##モーター
* タミヤのグラスホッパー純正はRS-380PH MAX3.2A
http://www.mabuchi-motor.co.jp/cgi-bin/catalog/j_catalog.cgi?CAT_ID=rs_380ph

* 380モーター互換　秋月　ＤＣモーター　ＲＳ－３８５ＰＨ－４０４５　MAX3.5A　http://akizukidenshi.com/catalog/g/gP-06439/
* マブチモーター（ブラシ）一覧
http://www.mabuchi-motor.co.jp/motorize/branch/motor/

##ホールセンサ
* ホールＩＣ　Ｓ－５７１６ＡＣＤＬ０－Ｍ３Ｔ１Ｕ　http://akizukidenshi.com/catalog/g/gI-11171/
* ホールセンサーＵＳ１８８１ＬＵＡ　http://akizukidenshi.com/catalog/g/gI-05274/
* SMT　ホールセンサーＵＳ１８８１ＬＳＥＴＲ（５個入）http://akizukidenshi.com/catalog/g/gI-05275/
* Panasonic AN48836B-NL
http://www.mouser.jp/Search/ProductDetail.aspx?R=AN48836B-NLvirtualkey66720000virtualkey667-AN48836B-NL
* Panasonic 磁気センサ (ホールIC)　42ms間欠駆動
http://www.semicon.panasonic.co.jp/jp/products/analog/hallic/#products-document
* 間欠駆動のためNGだった。　http://jiki-sensor.com/qa/qa150113.html

##README.mdファイル。マークダウン記法まとめ
http://codechord.com/2012/01/readme-markdown/

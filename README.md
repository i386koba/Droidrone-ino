# Droidrone-ino
![droidrone-servo2](https://github.com/i386koba/Droidrone-ino/blob/master/droidrone-servo2.jpg?raw=true)

![droidrone-servo2_schematic](https://github.com/i386koba/Droidrone-ino/blob/master/droidrone-servo2_schematic.jpg?raw=true)

![servo20pinout](https://github.com/i386koba/Droidrone-ino/blob/master/servo20pinout.png?raw=true)

#現在専用基板を作っているので、以下は専用基板用のアイデア、メモになっています。

##マイコン
###ＡＶＲマイコン　ＡＴＭＥＧＡ１６８Ｐ－２０ＰＵ
http://akizukidenshi.com/catalog/g/gI-03033/
ブートローダー書き込みでArduino化

セラミック発振子　コンデンサ内蔵タイプ　８ＭＨｚ（ＹＩＣ社）
http://akizukidenshi.com/catalog/g/gP-04547/

持っている書き込み機
https://synapse.kyoto/product/bootloader_writer/page001.html

ATmega88/88V/168PとATmega328Pの比較
https://synapse.kyoto/tips/bootloader_ATmega88/page001.html#index2

ＡＶＲマイコン　ＡＴｍｅｇａ８８Ｖ－１０ＰＵ　http://akizukidenshi.com/catalog/g/gI-03655/

ＡＶＲマイコンＡＴＭＥＧＡ４８－２０ＡＵは使えない模様。　http://akizukidenshi.com/catalog/g/gI-08437/

Arduino　Uno
http://www.pighixxx.com/test/wp-content/uploads/2014/11/uno.png

###出力
*デジタルIO　０，１ピンはシリアル

*サーボ　２－８、１１－１３（９，１０は使えない）

（UnoのようにATmega328Pを搭載しているArduinoボードでは、PWMデジタルピン3、5、6、9、10、11）

このため、サーボ2,4,6,7,8,11,12,13の8ch出力

ブラシモーター用PWM3,5の2ch出力とする。

###回路図
http://akizukidenshi.com/catalog/g/gP-04399/

http://www.aitendo.com/product/11541

###秋月電子 Arduino互換ボードの使い方
http://www.geocities.jp/bokunimowakaru/diy/arduino/ae-atmega.html

###超小型USBシリアル変換モジュール(AE-FT234X)をArduino互換機で使う
http://qiita.com/chrhsmt/items/e6bfc624d2bacdd7684d

##Bluetooth
###マイクロチップ　Ｂｌｕｅｔｏｏｔｈモジュール　ＲＮ－４２－Ｉ／ＲＭ
SMT　http://akizukidenshi.com/catalog/g/gM-07612/

###ＲＮ－４２ Ｂｌｕｅｔｏｏｔｈ　２ｍｍピッチ変換モジュール
Dip化　http://akizukidenshi.com/catalog/g/gM-08690/

ピンソケット　（メス・２ｍｍピッチ）　１ｘ１０　（１０Ｐ）　http://akizukidenshi.com/catalog/g/gC-03668/

２ｍｍピッチピンヘッダ　１×１０　（１０Ｐ）http://akizukidenshi.com/catalog/g/gC-08978/

3.3V -> 5V 変換　http://kosakai.world.coocan.jp/change_3_3V_5V.html
ＮｃｈチップＭＯＳＦＥＴ　ＢＳＳ１３８（２５個入）http://akizukidenshi.com/catalog/g/gI-04232/

###マイクロチップ　Ｂｌｕｅｔｏｏｔｈモジュール　ＲＮ４２ＸＶＰ－Ｉ／ＲＭ
外国人用　http://akizukidenshi.com/catalog/g/gM-07735/

###BLE　マイクロチップ　Ｂｌｕｅｔｏｏｔｈ　ＲＮ４０２０－Ｖ／ＲＭ１２３
AndroidでBLE変更が必要　http://akizukidenshi.com/catalog/g/gM-10066/

## ESC 
###タミヤのグラスホッパー純正ESCは TEU105BK　　
電動RCカー用のバック走行機能付き小型スピードコントローラー (ESC)　連続60A。

### GoolRC RC ESC 20A ブラシモーター https://www.amazon.co.jp/dp/B014RB6WS6
####380モーターで使えそうではある。
http://blog.livedoor.jp/yoshimon/archives/1957888.html

### ESC内蔵、スイッチで外部ESCと変更できる　
マルチコプターであればブラシレスモーターと外部ESCとなる。

http://www.musashinodenpa.com/arduino/ref/index.php?f=0&pos=2153
####内蔵 フルブリッジドライバ　Ｌ２９８Ｎ　http://akizukidenshi.com/catalog/g/gI-06380/
2Aまで。
####Ｌ２９８Ｎ使用　２Ａデュアルモーターコントローラー　http://akizukidenshi.com/catalog/g/gM-06680/

参考：
http://www.instructables.com/member/ArduinoDeXXX/

##モーター
###タミヤのグラスホッパー純正はRS-380PH MAX3.2A
http://www.mabuchi-motor.co.jp/cgi-bin/catalog/j_catalog.cgi?CAT_ID=rs_380ph

###380モーター互換　秋月　ＤＣモーター　ＲＳ－３８５ＰＨ－４０４５　MAX3.5A　http://akizukidenshi.com/catalog/g/gP-06439/

###マブチモーター（ブラシ）一覧
http://www.mabuchi-motor.co.jp/motorize/branch/motor/

##ホールセンサ
###ホールセンサーＵＳ１８８１ＬＵＡ
http://akizukidenshi.com/catalog/g/gI-05274/

###SMT　ホールセンサーＵＳ１８８１ＬＳＥＴＲ（５個入）
http://akizukidenshi.com/catalog/g/gI-05275/

### Panasonic AN48836B-NL
http://www.mouser.jp/Search/ProductDetail.aspx?R=AN48836B-NLvirtualkey66720000virtualkey667-AN48836B-NL

Panasonic 磁気センサ (ホールIC)　42ms間欠駆動
http://www.semicon.panasonic.co.jp/jp/products/analog/hallic/#products-document

間欠駆動周期が気になります　http://jiki-sensor.com/qa/qa150113.html
##README.mdファイル。マークダウン記法まとめ
http://codechord.com/2012/01/readme-markdown/

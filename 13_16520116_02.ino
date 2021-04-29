#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);		// pin Arduino terhubung LCD
const int ping_Pin = A1;					// pin Arduino terhubung Ultrasonic
long dur, cm;								// simpan nilai durasi dan jarak(cm)

void setup() {
  lcd.begin(16, 2);							// atur jumlah kolom dan baris LCD
  lcd.print("PING Sensor");					
}

void loop() {
  cm = read_sensor_ultrasonic();
  
  /* Print to LCD */
  lcd.setCursor(0,1);						// atur kursor ke kolom 0 baris 1
  lcd.print("Jarak");
  lcd.setCursor(6,1);						// atur kursor ke kolom 6 baris 1
  lcd.print(cm);							// cetak nilai jarak
  lcd.print("cm");
  print_unit_cm(cm);						// cetak satuan (cm)
}

int read_sensor_ultrasonic() {
  /* baca dari Ultrasonic Sensor */
  
  pinMode(ping_Pin, OUTPUT);		// atur pin sebagai OUTPUT
  digitalWrite(ping_Pin, LOW);	// beri sinyal awal LOW
  delayMicroseconds(2);			// jeda 2 microseconds
  digitalWrite(ping_Pin, HIGH);	// trigger sensor dengan sinyal HIGH
  delayMicroseconds(5);			// trigger sensor selama 5 microseconds
  digitalWrite(ping_Pin, LOW);	// beri sinyal LOW
  
  pinMode(ping_Pin, INPUT);					// atur pin sebagai INPUT
  dur = pulseIn(ping_Pin, HIGH);		// sinyal HIGH untuk dapat durasi (dalam microseconds)
  cm = ms_to_cm(dur);	// konversi microseconds ke cm
  
  if (cm >= 2 && cm <= 330) {
    return cm;
  } else {
    return 0;
  }
}

long ms_to_cm(long ms) {
  // kecepatan suara 340 m/s atau 29 microseconds/cm
  // dibagi dua untuk mencari jarak sensor-objek
  return ms / 29 / 2;
}

void print_unit_cm(long cm) {
  /* cetak satuan cm */
  
  int ROW = 1;							// nomor baris
  int ERR_Digit = 6;					// koordinat kolom
  int oneDigit = 7;						// koordinat kolom
  int twoDIgit = 8;						// koordinat kolom
  int threeDigit = 9;					// koordinat kolom
  int lenUnit = 2;						// jumlah karakter satuan
}
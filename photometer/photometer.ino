/*
    Photometer.ino - Code for the Arduino-based phototrigger
    Copyright (C) 2024  Vinicius Pavao

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

int l;
int photo = A0;
int out = 2;
 
void setup() {
    Serial.begin(9600);
    pinMode(photo, INPUT);
    pinMode(out, OUTPUT);
    digitalWrite(out, LOW);
}

void loop() {
    l = analogRead(photo);
    //Serial.print(float((5000*l)/1024)); Serial.println(" mV");
    delay(1);
    if((analogRead(photo) - l) > 15) {
        //Serial.println(">> Trigger signal sent");
        digitalWrite(out, HIGH);
        delay(200);
        digitalWrite(out, LOW);
        delay(1000);
    }
}

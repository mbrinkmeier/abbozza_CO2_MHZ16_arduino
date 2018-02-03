/**
 * @license
 * abbozza! Calliope plugin for the MH-Z16 CO2 sensor
 * 
 * The sensor has to be connected to a serial connection with 9600 baud.
 *
 * Copyright 2015 Michael Brinkmeier ( michael.brinkmeier@uni-osnabrueck.de )
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "SoftwareSerial.h"
#include "MHZ16.h"
#include "Arduino.h"

MHZ16::MHZ16(int tx, int rx) {
    this->serial = new SoftwareSerial(rx,tx,false);
    this->serial->begin(9600);
}


void MHZ16::calibrate() {
    int idx;
    for (idx = 0; idx < 9; idx++) {
        serial->write(cal[idx]);
    }
    delay(10);
}

void MHZ16::doMeasurement() {
    int idx;
    int bu;

    for (idx = 0; idx < 9; idx++) {
        serial->write(cmd[idx]);
    }
    delay(10);

    while (serial->available()) {
        do {
            bu = serial->read();
        } while (bu != 255);
        buf[0] = bu;

        idx = 1;
        while (serial->available() && (idx < 9)) {
            bu = serial->read();
            buf[idx] = bu;
            idx++;
        }

        if (idx == 9) {
            PPM = ((int) buf[2]) *256 + ((int) buf[3]);
        }
    }
}

int MHZ16::getPPM() {
    return PPM;
}

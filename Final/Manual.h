#ifndef MANUAL_H
#define MANUAL_H

const int MANUAL_OVERRIDE = 0;
const int OPEN = 1;
const int CLOSE = 2;
const int EXIT = 3;

void modeManual();
void ManualOverride();
void ManualOptionsDisplay();
void ChangeManualDisplay(int mode);



#endif
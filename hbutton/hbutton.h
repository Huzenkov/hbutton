/*
Иван Гузенков. Харьков 2020. instagramm @grabbly

При нажатии кнопки, переменная bPush принимает значение TRUE.
При двойном клике по кнопке во временном периоде определенным в delayDouble, переменная bDouble принимает значение TRUE.
При удержании кнопки во временном периоде определенным в delayHold, переменная bDouble принимает значение TRUE.
debounceDelay - время подавления дребезга и переходного процесса.
При удержании кнопки нажатой, переменная bHold будет менять значение с TRUE на FALSE с периодичностью delayHold
*/
#ifndef hbutton_h  // если библиотека Button не подключена
#define hbutton_h  // тогда подключаем ее
#include "Arduino.h"
class Button{
  public:
  Button(byte pin, int delayDouble, int delayHold);
    bool bPush;
    bool bDouble;
    bool bHold;
    byte bState;
    void scanState();
    void setPinDelay(byte pin, int delayDouble, int delayHold);
    void returned();

  private:
    long _lastPush;
    long _lastPush2;
    long _lastDouble;
    long _lastHold;
    int  _delayDouble;
    int  _delayHold;
    bool _trigPush;
    bool _trigPush2;
    bool _trigDouble;
    bool _trigHold;
    byte _pin;
};
#endif

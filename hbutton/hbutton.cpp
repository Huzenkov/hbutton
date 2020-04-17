/*
Иван Гузенков. Харьков 2020. instagramm @grabbly

При нажатии кнопки, переменная bPush принимает значение TRUE.
При двойном клике по кнопке во временном периоде определенным в delayDouble, переменная bDouble принимает значение TRUE.
При удержании кнопки во временном периоде определенным в delayHold, переменная bDouble принимает значение TRUE.
debounceDelay - время подавления дребезга и переходного процесса.
При удержании кнопки нажатой, переменная bHold будет менять значение с TRUE на FALSE с периодичностью delayHold
*/
#include "Arduino.h"
#include "hbutton.h"
void Button::scanState(){
  if(digitalRead(_pin) == 1)
    {
      if (_trigPush == 0)
        {
          _lastPush = millis();
          _trigPush = 1;
          _trigPush2 = 1;
        }
      if(_trigDouble == 0)
        {
          _lastDouble = millis();
          bDouble = 0;
        }

      if(_trigHold == 0) _lastHold = millis();

      if(millis() < _lastHold + _delayHold && _trigHold == 0)
        {
          bHold = 0;
          _trigHold = 1;
        }
      if(millis() > _lastHold + _delayHold && _trigHold == 1)
        {
          bHold = 1;
          _lastHold = millis();
          _trigHold = 0;
          _trigPush2 = 0;
        }
      if(_trigDouble == 1 && millis() < _lastDouble + _delayDouble)
        {
          bDouble = 1;
          _trigDouble = 0;
        }
    }

  if(digitalRead(_pin) == 0)
    {
      if(millis() < _lastDouble + _delayDouble) _trigDouble = 1;
      else _trigDouble = 0;
      if(_trigPush == 1)
        {
          _lastPush2 = millis();
          _trigPush = 0;
        }
      if (bPush == 1 )
        {
          bPush = 0;
          _trigPush2 = 0;
        }
    if(_lastPush2 - _lastPush > _delayDouble && _trigPush2 == 1) bPush = 1;
    else bPush = 0;
    _trigHold = 0;
    bHold = 0;
    bDouble = 0;
    }
  }
void Button::setPinDelay(byte pin, int delayDouble, int delayHold){
  _pin = pin;
  _delayDouble = delayDouble;
  _delayHold = delayHold;
  pinMode(_pin,INPUT_PULLUP);
}
Button::Button(byte pin, int delayDouble, int delayHold){
  _pin = pin;
  _delayDouble = delayDouble;
  _delayHold = delayHold;
  pinMode(_pin,INPUT_PULLUP);
}

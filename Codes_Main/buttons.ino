byte button(byte a, int b) {
  byte counter = 0;
  int c = b + 200; //check the button value in the range of 200
 p: int timer = 0 ;

  if (analogRead(a) > b && analogRead(a) < c) {
    while (analogRead(a) > b && analogRead(a) < c) {
      delay(1); //take only 1 input for long press
      timer++;
    }
    if (timer > 30) {//to fix the debounce issue
      timer = 0;
      counter++;
      while (!(analogRead(a) > b && analogRead(a) < c)) {
        delay(1);
        timer++;
        if (timer > 500) return counter;
      }
      goto p;
    }
  }
  return counter;
}

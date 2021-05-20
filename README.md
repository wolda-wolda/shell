# Walder Marcel - Shell


------------


## Ausführen
### Windows

```cmd
gcc main.c -o Shell.exe
Shell.exe
```
#### Optional:

Für farbige Ausgabe unter Windows wird einen Änderung im Regestrierung-Editor benötigt. 
Manuell unter Computer\HKEY_CURRENT_USER\Console den Wert von VirtualTerminalLevel und VirtualTerminalLevel#(falls vorhanden) auf 1 setzen.
Oder sonst denn unten aufgeführten Command in der CMD auführen.
```Regedit
REG ADD HKCU\CONSOLE /f /v VirtualTerminalLevel /t REG_DWORD /d 1
```
### Linux

```bash
gcc main.c -o Shell.out
./Shell.out
```

------------


## Befehle

#### ls
>ls: Gibt den Inhalt des aktullen Ordners aus.

#### cd
>cd PARAMETER: Wechselt das working directory zu den übergeben Parameter.

>cat
>>cat $$: gibt den Inhalt der übergebenen Datei aus.

>rm
>>rm $$: löscht die übergebenen Ordner oder Dateien. 
Deshalb kein rmdir notwendig

>mv
>>mv $ $$: verschiebt die übergebene Dateien ($$) in den übergebenen Ordner ($)

>cp
>>cp $ $$: kopiert den Inhalt der übergebene Dateien ($$) in die übergebene Datei ($). 
Die Datei ($) wird überschrieben (nach Bestätigung des Benutzers) und falls noch nicht vorhanden wird sie erstellt. 
Anstelle von einer Datei kann man auch einen Ordner ($) übergeben und die Dateien ($) dorthin kopieren. 
Falls sich in diesem Ordner bereits eine Datei mit gleichen Name befindet wird sie überschrieben (nach Bestätigung des Benutzers).

>echo
>>echo $$: gibt den übergebene Text aus.

>mkdir
>>mkdir $: erstellt im current working directory einen Ordner.

>pwd
>>pwd: gibt das current working directory aus.

>chmod
>>chmod $ $$: die Rechte der übergebene Dateinen und Ordner ($$) werden geändert. 
$ muss ein numerischer Code sein mit der bereits in Linux bekannten Zahlenmethode.

>touch
>>touch $$: erstellt im current working directory Dateien ($$).

>help
>>help ($$): listet alle Befehle mit kurzer Beschreibung auf. 
Falls Parameter übergeben werden, wird nur die Beschreibung dieser Befehler aufgelistet.

>exit
>>exit: beendet die Shell

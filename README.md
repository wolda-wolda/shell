https://github.com/wolda-wolda/shell.git

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
sudo ./Shell.out
```

------------


## Befehle

#### ls
ls: Gibt den Inhalt des aktullen Ordners aus.

#### cd
cd Ordner oder .. : Wechselt das working directory zu den übergeben Ordner oder relativen/absoluten Pfad.

#### cat
cat Datei: Gibt den Inhalt der übergebenen Datei aus, es können auch mehrere Dateien übergeben werden.

#### rm

rm Datei: löscht die übergebenen Dateien.

#### mv
mv Datei/Ordner Zielordner/Zieldatei: Verschiebt die übergebene Datei/Ordner in den übergebenen Ordner oder bennent die Datei/Ordner um.

#### cp
cp Datei Zielordner: Kopiert die übergebene Datei an denn übergebenen Zielordner. Falls die Datei schon exestiert wird sie überschrieben. 

#### echo
echo Text: Gibt den übergebenen Text aus.

#### mkdir
mkdir Ordner: Erstellt im aktuellen Ordner einen neuen Ordner. Wird ein relativer Pfad übergeben z.B. ../Ordner wird der Ordner an diesem Ort erstellt, der Befehlt funktioniert auch mit Absoluten Pfaden sofern der Benutzer die Berechtigunen besitzt dort Ordner zu erstellen.

#### pwd
pwd: Gibt den absoluten Pfad zum aktuellen Ordner an.

#### chmod

chmod 777 Ordner/Datei: Die Rechte der übergebenen Datei/Ordner wird geändert. Die Berechtigungen müssen als numerischer
Code wie in Linux übergeben werden.

#### touch

touch Datei: Erstellt im aktuellen Ordner eine Datei. Wird ein relativer Pfad übergeben z.B. ../Datei wird die Datei an
diesem Ort erstellt, der Befehlt funktioniert auch mit Absoluten Pfaden sofern der Benutzer die Berechtigunen besitzt
dort Dateien zu erstellen.

#### help

help: Listet alle verfügbaren Befehle auf mit Beschreibung wie hier.

#### settings

settings: Eingener Befehl der denn Benutzer die Farben der Ausgabe ändern lässt.

#### whoami

whoami: Zeigt denn aktullen Benutzer.

#### shutdown

shutdown: PC herunterfahren.

#### reboot

reboot: PC neustarten.

#### exit

exit: Beendet die Shell wer hätte sich das gedacht.

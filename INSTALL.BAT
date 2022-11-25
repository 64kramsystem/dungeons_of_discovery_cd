ECHO OFF

IF "%2" == "" GOTO INSTRUCT
ECHO.
ECHO Copying files...
ECHO.
MD %2:\DUNGEON
XCOPY %1: %2:\DUNGEON /S
DEL %2:\DUNGEON\INSTALL.BAT
ECHO.
ECHO All done!
ECHO.
GOTO END

:INSTRUCT
ECHO.
ECHO Please type INSTALL S D, where S is the source drive
ECHO and D is the destination drive. For example, to install
ECHO from the CD-ROM called D to the C hard drive, type 
ECHO INSTALL D C
ECHO.

:END

echo off
if "%1" == "" goto badstart
if "%2" == "" goto badstart
if "%3" == "" goto badstart
if "%3" == "y" goto begin
if "%3" == "n" goto begin
goto badstart
:begin
echo Please place a formatted BLANK disk labeled EXAMPLES in drive %2
pause
md %2\ANSWERS
md %2\EXAMPLES
md %2\PIE
unpack %1\ANSWERS.ARC %2\ANSWERS
unpack %1\EXAMPLES.ARC %2\EXAMPLES
unpack %1\PIE.ARC %2\PIE
if "%3" == "n" goto cont
if "%3" == "N" goto cont
echo Please place a formatted BLANK disk labeled REFEXAMP in drive %2
pause
md %2\REFEXAMP
unpack %1\REFEXAMP.ARC %2\REFEXAMP
:cont
echo Please place a formatted BLANK disk labeled PROGRAMS in drive %2
pause
unpack %1\PROGRAMS.ARC %2
echo Please place a formatted BLANK disk labeled BOOT DISK in drive %2
pause
copy %1\readme.* %2
:chkdsk2
if exist %1PROLOG.EXE goto cpyfile2
echo Please insert the Turbo Prolog disk labeled COMPILER into drive %1
pause
goto chkdsk2
:cpyfile2
copy %1\PROLOG.EXE %2
copy %1\BGI.LIB %2
copy %1\BGIOBJ.EXE %2
:chkdsk3
if exist %1PROLOG.ERR goto cpyfile3
echo Please insert the Turbo Prolog disk labeled HELP/BGI into drive %1
echo and a formatted BLANK disk labeled RUN DISK in drive %2
pause
goto chkdsk3
:cpyfile3
copy %1\*.* %2
erase %2\INSTALL*.BAT
:chkdsk4
if exist %1PROLOG.LIB goto cpyfile4
echo Please insert the Turbo Prolog disk labeled LIBRARY into drive %1
echo and a formatted BLANK disk labeled LIBRARY in drive %2
pause
goto chkdsk4
:cpyfile4
copy %1\*.* %2
erase %2\INSTALL*.BAT
echo 
echo Turbo Prolog 2.0 is now aready for use on your system.  Don't forget
echo to put the ORIGINAL disks in a safe place.
echo 
goto quit
:badstart
echo To install Turbo Prolog on a two floppy system place the disk labeled
echo INSTALLATION/README in drive A: and use the command
echo 
echo    INSTALLF A: B: y  (if you want to copy the Reference Examples)
echo  
echo    INSTALLF A: B: n  (if you don't want the Reference Examples)  
echo   
echo (Where A: is the SOURCE drive and B: is the DESTINATION drive.)  
:quit
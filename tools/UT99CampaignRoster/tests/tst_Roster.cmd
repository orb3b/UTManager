@ECHO OFF

SET Tests=Roster\tst_qstring.exe^
		  Roster\tst_pawn.exe^
		  Application\tst_editorconnector.exe

SetLocal EnableDelayedExpansion
for %%f in (%Tests%) do (		
	call %%f
	if not !ERRORLEVEL! equ 0 (
		echo Test FAILED, aborting...
		goto end
	)
	echo Test SUCCESS
	echo:
)
EndLocal

goto end

:end